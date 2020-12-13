//
// Created by alexscorpy on 21.11.2020.
//

#ifndef CURSE_PROJECT_RSA_CIPHER_H
#define CURSE_PROJECT_RSA_CIPHER_H

#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int random_simple(const int &n) {
    int *a = new int[n], i, j, k, simple;
    memset(a, 0, sizeof(int) * n);
    for (i = 1; 3 * i + 1 < n; i++) {
        for (j = 1; (k = i + j + 2 * i * j) < n && j <= i; j++)
            a[k] = 1;
    }
    for (i = n - 1; i >= 1; i--)
        if (a[i] == 0) {
            simple = 2 * i + 1;
            break;
        }
    delete[] a;
    return simple;
}

int NOD(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return abs(a);
}

void RSA_Cipher() {
    cout << "\nTo generate open and secret keys program will" << endl;
    cout << "select two different random prime numbers p and q." << endl;
    string str;
    srand((unsigned) time(NULL));
    int p = rand() % 100;
    int q = rand() % 100;
    int p_simple = random_simple(p);
    int q_simple = random_simple(q);
    int Euler = (p_simple - 1) * (q_simple - 1);
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
    cout << "p = " << p << "; q = " << q << endl;
    cout << "n = p*q = " << n << endl;
    cout << "Euler Function F(n) = (p_simple-1)*(q_simple-1) = " << Euler << endl;
    cout << "d = " << d << endl;
    cout << "Open key ===> " << "{e,n} <=> " << "{" << e << "," << n << "}" << endl;
    cout << "Secret key ===> " << "{d,n} <=> " << "{" << d << "," << n << "}" << endl;
    const int MAX = 100;
    char *Text = new char[MAX];
    cout << "You can use these symbols:" << endl;
    for (int i = 33; i <= 126; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter a string:" << endl;
    cin >> str;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < 33 || str[i] > 126)
            throw "Code of symbols of your string is not correct!!!";
    }
    for (size_t i = 0; i < str.size(); i++)
        Text[i] = char(str[i]);
    unsigned int *CryptoText = new unsigned int[MAX];
    unsigned int *Tdecrypt = new unsigned int[MAX];
//ci = (mj^e)%n.
    int b = 301;
    int c;
    cout << "|STRING|ASCII CODE|CryptoText/Block|ASCII DECRYPTED CODE|DECRYPTED STRING|" << endl
         << "--------------------------------------------------------------------------" << endl;
    for (size_t j = 0; j < str.size(); j++) {
        c = 1;
        unsigned int i = 0;
        int ASCIIcode = (static_cast<int>(Text[j])) + b;
        while (i < e) {
            c = c * ASCIIcode;
            c = c % n;
            i++;
        }
        CryptoText[j] = c;
        b += 1;
    }
//mi = (ci^d)%n
    b = 301;
    int m;
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
    for (size_t j = 0; j < str.size(); j++) {
        cout << "|  " << left << setw(4);
        if (Text[j] != '\0')
            cout << Text[j];
        else cout << " ";
        cout << "|   " << left << setw(7)
             << static_cast<int>(Text[j]) << "|      " << left << setw(10) << CryptoText[j] << "|        "
             << setw(12) << left << Tdecrypt[j] << "|       " << left << setw(9);
        if (Text[j] != '\0')
            cout << static_cast<char>(Tdecrypt[j]);
        else cout << " ";
        cout << "|" << endl;
    }
    cout << "--------------------------------------------------------------------------" << endl;
    delete[] Text;
    delete[] CryptoText;
    delete[] Tdecrypt;
    str = "";
}

#endif //CURSE_PROJECT_RSA_CIPHER_H
