//
// Created by alexscorpy on 25.11.2020.
//

#ifndef CURSE_CODE_AES_ANALYSIS_H
#define CURSE_CODE_AES_ANALYSIS_H

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>

#include "AES_Cipher.h"

#define BUFF_SIZE 1024
using namespace std;

char const *pCharset = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTU"
                       "VWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void random_key(uint8_t key[KEY_SIZE]) {
    cout << "[ ";
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = pCharset[rand() % 100 - 6];
        cout << key[i] << " ";
    }
    cout << "]" << endl;
}

void AES_Analysis() {
    int I = 0;
    string button;
    double start_time, end_time, search_time; // считаем время взлома
    string str, STR;
    uint8_t encrypted[BUFF_SIZE] = {0};
    uint8_t decrypted[BUFF_SIZE] = {0};
    uint8_t buffer[BUFF_SIZE];
    uint8_t key[KEY_SIZE] = "Key_is_128_bits";
    uint8_t KEY[KEY_SIZE] = "Key_is_128_bits";
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
    cout << "Your generated key ===> [" << key <<"]" << endl;
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
    cout << "[ ";
    for (size_t i = 0; i < str.size(); i++)
        cout << char(decrypted[i]) << " ";
    cout << "]" << endl;
    cout << endl;

    cout << "Do you want to hack this cipher???" << endl;
    cout << "Write <<yes>> or <<y>> if you want to make a cryptoanalysis." << endl;
    cin >> button;
    if (button == "yes" || button == "y") {
        start_time = clock(); // начальное время
        while (str != STR && I < 99999) {
            cout << I + 1 << ") ITERATION:" << endl;
            random_key(key);
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
        end_time = clock(); // конечное время
        search_time = end_time - start_time; // искомое время
        cout << "This cipher was hacked!" << endl;
        cout << "Your  key ===> [" << KEY <<"]" << endl;
        length = AES(decrypted, 'D', KEY, KEY_SIZE, encrypted, length);
        cout << "Decrypted string: " << endl;
        cout << "[ ";
        for (size_t i = 0; i < str.size(); i++)
            cout << int(decrypted[i]) << " ";
        for (size_t i = 0; i < length - str.size(); i++)
            cout << "0" << " ";
        cout << "]" << endl;
        cout << "[ ";
        for (size_t i = 0; i < str.size(); i++)
            cout << char(decrypted[i]) << " ";
        cout << "]" << endl;
        cout << "Time for hacking: " << search_time << " milliseconds ("
        << search_time / 1000 << " seconds)" << endl;
        cout << "                     ------------------------- ----------------"
        << endl;
        cout << "     =========>      |AES CIPHER HAS A CALCULATING RESISTANCE!|     "
                " <=========" << endl;
        cout << "                     -------------------------- ---------------"
        << endl;
    }

}

#endif //CURSE_CODE_AES_ANALYSIS_H
