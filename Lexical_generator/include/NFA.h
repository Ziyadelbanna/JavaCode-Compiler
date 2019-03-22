#ifndef NFA_H
#define NFA_H

#include <bits/stdc++.h>
#include "State_Node.h"
//#include "../read_files.h"

using namespace std;
class NFA
{
    public:
        NFA();
        virtual ~NFA();
        void build_NFA();
        vector<State_Node*> get_start_states();
    protected:

    private:
      vector<State_Node*> start_states;

    /******************************************* keyword ************************************/
      void create_keywords_path();
      void create_keyword_relop_mulop_addop_path(string kword, string type);

      /******************************************* keyword************************************/



      /******************************************* id*************************************/
      void create_id_path();
      /******************************************* id************************************/


      /******************************************* num************************************/
       void create_num_path();
      /******************************************* num************************************/



      /******************************************* relop************************************/
      void create_relop_path();
      /******************************************* relop************************************/


      /****************************************** assign & Punctuations ************************************/
      void create_assign_path();
      void create_punctuations_path();
      void create_assign_punc_path(char c, string type);
      /****************************************** assign & Punctuations ************************************/


     /****************************************** mulop **********************************/
      void create_mulop_path();
     /****************************************** mulop **********************************/


    /****************************************** addop **********************************/
      void create_addop_path();
     /****************************************** addop **********************************/

};

#endif // NFA_H
