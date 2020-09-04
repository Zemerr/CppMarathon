#include "uniqueWords.h"


ofstream create_file(string old) {
    string pre;
    string last;
    stringstream ss(old);
    string name;

    getline(ss, pre, '.');
    getline(ss, last);
    name = pre + "_mod." + last;
    ofstream myfile1(name);
    return myfile1;
}

ifstream open_file(string filename) {
    ifstream myfile (filename);
    return myfile;
}

set<string> txt_to_set(string filename) {
    set<string> st;
    ifstream myfile = open_file(filename);
    string str;
    string str1;
    string str2;
    

    regex date_re("[^a-zA-Z0-9-']+");

    if (myfile.is_open()) {
        while (getline(myfile, str, ' ')) {
            str2 = regex_replace(str, date_re, " ");
            stringstream ss(str2);
            while (getline(ss, str1, ' '))
                st.insert(str1);
        }
    }
    else {
        cerr << "error\n";
    }
    return st;


}
