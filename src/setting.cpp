#include "setting.hpp"

Setting::Setting() {
  rootDir = fetch_exe_path();
  std::ifstream ifs(rootDir + '/' + SETTING_FILE);
  json j;
  ifs >> j;
  {
    auto lib_info = j.at("library");
    lib_info.at("directory").get_to(libraryDir);
    if (libraryDir.back() != '/') libraryDir += '/';
    if (libraryDir[0] != '/') libraryDir = rootDir + '/' + libraryDir;
  }
  j.at("output_file").get_to(outputFile);
}
Setting::Setting(const Setting& src)
    : libraryDir(src.libraryDir),
      outputFile(src.outputFile) {}
Setting::~Setting() {}