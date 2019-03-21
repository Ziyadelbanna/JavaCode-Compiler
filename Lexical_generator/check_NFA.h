#ifndef CHECK_NFA_H
#define CHECK_NFA_H

#include <bits/stdc++.h>
#include "read_files.h"
#include "State_Node.h"

extern vector<State_Node> nfa_current_states;
extern bool reach_accepted_state;
extern vector<State_Node> nfa_next_states;
extern State_Node last_accepted_state;

int check_size();

#endif
