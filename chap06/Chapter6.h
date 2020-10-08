#ifndef CHAP06_CHAPTER6_H_
#define CHAP06_CHAPTER6_H_

int fact(int val);
int func();

template <typename T>
T abs(T i) {
  return i >= 0 ? i : -i;
}

#endif  // CHAP06_CHAPTER6_H_
