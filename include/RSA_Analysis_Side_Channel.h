//
// Created by alexscorpy on 16.12.2020.
//

#ifndef TEMPLATE_RSA_ANALYSIS_SIDE_CHANNEL_H
#define TEMPLATE_RSA_ANALYSIS_SIDE_CHANNEL_H

#include <iostream>
#include <string>
#include "Secret_Key.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

void RSA_Cipher_Analysis_Side_Channel() {
    cout << "\nTo generate open and secret keys program will" << endl;
    cout << "select two different random prime numbers p and q." << endl;
    string str, button;
    srand((unsigned) time(NULL));
    int p = rand() % 100;
    int q = rand() % 100;
    int p_simple = random_simple(p);
    int q_simple = random_simple(q);
    int Euler = (p_simple - 1) * (q_simple - 1);
    int n = p_simple * q_simple;
// НОД [d , (p_simple-1)*(q_simple-1)] = 1
    int d, d_simple = 0;
    while (d_simple != 1) {
        d = rand() % 100;
        d_simple = NOD(d, ((p_simple - 1) * (q_simple - 1)));
    }
//с(e*d)%((p_simple-1)*(q_simple-1))=1
    int e = 0, e_simple = 0;
    while (e_simple != 1) {
        e += 1;
        e_simple = (e * d) % ((p_simple - 1) * (q_simple - 1));
    }
    cout << "p = " << p << "; q = " << q << endl;
    cout << "n = p*q = " << n << endl;
    cout << "Euler Function F(n) = (p_simple-1)*(q_simple-1) = " << Euler << endl;
    cout << "d = " << d << endl;
    cout << "Open key ===> " << "{e,n} <=> " << "{" << e << "," << n << "}"
    << endl;
    cout << "Secret key ===> " << "{d,n} <=> " << "{" << d << "," << n << "}"
    << endl;
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
    cout << "|STRING|ASCII CODE|CryptoText/Block|ASCII DECRYPTED CODE|DECRYPTE"
            "D STRING|" << endl
         << "-----------------------------------------------------------------"
            "---------" << endl;
    for (size_t j = 0; j < str.size(); j++) {
        c = 1;
        int i = 0;
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
             << static_cast<int>(Text[j]) << "|      " << left << setw(10)
             << CryptoText[j] << "|        "
             << setw(12) << left << Tdecrypt[j] << "|       " << left
             << setw(9);
        if (Text[j] != '\0')
            cout << static_cast<char>(Tdecrypt[j]);
        else cout << " ";
        cout << "|" << endl;
    }
    cout << "-----------------------------------------------------------------"
            "---------" << endl;
    cout << "Do you want to hack this cipher???" << endl;
    cout << "Write <<yes>> or <<y>> if you want to make a cryptoanalysis." << endl;
    cin >> button;
    if (button == "yes" || button == "y") {
        string Test_Key="test_key";
        Secret_Key secret_key(Test_Key);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "      ======================================" << endl;
        cout << "      | Your key was hidden in this picture|" << endl;
        cout << "      ======================================" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        secret_key.Print_RSA_Key(d,n,e);
        cout << "Your private key was stolen by hackers, because transfer chan"
                "nel has been hacked!!!" << endl;
        cout << "Open key ===> " << "{e,n} <=> " << "{" << e << "," << n << "}"
             << endl;
        cout << "Secret key ===> " << "{d,n} <=> " << "{" << d << "," << n << "}"
             << endl;
        cout << "Hacked message: " << endl;
        for (size_t j = 0; j < str.size(); j++) {
            if (Text[j] != '\0')
                cout << static_cast<char>(Tdecrypt[j]);
            else cout << " ";
        }
        cout << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "This cipher was hacked! However..." << endl;
        cout << "                     ---------------------------------------" << endl;
        cout << "     =========>      |RSA CIPHER HAS A PROVABLE RESISTANCE!|      <=========" << endl;
        cout << "                     ---------------------------------------" << endl;
    }
    delete[] Text;
    delete[] CryptoText;
    delete[] Tdecrypt;
    str = "";
}

#endif //TEMPLATE_RSA_ANALYSIS_SIDE_CHANNEL_H
