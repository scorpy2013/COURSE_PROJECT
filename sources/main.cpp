// Copyright [2020] <Copyright scorpy2013>

#include "Cesar_Cipher.h"
#include "Cesar_Analysis.h"
#include "Cesar_Analysis_Frequency.h"
#include "Gamma_Cipher.h"
#include "Gamma_Analysis.h"
#include "Gamma_Analysis_Side_Channel.h"
#include "Vernam_Cipher.h"
#include "Vernam_Analysis.h"
#include "Vernam_Analysis_Side_Channel.h"
#include "RSA_Cipher.h"
#include "RSA_Analysis.h"
#include "RSA_Analysis_Side_Channel.h"
#include "DES_Cipher.h"
#include "DES_Analysis.h"
#include "DES_Analysis_Side_Channel.h"
#include "AES_Cipher.h"
#include "AES_Analysis.h"
#include "AES_Analysis_Side_Channel.h"
#include "BlowFish_Cipher.h"
#include "BlowFish_Analysis.h"
#include "BlowFish_Analysis_Side_Channel.h"

int main() {
    int button = 0;
    cout << "+-------------------------------------------------------------"
            "-----------------------------+" << endl;
    cout << "|                         WELCOME TO MY SMALL WORLD OF CRYP"
            "TOGRAPHY                        |" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
            "||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
            "||||||||||||||||||||||||||||" << endl;
    cout << "|                                  CRYPTOANALYSIS SYSTEM    "
            "                               |" << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
            "|||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
            "||||||||||||||||||||||||||||" << endl;
    while (button != 15) {
        cout << endl << "|---------------------------------------------------"
                        "---------------------------------------|"
             << endl;
        cout << "|                                     CONSOLE MENU          "
                "                               |" << endl;
        cout << "|-----------------------------------------------------------"
                "-------------------------------|" << endl;
        cout << "|----->                        (1)Cesar cipher;             "
                "                         <-----|" << endl;
        cout << "|----->                        (2)Cryptoanalysis of Cesar cip"
                "her;                    <-----|" << endl;
        cout << "|----->                        (3)Gamming cipher;            "
                "                        <-----|" << endl;
        cout << "|----->                        (4)Cryptoanalysis of Gamming c"
                "ipher;                  <-----|" << endl;
        cout << "|----->                        (5)Vernam cipher;             "
                "                        <-----|" << endl;
        cout << "|----->                        (6)Cryptoanalysis of Vernam ci"
                "pher;                   <-----|" << endl;
        cout << "|----->                        (7)AES cipher;                "
                "                        <-----|" << endl;
        cout << "|----->                        (8)Cryptoanalysis of AES ciphe"
                "r;                      <-----|" << endl;
        cout << "|----->                        (9)DES cipher;                "
                "                        <-----|" << endl;
        cout << "|----->                        (10)Cryptoanalysis of DES ciph"
                "er;                     <-----|" << endl;
        cout << "|----->                        (11)RSA cipher;               "
                "                        <-----|" << endl;
        cout << "|----->                        (12)Cryptoanalysis of RSA ciph"
                "er;                     <-----|" << endl;
        cout << "|----->                        (13)BlowFish cipher;          "
                "                        <-----|" << endl;
        cout << "|----->                        (14)Cryptoanalysis of BlowFish"
                " cipher;                <-----|" << endl;
        cout << "|----->                        (15)Quit.                     "
                "                        <-----|" << endl;
        cout << "|------------------------------------------------------------"
                "------------------------------|" << endl;
        cout << "                                   ENTER A COMMAND--->";
        cin >> button;
        cout << "============================================================="
                "==============================" << endl;
        switch (button) {
            case 1:
                cout << "                                      CESAR CIPHER" <<
                endl;
                try {
                    Cesar_Cipher();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 2:
                cout << "                             CRYPTOANALYSIS OF CESAR "
                        "CIPHER" << endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "              THE METHOD OF COMPLETE ENUMERATION + FR"
                        "EQUENCY ANALYSIS" << endl;
                cout << "-----------------------------------------------------"
                        "--------------------------------------"
                     << endl;
                try {
                    Cesar_Analysis();
                    Cesar_Analysis_Frequency();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 3:
                cout << "                                     GAMMING CIPHER"
                << endl;
                try {
                    Gamma_Cipher();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 4:
                cout << "                            CRYPTOANALYSIS OF GAMMING"
                        "CIPHER" << endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                            KEY ATTACK + SIDE-CHANNEL"
                        " ATTACK" << endl;
                cout << "-----------------------------------------------------"
                        "--------------------------------------"
                     << endl;
                try {
                    Gamma_Analysis();
                    Gamma_Analysis_Side_channel();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 5:
                cout << "                                     VERNAM CIPHER"
                << endl;
                try {
                    Vernam_Cipher();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 6:
                cout << "                            CRYPTOANALYSIS OF VERNAM "
                        "CIPHER" << endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                            KEY ATTACK + SIDE-CHANNEL"
                        " ATTACK" << endl;
                cout << "-----------------------------------------------------"
                        "--------------------------------------"
                     << endl;
                try {
                    Vernam_Analysis();
                    Vernam_Analysis_Side_channel();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 7:
                cout << "                                      AES CIPHER" <<
                endl;
                try {
                    AES_Cipher();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 8:
                cout << "                            CRYPTOANALYSIS OF AES CIP"
                        "HER" << endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                            KEY ATTACK + SIDE-CHANNEL"
                        " ATTACK" << endl;
                cout << "-----------------------------------------------------"
                        "--------------------------------------"
                     << endl;
                try {
                    AES_Analysis();
                    AES_Analysis_Side_Channel();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 9:
                cout << "                                      DES CIPHER" <<
                endl;
                try {
                    DES_Cipher();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 10:
                cout << "                            CRYPTOANALYSIS OF DES CIP"
                        "HER" << endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                            KEY ATTACK + SIDE-CHANNEL"
                        " ATTACK" << endl;
                cout << "-----------------------------------------------------"
                        "--------------------------------------"
                     << endl;
                try {
                    DES_Analysis();
                    DES_Analysis_Side_Channel();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 11:
                cout << "                                 RSA CIPHER" <<
                endl;
                try {
                    RSA_Cipher();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 12:
                cout << "                              CRYPTOANALYSIS OF RSA C"
                        "IPHER" << endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                            KEY ATTACK + SIDE-CHANNEL"
                        " ATTACK" << endl;
                cout << "-----------------------------------------------------"
                        "--------------------------------------"
                     << endl;
                try {
                    RSA_Analysis();
                    RSA_Cipher_Analysis_Side_Channel();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 13:
                cout << "                                   BLOWFISH CIPHER" <<
                endl;
                try {
                    BlowFish_Cipher();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 14:
                cout << "                        CRYPTOANALYSIS OF BLOWFISH CI"
                        "PHER" << endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                                           ||" <<
                endl;
                cout << "                            KEY ATTACK + SIDE-CHANNEL"
                        " ATTACK" << endl;
                cout << "-----------------------------------------------------"
                        "--------------------------------------"
                     << endl;
                try {
                    BlowFish_Analysis();
                    BlowFish_Analysis_Side_Channel();
                }
                catch (const char *str) {
                    cout << str << endl;
                }
                break;
            case 15:
                break;
            default:
                cout << endl << "WRONG COMMAND! PLEASE, TRY AGAIN!" << endl <<
                endl;
        }
    }
    return 0;
}
