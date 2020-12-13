//
// Created by alexscorpy on 23.11.2020.
//

#ifndef CURSE_PROJECT_CESAR_ANALYSIS_H
#define CURSE_PROJECT_CESAR_ANALYSIS_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;

// simple symbols in the table
// ASCII TABLE: [32]symbol - [128]symbol
void Cesar_Analysis() {
    int kol;
    double start_time, end_time, search_time; // считаем время взлома
    char en_str[100], de_str[100];
    cout << "You can use these symbols for encrypted string:" << endl;
    for (int i = 33; i <= 126; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter an encrypted string of length [1,100]: ";
    cin >> en_str;
    cout << "You can use these symbols for decrypted string:" << endl;
    for (int i = 33; i <= 95; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter a decrypted string of length [1,100]: ";
    cin >> de_str;
    if (strlen(en_str) > 100)
        throw "Your encrypted string has too big length!!!";
    else {
        if (strlen(de_str) > 100)
            throw "Your decrypted string has too big length!!!";
        else {
            if (strlen(en_str) != strlen(de_str)) {
                throw "Your encrypted and decrypted strings must have one length!!!";
            } else {
                for (size_t i = 0; i < strlen(en_str); i++) {
                    if (de_str[i] < 33 || de_str[i] > 95 || en_str[i] < 33 || en_str[i] > 126)
                        throw "Code of symbols of your string is not correct!!!";
                }
            }
        }
    }

    start_time = clock(); // начальное время
    for (int i = 0; i < 96; i++) {
        for (int j = 0; (j < 100 && en_str[j] != '\0'); j++)
            en_str[j] = en_str[j] - 1;
        cout << i + 1 << ") Hacked string: " << en_str << endl;
        if (strcmp(en_str, de_str) == 0)
            break;
        kol = i + 1;
    }
    end_time = clock(); // конечное время
    search_time = end_time - start_time; // искомое время
    if (strcmp(en_str, de_str) == 0) {
        cout << "Time for hacking: " << search_time << " milliseconds (" << search_time / 1000 << " seconds)" << endl;
        cout << "Shift number is: " << kol << endl;
        cout << "                     ---------------------------" << endl;
        cout << "     =========>      |CESAR CIPHER IS UNSTABLE!|      <=========" << endl;
        cout << "                     ---------------------------" << endl;
    } else {
        cout << "Input symbols are not correct, because this cipher can be hacked in any case!" << endl;
        cout << "Please, try again..." << endl;
    }
}

#endif //CURSE_PROJECT_CESAR_ANALYSIS_H
