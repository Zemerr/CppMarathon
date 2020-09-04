#include <iostream>

void ender(char str) {
  if (str != 0)
    throw 1;
}

int main(int argc, char** argv) {
  auto level = 1;
  auto health = 4.0f;
  auto stamina = 4.0;
  auto counter = 2;
  
  if (argc == 5) {
    auto pointer = 4ul;
    try {
      level = std::stoi(argv[counter], &pointer, 10);
      ender(argv[counter][pointer]);
      health = std::stof(argv[++counter], &pointer);
      ender(argv[counter][pointer]);
      stamina = std::stod(argv[++counter], &pointer);
      ender(argv[counter][pointer]);
    }
    catch (...) {
        std::cerr << "Invalid argument: " << argv[counter] << std::endl;
        return 1;
    }
    std::cout << "Name = " << argv[1] << "\n" << "Level = " << level << "\n" << "Health = " << health << "\n" << "Stamina = " << stamina << "\n";
  }
  else {
    std::cerr << "usage:./automaton [name] [level] [health] [stamina]" << std::endl;
  }
  return 0;
}
