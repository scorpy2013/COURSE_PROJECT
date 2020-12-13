//
// Created by alexscorpy on 25.11.2020.
//

#ifndef CURSE_CODE_GAMMA_ANALYSIS_H
#define CURSE_CODE_GAMMA_ANALYSIS_H

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

void print_key_generate_gamma(char const *pCharset, size_t const *pState, size_t Count, string &gamma) {
    for (size_t i = 0; i < Count; ++i) {
        gamma.push_back(pCharset[pState[i]]);
        cout << pCharset[pState[i]];
    }
}

bool increment_state(size_t *pState, size_t CharsetSize, size_t Count) {
    for (size_t i = 0; i < Count; ++i) {
        if (++pState[i] < CharsetSize) {
            return true;
        }

        pState[i] = 0;
    }
    return false;
}

void Gamma_Analysis() {
    int kol = 1;
    double start_time, end_time, search_time; // считаем время взлома
    int L; // длина нашего ключа
    string str, str1, gamma, GAMMA, rez;
    char const *pCharset = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    size_t const CharsetSize = strlen(pCharset);
    cout << "You can use these symbols:" << endl;
    for (size_t i = 33; i <= 126; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter an encrypted string: ";
    cin >> rez;
    cout << "Please enter the key length: ";
    cin >> L;
    size_t *key = new size_t[L];
    cout << "Please enter an decrypted string: ";
    cin >> str;
    memset(key, 0, L * sizeof(size_t));
    if (rez.size() != str.size()) {
        throw "Your encrypted and decrypted strings must have one length!!!";
    } else {
        for (size_t i = 0; i < rez.size(); i++) {
            if (rez[i] < 33 || rez[i] > 126 || str[i] < 33 || str[i] > 126)
                throw "Code of your symbols must be in this range -> [33,126] !!!";
        }
    }

    start_time = clock(); // начальное время
    do {
        cout << kol << " KEY: ";
        print_key_generate_gamma(pCharset, key, L, gamma);
        Gamma_Decoding(rez, gamma, str1);
        cout << " ===> HACKED STRING: " << str1 << endl;
        kol++;
        GAMMA = gamma;
        gamma = "";
        if (str1 == str || kol >= 5000000)
            break;
    } while (false != increment_state(key, CharsetSize, L));
    end_time = clock(); // конечное время
    search_time = end_time - start_time; // искомое время
    if (str1 == str) {
        cout << "Time for hacking: " << search_time << " milliseconds (" << search_time / 1000 << " seconds)" << endl;
        cout << "The hack required " << kol << " operations." << endl;
        cout << "The key is: " << GAMMA << " ===> This algorithm is stable! You choose to small key!" << endl;
    } else {
        cout << "Time for hacking: " << search_time << " milliseconds (" << search_time / 1000 << " seconds)" << endl;
        cout << "This cipher can't be hacked!" << endl;
        cout << "                     ---------------------------------------" << endl;
        cout << "     =========>      |GAMMING CIPHER HAS A HIGH RESISTANCE!|      <=========" << endl;
        cout << "                     ---------------------------------------" << endl;
    }
    delete[] key;
}

#endif //CURSE_CODE_GAMMA_ANALYSIS_H
