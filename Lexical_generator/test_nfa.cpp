#include "test_nfa.h"

void test_read_rule_file(){
    read_rules_file();

    for(int i=0; i<key_words.size(); i++){
       cout << key_words[i] << "  ";
    }
    printf("\n");

    for(int i=0; i<relop.size(); i++){
       cout << relop[i] << "  ";
    }
    printf("\n");


    for(int i=0; i<addop.size(); i++){
       cout << addop[i] << "  ";
    }
    printf("\n");


    for(int i=0; i<mulop.size(); i++){
       cout << mulop[i] << "  ";
    }
    printf("\n");


    for(int i=0; i<punctuations.size(); i++){
       printf("%c ", punctuations[i]);
    }
    printf("\n");

    for(int i=0; i<letters.size(); i++){
       printf("%c ", letters[i]);
    }
    printf("\n");

    for(int i=0; i<digits.size(); i++){
       printf("%c ", digits[i]);
    }
    printf("\n");

    printf("%c\n",assignop);
}


void test_read_code_file(){
     read_code_file();
     for(int i=0; i<buffer_words.size(); i++){
        cout << buffer_words[i] << endl;
     }
     printf("\n");
}


void print_state_info(State_Node* state){
   vector<State_Node*> nxt_states = state->get_next_states();
   vector< vector<char> > nxt_states_chars = state->get_next_states_values();
   printf("State Id = %d, is_accepted = %d\n", state->get_state_id(), state->get_accepted());
   cout << state->get_state_type() << endl;
   printf("-------------------------\n");

   for(int i=0; i<nxt_states.size(); i++){
        State_Node* node = nxt_states[i];
        vector<char> vec = nxt_states_chars[i];
        printf("From state %d to state %d\n", state->get_state_id(), node->get_state_id());
        for(int j=0; j<vec.size(); j++){
           printf("%c ", vec[j]);
        }
        printf("\n++++++++++++++++++++++++++++++\n");
        if(state!=node)print_state_info(node);
   }

   printf("End state %d\n", state->get_state_id());
   printf("--------------------------\n");
}


void test_nfa_states(){
    NFA nfa;

    nfa.build_NFA();

    vector<State_Node*> start_states = nfa.get_start_states();
    for(int i=0; i<start_states.size(); i++){
       print_state_info(start_states[i]);
    }

}
