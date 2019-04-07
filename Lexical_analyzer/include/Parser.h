#ifndef PARSER_H
#define PARSER_H

#include <bits/stdc++.h>
using namespace std;

class Parser
{
    public:
        Parser();
        virtual ~Parser();
        void read_rules_file();
        void parse_line(string);
        void split_line(string, vector<string> &);
        void print_vectors();
        string trim(string);
        vector< pair < string, string> > definitions;
        vector< pair < string, string> > expressions;
        vector<string> keywords;
        vector<string> relop;
        vector<string> addop;
        vector<string> mulop;
        vector<char> punctuations;
        char assignop;
    protected:

    private:
};

#endif // PARSER_H
