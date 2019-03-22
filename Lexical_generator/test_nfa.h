#ifndef TEST_NFA_CODE_H
#define TEST_NFA_CODE_H


#include "./include/NFA.h"
#include "./include/State_Node.h"
#include "read_files.h"
#include "check_NFA.h"
#include <bits/stdc++.h>


void test_read_rule_file();
void test_read_code_file();
void print_state_info(State_Node state);
void test_nfa_states();
#endif // TEST_NFA_CODE_H
