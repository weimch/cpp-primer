#include <string>

class Account {
 public:
  void calculate() {amount += amount * interestRate;}
  static double rate() {return interestRate;}
  static void rate(double);
 private:
  std::string owner;
  double amount;
  static double interestRate;
  static double initRate() {
    return 0.05;
  }
};

void Account::rate(double newRate) {
  interestRate = newRate;
}

double Account::interestRate = initRate();
