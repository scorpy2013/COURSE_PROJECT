//
// Created by alexscorpy on 16.12.2020.
//

#ifndef TEMPLATE_VERNAM_ANALYSIS_SIDE_CHANNEL_H
#define TEMPLATE_VERNAM_ANALYSIS_SIDE_CHANNEL_H

#include <iostream>
#include "Gamma_Cipher.h"

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
    cout << "Write <<YES>> if you want to make a cryptoanalysis." << endl;
    cin >> button;
    if (button == "YES") {
        cout << "Your gamma-key was stolen by hackers!" << endl;
        cout << "Key is ===> [" << gamma << "]." << endl;
        Gamma_Decoding(rez, gamma, str1);
        cout << "Hacked string: ";
        cout << str1 << endl;
        cout << "This cipher was hacked! However..." << endl;
        cout << "                     ---------------------------------------"
        << endl;
        cout << "     =========>      | VERNAM CIPHER HAS A HIGH RESISTANCE!| "
                "     <=========" << endl;
        cout << "                     ---------------------------------------"
        << endl;
    }
}

#endif //TEMPLATE_VERNAM_ANALYSIS_SIDE_CHANNEL_H
