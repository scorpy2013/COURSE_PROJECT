//
// Created by alexscorpy on 16.12.2020.
//

#ifndef TEMPLATE_DES_ANALYSIS_SIDE_CHANNEL_H
#define TEMPLATE_DES_ANALYSIS_SIDE_CHANNEL_H

#define BUFF_SIZE 1024
#include <iostream>
#include "DES_Cipher.h"
#include "Secret_Key.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

void DES_Analysis_Side_Channel() {
    string button;
    string str, KEY;
    uint8_t encrypted[BUFF_SIZE], decrypted[BUFF_SIZE];
    uint8_t buffer[BUFF_SIZE] = {0};
    uint8_t keys8b[8] = "Key56bt";
    cout << "You can use these symbols:" << endl;
    for (int i = 33; i <= 126; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter a string:" << endl;
    cin >> str;
    size_t length = str.size();
    for (size_t i = 0; i < length; i++) {
        buffer[i] = str[i];
        if (buffer[i] < 33 || buffer[i] > 126)
            throw "Code of your symbols must be in this range -> [33,126] !!!";
    }
    print_array(buffer, length);
    cout << "Your generated key ===> [" << keys8b <<"]" << endl;
    cout << "Encrypted string: " << endl;
    length = DES(encrypted, 'E', keys8b, buffer, length);
    print_array(encrypted, length);

    cout << "Decrypted string: " << endl;
    length = DES(decrypted, 'D', keys8b, encrypted, length);
    cout << "[ ";
    for (size_t i = 0; i < str.size(); i++)
        cout << int(decrypted[i]) << " ";
    for (size_t i = 0; i < length - str.size(); i++)
        cout << "0" << " ";
    cout << "]" << endl;

    cout << "Do you want to hack this cipher???" << endl;
    cout << "Write <<YES>> if you want to make a cryptoanalysis." << endl;
    cin >> button;
    if (button == "YES") {
        for (int i=0; i<8;i++)
            KEY.push_back(char(keys8b[i]));
        Secret_Key secret_key(KEY);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "      ======================================" << endl;
        cout << "      | Your key was hidden in this picture|" << endl;
        cout << "      ======================================" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        secret_key.Print_Key8b();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Your key was stolen by hackers, because transfer channel has "
                "been hacked!!!" << endl;
        cout << "Your key is [" << keys8b << "]." << endl;
            cout << "Decrypted string: " << endl;
            length = DES(decrypted, 'D', keys8b, encrypted, length);
            cout << "[ ";
            for (size_t i = 0; i < str.size(); i++) {
                cout << int(decrypted[i]) << " ";
            }
            for (size_t i = 0; i < length - str.size(); i++)
                cout << "0" << " ";
            cout << "]" << endl;
            cout << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "This cipher was hacked! However..." << endl;
        cout << "                     ---------------------------------------" << endl;
        cout << "     =========>      |DES CIPHER HAS A PROVABLE RESISTANCE!|      <=========" << endl;
        cout << "                     ---------------------------------------" << endl;
        }

    }

#endif //TEMPLATE_DES_ANALYSIS_SIDE_CHANNEL_H
