#include <cstddef>
#include <stdexcept>
#include <vector>

#include "trie_node.hpp"

template <typename T>
TrieNode<T>::TrieNode() : value_(nullptr), is_end_(false) {}
template <typename T>
TrieNode<T>::TrieNode(const TrieNode &src)
    : value_(src.value_), is_end_(src.is_end_) {}
template <typename T>
TrieNode<T> &TrieNode<T>::operator=(const TrieNode<T> &src) {
  if (this != &src) {
    this->children_ = src.children_;
    this->value_ = src.value_;
    this->is_end_ = src.is_end_;
  }
  return *this;
}
template <typename T>
TrieNode<T>::~TrieNode() {
  for (std::size_t i = 0; i < this->children_.size(); i++) {
    delete this->children_[i];
  }
}

template <typename T>
void TrieNode<T>::insert(const std::string& key, const T& value_) {
  TrieNode<T> *current = this;
  for (std::size_t i = 0; key[i] != '\0'; i++) {
    if (current->children_.find(key[i]) == current->children_.end())
      current->children_[key[i]] = new TrieNode<T>();
    current = current->children_[key[i]];
  }
  current->value_ = value_;
  current->is_end_ = true;
}

template <typename T>
T& TrieNode<T>::search(const std::string& key) const {
  const TrieNode<T> *current = this;
  for (std::size_t i = 0; key[i] != '\0'; i++) {
    if (current->children_.find(key[i]) == current->children_.end()) return T();
    current = current->children_[key[i]];
  }
  return current->value_;
}

template <typename T>
T& TrieNode<T>::search(const std::string& key, const char end) const {
  const TrieNode<T> *current = this;
  for (std::size_t i = 0; key[i] != '\0' && key[i] != end; i++) {
    if (current->children_.find(key[i]) == current->children_.end()) return T();
    current = current->children_[key[i]];
  }
  if (current->is_end_) return current->value_;
  return T();
}
