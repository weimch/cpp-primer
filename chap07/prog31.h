#pragma once

class Y;

class X {
  Y *py = nullptr;
};

class Y {
  X *px = nullptr;
};
