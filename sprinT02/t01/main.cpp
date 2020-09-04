#include "uniqueWords.h"



int main(int argc, char **argv) {
    string s;
    int count = 0;

    if (argc == 2) {
        multiset<string> sty = txt_to_mset(argv[1]);
        ofstream myfile1 = create_file(argv[1]);
        if (!sty.empty() && myfile1.is_open()) {
            for (auto i : sty) {
                if (i != s) {
                    s = i;
                    myfile1 << i << ": "<< sty.count(i) << "\n";
                }
            }
        }
        else
            cerr << "error\n";
    }
    else {
       cerr << "usage: ./uniqueWords [file_name]\n";
    }
    
}
