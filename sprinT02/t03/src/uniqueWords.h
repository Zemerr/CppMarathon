#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <regex>
#include <sstream>
#include <map>

using namespace std;

multiset<string> txt_to_mset(string filename);
ofstream create_file(string old);
void book(string file);

