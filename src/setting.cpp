#include "setting.hpp"

Setting::Setting(const std::string& path) {
  std::ifstream ifs(path);
  json j;
  ifs >> j;
  {
    auto lib_info = j.at("library");
    lib_info.at("directory").get_to(libraryDir);
    if (libraryDir.back() != '/') libraryDir += '/';
    lib_info.at("header").get_to(header);
    header = libraryDir + header;
    lib_info.at("main").get_to(main);
    main = libraryDir + main;
  }
  j.at("output_file").get_to(outputFile);
}
Setting::Setting(const Setting& src)
    : header(src.header),
      main(src.main),
      libraryDir(src.libraryDir),
      outputFile(src.outputFile) {}
Setting::~Setting() {}