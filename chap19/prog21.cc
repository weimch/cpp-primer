#include <string>
#include <iostream>

class Token {
 public:
  Token() : tok(INT), ival{0} {}
  Token(const Token &t) : tok(t.tok) {
    copyUnion(t);
  }
  Token &operator=(Token&&) noexcept;
  ~Token() {
    if (tok == STR) sval.std::string::~string();
  }
  Token &operator=(const std::string&);
  Token &operator=(char);
  Token &operator=(int);
  Token &operator=(double);
 private:
  enum {INT, CHAR, DBL, STR} tok;
  union {
    char cval;
    int ival;
    double dval;
    std::string sval;
  };
  void copyUnion(const Token&);
};