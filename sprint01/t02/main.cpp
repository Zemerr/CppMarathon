#include "./src/visitAll.h"

void ender(char str) {
  if (str != 0)
    throw 1;
}

bool valid(string stamina, string distance, Town** town) {
    size_t pointer;

    try {
      (*town)->stamina = std::stoi(stamina, &pointer, 10);
      ender(stamina[pointer]);
      (*town)->distance = std::stof(distance, &pointer);
      ender(distance[pointer]);
    }
    catch (...) {
        return false;
    }
    return true;
}

void algorithm(deque<Town*> myd) {
    deque<Town*>::iterator iter = myd.begin();
     deque<Town*>::iterator itertwo;
     int dif = 0;
     bool trig = false;
     int size = 0;

    for ( ; iter < myd.end() && size < myd.size(); iter++) {
        if ((*iter)->stamina < (*iter)->distance) {
            myd.push_back((*iter));
            myd.pop_front();
        }
        else {
            itertwo = iter;
            for (; itertwo < myd.end(); itertwo++)
                dif = (*itertwo)->stamina - (*itertwo)->distance + dif;
            if (dif >= 0)
                trig = true;
            dif = 0;
        }
        if (trig == true)
            break;
        size++;
    }
    if (trig == true) {
        for (auto i : myd) {
            dif = i->stamina - i->distance + dif;
            cout << dif << ". " << i->name << "\n";
        }
   }
   else {
       std::cerr << "Mission: Impossible" << std::endl;
   }
}

int main(int argc, char **argv) {
    deque<Town*> myd;
    stringstream ss;
    auto index = 0;
    string stamina;
    string disatnce;
    
    if (argc <= 1) {
        std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]" << std::endl;
        return 1;
    }
    for (auto i = 1; i < argc; i++){
        Town* town = new Town;
        stringstream ss(argv[i]);
        getline(ss, town->name, ',');
        getline(ss, stamina, ',');
        getline(ss, disatnce, ',');
        if (valid(stamina, disatnce, &town) && town->name.size() > 1 && ss.eof())
            myd.push_back(town);
        else {
            std::cerr << "Argument " << argv[i] << " is not valid" << std::endl;
            return 1;
        }
    }
    algorithm(myd);
}
