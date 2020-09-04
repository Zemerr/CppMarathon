#include <iostream>
#include <vector>
#include <sstream>

void inventory();
void insert_remove(std::vector<std::string>& items, std::string item, std::string command);
void show(std::vector<std::string>& items);
void remove(std::vector<std::string>& items, std::string item);
void help();
