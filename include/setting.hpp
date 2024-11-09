#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>
using json = nlohmann::json;

class Setting {
 public:
  std::string header;
  std::string main;
  std::string libraryDir;
  std::string outputFile;

  Setting(const std::string& path);
  Setting(const Setting& src);
  ~Setting();
};
