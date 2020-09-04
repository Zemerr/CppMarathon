#include <iostream>
#include "isPalindrome.h"


int main() {
    std::string str= "LoLdfgdfvbdfg";
    
    isPalindrome(str.begin(), str.end())? std::cout << "Yes\n":  std::cout  <<"No\n";
}
