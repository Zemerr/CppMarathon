#include "./src/stdAlgoV2.h"



void replace_long_short(forward_list<string>& flist) {
    for (auto& i : flist) {
        if (i.size() > 10) {
            i = "Long one";
        }
        else if (i.size() < 4)
            i = "Short one";
    }
}


bool remove_comdition(string str) {
    if (str.find("c") != string::npos)
        return true;
    else if (str.find("b") != string::npos)
        return true;
    else if (str.find("l") != string::npos)
        return true;
    else
        return false;
}

void remove(forward_list<string>& flist) {
    flist.remove_if(remove_comdition);
}

string create_name(string old) {
    string pre;
    string last;
    stringstream ss(old);
    string name;

    getline(ss, pre, '.');
    getline(ss, last);
    name = pre + "_mod." + last;
    return name;

}

void do_all(forward_list<string>& flist, string name) {
    string filename;

    remove(flist);
    replace_long_short(flist);
    flist.unique();
    flist.sort();
    flist.reverse();
    filename = create_name(name);
    ofstream myfile1(filename);
    if (myfile1.is_open()) {
        for (auto i : flist) {
            myfile1 << i << "\n";
        }
        myfile1.close();
    }
    else
        cerr << "error\n";
}

int main(int argc, char **argv) {
    string line;
    forward_list<string> flist;
    ifstream myfile (argv[1]);
    string filename;
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
        do_all(flist, argv[1]);
    }
    else
        cerr << "error\n";
}
