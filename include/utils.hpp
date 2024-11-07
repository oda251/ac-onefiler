#pragma once
#include <stdexcept>

#include "library.hpp"

Library detect_include_directive(const std::string& line);
