#include "utils.hpp"

std::string fetch_exe_path() {
  char path[1024];
  std::string path_str;
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || \
    defined(__FreeBSD__)
  ssize_t count = readlink("/proc/self/exe", path, 1024);
  if (count == -1) {
    throw std::runtime_error("Failed to read the path of the executable.");
  }
  path_str = std::string(path, count);
  path_str = path_str.substr(0, path_str.find_last_of('/'));
#elif defined(_WIN32) || defined(_WIN64)
  DWORD count = GetModuleFileName(NULL, path, 1024);
  if (count == 0) {
    throw std::runtime_error("Failed to read the path of the executable.");
  }
  path_str = PathRemoveFileSpec(path);
#endif
  return path_str;
}
