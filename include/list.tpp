/**
 * @file list.tpp
 * @brief Implementation of a singly linked list template class.
 */
#ifndef LIST_TPP
#define LIST_TPP

#include "list.h"

#include <iostream>
#include <stdexcept>

namespace ds {


  /**
   * @brief Default constructor for the Node class.
   * Initializes a new Node with default values.
   */
  template <typename T>
  list<T>::node::node() : data({}), next(nullptr) {}

  /**
   * @brief Constructor for the Node class with initial value.
   * Initializes a new Node with the given value.
   * @param data The initial value to set.
   */
  template <typename T>
  list<T>::node::node(const T & data) : data(data), next(nullptr) {}

  /**
   * @brief Default constructor for the singly linked list.
   * Initializes a new list with default values.
   */
  template <typename T>
  list<T>::list() : head(nullptr), size(0) {}


  /**
   * @brief Destructor for the singly linked list.
   * Cleans up memory used by the list.
   */
  template <typename T>
  list<T>::~list() {
    node * current = head;

    while(current != nullptr) {
      node * temp = current;

      current = current -> next;
      delete temp;
    }

    head = nullptr;
    size = 0;
  }

  
  template <typename T>
  bool list<T>::insert_front(const T & data) {
    try {
      node * new_node = new node(data);

      new_node -> next = head; // makes the new node point to the previous head
      head = new_node; // makes the new node the new head

      size++;

      return true;
    }
    catch(const std::bad_alloc & e) {
      std::cout << "Unable to allocate more memory" << std::endl;
      return false;
    }
  }

  template <typename T>
  bool list<T>::insert_back(const T & data) {
    if(size == 0) 
      return insert_front(data);
    else {
      try {
        node * new_node = new node(data);
        node * temp = head;

        // find the last node
        while(temp -> next != nullptr)
          temp = temp -> next;

        temp -> next = new_node;
        new_node -> next = nullptr;

        size++;

        return true;
      }
      catch(const std::bad_alloc & e) {
        std::cout << "Unable to allocate more memory" << std::endl;
        return false;
      }
    }
  }

  template <typename T>
  bool list<T>::delete_front() {
    if(head == nullptr)
      return false;
    else {
      node * temp = head;

      head = head -> next;
      delete temp;

      size--;

      return true;
    }
  }

  template <typename T>
  bool list<T>::delete_back() {
    if(head == nullptr)
      return false;
    else {
      node * temp = head;

      // find the 2nd last node
      while(temp -> next -> next != nullptr)
        temp = temp -> next;

      delete temp -> next; // delete the last node
      temp -> next = nullptr; // make the 2nd last node the last node
      size--;

      return true;
    }
  }

  template <typename T>
  bool list<T>::delete_key(const T & key) {
    //if(head == nullptr)
    if(size == 0)
      return false;
    else if(size == 1) {
      if(head -> data == key) {
        delete head;
        head = nullptr;
        size--;

        return true;
      }
    }
    else if(size == 2) {
      if(head -> data == key) {
        node * temp = head;
        head = head -> next;
        delete temp;
        size--;

        return true;
      }
      else if(head -> next -> data == key) {
        delete head -> next;
        head -> next = nullptr;
        size--;

        return true;
      }
    }
    else {
      for (node * temp = head; temp -> next != nullptr; temp = temp -> next) {
        if( (temp -> next != nullptr) && (temp -> next -> data == key) ) { // find the previous node of the target node
          node * target = temp -> next;

          temp -> next = target -> next; // make the previous node of the target point to the node after the target node
          //temp -> next = temp -> next -> next; // make the previous node of the target point to the node after the target node
          delete target;
          size--;

          return true;
        }
      }
    }

    return false;
  }

  template <typename T>
  bool list<T>::search(const T & key) {
    for(node * temp = head; temp != nullptr; temp = temp -> next) {
      if(temp -> data == key)
        return true;
    }

    return false;
  }

  template <typename T>
  void list<T>::print() {
    std::cout << "[";

    for(node * i = head; i != nullptr; i = i -> next) {
      std::cout << " " << i -> data;

      if(i -> next == nullptr)
        std::cout << " ";
      else
        std::cout << ",";
    }

    std::cout << "]" << std::endl;
  }

  template <typename T>
  typename list<T>::node * list<T>::begin() const {
    return head;
  }

  template <typename T>
  typename list<T>::node * list<T>::end() const {
    node * temp = head;

    while(temp -> next != nullptr)
      temp = temp -> next;

    return temp;
  }

  template <typename T>
  int list<T>::get_size() const {
    return size;
  }


  template <typename T>
  T& ds::list<T>::operator[](int index) {
      if (index < 0 || index >= size) {
          throw std::out_of_range("Index out of bounds");
      }

      node* current = head;
      for (int i = 0; i < index; i++) {
          current = current->next;
      }

      return current->data;
  }
}

#endif
