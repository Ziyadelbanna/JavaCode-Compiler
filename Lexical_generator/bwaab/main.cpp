#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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

int main()
{
    // Read Rules file
    read_rules_file();

    // Read codes file
    //read_code_file();

    return 0;
}

void read_rules_file(){
    ifstream rules_file;

    rules_file.open("/home/ahmed/Desktop/Compiler/Lexical Analyzer Generator/rules");

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
        }else if(rule_line[0] == 'd'){
            start_digit = rule_line[8];
            end_digit = rule_line[12];
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

    code_file.open("/home/ahmed/Desktop/Compiler/Lexical Analyzer Generator/code");

    if (!code_file) {
        cout << "Unable to open code file";
        exit(1); // terminate with error
    }

    char output;

    if (code_file.is_open()) {
        while (!code_file.eof()) {

            output = code_file.get();
            cout<<output << endl;

        }
    }

    code_file.close();
}
