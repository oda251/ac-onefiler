#pragma once
#include <stdexcept>
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || \
    defined(__FreeBSD__)
#include <unistd.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

#include "library.hpp"

std::string fetch_exe_path();
Library find_include_directive(const std::string& line);
