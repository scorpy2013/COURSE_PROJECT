//
// Created by alexscorpy on 25.11.2020.
//

#ifndef CURSE_CODE_DES_ANALYSIS_H
#define CURSE_CODE_DES_ANALYSIS_H
char const *pCharset2 = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void DES_random_key(uint8_t key[8]) {
    cout << "[ ";
    for (int i = 0; i < 8; i++) {
        key[i] = pCharset2[rand() % 100 - 6];
        cout << key[i] << " ";
    }
    cout << "]" << endl;
}

void DES_Analysis() {
    int I = 0;
    string button;
    double start_time, end_time, search_time; // считаем время взлома
    string str, STR;
    uint8_t encrypted[BUFF_SIZE], decrypted[BUFF_SIZE];
    uint8_t buffer[BUFF_SIZE] = {0};
    uint8_t keys8b[8] = "Key56bt";
    cout << "You can use these symbols:" << endl;
    for (int i = 33; i <= 126; i++) {
        cout << char(i) << " ";
    }
    cout << endl;
    cout << "Please enter a string:" << endl;
    cin >> str;
    size_t length = str.size();
    for (size_t i = 0; i < length; i++) {
        buffer[i] = str[i];
        if (buffer[i] < 33 || buffer[i] > 126)
            throw "Code of your symbols must be in this range -> [33,126] !!!";
    }
    print_array(buffer, length);
    cout << "Your generated key ===> [" << keys8b <<"]" << endl;
    cout << "Encrypted string: " << endl;
    length = DES(encrypted, 'E', keys8b, buffer, length);
    print_array(encrypted, length);

    cout << "Decrypted string: " << endl;
    length = DES(decrypted, 'D', keys8b, encrypted, length);
    cout << "[ ";
    for (size_t i = 0; i < str.size(); i++)
        cout << int(decrypted[i]) << " ";
    for (size_t i = 0; i < length - str.size(); i++)
        cout << "0" << " ";
    cout << "]" << endl;
    cout << "[ ";
    for (size_t i = 0; i < str.size(); i++)
        cout << char(decrypted[i]) << " ";
    cout << "]" << endl;
    cout << endl;

    cout << "Do you want to hack this cipher???" << endl;
    cout << "Write <<yes>> or <<y>> if you want to make a cryptoanalysis." << endl;
    cin >> button;
    if (button == "yes" || button == "y") {
        start_time = clock(); // начальное время
        while (str != STR && I < 99999) {
            cout << I + 1 << ") ITERATION:" << endl;
            DES_random_key(keys8b);
            cout << "Decrypted string: " << endl;
            length = DES(decrypted, 'D', keys8b, encrypted, length);
            cout << "[ ";
            for (size_t i = 0; i < str.size(); i++) {
                STR.push_back(decrypted[i]);
                cout << int(decrypted[i]) << " ";
            }
            for (size_t i = 0; i < length - str.size(); i++)
                cout << "0" << " ";
            cout << "]" << endl;
            cout << endl;
            STR.clear();
            I++;
        }
        end_time = clock(); // конечное время
        search_time = end_time - start_time; // искомое время
        cout << "Time for hacking: " << search_time << " milliseconds (" << search_time / 1000 << " seconds)" << endl;
        cout << "This cipher can't be hacked!" << endl;
        cout << "                     ---------------------------------------" << endl;
        cout << "     =========>      |DES CIPHER HAS A PROVABLE RESISTANCE!|      <=========" << endl;
        cout << "                     ---------------------------------------" << endl;
    }
}

#endif //CURSE_CODE_DES_ANALYSIS_H
