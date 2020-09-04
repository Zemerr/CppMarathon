#include "uniqueWords.h"


void add_com(map<string, string>& books, string book) {
    string text;

    if (books.find(book) == books.end()) {


        ifstream openbook = open_file("./library/" + book);

        if (openbook.is_open()) {
            getline(openbook, text, '\0');
            if (!text.empty()) {
                books.insert(pair<string, string>(book, text));
                cout << book << " was added\n";
            }
            else
                cerr << "invalid book\n";
        }
        else
            cerr << "invalid book\n";
    }
}

void remove_book(map<string, string>& books, string book) {
    auto pair = books.find(book);

    if (pair != books.end()) {
        books.erase(pair);
        cout << book << " deleted\n";
    }
    else
        cerr << "invalid book\n";

}

void read_book(map<string, string>& books, string book) {
    auto pair = books.find(book);

    if (pair != books.end()) {
        cout << (*pair).second << "\n";
    }
    else
        cerr << "invalid book\n";
}

void read_add_delete(string command, map<string, string>& books, string book) {
    if (command == "add")
        add_com(books, book);
    else if (command == "read")
        read_book(books, book);
    else if (command == "delete")
        remove_book(books, book);
}

void show_books(map<string, string>& books) {
    if (!books.empty()) {
        for (auto [key, val] : books) {
            cout << key << " ";
        }
        cout << "\n";
    }
}


void valid_comands(std::string str, map<string, string>& books) {
    std::stringstream ss(str);
    std::string command;
    std::string book;

    ss >> command;
    if (ss.eof()) {
        if (command == "list") {
            show_books(books);
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
        if (command == "add" || command == "delete" || command == "read") {
            ss >> book;
            if (!ss.eof()) {
                std::cerr << "Invalid command." << "\n";
            }
            else {
                read_add_delete(command, books, book);
            }
        }
        else {
            std::cerr << "Invalid command." << "\n";
        }
    }
}



void cycle() {
    std::string inputstr;
    std::map<string, string> books;

    while(1) {
        std::cout << "enter command:> ";
        getline(std::cin, inputstr, '\n');
        valid_comands(inputstr, books);
    }
}
