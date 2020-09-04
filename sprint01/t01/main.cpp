#include "./src/moveAlong.h"

int main(int argc, char **argv) {
    vector<string> myvec;
    string str;
    vector<string> strings;

    strings.push_back("MERCE");
    strings.push_back("EMER");
    strings.push_back("JIM");

    if (argc < 2) {
        cerr << "usage: ./moveAlong [args]" << "\n";
        return 1;
    }
    for (auto i = 0; i < argc; i++) {
        str = string (argv[i]);
        std::transform(str.begin(), str.end(),str.begin(), ::toupper);
        for (auto j : strings) {
            auto it = str.find(j, 0);
            if (it != string::npos) {
                myvec.push_back(str);
                break;
            }
        }
    }
    for (auto j : myvec) {
        cout << j << ", move along!\n";
    }
}
