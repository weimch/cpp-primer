#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <memory>

struct QueryResult {
 public:
  QueryResult(std::shared_ptr<std::set<int>> lines,
    std::shared_ptr<std::vector<std::string>> data, std::string word) :
    lines(lines), data(data) {}
  std::shared_ptr<std::set<int>> lines;
  std::shared_ptr<std::vector<std::string>> data;
  std::string word;
};

class TextQuery {
 public:
  explicit TextQuery(std::ifstream &infile) :
    data(std::make_shared<std::vector<std::string>>()) {
    std::string line, word;
    int line_num = 0;
    while (std::getline(infile, line)) {
      data->push_back(line);
      std::istringstream iss(line);
      while (iss >> word) {
        std::transform(word.begin(), word.end(), word.begin(),
          [](unsigned char ch){ return std::tolower(ch); });
        if (word.rfind(',') == 0) {
          word = word.substr(0, word.size()-1);
        }
        if (m.find(word) == m.end()) {
          m[word] = std::make_shared<std::set<int>>();
        }
        m[word]->insert(line_num);
      }
      ++line_num;
    }
  }
  QueryResult query(std::string tq) {
    std::transform(tq.begin(), tq.end(), tq.begin(),
          [](unsigned char ch){ return std::tolower(ch); });
    if (m.find(tq) == m.end()) {
      return QueryResult(nullptr, nullptr, tq);
    }
    return QueryResult(m[tq], data, tq);
  }

 private:
  std::shared_ptr<std::vector<std::string>> data;
  std::map<std::string, std::shared_ptr<std::set<int>>> m;
};

std::ostream & print(std::ostream &out, const QueryResult &qr) {
  if (qr.data == nullptr) {
    out << qr.word << " not found" << std::endl;
    return out;
  }
  out << qr.word << " occurs " << qr.lines->size() << "times" << std::endl;
  for (const auto &e : *qr.lines) {
    out << "\t(line " << e << ") " << (*qr.data)[e] << std::endl;
  }
  return out;
}

int main() {
  std::ifstream infile("textquery.txt");
  TextQuery tq(infile);
  while (true) {
    std::cout << "enter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
  }
  return 0;
}
