//
// Created by alexscorpy on 18.12.2020.
//

#ifndef TEMPLATE_LONG_SECRET_KEY_H
#define TEMPLATE_LONG_SECRET_KEY_H

#include <iostream>
#include <vector>
using namespace std;

class Long_Secret_Key {
private:
    vector<int> secret_key;
    string key;
public:
    Long_Secret_Key(string KEY) : key(KEY) {
        for (size_t i = 0; i < key.size(); i++)
            secret_key.push_back(int(key[i]));
    }
    void Print_Long_Key() {
        for (size_t i = 0; i < secret_key.size(); i++)
            cout << secret_key[i];
        cout << endl;
    }
};

#endif //TEMPLATE_LONG_SECRET_KEY_H
