#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>

#include "utils.hpp"
using json = nlohmann::json;

#define SETTING_FILE "setting.json"

class Setting {
 public:
  std::string rootDir;
  std::string libraryDir;
  std::string outputFile;

  Setting();
  Setting(const Setting& src);
  ~Setting();
};
