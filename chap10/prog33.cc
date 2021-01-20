#include <fstream>
#include <iterator>

int main() {
  std::ifstream fin("prog33.input");
  std::ofstream fout1("prog33.out1"), fout2("prog33.out2");
  std::istream_iterator<int> ist(fin), eof;
  std::ostream_iterator<int> ost1(fout1, " "), ost2(fout2, "\n");
  while (ist != eof) {
    int val = *ist++;
    if (val % 2 == 1) {
      *ost1++ = val;
    } else {
      *ost2++ = val;
    }
  }
  return 0;
}