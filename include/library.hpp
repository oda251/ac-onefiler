#pragma once
#include <string>
#include <vector>

class Library {
  public:
    enum Type : char {
      OWN_LIB,
      STD_LIB,
      OTHERS
    };
    Type type;
    std::string path;
    int priority;

    Library();
    Library(const std::string& path);
    Library(const Library& src);
    ~Library();
    Library& operator=(const Library& src);

    static bool less(const Library& a, const Library& b);
};