#pragma once

#include <set>

class Message;

class Folder {
 public:
  void addMsg(Message *msg) {
    msgs.insert(msg);
  }
  void remMsg(Message *msg) {
    msgs.erase(msg);
  }
 private:
  std::set<Message*> msgs;
};
