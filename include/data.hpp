#pragma once
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "library.hpp"
#include "setting.hpp"

class Data {
 public:
  const Setting setting;
  std::ofstream outfile;
  std::vector<std::string> source;
  std::unordered_map<std::string, Library> libraries;

  Data(int argc, char* const* const argv, const std::string setting_file_path);
  ~Data();
};

void register_library(Data& data, const Library& lib);