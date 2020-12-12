//
// Created by alexscorpy on 25.11.2020.
//

#ifndef CURSE_CODE_GAMMA_CIPHER_H
#define CURSE_CODE_GAMMA_CIPHER_H

#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int FIRST_SYMBOL = ' '; // первый символ
const int SYMBOL_NUMBER = 95; // последний символ

void Gamma_Coding(string &input, string &gamma, string &result) {
    result.clear();
    for (string::iterator i = input.begin(), j = gamma.begin(); i < input.end(); i++, j++) {
        if (j == gamma.end()) j = gamma.begin();
        int Ti = *i - FIRST_SYMBOL;
        int Gi = *j - FIRST_SYMBOL;
        result.push_back(FIRST_SYMBOL + (Ti + Gi) % SYMBOL_NUMBER);
    }
}

void Gamma_Decoding(string &input, string &gamma, string &result) {
    result.clear();
    for (string::iterator i = input.begin(), j = gamma.begin(); i < input.end(); i++, j++) {
        if (j == gamma.end()) j = gamma.begin();
        int Ci = *i - FIRST_SYMBOL;
        int Gi = *j - FIRST_SYMBOL;
        result.push_back(FIRST_SYMBOL + (Ci - Gi + SYMBOL_NUMBER) % SYMBOL_NUMBER);
    }
}

void Gamma_Cipher() {
    int x;
    string str1, gamma, rez;
    cout << "Please choose next action:\n";
    cout << "(1) Encrypt the string." << endl;
    cout << "(2) Decrypt the string." << endl;
    cout << "ENTER A COMMAND--->";
    cin >> x;
    switch (x) {
        case 1:
            cout << "You can use these symbols:" << endl;
            for (int i = 33; i <= 126; i++) {
                cout << char(i) << " ";
            }
            cout << endl;
            cout << "Please enter a string: ";
            cin >> str1;
            cout << "Please enter a gamma(your key): ";
            cin >> gamma;
            for (size_t i = 0; i < str1.size(); i++) {
                if (str1[i] < 33 || str1[i] > 126)
                    throw "Code of your symbols must be in this range -> [33,126] !!!";
            }
            for (size_t i = 0; i < gamma.size(); i++) {
                if (gamma[i] < 33 || gamma[i] > 126)
                    throw "Code of your symbols must be in this range -> [33,126] !!!";
            }
            Gamma_Coding(str1, gamma, rez);
            cout << "Encrypted string: ";
            cout << rez << endl;
            break;
        case 2:
            cout << "You can use these symbols:" << endl;
            for (size_t i = 33; i <= 126; i++) {
                cout << char(i) << " ";
            }
            cout << endl;
            cout << "Please enter an encrypted string: ";
            cin >> rez;
            cout << "Please enter a gamma(your key): ";
            cin >> gamma;
            for (size_t i = 0; i < rez.size(); i++) {
                if (rez[i] < 33 || rez[i] > 126)
                    throw "Code of your symbols must be in this range -> [33,126] !!!";
            }
            for (size_t i = 0; i < gamma.size(); i++) {
                if (gamma[i] < 33 || gamma[i] > 126)
                    throw "Code of your symbols must be in this range -> [33,126] !!!";
            }
            Gamma_Decoding(rez, gamma, str1);
            cout << "Decrypted string: ";
            cout << str1 << endl;
            break;
        default:
            cout << "Wrong command!" << endl;
    }
}

#endif //CURSE_CODE_GAMMA_CIPHER_H
