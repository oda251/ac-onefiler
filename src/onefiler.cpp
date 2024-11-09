#include "onefiler.hpp"

#include <iostream>
void detect_libraries(Data& data, const std::string& path, int priority);
void process(Data& data);
void copy_src(Data& data, const std::string& path);

void onefiler(Data& data) {
  data.outfile = std::ofstream(data.setting.outputFile);
  if (data.outfile.fail()) {
    throw std::runtime_error("Failed to open output file.");
  }
  for (const std::string& src : data.source) {
    detect_libraries(data, src, 0);
  }
  process(data);
}

void detect_libraries(Data& data, const std::string& path, int priority) {
  if (path.empty()) return;
  std::ifstream ifs(path);
  if (!ifs) {
    throw std::runtime_error("Failed to open file " + path);
  }
  try {
    std::string line;
    while (std::getline(ifs, line)) {
      if (line[0] == '#') {
        Library lib = detect_include_directive(line);
        lib.priority = priority;
        register_library(data, lib);
        if (lib.type == Library::Type::LOCAL) {
          detect_libraries(data, data.setting.libraryDir + lib.path,
                           priority + 1);
        }
      }
    }
  } catch (std::exception& e) {
    ifs.close();
    throw new std::runtime_error("Error occured in " + path + ".\n" + e.what());
  }
  ifs.close();
}

void process(Data& data) {
  std::vector<Library> libs;
  for (const auto& [path, lib] : data.libraries) {
    // write #include <...>
    if (lib.type == Library::Type::SYSTEM)
      data.outfile << "#include <" << path << ">\n";
    else
      libs.push_back(lib);
  }
  // sort by priority
  sort(libs.begin(), libs.end(), Library::less);
  // copy source code
  for (const Library& lib : libs) {
    copy_src(data, data.setting.libraryDir + lib.path);
  }
  for (const std::string& src : data.source) {
    copy_src(data, src);
  }
}

void copy_src(Data& data, const std::string& path) {
  if (path.empty()) return;
  std::ifstream ifs(path);
  if (!ifs) {
    throw std::runtime_error("Failed to open file " + path);
  }
  std::string line;
  while (std::getline(ifs, line)) {
    // skip include directive
    if (line[0] == '#' &&
        detect_include_directive(line).type != Library::Type::OTHERS)
      continue;
    data.outfile << line << '\n';
  }
}