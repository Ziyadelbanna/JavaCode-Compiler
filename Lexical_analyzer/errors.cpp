#include "errors.h"

void read_files_error(string file_name){
   cout << "Error while opening the file " << file_name << endl;
   exit(1);
}

void parse_file_error(){
   cout << "There is an Error while parsing the rules files" << endl;
   exit(1);
}
