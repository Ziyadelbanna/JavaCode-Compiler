#include "Parser.h"
#include "../errors.h"

Parser::Parser(){
   assignop = '0';
}
Parser::~Parser(){}

void Parser::read_rules_file(){

    string path = "/home/mohamedabobakr/Documents/codeblocksProjects/Lexical_analyzer/rules.txt";
    ifstream rules_file;
    rules_file.open(path);

    if (!rules_file) {
        read_files_error("rules.txt");
    }

    string rule_line;

    while(getline(rules_file , rule_line)){
        parse_line(rule_line);
    }

    rules_file.close();
}


void Parser::parse_line(string line){
     line = trim(line);
     if(line.size()==0) return;

     // read keywords
     if(line[0]=='{'){
        line = line.substr(1, line.size() - 2);
        line = trim(line);
        line += " ";
        size_t pos = 0;
        string key_word;
        while((pos = line.find(" ")) != string::npos){
                key_word = line.substr(0 , pos);
                line.erase(0 , pos + 1);
                keywords.push_back(key_word);
        }
     }
     // read punctuations
     else if(line[0] == '['){
            int i = 1;
            while(line[i] != ']'){
                if(line[i] != '\\' && line[i] != ' '){
                    punctuations.push_back(line[i]);
                }
                i++;
            }
     }

     // read relops
     else if(line.find("relop") != string::npos){
            split_line(line, relop);
     }
     // read addop
     else if(line.find("addop") != string::npos){
            split_line(line, addop);
     }
     // read mulop
     else if(line.find("mulop") != string::npos){
            split_line(line, mulop);
     }
     // read assign
     else if(line.find("assign") != string::npos){
            assignop = '=';
     }
     // read definition
     else if(line.find("=") != string::npos){
          size_t pos = line.find("=");
          string def_name = line.substr(0,pos);
          string def_value = line.substr(pos+1, line.size());
          def_name = trim(def_name);
          def_value = trim(def_value);
          definitions.push_back({def_name, def_value});
     }
     // read expression
     else if(line.find(":") != string::npos){
          size_t pos = line.find(":");
          string exp_name = line.substr(0,pos);
          string exp_value = line.substr(pos+1, line.size());
          exp_name = trim(exp_name);
          exp_value = trim(exp_value);
          expressions.push_back({exp_name, exp_value});
     }
     // error
     else{
         parse_file_error();
     }
}


void Parser::print_vectors(){
    cout << "Keywords:  ";
    for(int i=0; i<keywords.size(); i++){
       cout << keywords[i] << "   ";
    }
    cout << endl;
    cout << "relop:  ";
    for(int i=0; i<relop.size(); i++){
       cout << relop[i] << "   ";
    }
    cout << endl;
    cout << "addop:  ";
    for(int i=0; i<addop.size(); i++){
       cout << addop[i] << "   ";
    }
    cout << endl;
    cout << "mulop:  ";
    for(int i=0; i<mulop.size(); i++){
       cout << mulop[i] << "   ";
    }
    cout << endl;
    cout << "punctuation:  ";
    for(int i=0; i<punctuations.size(); i++){
       cout << punctuations[i] << "   ";
    }
    cout << endl;

    cout << "definitions:\n";
    for(int i=0; i<definitions.size(); i++){
       cout << definitions[i].first << "  =  " << definitions[i].second << endl;
    }
    cout << endl;

    cout << "expressions:\n";
    for(int i=0; i<expressions.size(); i++){
       cout << expressions[i].first << "  =  " << expressions[i].second << endl;
    }
    cout << endl;
}

void Parser::split_line(string line, vector<string> &vec){
        line = trim(line);
        size_t pos1 = line.find(":");
        line.erase(0, pos1+1);
        size_t pos = 0;
        string operation;
        vector<char> temp;
        line += "|";
        while((pos = line.find("|")) != string::npos){
            operation = line.substr(0 , pos);
            line.erase(0 , pos + 1);
            for(int i = 0 ; i < operation.size() ; i++){
                if(operation[i] != '\\' && operation[i] != ' '){
                    temp.push_back(operation[i]);
                }
            }
            std::string str(temp.begin(),temp.end());
            vec.push_back(str);
            temp.clear();
        }
}

string Parser::trim(string str){
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}
