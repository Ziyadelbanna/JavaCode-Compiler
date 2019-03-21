#include "State_Node.h"

State_Node::State_Node(){}
State_Node::~State_Node(){}


string State_Node::get_state_type(){
        return state_type;
}

void State_Node::set_state_type(string tp){
       state_type = tp;
}

void State_Node::set_accepted(bool acc){
       is_accepted = acc;
}


bool State_Node::get_accepted(){
       return is_accepted;
}


void State_Node::add_transaction(State_Node next_state, vector<char> nxt_input){
         next_states.push_back(next_state);
         next_state_inputs.push_back(nxt_input);
}


vector<char>  State_Node::get_accepted_buffer_sofar(){
        return accepted_buffer_sofar;
}

void State_Node::set_accepted_buffer_sofar(vector<char> vec){
        accepted_buffer_sofar = vec;
}

vector<State_Node> State_Node::get_next_states(){
        return next_states;
}

vector< vector < char > > State_Node::get_next_states_values(){
        return next_state_inputs;
}
