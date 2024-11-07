#include <fstream>
#include <iostream>

#include "data.hpp"
#include "onefiler.hpp"

int main(int argc, char** argv) {
  try {
    Data data(argc, argv, "setting.json");
    onefiler(data);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
