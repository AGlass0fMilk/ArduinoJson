// Copyright Benoit Blanchon 2014
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson

#pragma once

namespace ArduinoJson {
namespace Internals {

template <typename T>
class ListConstIterator {
 public:
  explicit ListConstIterator(const ListNode<T> *node = NULL) : _node(node) {}

  const T &operator*() const { return _node->content; }
  const T *operator->() { return &_node->content; }

  bool operator==(const ListConstIterator<T> &other) const {
    return _node == other._node;
  }

  bool operator!=(const ListConstIterator<T> &other) const {
    return _node != other._node;
  }

  ListConstIterator<T> &operator++() {
    if (_node) _node = _node->next;
    return *this;
  }

 private:
  const ListNode<T> *_node;
};
}
}
