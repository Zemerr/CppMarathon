#include "src/vector.h"
#include <iostream>
#include <string>
#include <vector>


int main() {

    // //first constrtuct
     size_t i = 8;
    CBL::Vector<int> tmp(8);

    std::vector<int> tempo {1,2,3,4,5};
    std::vector<int> tempoz {7,8,44,444,55, 97, 8};
    //second constrtuct
    CBL::Vector<int> temp(i, 7);

    // std::cout << temp[4] << "\n";
    // for(auto i : temp)
    //     std::cout << i << "\n";

    CBL::Vector<int> tempi{1,2,3,4,5};
    //CBL::Vector<int> tempol(tempi.begin(), tempi.end());
   // CBL::Vector<int> tempolr(tempi);
   //CBL::Vector<int> tempolr = tempi;

    
        // for(auto i : tempolr)
        // std::cout << i << "\n";

        // std::cout <<  "\n";
    
    // tempi.resize(10, 9);
    //        for(auto i : tempi)
    //     std::cout << i << "\n";

    //     tempi.reserve(15);
    //        for(auto i : tempi)
    //     std::cout << i << "\n";
   // std::cout << (tempo==tempoz) << "\n";
   //std::cout << tempi.at(20)<< "\n";

    // tempi.push_back(777);
    //            for(auto i : tempi)
    //     std::cout << i << "\n";
   //tempo.insert(tempo.begin()+800, 999);
   std::cout << tempi.capacity() << " ==== CAPACITY\n";
   tempi.insert(tempi.begin()+5, 999);
    for(auto i : tempi)
        std::cout << i << "\n";
    //std::cout << tempi.capacity() << " ==== CAPACITY\n";
    // tempo.clear();
    // std::cout << tempi.capacity() << "==== CAPACITY\n";
    // std::cout << tempi.size() << "==== Size\n";
    return 0;
}
