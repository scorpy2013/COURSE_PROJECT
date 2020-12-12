//
// Created by alexscorpy on 28.11.2020.
//

#ifndef CURSE_CODE_VERNAM_CIPHER_H
#define CURSE_CODE_VERNAM_CIPHER_H

#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void Vernam_Cipher() {
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
            if (str1.size() != gamma.size()) {
                throw "Gamma and your text must have one length!";
            } else {
                for (size_t i = 0; i < str1.size(); i++) {
                    if (str1[i] < 33 || str1[i] > 126 || gamma[i] < 33 || gamma[i] > 126)
                        throw "Code of symbols of your string is not correct!!!";
                }
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
            if (rez.size() != gamma.size()) {
                throw "Gamma and your text must have one length!";
            } else {
                for (size_t i = 0; i < rez.size(); i++) {
                    if (rez[i] < 33 || rez[i] > 126 || gamma[i] < 33 || gamma[i] > 126)
                        throw "Code of symbols of your string is not correct!!!";
                }
            }
            Gamma_Decoding(rez, gamma, str1);
            cout << "Decrypted string: ";
            cout << str1 << endl;
            break;
        default:
            cout << "Wrong command!" << endl;
    }
}

#endif //CURSE_CODE_VERNAM_CIPHER_H
