#ifndef STATE_NODE_H
#define STATE_NODE_H

#include <bits/stdc++.h>
#include "../read_files.h"
using namespace std;

class State_Node
{
    public:
        State_Node();
        virtual ~State_Node();
        string get_state_type();
        void set_state_type(string tp);
        void set_accepted(bool acc);
        bool get_accepted();
        void add_transaction(State_Node next_state, vector<char> nxt_input);
        vector<char> get_accepted_buffer_sofar();
        void set_accepted_buffer_sofar(vector<char> vec);
        vector<State_Node> get_next_states();
        vector< vector < char > > get_next_states_values();

    protected:

    private:
        vector<State_Node> next_states;
        vector< vector < char > > next_state_inputs;
        vector<char> accepted_buffer_sofar;
        bool is_accepted = false;
        string state_type = "null";
};

#endif // STATE_NODE_H
