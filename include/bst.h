/*
  Header file for Binary Search Tree (bst).
  It contains structural definitions and
  prototypes for bst.
*/

#ifndef BST_H
#define BST_H

#include <memory>
#include <string>
#include <cstddef>

namespace ds {
  template <typename T>
  class bst {
    public:
      struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node();
        Node(const T & value);
      };

    private:
      size_t count;
      std::unique_ptr<Node> root;

      bool insert_helper(std::unique_ptr<Node> & node, const T & value);
      Node * search_helper(const std::unique_ptr<Node> & node, const T & key) const;
      bool remove_helper(std::unique_ptr<Node> & node, const T & value);
      void print_helper(bst<T>::Node * root, size_t level, std::string prefix) const;
      bool is_full_helper(const std::unique_ptr<Node> & node) const;

    public:
      bst();
      ~bst();

      bool insert(const T& value);
      bool remove(const T& value);
      T *  search(const T& key);
      Node * search_node(const T & key);
      void print() const;

      bool is_empty() const;
      bool is_full() const;
      size_t get_count() const;
      Node * get_root() const;
  };
}

#include "bst.tpp"

#endif // bst_H
