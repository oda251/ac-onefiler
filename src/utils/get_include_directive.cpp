#include "utils.hpp"
#include <iostream>
Library detect_include_directive(const std::string& line) {
  size_t i = 0;
  Library res;
  if (line[i++] != '#') {
    return res;
  }
  while (line[i] == ' ' || line[i] == '\t') {
    i++;
  }
  // compare "include"
  for (size_t j = 0; j < 7; j++) {
    if (line[i++] != "include"[j]) {
      return res;
    }
  }
  while (line[i] == ' ' || line[i] == '\t') {
    i++;
  }
  // compare "<" or """
  char opposite;
  switch (line[i]) {
    case '<':
      res.type = Library::Type::STD_LIB;
      opposite = '>';
      break;
    case '"':
      res.type = Library::Type::OWN_LIB;
      opposite = '"';
      break;
    default:
      throw std::runtime_error("Invalid include derective.\n  " + line);
      break;
  }
  i++;
  size_t len = 0;
  while (line[i + len] != opposite) {
    if (line[i + len] == '\0') {
      throw std::runtime_error("Invalid include derective.\n  " + line);
    }
    len++;
  }
  if (len == 0) {
    throw std::runtime_error("Invalid include derective.\n  " + line);
  }
  res.path = line.substr(i, len);
  return res;
}
