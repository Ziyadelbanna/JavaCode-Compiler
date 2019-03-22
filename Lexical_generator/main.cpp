#include <bits/stdc++.h>
#include "read_files.h"
#include "check_NFA.h"
#include "test_nfa.h"
using namespace std;


int main()
{
    //test_read_rule_file();
    //test_read_code_file();
    read_rules_file();
    read_code_file();
    test_nfa_states();
    return 0;
}
