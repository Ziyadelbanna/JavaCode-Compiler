#include <iostream>
#include "Parser.h"
using namespace std;

int main()
{
    Parser ps;
    ps.read_rules_file();
    ps.print_vectors();
    return 0;
}
