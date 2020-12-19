//
// Created by alexscorpy on 28.11.2020.
//

#ifndef CURSE_CODE_VERNAM_ANALYSIS_H
#define CURSE_CODE_VERNAM_ANALYSIS_H

#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

void Vernam_Analysis() {
    double start_time, end_time, search_time; // считаем время взлома
    int L; // длина нашего ключа
    string str, str1, gamma, GAMMA, rez;
    int kol=1;
    char const *pCharset = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    size_t const CharsetSize = strlen(pCharset);
    cout << "Please enter an encrypted string: ";
    cin >> rez;
    L = rez.size();
    size_t *key = new size_t[L];
    cout << "The key length is: " << L << endl;
    cout << "Please enter an decrypted string: ";
    cin >> str;
    if (rez.size() != str.size()) {
        throw "Encrypted and decrypted texts must have one length!";
    } else {
        for (size_t i = 0; i < rez.size(); i++) {
            if (rez[i] < 33 || rez[i] > 126 || str[i] < 33 || str[i] > 126)
                throw "Code of symbols of your string is not correct!!!";
        }
    }
    memset(key, 0, L * sizeof(size_t));
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
        cout << "     =========>      |  ABSOLUTE CRYPTOGRAPHIC STRENGTH!!! |      <=========" << endl;
        cout << "                     ---------------------------------------" << endl;
    }
    delete[] key;
}

#endif //CURSE_CODE_VERNAM_ANALYSIS_H
