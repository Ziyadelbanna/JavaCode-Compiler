#include "read_files.h"
#include <bits/stdc++.h>

void read_rules_file();
void read_code_file();

char start_small_letter;
char end_small_letter;
char start_capital_letter;
char end_capital_letter;
char start_digit;
char end_digit;

vector<string> key_words;
vector<string> relop;
vector<string> addop;
vector<string> mulop;
char assignop;
vector<char> punctuations;
vector<char> letters;
vector<char> digits;
vector<string> buffer_words;

int id_num = 0;

void read_rules_file(){
    ifstream rules_file;

    rules_file.open("/home/mohamedabobakr/Documents/codeblocksProjects/Lexical_generator/rules.txt");

    if (!rules_file) {
        cout << "Unable to open rules file";
        exit(1); // terminate with error
    }

    string rule_line;

    while(getline(rules_file , rule_line)){
        if(rule_line[0] == 'l'){
            start_small_letter = rule_line[9];
            end_small_letter = rule_line[11];
            start_capital_letter = rule_line[15];
            end_capital_letter = rule_line[17];

            for(char i = start_small_letter; i<=end_small_letter; i++){
              letters.push_back(i);
            }

            for(char i = start_capital_letter; i<=end_capital_letter; i++){
              letters.push_back(i);
            }

        }else if(rule_line[0]=='d' && rule_line[5]==' '){
            start_digit = rule_line[8];
            end_digit = rule_line[12];
            for(char i = start_digit; i<=end_digit; i++){
              digits.push_back(i);
            }

        }else if(rule_line[0] == '{'){
            if(rule_line[1] == ' '){
                rule_line = rule_line.substr(2, rule_line.size() - 4);
            }else{
                rule_line = rule_line.substr(1, rule_line.size() - 2);
            }
            rule_line += " ";
            size_t pos = 0;
            string key_word;
            while((pos = rule_line.find(" ")) != string::npos){
                key_word = rule_line.substr(0 , pos);
                rule_line.erase(0 , pos + 1);
                key_words.push_back(key_word);
            }
        }else if(rule_line[0] == 'r'){
            rule_line = rule_line.substr(7, rule_line.size()-1);
                size_t pos = 0;
                string operation;
                vector<char> temp;
                rule_line+= "|";
                while((pos = rule_line.find("|")) != string::npos){
                    operation = rule_line.substr(0 , pos);
                    rule_line.erase(0 , pos + 1);
                    for(int i = 0 ; i < operation.size() ; i++){
                        if(operation[i] != '\\' && operation[i] != ' '){
                            temp.push_back(operation[i]);
                        }
                    }
                    std::string str(temp.begin(),temp.end());
                    relop.push_back(str);
                    temp.clear();
                }
        }else if(rule_line[0] == 'm'){
            rule_line = rule_line.substr(7, rule_line.size()-1);
                size_t pos = 0;
                string operation;
                vector<char> temp;
                rule_line+= "|";
                while((pos = rule_line.find("|")) != string::npos){
                    operation = rule_line.substr(0 , pos);
                    rule_line.erase(0 , pos + 1);
                    for(int i = 0 ; i < operation.size() ; i++){
                        if(operation[i] != '\\' && operation[i] != ' '){
                            temp.push_back(operation[i]);
                        }
                    }
                    std::string str(temp.begin(),temp.end());
                    mulop.push_back(str);
                    temp.clear();
                }
        }else if(rule_line[0] == 'a' && rule_line[1] == 's'){
            assignop = rule_line[8];
        }else if(rule_line[0] == 'a' && rule_line[1] != 's'){
            rule_line = rule_line.substr(7, rule_line.size()-1);
                size_t pos = 0;
                string operation;
                vector<char> temp;
                rule_line+= "|";
                while((pos = rule_line.find("|")) != string::npos){
                    operation = rule_line.substr(0 , pos);
                    rule_line.erase(0 , pos + 1);
                    for(int i = 0 ; i < operation.size() ; i++){
                        if(operation[i] != '\\' && operation[i] != ' '){
                            temp.push_back(operation[i]);
                        }
                    }
                    std::string str(temp.begin(),temp.end());
                    addop.push_back(str);
                    temp.clear();
                }
        }else if(rule_line[0] == '['){
            int i = 1;
            while(rule_line[i] != ']'){
                if(rule_line[i] != '\\' && rule_line[i] != ' '){
                    punctuations.push_back(rule_line[i]);
                }
                i++;
            }
        }
    }

    rules_file.close();
}

void read_code_file(){
    ifstream code_file;

    code_file.open("/home/mohamedabobakr/Documents/codeblocksProjects/Lexical_generator/code.txt");

    if (!code_file) {
        cout << "Unable to open code file";
        exit(1); // terminate with error
    }

    string output;

    if (code_file.is_open()) {
        while (code_file >> output) {
            buffer_words.push_back(output);
        }
    }

    code_file.close();
}
