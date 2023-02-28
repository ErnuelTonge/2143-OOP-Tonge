/*****************************************************************************
 *
 *  Author:           Ernuel Tonge
 *  Title:            MyVector Class 2 - more robust vector class
 *  Course:           2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        Uses a previously established singly linked list based "vector" class
 *definition to create a more robust MyVector class that includes some added
 *functionality with the overloading of some C++ operators.
 *
 *  Usage:
 *        Use it like a vector. The <<, >>, =, +, ==, and [] operators have all
 *been overloaded to allow instances of the vector class to function more like
 *actual "vectors".
 *
 *  Files: Prints to output.txt file.
 *****************************************************************************/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#pragma once

#define INF 1000000000 // infinity

using namespace std;

// Node for our linked list
struct Node {
  int data;

  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

class MyVector {
private:
  Node *head; // base pointer of list
  Node *tail;
  int size;
  static ofstream fout;
  string fileName;
  bool sorted;

  /**
   * @brief Private version of inOrder push.
   *
   * @param x
   */
  void _inorderPush(int x) {
    Node *tempPtr = new Node(x); // allocate new node
    Node *prev = head;           // get previous and next pointers
    Node *curr = head;

    while (curr->data > x) { // loop to find proper location
      prev = curr;
      curr = curr->next;
    }

    tempPtr->next = prev->next; // add new node in its proper position
    prev->next = tempPtr;

    size++; // add to size :)
  }

public:
  /**
   * @brief Default constructor
   *
   */
  MyVector() { init(); }

  /**
   * @brief Overloaded Constructor
   *
   * @param int   *A - pointer to array
   * @param int   aSize - size of array
   */
  MyVector(int A[], int aSize) {
    init();

    for (int i = 0; i < aSize; i++) {
      pushRear(A[i]);
    }
  }

  /**
   * @brief Overloaded Constructor
   *
   * @param string FileName - file to open and read
   *
   * Assumes infile will contain numbers only delimited by spaces or
   * new lines.
   */
  MyVector(string FileName) {
    init();

    ifstream fin;
    int x = 0;

    fin.open(FileName);
    while (!fin.eof()) {
      fin >> x;
      pushRear(x);
    }
  }

  /**
   * @brief Copy Constructor
   *
   * @param MyVector &other
   */
  MyVector(const MyVector &other) {
    init();

    Node *temp = other.head;

    while (temp) {
      pushRear(temp->data);
      temp = temp->next;
    }
  }

  /**
   * @brief - Initialize the data members so we don't
   *      have duplicate lines in each constructor.
   *
   */
  void init() {
    head = tail = NULL;
    fileName = "";
    size = 0;
    sorted = 0;
  }

  /**
   * @brief Public version of inOrder push.
   *
   * @param x
   */
  void inorderPush(int x) {
    if (!sorted) {
      sortList();
    }

    if (!head) {
      pushFront(x); // call push front for empty list (or pushRear would work)
    } else if (x < head->data) {
      pushFront(x); // call push front if x is less than head
    } else if (x > tail->data) {
      pushRear(x); // call push rear if x > tail
    } else {
      _inorderPush(x); // call private version of push in order
    }
  }

  /**
   * @brief Sort the current values in the linked list.
   *
   * @returns None
   */
  void sortList() {
    Node *newFront = head;
    while (newFront->next) {
      Node *smallest = newFront;
      Node *current = newFront;
      int minimum = INF;
      while (current) {
        if (current->data < minimum) {
          smallest = current;
          minimum = current->data;
        }
        current = current->next;
      }
      smallest->data = newFront->data;
      newFront->data = minimum;
      newFront = newFront->next;
    }
    sorted = true;
  }

  /**
   * @brief Add value to front of list.
   *
   * @param x
   */
  void pushFront(int x) {
    Node *tempPtr = new Node(x);

    // empty list make head and tail
    // point to new value
    if (!head) {
      head = tail = tempPtr;
      // otherwise adjust head pointer
    } else {
      tempPtr->next = head;
      head = tempPtr;
    }
    size++;
  }

  /**
   * @brief This method loads values from 'other' list in 'this' list.
   *          It loads an array first so we can process the values in
   *          reverse so they end up on 'this' list in the proper order.
   *          If we didn't use the array, we would reverse the values
   *          from the 'other' list.
   *
   * @depends - Uses `pushFront(int)`
   * @param MyVector& other
   * @return None
   */
  void pushFront(const MyVector &other) {
    Node *otherPtr = other.head;         // get copy of other lists head
    int *tempData = new int[other.size]; // allocate memory to hold values

    // load other list into array
    int i = 0;
    while (otherPtr) {
      tempData[i] = otherPtr->data;
      otherPtr = otherPtr->next;
      ++i;
    }

    // process list in reverse in order to keep them
    // in their original order.
    for (int i = other.size - 1; i >= 0; i--) {
      pushFront(tempData[i]);
    }
  }

  /**
   * @brief -  Add 'other' list's values to end of 'this' list.
   * @note - Uses `pushRear(int)`
   * @param MyVector& other
   * @return None
   */
  void pushRear(const MyVector &other) {
    Node *otherPtr = other.head; // get copy of other lists head

    while (otherPtr) { // traverse and add
      pushRear(otherPtr->data);
      otherPtr = otherPtr->next;
    }
  }

  /**
   * @brief Push value onto list at soecified position, if it exists.
   *
   * @param int i - location index
   * @param inr x - value to add
   * @return bool - true add successful / false add failed
   */
  bool pushAt(int i, int x) {
    if (i >= size) {
      return false;
    }

    Node *tempPtr = new Node(x); // allocate new node
    Node *prev = head;           // get previous and next pointers
    Node *curr = head;

    while (i > 0) { // loop to find proper location
      prev = curr;
      curr = curr->next;
      i--;
    }

    tempPtr->next = prev->next; // add new node in its proper position
    prev->next = tempPtr;

    size++; // add to size :)
    return true;
  }

  /**
   * @brief - Add value to rear of list
   *
   * @param int x - value to be added
   * @return None
   */
  void pushRear(int x) {
    Node *tempPtr = new Node(x);

    if (!head) {
      head = tail = tempPtr;

    } else {
      tail->next = tempPtr;
      tail = tempPtr;
    }
    size++; // add to size of list
  }

  /**
   * Public : ostream &operator<<
   *
   * Description:
   *      Overloads ostream operator (<<) to directly print the contents
   *      of a MyVector class instance to the console.
   *
   * Params:
   *      ostream    :  reference to the original ostream object
   *      MyVector   :  Instance of MyVector class of integers
   *
   * Returns:
   *      ostream    :  returns a reference to the original ostream object
   */
  friend ostream &operator<<(ostream &os, const MyVector &rhs) {
    Node *temp = rhs.head; // temp pointer copies head
    os << "[";
    while (temp) { // this loops until temp is NULL
                   // same as `while(temp != NULL)`

      os << temp->data; // print data from Node
      if (temp->next) {
        os << ",";
      }
      if (!temp->next) {
        os << "]";
      }
      temp = temp->next; // move to next Node
    }
    os << endl;
    return os;
  }

  /**
   * Public : ofstream &operator<<
   *
   * Description:
   *      Overloads ofstream operator (<<) to directly print the contents
   *      of a MyVector class instance to an output file.
   *
   * Params:
   *      ofstream   :  a reference to the original ostream object
   *      MyVector   :  Instance of MyVector class of integers
   *
   * Returns:
   *      ofstream    : returns a reference to the original ostream object
   */
  friend ofstream &operator<<(ofstream &ofs, const MyVector &rhs) {

    Node *temp = rhs.head; // temp pointer copies head
    ofs << "[";
    while (temp) { // this loops until temp is NULL
                   // same as `while(temp != NULL)`

      ofs << temp->data; // print data from Node
      if (temp->next) {
        ofs << ",";
      }
      if (!temp->next) {
        ofs << "]";
      }
      temp = temp->next; // move to next Node
    }
    ofs << endl;
    return ofs;
  }

  /**
   * Public : &operator[]
   *
   * Description:
   *      Overloads square bracket operator ([]) to access and manipulate the
   *      contents of a vector directly as though it were an array.
   *
   * Params:
   *      int   :  Integer value of the index of the vector trying to be
   * accessed.
   *
   * Returns:
   *      int   :  The data found in that location.
   */
  int &operator[](int location) {
    Node *temp = Find(location);
    return temp->data;
  }

  /**
   * Public : operator==
   *
   * Description:
   *      Overloads comparison operator (==) to allow the direct comparison of
   * two vectors.
   *
   * Params:
   *      MyVector   :  Instance of MyVector class of integers
   *
   * Returns:
   *      bool   :  Returns a 1 if both vectors are the same and 0 if they are
   * not.
   */
  bool operator==(MyVector const &rhs) {
    int matches = 0;
    Node *right = rhs.head;
    Node *left = this->head;

    // initially checks to see if both vectors being compared are the same size,
    // if not they are already not equal
    if (rhs.size != this->size) {
      return 0;
    }

    // if both vectors are the same size then traverse both vectors and check to
    // see if each entry is the same and if so increment the variable matches
    else {
      while (right) {
        if (right->data == left->data) {
          matches++;
          // cout << "matches = " << matches << endl;
          right = right->next;
          if (left->next)
            left = left->next;
        }
      }
      // if each data comparison is a match then the fucction returns 1, if not
      // it returns 0.
      if (rhs.size == matches && this->size == matches) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  /**
   * Public : &operator=
   *
   * Description:
   *      Overloads assignment operator (=) to asign the values of on vector to
   * another.
   *
   * Params:
   *      MyVector    :  Instance of MyVector class of integers whose values
   * will be assigned to another vector
   *
   * Returns:
   *      MyVector*   : Pointer to a vector of integers
   */
  MyVector &operator=(const MyVector &rhs) {
    init();

    Node *temp = rhs.head;

    while (temp) {
      pushRear(temp->data);
      temp = temp->next;
    }
    return *this;
  }

  /**
   * Public : operator+
   *
   * Description:
   *      Overloads addition operator (+) to to directly add the contents of two
   * vectors.
   *
   * Params:
   *      MyVector    :  Instance of MyVector class of integers whose values
   * will be added to another vector
   *
   * Returns:
   *      MyVector   :  A vector populated with the added integer values.
   */
  MyVector operator+(MyVector &rhs) {
    int arSize = 0;
    // check to see which vector is larger and sets arSize = to the size of the
    // larger vector
    if (rhs.size > this->size)
      arSize = rhs.size;
    else
      arSize = this->size;

    // create 3 arrays sized to the largest vector
    int tempArr1r[arSize];
    int tempArr2l[arSize];
    int tempArr3t[arSize];

    // fills the first two arrays with zeros
    for (int i = 0; i < arSize; i++) {
      tempArr1r[i] = 0;
      tempArr2l[i] = 0;
    }

    Node *tempr = rhs.head;
    Node *templ = this->head;

    // populate the array with the valuse of the vector
    for (int i = 0; i < rhs.size; i++) {
      tempArr1r[i] = tempr->data;
      tempr = tempr->next;
    }

    // populate the array with the valuse of the vector
    for (int i = 0; i < arSize; i++) {
      tempArr2l[i] = templ->data;
      templ = templ->next;
    }

    // populate the third array with the sum of the first two arrays
    for (int i = 0; i < arSize; i++) {
      tempArr3t[i] = tempArr1r[i] + tempArr2l[i];
      if (templ->next != NULL) {
        templ = templ->next;
      }
    }

    // create a vector populated with the contents of the third array
    MyVector vAdd(tempArr3t, arSize);
    return vAdd;
  }

  /**
   * Public : Find
   *
   * Description:
   *      Overloads addition operator (+) to to directly add the contents of two
   * vectors.
   *
   * Params:
   *      int    :   index of the node being accessed
   *
   * Returns:
   *      Node*   :  Pointer to the address of the Node of specified index
   */
  Node *Find(int location) {
    Node *travel = head;
    int i = location;
    for (int i = location; i > 0; i--) {
      travel = travel->next;
    }
    return travel;
  }

  /**
   * @brief Destroy the My Vector object
   *
   */
  ~MyVector() {
    Node *curr = head;
    Node *prev = head;

    while (curr) {
      prev = curr;
      curr = curr->next;
      cout << "deleting: " << prev->data << endl;
      delete prev;
    }
  }
};

int main() {

  ofstream fout;
  fout.open("output.txt");

  cout << "2143" << endl
       << "P02" << endl
       << "Name: Ernuel Tonge" << endl
       << endl;
  fout << "2143" << endl
       << "P02" << endl
       << "Name: Ernuel Tonge" << endl
       << endl;

  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};

  MyVector v1(a1, 5);
  MyVector v2(a2, 3);

  cout << v1[2] << endl;
  fout << v1[2] << endl;
  // writes out 3

  cout << endl;
  fout << endl;

  v1[4] = 9;
  // v1 now = [1,2,3,4,9]

  cout << v1 << endl;
  fout << v1 << endl;
  // writes out [1,2,3,4,9] to console and output file.

  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [11,22,33,4,9] to console and output file.

  cout << (v2 == v1) << endl;
  fout << (v2 == v1) << endl;
  // writes 0 to console (false) .

  cout << endl;
  fout << endl;

  MyVector v4 = v1;
  cout << (v4 == v1) << endl;
  fout << (v4 == v1) << endl;
  // writes 1 to console (true) .

  cout << endl;
  fout << endl;
}