#include <iostream>
#include <string>
#include <limits> // for clearing input buffer
#include <algorithm> // for std::transform
#include <cctype> // for std::tolower

#include "../include/bst.h"
#include "../include/word.h"

#define endl "\n"

using std::cin;
using std::cout;
using std::string;

static ds::bst<word> WORD_TREE;

void initialize();
void print_menu();
int choice();
bool word_is_alpha(const std::string & word);
string input_word();
void print_suggestions(ds::bst<word>::Node * subtree);

void add_word();
void search_word();
void delete_word();
void update_word();

int main() {
  initialize();

  while(1) {
    print_menu();

    switch (choice()) {
      case 1:
        add_word();
        break;
      case 2:
        search_word();
        break;
      case 3:
        delete_word();
        break;
      case 4:
        update_word();
        break;
      case 5:
        exit(0);
      default:
        cout << "Invalid input!" << endl;
        break;
    }
  }
}

void initialize() {

}

void print_menu() {
  cout << "        Word Dictionary" << endl;
  cout << "-----------------------" << endl;
  cout << "1. Add Word" << endl;
  cout << "2. Search Word" << endl;
  cout << "3. Delete Word" << endl;
  cout << "4. Update Word" << endl;
  cout << "5. Quit" << endl;
}

int choice() {
  int choice = {};

  do {
    cout << "Please enter a corresponding number: " << endl;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 5) {
      cout << "Invalid input. Please try again." << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else {
      break;
    }
  } while (true);

  return choice;
}

bool word_is_alpha(const std::string & word) {
  for (char c : word) {
    if (!std::isalpha(c)) {
        return false; // If a non-alphabetic character is found, return false
    }
  }
  return true; // All characters are alphabetic
}

string input_word() {
  string str = {};

  do {
    cout << "Enter a word: " << endl;
    cin >> str;

    if(!word_is_alpha(str)) {
      cout << "Error! Word should only contain alphabets!" << endl;
      cout << "Please try again!" << endl;
    }
    else {
      break;
    }
  } while(true);

  std::transform(str.begin(), str.end(), str.begin(),
    [](unsigned char c) {return std::tolower(c);} );

  return str;
}

void print_suggestions(ds::bst<word>::Node * subtree) {

}


void add_word() {
  string term = {};
  string definition = {};

  term = input_word();

  cout << "Enter the definition of the word: " << endl;
  std::getline(cin, definition);

  word new_word(term, definition);

  if (WORD_TREE.insert(new_word)) {
    return;
  }
  else {
    cout << "Error! Could not add the word!" << endl;
  }
}

void search_word() {
  string target_str = {};

  cout << "        Search" << endl;
  cout << "--------------" << endl;
  target_str = input_word();

  word target(target_str, {});
  word * result = WORD_TREE.search(target);

  if(result != nullptr) {
    //print_suggestions();
  }
  else {
    (*result).display();
  }
}

void delete_word() {

}

void update_word() {

}
