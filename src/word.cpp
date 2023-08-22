#include "../include/word.h"
#include <iostream>
#include <string>
#include <algorithm> // for std::transform
#include <cctype> // for std::tolower

using std::string;

word::word() : term({}), definition({}) {}

word::word(const string & term, const string & definition) : definition(definition) {
  this->term = term;

  std::transform(this->term.begin(), this->term.end(), this->term.begin(),
    [](unsigned char c) {return std::tolower(c);} );
}

word::~word() {}


string word::get_term() const {
  return term;
}

string word::get_definition() const {
  return definition;
}

void word::set_term(const string & term) {
  this->term = term;
}

void word::set_definition(const string & definition) {
  this->definition = definition;
}

void word::set_similar_words(const ds::list<ds::bst<string>::Node *> similar_words) {
  this->similar_words = similar_words;
}

void word::display() const {
  std::cout << term << ":-" << endl;
  std::cout << "\t" << "Definition - " << definition << endl;
}


bool word::operator==(const word & other) const {
  return term == other.term;
}
bool word::operator!=(const word & other) const {
  return !(*this == other);
}
bool word::operator<(const word & other) const {
  return term < other.term;
}
bool word::operator>(const word & other) const {
  return term > other.term;
}

ostream & operator<<(ostream & os, const word & w) {
  os << w.term;

  return os;
}


word::operator std::string() const {
  return term;
}
