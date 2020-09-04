#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <regex>
#include <sstream>

using namespace std;

multiset<string> txt_to_mset(string filename);
ofstream create_file(string old);

