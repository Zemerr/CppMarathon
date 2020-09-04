#include <string>
#include <iostream> 
#include <iterator>
#include <fstream>
#include <sstream>
using namespace std;

template<class T>
T sumFileData(const std::string& fileName) {
    ifstream myfile (fileName);
    std::istream_iterator<T> it (myfile);
    std::istream_iterator<T> end;
    T sum = 0;

    while (it != end) {
        sum += *it;
        it++;
    }
    myfile.close();

    return sum;
}
