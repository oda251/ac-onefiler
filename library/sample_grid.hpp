#include "sample_header.hpp"
#include "sample_point.hpp"
#line 1 "library/sample_grid.hpp"
class Grid {
 private:
  int size_;
  vector<int> data_;

 public:
  Grid(int size) : size_(size), data_(size * size) {
    for (int i = 0; i < size; i++) data_[i] = i;
  }
  int& operator[](const Point& p) { return data_[p.y * size_ + p.x]; }
};