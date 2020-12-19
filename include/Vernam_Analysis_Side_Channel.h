//
// Created by alexscorpy on 16.12.2020.
//

#ifndef TEMPLATE_VERNAM_ANALYSIS_SIDE_CHANNEL_H
#define TEMPLATE_VERNAM_ANALYSIS_SIDE_CHANNEL_H

#include <iostream>
#include "Gamma_Cipher.h"
#include "Long_Secret_Key.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

void Vernam_Analysis_Side_channel() {
    string str1, gamma, rez, button;
    cout << "You can use these symbols:" << endl;
    for (int i = 33; i <= 126; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter a string: ";
    cin >> str1;
    cout << "Please enter a gamma(your key): ";
    cin >> gamma;
    if (str1.size() != gamma.size()) {
        throw "Gamma and your text must have one length!";
    } else {
        for (size_t i = 0; i < str1.size(); i++) {
            if (str1[i] < 33 || str1[i] > 126 || gamma[i] < 33 ||
            gamma[i] > 126)
                throw "Code of symbols of your string is not correct!!!";
        }
    }
    Gamma_Coding(str1, gamma, rez);
    cout << "Encrypted string: ";
    cout << rez << endl;
    cout << "Do you want to hack this cipher???" << endl;
    cout << "Write <<yes>> or <<y>> if you want to make a cryptoanalysis." << endl;
    cin >> button;
    if (button == "yes" || button == "y") {
        Long_Secret_Key secret_key(gamma);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "======================================" << endl;
        cout << "| Your key was hidden in this string |" << endl;
        cout << "======================================" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        secret_key.Print_Long_Key();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Your gamma-key was stolen by hackers, because transfer channe"
                "l has been hacked!!!" << endl;
        cout << "Key is ===> [" << gamma << "]." << endl;
        Gamma_Decoding(rez, gamma, str1);
        cout << "Hacked string: ";
        cout << str1 << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "This cipher was hacked! However..." << endl;
        cout << "                     ---------------------------------------" << endl;
        cout << "     =========>      |  ABSOLUTE CRYPTOGRAPHIC STRENGTH!!! |      <=========" << endl;
        cout << "                     ---------------------------------------" << endl;
    }
}

#endif //TEMPLATE_VERNAM_ANALYSIS_SIDE_CHANNEL_H
