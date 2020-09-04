#include "header.h"

void insert_remove(std::vector<std::string>& items, std::string item, std::string command) {
    std::string it;

    if (item == "w")
        it = 'w';
    else if (item == "f")
        it = 'f';
    else if (item == "a")
        it = 'a';
    else if (item == "p")
        it = 'p';
    else {
        std::cerr << "Invalid item." << "\n";
        return;
    }
    if (command == "insert") {
        if (items.size() >= 12) {
            std::cerr << "Inventory is full." << "\n";
            return;
        }
        else {
            items.push_back(it);
            std::cout << item << " was inserted." << "\n";
        }
    }
    else {
        remove(items, item);
    }
    
}

void show(std::vector<std::string>& items) {
    int size = items.size();
    std::cout << "Inventory { ";

    for (auto i : items) {
        std::cout << i << " ";
    }
    for(auto j = 12 - size; j > 0; j--) {
        std::cout << "- ";
    }
     std::cout << "}\n";
}

void remove(std::vector<std::string>& items, std::string item) {
    for(auto i = items.begin(); i < items.end(); i++) {
        if (*i == item) {
            items.erase(i);
            std::cout << item << " was removed." << "\n";
            break;
        }
    }
    std::cerr << "Invalid item." << "\n";
}

void help() {
    std::cout << "Available commands:\n";
    std::cout << "1. insert <itemType>\n";
    std::cout << "2. remove <itemType>\n";
    std::cout << "3. show inventory\n";
    std::cout << "4. help\n";
    std::cout << "5. exit\n";
}
