#pragma once

#include <string>

class Screen {
 public:
  using pos = std::string::size_type;
  Screen() = default;
  Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
  char get() const {
    return contents[cursor];
  }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  void some_member() const;
  Screen &set(char);
  Screen &set(pos, pos, char);
  Screen &display(std::ostream &os) {
    do_dispaly(os);
    return *this;
  }
  const Screen &display(std::ostream &os) const {
    do_dispaly(os);
    return *this;
  }

 private:
  void do_dispaly(std::ostream &os) const {
    os << contents;
  }
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  mutable size_t access_ctr;
};

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

void Screen::some_member() const {
  ++access_ctr;
}

inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
  contents[r*width+col] = ch;
  return *this;
}
