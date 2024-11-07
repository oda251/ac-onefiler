#pragma once
#include <cstddef>
#include <vector>
#include <unordered_map>

template <typename T>
class TrieNode {
 private:
  std::unordered_map<char, TrieNode<T>*> children_;
  T value_;
  bool is_end_;

 public:
  TrieNode();
  TrieNode(const TrieNode &src);
  TrieNode &operator=(const TrieNode &src);
  ~TrieNode();

  void insert(const std::string& key, const T& value);
  T& search(const std::string& key) const;
  T& search(const std::string& key, char end) const;
};

#include "trie_node.tpp"