#include "library.hpp"

Library::Library() : type(Library::Type::OTHERS), priority(0) {}
Library::Library(const std::string& path)
    : type(Library::Type::OTHERS), path(path), priority(0) {}
Library::Library(const Library& src)
    : type(src.type), path(src.path), priority(src.priority) {}
Library::~Library() {}

Library& Library::operator=(const Library& src) {
  if (this != &src) {
    this->type = src.type;
    this->path = src.path;
    this->priority = src.priority;
  }
  return *this;
}

bool Library::less(const Library& a, const Library& b) {
  return a.priority > b.priority;
}
