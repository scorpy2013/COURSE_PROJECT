//
// Created by alexscorpy on 16.12.2020.
//

#ifndef TEMPLATE_CESAR_ANALYSIS_FREQUENCY_H
#define TEMPLATE_CESAR_ANALYSIS_FREQUENCY_H

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

struct Frequency {
    char symbol;
    double kol;
    double frequency;
};

bool operator<(Frequency left, Frequency right) {
    return left.frequency > right.frequency;
}

void Cesar_Analysis_Frequency() {
    vector<Frequency> frequency;
    vector<Frequency> frequency_of_english_symbols;
    int number;
    string button;
    char str[100];
    //===========================================================================
    // подготовка таблицы частотных характеристик символов в английском алфавите
    //===========================================================================
    frequency_of_english_symbols.push_back({'A', 0, 8.17});
    frequency_of_english_symbols.push_back({'B', 0, 1.49});
    frequency_of_english_symbols.push_back({'C', 0, 2.78});
    frequency_of_english_symbols.push_back({'D', 0, 4.25});
    frequency_of_english_symbols.push_back({'E', 0, 12.70});
    frequency_of_english_symbols.push_back({'F', 0, 2.29});
    frequency_of_english_symbols.push_back({'G', 0, 2.02});
    frequency_of_english_symbols.push_back({'H', 0, 6.09});
    frequency_of_english_symbols.push_back({'I', 0, 6.97});
    frequency_of_english_symbols.push_back({'G', 0, 0.15});
    frequency_of_english_symbols.push_back({'K', 0, 0.77});
    frequency_of_english_symbols.push_back({'L', 0, 4.03});
    frequency_of_english_symbols.push_back({'M', 0, 2.41});
    frequency_of_english_symbols.push_back({'N', 0, 6.75});
    frequency_of_english_symbols.push_back({'O', 0, 7.51});
    frequency_of_english_symbols.push_back({'P', 0, 1.93});
    frequency_of_english_symbols.push_back({'Q', 0, 0.10});
    frequency_of_english_symbols.push_back({'R', 0, 5.99});
    frequency_of_english_symbols.push_back({'S', 0, 6.33});
    frequency_of_english_symbols.push_back({'T', 0, 9.06});
    frequency_of_english_symbols.push_back({'U', 0, 2.76});
    frequency_of_english_symbols.push_back({'V', 0, 0.98});
    frequency_of_english_symbols.push_back({'W', 0, 2.36});
    frequency_of_english_symbols.push_back({'X', 0, 0.15});
    frequency_of_english_symbols.push_back({'Y', 0, 1.97});
    frequency_of_english_symbols.push_back({'Z', 0, 0.07});
    //===========================================================================
    cout << "You can use these symbols:" << endl;
    for (int i = 65; i <= 90; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    for (int i = 65; i <= 126; i++)
        frequency.push_back({char(i), 0, 0});
    cout << "Please enter your string of length [1,100] without whitespaces: ";
    cin >> str;
    if (strlen(str) > 100)
        throw "Your string has too big length!!!";
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] < 65 || str[i] > 90)
            throw "Code of your symbols must be in this range -> [65,90] !!!";
    }
    cout << "Please enter the number of range [1,36] by which we will shift th"
            "e letters: ";
    cin >> number;
    if (number < 1 || number > 36)
        throw "Your number must be in this range -> [1, 36] !!!";
    for (int i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + number;
    cout << "Encrypted string: " << str << endl;
    for (size_t i = 0; i < strlen(str); i++) {
        for (size_t j = 0; j < 62; j++) {
            if (frequency[j].symbol == str[i]) {
                frequency[j].kol++;
                frequency[j].frequency = frequency[j].kol / strlen(str) * 100;
            }
        }
    }
    // сортируем наши частотные характеристики
    sort(frequency.begin(), frequency.end());
    sort(frequency_of_english_symbols.begin(),
         frequency_of_english_symbols.end());
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "================================================================="
            "=========" << endl;
    cout << "|Frequency of symbols in your string||    Frequency of english sy"
            "mbols   |" << endl;
    cout << "================================================================="
            "=========" << endl;
    cout << "|     SYMBOL     |  FREQUENCY(%)    || ENGLISH SYMBOL |    FREQU"
            "ENCY(%)  |" << endl;
    for (int i = 0; i < 62; i++) {
        cout << "|       " << left << setw(9) << frequency[i].symbol <<
             "|       " << left << setw(11) << frequency[i].frequency;
        if (i > 25) {
            cout << "||                |                  |" << endl;
        } else {
            cout << "||   "
                    "     " << left
                 << setw(8) << frequency_of_english_symbols[i].symbol <<
                 "|       " << left << setw(11) <<
                 frequency_of_english_symbols[i].frequency << "|" << endl;
        }

    }
    cout << "================================================================="
            "=========" << endl << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "If you want to continue, press <<yes>> or <<y>>." << endl;
    cin >> button;
    if (button == "yes" || button == "y") {
        cout << "===========================================" << endl;
        cout << "|SYMBOLS OF THE BIGGEST VALUE OF FREQUENCY|" << endl;
        cout << "===========================================" << endl;
        cout << "|         " << frequency[0].symbol << "          |          "
             << frequency_of_english_symbols[0].symbol << "         |" << endl;
        cout << "===========================================" << endl;
        cout << "KEY is " << int(frequency[0].symbol) -
        int(frequency_of_english_symbols[0].symbol) << endl;
        for (int i = 0; (i < 100 && str[i] != '\0'); i++)
            str[i] = str[i] - number;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if ((int(frequency[0].symbol) -
            int(frequency_of_english_symbols[0].symbol)) == number) {
            cout << "HACKED MESSAGE: " << str << endl;
            cout << "                     ---------------------------" << endl;
            cout << "     =========>      |CESAR CIPHER IS UNSTABLE!|      <=="
                    "=======" << endl;
            cout << "                     ---------------------------"
            << endl;
        }else {
            cout << "Input symbols are wrong, because this cipher can be"
                    " hacked in any case!" << endl;
            cout << "Your string is too short, because of this a table of freq"
                    "uency is not correct..." << endl;
            cout << "Please, try again..." << endl;
        }

    }
}

#endif //TEMPLATE_CESAR_ANALYSIS_FREQUENCY_H
