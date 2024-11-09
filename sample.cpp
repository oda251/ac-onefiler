#include "sample_grid.hpp"
int main() {
  Grid grid(3);
  Point p(1, 1);
  cout << grid[p] << endl;
  return 0;
}