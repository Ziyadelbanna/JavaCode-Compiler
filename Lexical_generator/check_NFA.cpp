#include "check_NFA.h"
#include "State_Node.h"
#include "read_files.h"

vector<State_Node> nfa_current_states;
vector<State_Node> nfa_next_states;
vector<State_Node> initial_nfa_states;
vector<string> output;

bool reach_accepted_state = false;
bool first_initial = false;
int last_accepted_index;
State_Node last_accepted_state;


/********************************************** Initialization **************************************/

void initialize_current_states(vector<State_Node> start_states){
   if(!first_initial){
      initial_nfa_states = start_states;
      first_initial = true;
    }
   nfa_current_states = start_states;
   nfa_next_states.clear();
}

/********************************************** Initialization **************************************/



/********************************************** Update current state *********************************/
void update_current_next_states(){
   nfa_current_states = nfa_next_states;
   nfa_next_states.clear();
}
/********************************************** Update current state *********************************/



/********************************************** Set next states **************************************/

void check_state(State_Node curr_state, char buffer_char){
        vector<State_Node> next_states_temp = curr_state.get_next_states();
        vector< vector < char > > next_state_inputs_temp = curr_state.get_next_states_values();

        for(int i=0; i<next_states_temp.size(); i++){
           vector<char> curr_v = next_state_inputs_temp[i];
           if(std::find( curr_v.begin(), curr_v.end(), buffer_char) != curr_v.end()){
              State_Node node = next_states_temp[i];
              vector<char> old_sofar = curr_state.get_accepted_buffer_sofar();
              old_sofar.push_back(buffer_char);
              node.set_accepted_buffer_sofar(old_sofar);
              nfa_next_states.push_back(node);
           }
        }
}


void check_current_states(char buffer_char){
     for(int i=0; i<nfa_current_states.size(); i++){
         check_state(nfa_current_states[i], buffer_char);
     }
}

/********************************************** Set next states **************************************/



/********************************************** Update last accepted state ***************************/

void update_last_accepted(int index){

    int flag=0;
    for(int i=0; i<nfa_next_states.size(); i++){
        State_Node curr_state = nfa_next_states[i];
        if(curr_state.get_accepted()){
            last_accepted_index = index;
            if(flag==0){
                last_accepted_state = curr_state;
                flag=1;
            }
            else check_priority(curr_state);
            reach_accepted_state = true;
        }
    }

}


void check_priority(State_Node curr_state){
    string type1 = last_accepted_state.get_state_type();
    string type2 = curr_state.get_state_type();

    if(type1=="Id" && type2=="Keyword"){
        last_accepted_state =curr_state;
    }
}

/********************************************** Update last accepted state ***************************/





/**********************************************  check buffer words **********************************/


void set_error(string err){
   cout << err << endl;
   exit(1);
}



void update_result(){

   string type = last_accepted_state.set_state_type();

   if(type=="Keyword") output.push_back(to_string(last_accepted_state.get_accepted_buffer_sofar()));
   else output.push_back(type);
}



void check_word(string word){

      last_accepted_index =-1;
      for(int i=0; i<word.size(); i++){
          char curr_char = word[i];
          check_current_states(curr_char);
          if(nfa_next_states.size()==0){
              if(last_accepted_index==i-1 || !reach_accepted_state){
                   set_error();
                   return;
              }
              update_result();
              i=last_accepted_index;
          }else{
              update_last_accepted(i);
              update_current_next_states();
          }
       }

       if(!reach_accepted_state || last_accepted_index!=(word.size()-1)) set_error();
       update_result();
}


void check_buffer_words(){

    for(int i=0; i<buffer_words.size(); i++){
         initialize_current_states(initial_nfa_states);
         check_word(buffer_words[i]);
    }
}


void string to_string(vector<char> vec){
    string res="";
    for(int i=0; i<vec.size(); i++){
       res += vec[i];
    }
    return res;
}

/**********************************************  check buffer words **********************************/
