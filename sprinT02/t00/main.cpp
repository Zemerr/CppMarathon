#include "uniqueWords.h"

int main(int argc, char **argv) {
    if (argc == 2) {
        set<string> sty = txt_to_set(argv[1]);
        ofstream myfile1 = create_file(argv[1]);
        if (!sty.empty() && myfile1.is_open()) {
            for (auto i : sty) {
                cout << i << "\n";
            }
        }
        else
            cerr << "error\n";
    }
    else {
       cerr << "usage: ./uniqueWords [file_name]\n";
    }
    
}
