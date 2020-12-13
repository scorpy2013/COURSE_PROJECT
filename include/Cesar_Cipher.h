//
// Created by alexscorpy on 21.11.2020.
//

#ifndef CURSE_PROJECT_CESAR_CIPHER_H
#define CURSE_PROJECT_CESAR_CIPHER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
// для простоты кодируем символы с кодами по таблице ASCII [33] - [95]
// получается, что сдвиг можно выбирать в диапазоне [1, 31], иначе
// символы выйдут за пределы таблицы значений
using namespace std;

void Cesar_Cipher() {
    int x, number;
    char str[100];
    cout << "You can use these symbols:" << endl;
    for (int i = 33; i <= 95; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter a string of length [1,100]: ";
    cin >> str;
    if (strlen(str) > 100)
        throw "Your string has too big length!!!";
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] < 33 || str[i] > 95)
            throw "Code of your symbols must be in this range -> [33,95] !!!";
    }
    cout << "Please enter the number of range [1,31] by which we will shift the letters: ";
    cin >> number;
    if (number < 1 || number > 31)
        throw "Your number must be in this range -> [1, 31] !!!";
    cout << "Please choose next action:\n";
    cout << "(1) Encrypt the string." << endl;
    cout << "(2) Decrypt the string." << endl;
    cout << "ENTER A COMMAND--->";
    cin >> x;
    switch (x) {
        case 1:
            for (int i = 0; (i < 100 && str[i] != '\0'); i++)
                str[i] = str[i] + number;
            cout << "Encrypted string: " << str << endl;
            break;
        case 2:
            for (int i = 0; (i < 100 && str[i] != '\0'); i++)
                str[i] = str[i] - number;
            cout << "Decrypted string: " << str << endl;
            break;
        default:
            cout << "Wrong command!" << endl;
    }
}

#endif //CURSE_PROJECT_CESAR_CIPHER_H
