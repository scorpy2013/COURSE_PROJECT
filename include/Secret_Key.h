//
// Created by alexscorpy on 17.12.2020.
//

#ifndef TEMPLATE_SECRET_KEY_H
#define TEMPLATE_SECRET_KEY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Secret_Key {
private:
    vector<string> secret_key;
    string key;
public:
    Secret_Key(string KEY) {
        key=KEY;
        secret_key.push_back("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
        secret_key.push_back("▓▓)(*&&^&&&%^%$#!~$890898~*798++$%___*(6&^&*^=+"":▓▓");
        secret_key.push_back("▓▓(&*&^%$#$%^&*<>?>*&7867^<"":#&*&%#*&^%##$%%^^&^^▓▓");
        secret_key.push_back("▓▓&*^%$#$$%&(&*^%$%^&""?><:{}*&766#@786|}|}|}|}|}}▓▓");
        secret_key.push_back("▓▓5465363%&^*78&^&77*)(877&*&#*#@887878&&778"":>{]▓▓");
        secret_key.push_back("▓▓(*&^%$#6776&676(&6676788^&9^8&*7&&'':.,]{{[{{{▓▓");
        secret_key.push_back("▓▓(*&^578768769"";:{}>##$#@@#<))%^(8^%^7&^&^87^(^&▓▓");
        secret_key.push_back("▓▓*&*^86786768^*&^678#676*&^&^87676767&6876&*766▓▓");
        secret_key.push_back("▓▓&^*&^%786778^*&896#7876876&&7687*&87898^&^7676▓▓");
        secret_key.push_back("▓▓^&*^68767867^&^&8#578676&^&*^*(67867867^&67666▓▓");
        secret_key.push_back("▓▓*&%^&%657$%&*%*58678576$87568578%*%857868%8#75▓▓");
        secret_key.push_back("▓▓*(^&*85765&*^*^*78^&^^76*&&*^8%&*^&*%78^*&^#&^▓▓");
        secret_key.push_back("▓▓(*&^%$&*66786&*%&*%765&^%*664&^%&^&^%&^%&^^%^%▓▓");
        secret_key.push_back("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓");
        secret_key.push_back("_______▒__________▒▒▒▒▒▒▒▒▒▒▒▒▒▒                  ");
        secret_key.push_back("______▒_______________▒▒▒▒▒▒▒▒                    ");
        secret_key.push_back("_____▒________________▒▒▒▒▒▒▒▒                    ");
        secret_key.push_back("____▒___________▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓               ");
        secret_key.push_back("___▒                                              ");
        secret_key.push_back("__▒______▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓      ");
        secret_key.push_back("_▒______▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓       ");
        secret_key.push_back("▒▒▒▒___▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓        ");
        secret_key.push_back("▒▒▒▒__▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓▒▓         ");
        secret_key.push_back("▒▒▒__▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓          ");
        secret_key.push_back("▒▒                                                ");
    }
    void Print_RSA_Key(const int d, const int n, const int e){
        for (int i = 0; i < 25; i++) {
            if (i==7){
                cout << "▓▓8&9*9&^}{.?732!@34%041" << setw(6) << left << d <<
                setw(6) << left <<  n << setw(6) << left << e <<
                setw (6)<< left <<  n << setw(6) << left << "▓▓";
            }else{
                for (const auto &it:secret_key[i])
                    cout << it;
            }
            cout << endl;
        }
    }
    void Print_Key8b(){
        for (int i = 0; i < 25; i++) {
            if (i==5){
                cout<<"▓▓*(&(*^$@$76$@$#!8%><?:" << key << "^&^3%^(*7^54#2%&5▓▓";
            } else {
                for (const auto &it:secret_key[i])
                    cout << it;
            }
            cout << endl;
        }
    }
    void Print_Key16b(){
        for (int i = 0; i < 25; i++) {
            if (i==5){
                cout<<"▓▓*(&&(*^$@$$%><?><:" << key << "*^&%^3%^%%5&5▓▓";
            } else {
                for (const auto &it:secret_key[i])
                    cout << it;
            }
            cout << endl;
        }
    }
    void Print_Key56b(){
        for (int i = 0; i < 25; i++) {
            if (i==5){
                cout<<"▓▓*(&(*№;%8?^@$";
                for (int j=0; j<28; j++)
                    cout << key[j];
                cout<<"&**&*▓▓";
            } else if (i==6){
                cout<<"▓▓<}*6*(*977%^%^";
                for (int j=28; j<56 ; j++)
                    cout << key[j];
                cout<<"7*9>@▓▓";
            }else{
                for (const auto &it:secret_key[i])
                    cout << it;
            }
            cout << endl;
        }
    }
};

#endif //TEMPLATE_SECRET_KEY_H
