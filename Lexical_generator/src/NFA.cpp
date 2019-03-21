#include "NFA.h"

NFA::NFA(){}

NFA::~NFA(){}


void NFA::create_keywords_path(){
           for(int i=0; i<key_words.size(); i++){
              create_keyword_relop_mulop_addop_path(key_words[i], "Keyword");
           }
}

void NFA::create_keyword_relop_mulop_addop_path(string kword, string type){
            State_Node parent_state;
            start_states.push_back(parent_state);

            for(int i=0; i< kword.size(); i++){
               char c = kword[i];
               State_Node child_state;
               vector<char> vec; vec.push_back(c);
               parent_state.add_transaction(child_state, vec);
               parent_state = child_state;
            }

            parent_state.set_accepted(true);
            parent_state.set_state_type(type);
}

/******************************************* keyword************************************/



 /******************************************* id*************************************/
void NFA::create_id_path(){
            State_Node parent_state, child_state;
            start_states.push_back(parent_state);

            parent_state.add_transaction(child_state, letters);

            // merge letters and digits
            vector<char> let_dig;
            for(int i=0; i<letters.size(); i++) let_dig.push_back(letters[i]);
            for(int i=0; i<digits.size(); i++) let_dig.push_back(digits[i]);
            child_state.add_transaction(child_state,let_dig);

            child_state.set_accepted(true);
            child_state.set_state_type("Id");

}

/******************************************* id************************************/

/******************************************* num************************************/

void NFA::create_num_path(){
            State_Node parent_state;
            State_Node state1, state2,state3,state4,state5,state6;
            start_states.push_back(parent_state);

            parent_state.add_transaction(state1, digits);

            vector<char> dot_vec; dot_vec.push_back('.');
            vector<char> lambda_vec; lambda_vec.push_back('L');
            vector<char> Exp_vec; Exp_vec.push_back('E');

            state1.add_transaction(state1, digits);
            state1.add_transaction(state2, dot_vec);
            state2.add_transaction(state3, digits);
            state3.add_transaction(state3, digits);
            state3.add_transaction(state4, lambda_vec);
            state3.add_transaction(state5, Exp_vec);
            state5.add_transaction(state6, digits);
            state6.add_transaction(state6, digits);

            state1.set_accepted(true);
            state1.set_state_type("num");

            state4.set_accepted(true);
            state4.set_state_type("num");

            state6.set_accepted(true);
            state6.set_state_type("num");
}
/******************************************* num************************************/


/******************************************* relop************************************/
void NFA::create_relop_path(){
          for(int i=0; i<relop.size(); i++){
              create_keyword_relop_mulop_addop_path(relop[i], "Relop");
           }
}
/******************************************* relop************************************/


/****************************************** assign & Punctuations ************************************/

void NFA::create_assign_path(){
         create_assign_punc_path('=', "Assign");
}

void NFA::create_punctuations_path(){
         for(int i=0; i<punctuations.size(); i++){
           create_assign_punc_path(punctuations[i], "Punc");
         }
}

void NFA::create_assign_punc_path(char c, string type){
          State_Node parent_state, child_state;
          start_states.push_back(parent_state);
          vector<char> equal_vec; equal_vec.push_back(c);
          parent_state.add_transaction(child_state,equal_vec);

          child_state.set_accepted(true);
          child_state.set_state_type(type);
}
/****************************************** assign ************************************/


/****************************************** mulop **********************************/
void NFA::create_mulop_path(){
            for(int i=0; i<mulop.size(); i++){
               create_keyword_relop_mulop_addop_path(mulop[i], "Mulop");
            }
}


/****************************************** mulop **********************************/


/****************************************** addop **********************************/
void NFA::create_addop_path(){
            for(int i=0; i<addop.size(); i++){
               create_keyword_relop_mulop_addop_path(addop[i], "Addop");
            }
}

/****************************************** addop **********************************/


