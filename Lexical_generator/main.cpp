#include <bits/stdc++.h>
#include "read_files.h"
#include "check_NFA.h"
using namespace std;

//extern vector<State_Node> current_states;


/*

class State_Node{

private:
    vector<State_Node> next_states;
    vector< vector < char > > next_state_inputs;
    vector<char> accepted_buffer_sofar;
    bool is_accepted = false;
    string state_type = "null";

public:

    string get_state_type(){
        return state_type;
    }

    void set_state_type(string tp){
       state_type = tp;
    }

    void set_accepted(bool acc){
       is_accepted = acc;
    }

    void add_transaction(State_Node next_state, vector<char> nxt_input){
         next_states.push_back(next_state);
         next_state_inputs.push_back(nxt_input);
    }


    vector<char> get_accepted_buffer_sofar(){
        return accepted_buffer_sofar;
    }

    void set_accepted_buffer_sofar(vector<char> vec){
        accepted_buffer_sofar = vec;
    }

    vector<State_Node> get_next_states(){
        return next_states;
    }

    vector< vector < char > > get_next_states_values(){
        return next_state_inputs;
    }

};

*/

/*
class NFA{

private:
      vector<State_Node> start_states;
      vector<State_Node> current_states;
      vector<State_Node> next_states;

      bool reach_accepted_state = false;
      State_Node last_accepted_state;


      void create_keywords_path(){
           for(int i=0; i<key_words.size(); i++){
              create_keyword_relop_mulop_addop_path(key_words[i], "Keyword");
           }
      }

      void create_keyword_relop_mulop_addop_path(string kword, string type){
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




      void create_id_path(){
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



       void create_num_path(){
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

      void create_relop_path(){
          for(int i=0; i<relop.size(); i++){
              create_keyword_relop_mulop_addop_path(relop[i], "Relop");
           }
      }


      void create_assign_path(){
         create_assign_punc_path('=', "Assign");
      }

      void create_punctuations_path(){
         for(int i=0; i<punctuations.size(); i++){
           create_assign_punc_path(punctuations[i], "Punc");
         }
      }

      void create_assign_punc_path(char c, string type){
          State_Node parent_state, child_state;
          start_states.push_back(parent_state);
          vector<char> equal_vec; equal_vec.push_back(c);
          parent_state.add_transaction(child_state,equal_vec);

          child_state.set_accepted(true);
          child_state.set_state_type(type);
      }

      void create_mulop_path(){
            for(int i=0; i<mulop.size(); i++){
               create_keyword_relop_mulop_addop_path(mulop[i], "Mulop");
            }
      }

      void create_addop_path(){
            for(int i=0; i<addop.size(); i++){
               create_keyword_relop_mulop_addop_path(addop[i], "Addop");
            }
      }




public:


      void build_NFA(){
         create_keywords_path();
         create_id_path();
         create_addop_path();
         create_assign_path();
         create_mulop_path();
         create_punctuations_path();
         create_num_path();
         create_relop_path();
      }

     };

*/
int main()
{
    //read_rules_file();
    //read_code_file();
    //printf("%d\n",check_size());

    string a="";
    a+='a';
    a+='b';
    cout >> a;
    return 0;
}
