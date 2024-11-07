#include "sample_header.hpp"
#include "sample_point.hpp"

template <typename T>
class Grid {
 private:
  int width, height;
  vector<vector<T>> data;

 public:
  Grid(int size);
  Grid(int width, int height);
  Grid(const Grid& src);
  ~Grid();
  Grid& operator=(const Grid& src);
  Grid& operator[](const Point& p);
};

template <typename T>
Grid<T>::Grid(int size) : width(size), height(size) {
  data = vector<vector<T>>(size, vector<T>(size));
}

template <typename T>
Grid<T>::Grid(int width, int height) : width(width), height(height) {
  data = vector<vector<T>>(height, vector<T>(width));
}

template <typename T>
Grid<T>::Grid(const Grid& src)
    : width(src.width), height(src.height), data(src.data) {}

template <typename T>
Grid<T>::~Grid() {}

template <typename T>
Grid<T>& Grid<T>::operator=(const Grid& src) {
  if (this != &src) {
    this->width = src.width;
    this->height = src.height;
    this->data = src.data;
  }
  return *this;
}

template <typename T>
Grid<T>& Grid<T>::operator[](const Point& p) {
  return data[p.y][p.x];
}