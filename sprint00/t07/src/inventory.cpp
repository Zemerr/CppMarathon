#include "header.h"



void valid_comands(std::string str, std::vector<std::string>& items) {
    std::stringstream ss(str);
    std::string command;
    std::string item;

    ss >> command;
    if (ss.eof()) {
        if (command == "show") {
            show(items);
        }
        else if (command == "help") {
            help();
        }
        else if (command == "exit") {
            std::cout << "Bye." << "\n";
            exit(0);
        }
        else {
            std::cerr << "Invalid command." << "\n";
        }
    }
    else {
        if (command == "insert" || command == "remove") {
            ss >> item;
            if (!ss.eof()) {
                std::cerr << "Invalid command." << "\n";
            }
            else {
                insert_remove(items, item, command);
            }
        }
        else {
            std::cerr << "Invalid command." << "\n";
        }
    }
}


void inventory() {
    std::string inputstr = "";
    std::vector<std::string> items;

    while(1) {
        std::cout << "Enter command:> ";
        getline(std::cin, inputstr, '\n');
        valid_comands(inputstr, items);
        //std::cout << inputstr;
    }
}
