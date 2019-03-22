#ifndef CHECK_NFA_H
#define CHECK_NFA_H

#include <bits/stdc++.h>
#include "read_files.h"
#include "State_Node.h"

extern vector<State_Node*> nfa_current_states;
extern vector<State_Node*> nfa_next_states;
extern bool reach_accepted_state;
extern State_Node* last_accepted_state;


void initialize_current_states(vector<State_Node*> start_states);
void update_current_next_states();
void check_state(State_Node* curr_state, char buffer_char);
void check_current_states(char buffer_char);
void update_last_accepted(int index);
void check_priority(State_Node* curr_state);
void set_error();
void update_result();
void check_word(string word);
void check_buffer_words();
string to_string(vector<char> vec);


#endif
