// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "Cesar_Cipher.h"
#include "Cesar_AnaLysis.h"
#include "Gamma_Cipher.h"
#include "Gamma_Analysis.h"
#include "Vernam_Cipher.h"
#include "Vernam_Analysis.h"
#include "RSA_Cipher.h"
#include "RSA_Analysis.h"
#include "DES_Cipher.h"
#include "DES_Analysis.h"
#include "AES_Cipher.h"
#include "AES_Analysis.h"
#include "BlowFish_Cipher.h"
#include "BlowFish_Analysis.h"
#include <string>
#include <cstring>
#include <math.h>
#include <vector>

bool simple_or_not(const int &x){
  for (int i=2;i<sqrt(x);i++){
    if (x%i==0) return false;
  }
  return true;
}

TEST(GAMMA, Coding1) {
  string str, gamma, rez1, rez2;
  str="C++_IS_THE_BEST_PROGRAMM_LANGUAGE!!!";
  gamma="KEY";
  rez1="nPd+n-+y\"p%{px.+u,zl,lr'+qzyl/ll~LFZ";
  Gamma_Coding(str, gamma, rez2);
  ASSERT_EQ(rez1,rez2);
}
TEST(GAMMA, Coding2) {
  string str, gamma, rez1, rez2;
  str="ALEXANDER_IS_A_STUDENT_FROM_GROUP_ICS8-33";
  gamma="KEY_FOR_GAMMA";
  rez1="lq~8g}v%y!v!!l%-4{sw.{!s px%!2u%#?pd!eN^X";
  Gamma_Coding(str, gamma, rez2);
  ASSERT_EQ(rez1,rez2);
}
TEST(GAMMA, Coding3) {
  string str, gamma, rez1, rez2;
  str="!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_abcdefghijklmnopqrstuvwxyz{|}~ ";
  gamma="ALL_SYMBOLS_ARE_HERE";
  rez1="BNOcX_TJXV^kN`ToYWeYVbcwlsh^ljr bth$mkymjvw,!(|r!~'4v)|8\" .\"~+,A6=2(64<I,>2M75C74@AUJQF<JHP]@R";
  Gamma_Coding(str, gamma, rez2);
  ASSERT_EQ(rez1,rez2);
}
TEST(GAMMA, Decoding1) {
    string str1, str2, gamma, rez;
    str1="HELLO_WORLD!";
    gamma="COMPUTER";
    rez="kty|%4|\"u{qQ";
    Gamma_Decoding(rez, gamma, str2);
  ASSERT_EQ(str1,str2);
}
TEST(GAMMA, Decoding2) {
  string str1, str2, gamma, rez;
  str1="I'M_THE_BEST_PROGRAMMIST!";
  gamma="ARE_YOU_SURE?";
  rez="jYr?.wz?uz&y~q%t',p#-|)'F";
  Gamma_Decoding(rez, gamma, str2);
  ASSERT_EQ(str1,str2);
}
TEST(GAMMA, Decoding3) {
  string str1, str2, gamma, rez;
  str1="FINAL_TEST";
  gamma="VERY_LONG_GAMMA-KEY!!!";
  rez="|n!z,,$sz4";
  Gamma_Decoding(rez, gamma, str2);
  ASSERT_EQ(str1,str2);
}
TEST(AESCipher, Test1) {
  string text;
  string encrypted_text="\xC0vc\x87\xEF`lz\x8EP\xF6" "4\x7F\xE7\xFAq";
  string decrypted_text="I_WANT_TO_BE_A_P";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="I_WANT_TO_BE_A_PROGRAMMIST_IN_GOOGLE.";
  uint8_t key[KEY_SIZE] = "Key_is_128_bits";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  length = AES(encrypted, 'E', key, KEY_SIZE, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = AES(decrypted, 'D', key, KEY_SIZE, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(AESCipher, Test2) {
  string text;
  string encrypted_text="_R\xCA'\x87" "8\xB0\xF5\n\x12\x97\xA0" "E\x83\xD6\xE2";
  string decrypted_text="Computers_change";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="Computers_change_our_life.";
  uint8_t key[KEY_SIZE] = "Key_is_128_bits";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  length = AES(encrypted, 'E', key, KEY_SIZE, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = AES(decrypted, 'D', key, KEY_SIZE, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(AESCipher, Test3) {
  string text;
  string encrypted_text="\x9F" "f\x84\xF0" "0\xC4\xD3=\rG\v\x9F\xF2v\x1Dn";
  string decrypted_text="This_programm_ca";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="This_programm_can_huck_your_computer.";
  uint8_t key[KEY_SIZE] = "Key_is_128_bits";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  length = AES(encrypted, 'E', key, KEY_SIZE, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = AES(decrypted, 'D', key, KEY_SIZE, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(AESCipher, Test4) {
  string text;
  string encrypted_text="\xB8\xD6\xAF>\xF1\xF6\xE7.C2J\xEF\xB1\x8E" "f+";
  string decrypted_text="Programmist-is_a";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="Programmist-is_a_highly-paid_job.";
  uint8_t key[KEY_SIZE] = "Key_is_128_bits";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  length = AES(encrypted, 'E', key, KEY_SIZE, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = AES(decrypted, 'D', key, KEY_SIZE, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(DESCipher, Test1) {
  string text;
  string encrypted_text="\xE5\xAC\xD4'E\xE1\xF5N\xB7\xBD\xDA\x8A|\xB6\xAC@";
  string decrypted_text="I_WANT_TO_BE_A_P";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="I_WANT_TO_BE_A_PROGRAMMIST_IN_GOOGLE.";
  uint8_t keys8b[8] = "Key56bt";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  length = DES(encrypted, 'E', keys8b, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = DES(decrypted, 'D', keys8b, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(DESCipher, Test2) {
  string text;
  string encrypted_text="\xA2\xCF\xB5" "d\x19h\xD0<\xA7\x1Bu\xE4\x88\xBA\xEBz";
  string decrypted_text="Computers_change";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="Computers_change_our_life.";
  uint8_t keys8b[8] = "Key56bt";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  length = DES(encrypted, 'E', keys8b, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = DES(decrypted, 'D', keys8b, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(DESCipher, Test3) {
  string text;
  string encrypted_text="-\x93\xC1\x10" "d\xAA\x88 \xF0$/{\x16K\xB0~";
  string decrypted_text="This_programm_ca";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="This_programm_can_huck_your_computer.";
  uint8_t keys8b[8] = "Key56bt";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  length = DES(encrypted, 'E', keys8b, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = DES(decrypted, 'D', keys8b, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(DESCipher, Test4) {
  string text;
  string encrypted_text="\xF8\xA5 \x6\f\xA1\xD0\tU\x8B\xD8k\x88\xEE\xFF ";
  string decrypted_text="Programmist-is_a";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="Programmist-is_a_highly-paid_job.";
  uint8_t keys8b[8] = "Key56bt";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  length = DES(encrypted, 'E', keys8b, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = DES(decrypted, 'D', keys8b, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(RSACipher, Test1) {
vector<int>numbers={100,200,300,400,500,600,700,800,900,1000};
vector<int>simple_numbers={1,2,3,4,5,6,7,8,9,10};
vector<bool>simple={false,false,false,false,false,false,false,false,false,false};
for (int i=0; i<10;i++){
  simple_numbers[i]=random_simple(numbers[i]);
  simple[i]=simple_or_not(simple_numbers[i]);
  EXPECT_TRUE(simple[i]);
}
}
TEST(RSACipher, Test2) {
int a=167234, b=2234534, c=2;
EXPECT_EQ(c,NOD(a,b));
}
TEST(BlowFish, Test1) {
  string text;
  string encrypted_text="\x1Cp\xCF\x8E\xE7r\x16\xC7" "4\xE2\xAA#)\aB]";
  string decrypted_text="I_WANT_TO_BE_A_P";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="I_WANT_TO_BE_A_PROGRAMMIST_IN_GOOGLE.";
  uint8_t key64b[56] = "This_is_a_blowfish__448__bits__key__and__64__bits__text";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  BF_key_extension(__Keys32b, key64b, 448);
  length = blowfish(encrypted, 'E', __Keys32b, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = blowfish(decrypted, 'D', __Keys32b, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(BlowFish, Test2) {
  string text;
  string encrypted_text="+0\bH\xC9\n?\xBA" "f\xCB\xA3|\x12Jrg";
  string decrypted_text="Computers_change";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="Computers_change_our_life.";
  uint8_t key64b[56] = "This_is_a_blowfish__448__bits__key__and__64__bits__text";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  BF_key_extension(__Keys32b, key64b, 448);
  length = blowfish(encrypted, 'E', __Keys32b, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = blowfish(decrypted, 'D', __Keys32b, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(BlowFish, Test3) {
  string text;
  string encrypted_text="\xB1N\xE5\x90\x5\x91\xA5\\\x1D" "1\x89+z\xC4\xDBi";
  string decrypted_text="This_programm_ca";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="This_programm_can_huck_your_computer.";
  uint8_t key64b[56] = "This_is_a_blowfish__448__bits__key__and__64__bits__text";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  BF_key_extension(__Keys32b, key64b, 448);
  length = blowfish(encrypted, 'E', __Keys32b, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = blowfish(decrypted, 'D', __Keys32b, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}
TEST(BlowFish, Test4) {
  string text;
  string encrypted_text=",9\xE9\xB7k\x2\xAB\x17\x96" "3\x4\x9D~@\x87\xF7";
  string decrypted_text="Programmist-is_a";
  uint8_t encrypted[BUFF_SIZE] = {0};
  uint8_t decrypted[BUFF_SIZE] = {0};
  uint8_t buffer[BUFF_SIZE]="Programmist-is_a_highly-paid_job.";
  uint8_t key64b[56] = "This_is_a_blowfish__448__bits__key__and__64__bits__text";
  size_t length=KEY_SIZE;
  size_t length1=16;
  size_t length2=16;
  BF_key_extension(__Keys32b, key64b, 448);
  length = blowfish(encrypted, 'E', __Keys32b, buffer, length);
  for (size_t i=0;i<length;i++)
    text.push_back(encrypted[i]);
  ASSERT_EQ(length,length1);
  ASSERT_EQ(text,encrypted_text);
  text="";
  length = blowfish(decrypted, 'D', __Keys32b, encrypted, length);
  for (size_t i=0;i<length;i++)
    text.push_back(decrypted[i]);
  ASSERT_EQ(length,length2);
  ASSERT_EQ(text,decrypted_text);
}