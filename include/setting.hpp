#pragma once
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
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
