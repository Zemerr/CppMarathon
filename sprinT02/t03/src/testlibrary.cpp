#include "uniqueWords.h"

void parse_one(string s, multimap <string, string>& m) {
    int submatches[] = { 1, 2 };
    std::regex e ("\"(.*)\"\\s*:\\s*\"(.*)\"");
    string author;
    string book;
    regex_token_iterator<std::string::iterator> rend;
    std::regex_token_iterator<std::string::iterator> c ( s.begin(), s.end(), e, submatches );

    if (c!=rend)
        author = *c;
    *c++;
    if (c!=rend)
        book = *c;
    m.insert(pair<string, string>(author, book));

}

void parse_func(string inputstr, multimap <string, string>& m) {
    std::regex e ("(\\n)");
    regex_token_iterator<std::string::iterator> a ( inputstr.begin(), inputstr.end(), e, -1);
    regex_token_iterator<std::string::iterator> rend;
    std::regex b ("\"(.*)\"\\s+:\\s+\"(.*)\"");
    std::regex rx("\\s*\"(.*)\"\\s*:\\s*\"(.*)\"\\s*");
    int line = 1;

    while (a!=rend) {
        string allstr = *a;
        if (!allstr.empty()) {
            if (regex_match(allstr.begin(), allstr.end(), rx))
                parse_one(allstr, m);
            else {
                cerr << "Line " << line << " is invalid\n";
                exit(1);
            }
        }
        *a++;
        line++;
    }


}

string take_str(string file) {
    string allstr;
    std::regex e ("(\\n)"); 
    ifstream myfile;
    regex_token_iterator<std::string::iterator> rend;

    myfile.open (file);
    if (myfile.is_open()) {
        getline(myfile, allstr, '\0');
        myfile.close();
    }
    else {
        cerr << "error\n";
        exit(1);
    }
    return allstr;
}

void print_m(multimap <string, string> mymap) {
    multimap<string,string> :: iterator it;
    string chek;
    int num = 1;

    for (auto [author, book] : mymap) {
        if (author != chek) {
            chek = author;
            num = 1;
            cout << author << ":\n";
            cout << " " << num << ": " << book << "\n";
        }
        else {
            num ++;
            cout << " " << num << ": " << book << "\n";
        }
    }
}

void book(string file) {
    multimap <string, string> m;
    string input = take_str(file);
    parse_func(input, m);
    print_m(m);
}
