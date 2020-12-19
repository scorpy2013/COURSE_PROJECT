//
// Created by alexscorpy on 25.11.2020.
//

#ifndef CURSE_CODE_RSA_ANALYSIS_H
#define CURSE_CODE_RSA_ANALYSIS_H

#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void random_key(int &P, int &Q, unsigned int &E, int &D, int &N) {
    srand((unsigned) time(NULL));
    int p = rand() % 100;
    int q = rand() % 100;
    int p_simple = random_simple(p);
    int q_simple = random_simple(q);
    unsigned int n = p_simple * q_simple;
// НОД [d , (p_simple-1)*(q_simple-1)] = 1
    int d, d_simple = 0;
    while (d_simple != 1) {
        d = rand() % 100;
        d_simple = NOD(d, ((p_simple - 1) * (q_simple - 1)));
    }
//с(e*d)%((p_simple-1)*(q_simple-1))=1
    unsigned int e = 0, e_simple = 0;
    while (e_simple != 1) {
        e += 1;
        e_simple = (e * d) % ((p_simple - 1) * (q_simple - 1));
    }
    cout << "Open key ===> " << "{e,n} <=> " << "{" << e << "," << n << "}"
    << endl;
    cout << "Secret key ===> " << "{d,n} <=> " << "{" << d << "," << n << "}"
    << endl;
    P = p;
    Q = q;
    E = e;
    D = d;
    N = n;
}

void RSA_Analysis() {
    double start_time, end_time, search_time = 0; // считаем время взлома
    int p, q, n, d;
    unsigned int e;
    int b = 301;
    int m, I = 0;
    string Decrypted;
    const int MAX = 20;
    int max, NEWMAX;
    char *Text = new char[MAX];
    unsigned int *CryptoText = new unsigned int[MAX];
    unsigned int *Tdecrypt = new unsigned int[MAX];
    cout << "You can use these symbols:" << endl;
    for (int i = 33; i <= 126; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter a length of your CryproText [1,20]:" << endl;
    cin >> NEWMAX;
    if (NEWMAX < 1 || NEWMAX > 20)
        throw "Length of your CryproText must be in range of [1,20]!!!";
    cout << "Please enter an encrypted string:" << endl;
    for (int i = 0; i < NEWMAX; i++) {
        cout << "[" << i + 1 << "] ";
        cin >> CryptoText[i];
    }
    cout << "Please enter a decrypted string:" << endl;
    cin >> Text;
    max = strlen(Text);
    if (NEWMAX != max) {
        throw "Your encrypted and decrypted strings must have one length!!!";
    } else {
        for (int i = 0; i < NEWMAX; i++) {
            if (Text[i] < 33 || Text[i] > 126)
                throw "Code of symbols of your string is not correct!!!";
        }
    }
    start_time = clock(); // начальное время
    while (I < 100000) {
        cout << I + 1 << ") iteration: " << endl;
        random_key(p, q, e, d, n);
        for (int j = 0; j < MAX; j++) {
            m = 1;
            int i = 0;
            while (i < d) {
                m = m * CryptoText[j];
                m = m % n;
                i++;
            }
            m = m - b;
            Tdecrypt[j] = m;
            b += 1;
        }
        for (int j = 0; j < MAX; j++)
            Decrypted.push_back(static_cast<char>(Tdecrypt[j]));
        cout << "Decrypted string: " << Decrypted << endl << endl;
        Decrypted = "";
        I++;
    }
    end_time = clock(); // конечное время
    search_time = end_time - start_time; // искомое время
    cout << "Time for hacking: " << search_time << " milliseconds (" <<
    search_time / 1000 << " seconds)" << endl;
    cout << "This cipher can't be hacked!" << endl;
    cout << "                     ---------------------------------------" << endl;
    cout << "     =========>      |RSA CIPHER HAS A PROVABLE RESISTANCE!|      <=========" << endl;
    cout << "                     ---------------------------------------" << endl;
    delete[] Text;
    delete[] CryptoText;
    delete[] Tdecrypt;
}

#endif //CURSE_CODE_RSA_ANALYSIS_H
