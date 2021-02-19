#pragma once

#include <utility>
#include <string>
#include <set>

#include "Folder.h"

class Message {
  friend class Folder;
  friend void swap(Message&, Message&);
 public:
  explicit Message(const std::string &str = "") : contents(str) {}
  Message(const Message& m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
  }
  Message(Message &&m) : contents(std::move(m.contents)) {
    move_Folders(&m);
  }
  Message& operator=(const Message& m) {
    remove_from_Folders();
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
  }
  Message& operator=(Message &&m) {
    if (this != &m) {
      remove_from_Folders();
      contents = std::move(m.contents);
      move_Folders(&m);
    }
    return *this;
  }
  void save(Folder& f) {
    folders.insert(&f);
    f.addMsg(this);
  }
  void remove(Folder& f) {
    folders.erase(&f);
    f.remMsg(this);
  }
  ~Message() {
    remove_from_Folders();
  }
  void addFolder(Folder &f) {
    f.addMsg(this);
  }
  void remFolder(Folder &f) {
    f.remMsg(this);
  }
 private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message &m) {
    for (auto f : m.folders) {
      f->addMsg(this);
    }
  }
  void remove_from_Folders() {
    for (auto f : folders) {
      f->remMsg(this);
    }
  }
  void move_Folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f : folders) {
      f->remMsg(m);
      f->addMsg(this);
    }
    m->folders.clear();
  }
};

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto f : lhs.folders) {
    f->remMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->remMsg(&rhs);
  }
  swap(lhs.folders, rhs.folders);
  swap(lhs.contents, rhs.contents);
  for (auto f : lhs.folders) {
    f->addMsg(&lhs);
  }
  for (auto f : rhs.folders) {
    f->addMsg(&rhs);
  }
}
