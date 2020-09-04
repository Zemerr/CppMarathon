#include "./src/stdAlgoV1.h"

void fsize(forward_list<string> flist, int size) {
    if (!flist.empty())
        cout << "size: " << size << "\n";
}

void find_rich(forward_list<string> flist) {
    for (auto i : flist) {
        auto it = i.find("rich", 0);
        if (it != string::npos) {
            cout << "contains 'rich': true\n";
            return;
        }
    }
    cout << "contains 'rich': false\n";
}

bool count_vel(string str) {
    auto it = str.rfind("vel");
    if (it == str.size() - 3)
        return true;
    else
        return false;
}

void find_vel(forward_list<string> flist, int size) {
    int vel_count = count_if(flist.begin(), flist.end(), count_vel);

    if (vel_count == size)
        std::cout << "all end with'vel': true" << '\n';
    else
        std::cout << "all end with'vel': false\n";

}

bool condition(string str) {
    if (str.size() == 15)
        return true;
    else
        return false;
}
void find_15(forward_list<string> flist) {
    auto it = find_if(flist.begin(), flist.end(), condition);

    if (it == flist.end())
        std::cout << boolalpha << "none of lengths is 15: " << (it == flist.end()) << '\n';
    else
        std::cout << "none of lengths is 15: false" << '\n';
}

bool count_mel(string str) {
    if (str.find("mel") != string::npos)
        return false;
    else
        return true;
}

void not_mel(forward_list<string> flist) {
    int not_mel = count_if(flist.begin(), flist.end(), count_mel);

    std::cout << "not contains'mel': " << not_mel << '\n';
}

int main(int argc, char **argv) {
    string line;
    forward_list<string> flist;
    ifstream myfile (argv[1]);
    int size = 0;

    if (argc != 2) {
        cerr << "usage: ./stdAlgoV1 [file_name]\n";
        return 1;
    }
    if (myfile.is_open()) {
        while ( getline (myfile,line, '\n') ) {
            if (!line.empty() && line != "\n" && line != " ") {
                flist.push_front(line);
                size++;
            }
        }
        myfile.close();
    }
    else {
        cerr << "error\n";
        return 1;
    }
    if (size != 0) {
        fsize(flist, size);
        find_rich(flist);
        find_15(flist);
        find_vel(flist, size);
        not_mel(flist);
    }
    else
        cerr << "error\n";
}
