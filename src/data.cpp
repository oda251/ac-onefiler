#include "data.hpp"

Data::Data(int argc, char* const* const argv,
           const std::string setting_file_path)
    : setting(setting_file_path) {
  if (argc == 1) {
    throw std::runtime_error("Usage: " + std::string(argv[0]) +
                             " <file paths to compile...>");
  }
  for (int i = 1; i < argc; i++) {
    this->source.push_back(argv[i]);
  }
  this->outfile = std::ofstream(this->setting.outputFile);
  if (!this->outfile) {
    throw std::runtime_error("Failed to open output file.");
  }
}
Data::~Data() { this->outfile.close(); }

void register_library(Data& data, const Library& lib) {
  if (data.libraries.find(lib.path) == data.libraries.end()) {
    data.libraries[lib.path] = lib;
    return;
  }
  Library& tmp = data.libraries[lib.path];
  if (tmp.type != lib.type) {
    throw std::runtime_error("library name conflict.\n  " + lib.path + "\n  " +
                             tmp.path);
  }
  tmp.priority = std::max(tmp.priority, lib.priority);
}
