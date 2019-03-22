#ifndef READ_FILES_H
#define READ_FILES_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void read_rules_file();
void read_code_file();

extern char start_small_letter;
extern char end_small_letter;
extern char start_capital_letter;
extern char end_capital_letter;
extern char start_digit;
extern char end_digit;

extern vector<string> key_words;
extern vector<string> relop;
extern vector<string> addop;
extern vector<string> mulop;
extern char assignop;
extern vector<char> punctuations;
extern vector<char> letters;
extern vector<char> digits;
extern vector<string> buffer_words;

extern int id_num;
#endif
