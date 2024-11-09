#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include "data.hpp"
#include "onefiler.hpp"

int main(int argc, char** argv) {
  try {
    Data data(argc, argv);
    #ifdef DEBUG
    std::cerr << "# data constructed." << std::endl;
    #endif
    onefiler(data);
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
