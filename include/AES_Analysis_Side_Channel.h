//
// Created by alexscorpy on 16.12.2020.
//

#ifndef TEMPLATE_AES_ANALYSIS_SIDE_CHANNEL_H
#define TEMPLATE_AES_ANALYSIS_SIDE_CHANNEL_H

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>

#include "AES_Cipher.h"

#define BUFF_SIZE 1024
using namespace std;

void AES_Analysis_Side_Channel() {
    int I = 0;
    string button;
    string str, STR;
    uint8_t encrypted[BUFF_SIZE] = {0};
    uint8_t decrypted[BUFF_SIZE] = {0};
    uint8_t buffer[BUFF_SIZE];
    uint8_t key[KEY_SIZE] = "Key_is_128_bits";
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
    AES_print_array(buffer, length);
    cout << "Encrypted string: " << endl;
    length = AES(encrypted, 'E', key, KEY_SIZE, buffer, length);
    AES_print_array(encrypted, length);
    cout << "Decrypted string: " << endl;
    length = AES(decrypted, 'D', key, KEY_SIZE, encrypted, length);
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
        cout << "You key was stolen by hackers!" << endl;
        cout << "Your key is [" << key << "]." << endl;
        cout << "Decrypted string: " << endl;
        length = AES(decrypted, 'D', key, KEY_SIZE, encrypted, length);
        cout << "[ ";
        for (size_t i = 0; i < str.size(); i++) {
            STR.push_back(decrypted[i]);
            cout << int(decrypted[i]) << " ";
        }
        for (size_t i = 0; i < length - str.size(); i++)
            cout << "0" << " ";
        cout << "]" << endl;
        cout << endl;
        STR.clear();
        I++;
    }
    cout << "This cipher was hacked! However..." << endl;
    cout << "                     -----------------------------------" << endl;
    cout << "     =========>      |AES CIPHER HAS A HIGH RESISTANCE!|      <=="
            "=======" << endl;
    cout << "                     -----------------------------------" << endl;
}



#endif //TEMPLATE_AES_ANALYSIS_SIDE_CHANNEL_H
