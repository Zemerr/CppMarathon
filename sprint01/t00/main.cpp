#include "./src/simpleSort.h"

int main(int argc, char **argv) {
    array<string, 5> arr;

    if (argc != 6) {
        cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5" << "\n";
        return 1;
    }
    for (auto i = 1; i < argc; i++)
        arr.at(i-1) = argv[i];
    sort(arr.begin(), arr.end());
    for (auto j = 0; j < arr.size(); j++) {
        cout << arr[j];
        if (j != arr.size() - 1)
            cout << " ";
    }
    cout << "\n";
}
