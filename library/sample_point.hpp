class Point {
 public:
  int x, y;
  Point(int x, int y);
  Point(const Point& src);
  Point& operator=(const Point& src);
  ~Point();
};

Point::Point(int x, int y) : x(x), y(y) {}
Point::Point(const Point& src) : x(src.x), y(src.y) {}
Point& Point::operator=(const Point& src) {
  if (this != &src) {
    this->x = src.x;
    this->y = src.y;
  }
  return *this;
}
Point::~Point() {}