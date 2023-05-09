/*****************************************************************************
 *
 *  Author:           Ernuel Tonge
 *  Title:            List Based Queue
 *  Course:           2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        List based implementation of a queue data structure that includes additional methods to add values, 
 *        remove values, and maintain sorted values if needed. This class also has the ability to be initialized 
 *        with different data sources (files, other vectors, and arrays).
 *
 *  Usage:
 *        Use it like a linked list.
 *
 *  Files:
 *        main.cpp
 *        input.dat
 *        test.out
 *****************************************************************************/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * Node
 * 
 * Description:
 *      Node for our linked list
 * 
 * Public Methods:
 *                          Node(int x)                             
 * 
 * Usage: 
 * 
 *      Node *temp = new Node(value)                // Dynamically alocate a Node 
 *                                                     initialized to value
 */
struct Node {
  int data;
  Node *next;
  Node *prev;

  Node(int x) {
    data = x;
    next = nullptr;
    prev = nullptr;
  }
};


/**
 * Vector
 * 
 * Description:
 *      List based implementation of a queue data structure that includes additional 
 *      methods to add values, remove values, and maintain sorted values if needed.  
 *      This class also has the ability to be initialized with different data sources
 *      (files, other vectors, and arrays).
 *      
 * 
 * Public Methods:
 *                        Vector()
 *                        Vector(const Vector &other)
 *                        Vector(string inFileName)
 *                        Vector (int arr[], int arrSize)
 *                        
 *      void             pushFront(int val)
 *      void             pushRear(int val)
 *      void             pushFront(const Vector& other)
 *      void             pushRear(const Vector& other)
 *      void             pushAt(int loc, int val)
 *      void             inOrderPush(int val)
 *      int              popFront()
 *      int              popRear()
 *      int              popAt(int loc)
 *      int              find(int val)
 *      void             print()
 *     
 * 
 * Private Methods:
 *      void                pushFront(Node *node)
 *      void                pushRear(Node *node)
 *      void                push(int value)
 * 
 * Usage: 
 *       Vector V1;                  // Create Instance of Vector
 *       Vector v2(A,5);             //Create and initialize Vector using array
 *       Vector v3(v1);              //Create and initialize Vector using Vector
 *       Vector v4("input.dat");     //Create and initialize Vector using text file
 *
 *       v1.pushFront(18);           //Pushes a single integer to the front of the vector
 *       v1.print();                 //prints the contents of Vector
 *       v2.pushRear(63);            //Pushes a single integer to the rear of the vector
 *       v3.pushFront(v2);           //Pushes the contents of a Vector to the front of 
 *                                     another vector
 *       x = v1.popFront();          //Removes and returns the value at the front of Vector
 *       x = v1.popRear();           //Removes and returns the value at the front of Vector
 *       x = v2.popAt(3);            //Removes and returns the value at the specified index
 *       x = v2.find(51);            //Returns the index of the specified value 
 *       v3.pushFront(v2);
 *      
 */
class Vector {
  Node *front;
  Node *rear;
  int count;

/**
     * Private : pushFront
     * 
     * Description:
     *      pushes a recieved node (by address) to the front of the list
     * 
     * Params:
     *      Node*   : new Node to be added to list
     * 
     * Returns:
     *      Nothing
     */
void pushFront(Node *node) {
    node->next = front;
    front = node;
  }

/**
     * Private : pushRear
     * 
     * Description:
     *      Pushes a recieved node (by address) to the rear of the list
     * 
     * Params:
     *      Node*   : new Node to be added to list
     * 
     * Returns:
     *      Nothing
     */
void pushRear(Node *node) {
    if (!rear)
      front = rear = node;

    else {
      rear->next = node;
      rear = node;
    }
  }

/**
     * Private : push
     * 
     * Description:
     *      Pushes a recieved value onto the linked list based Vector
     * 
     * Params:
     *      int   : data value of the node
     * 
     * Returns:
     *      Nothing
     */
void push (int value) {
    Node *temp = new Node(value);
      if (rear == nullptr) {
      front = rear = temp;
    } 
    else {
      pushRear(temp);
    }
  count++;
  }

public:

/**
     * Public : Vector
     * 
     * Description: 
     *      Default constructor, sets front and rear to null.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
Vector() { front = rear = nullptr; }

/**
     * Public : Vector
     * 
     * Description: 
     *      Constructor that recieves another Vector and initializes
     *      the new Vector to the values of the one that was revieved.
     * 
     * Params:
     *      Vector & : address of vector being used to initialize.
     * 
     * Returns:
     *      Nothing
     */
Vector(const Vector &other) {
    front = rear = nullptr;
    Node *traverse = other.front;
    while (traverse != nullptr) {
      Node *temp;
      temp = new Node(traverse->data);
      pushRear(temp);
      traverse = traverse->next;
      count++;
    }
  }

/**
     * Public : Vector
     * 
     * Description: 
     *      Constructor that recieves a file and reads the values of
     *      the file into the list based vector.
     * 
     * Params:
     *      Vector & : address of vector being used to initialize.
     * 
     * Returns:
     *      Nothing
     */
Vector(string inFileName){
    int value;
    front = rear = nullptr; 
    ifstream inFile;
    inFile.open(inFileName.c_str());
    if (inFile.is_open()){
      while (!inFile.eof()) {
            inFile>>value;
            this->push(value);
            count++;
          }
      inFile.close(); // CLose input file
    }  
  
    else { //Error message
          cout << "Can't find input file " << inFileName << endl;                  
      } 
    }

/**
     * Public : Vector
     * 
     * Description: 
     *      Constructor that recieves an array and reads the values
     *      of the array in to the list based vector.
     * 
     * Params:
     *      int []  : array of values for initialization
     *      int     : array size
     * 
     * Returns:
     *      Nothing
     */
Vector (int arr[], int arrSize){
  front = rear = nullptr;
  for (int i = 0; i < arrSize; i++)
    {
      push(arr[i]);
      count++;
    }
}

/**
     * Public : pushFront
     * 
     * Description:
     *      Pushes an integer value to the front of the list. 
     *      An instance of the pushFront method that reciieves 
     *      an interger value.
     * 
     * Params:
     *      int     :  node data value
     * 
     * Returns:
     *      Nothing
     */
void pushFront(int val) {
    Node* newNode = new Node(val);
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
    count++;
}

/**
     * Public : pushRear
     * 
     * Description:
     *      An instance of the pushRear method that reciieves 
     *      an interger value, and pushes that to the rear of 
     *      the list as the data value of a node.
     * 
     * Params:
     *      int     :  node data value
     * 
     * Returns:
     *      Nothing
     */
void pushRear(int val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = newNode;
        }
        else {
            Node* temp = front;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

/**
     * Public : pushFront
     * 
     * Description: 
     *      An instance of the pushRear method that reciieves 
     *      a Veator of values, and pushes each value to the front of 
     *      the list as the data value of a node.
     * 
     * Params:
     *      int     :  node data value
     * 
     * Returns:
     *      Nothing
     */
void pushFront(const Vector& other) {
    Node* otherPtr = other.front; // get copy of other list's head

    Node* currentNode = other.front;
    int count = 0;
    
    while (currentNode != nullptr) {
        count++;
        currentNode = currentNode->next;
    }

  
    int* tempData = new int[count]; // allocate memory to hold values

    // load other list into array
    int i = 0;
    while (otherPtr) {
        tempData[i] = otherPtr->data;
        otherPtr = otherPtr->next;
        ++i;
    }

    // add values to the front of the list in their original order
    for (int i = count - 1; i >= 0; i--) {
        pushFront(tempData[i]);
    }

    delete[] tempData; // free dynamically allocated memory
}

/**
     * Public : pushFront
     * 
     * Description: 
     *      An instance of the pushRear method that reciieves 
     *      a Veator of values, and pushes each value to the rear of 
     *      the list as the data value of a node.
     * 
     * Params:
     *      int     :  node data value
     * 
     * Returns:
     *      Nothing
     */
void pushRear(const Vector& other) {
        Node* temp = other.front;
        while (temp) {
            pushRear(temp->data);
            temp = temp->next;
            count++;
        }
    }

/**
     * Public : PushAt
     * 
     * Description: 
     *      Pushes a value at a specified location (if it exists)
     *      
     * 
     * Params:
     *      int     : index location of value
     *      int     : value being added
     * 
     * Returns:
     *      Nothing
     */
void pushAt(int loc, int val) {
        if (loc < 0 || loc > count - 1) {
            return;
        }
        if (loc == 0) {
            pushFront(val);
        }
        else {
            Node* newNode = new Node(val);
            Node* temp = front;
            for (int i = 0; i < loc - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            count++;
        }
    }

/**
     * Public : inOrderPush
     * 
     * Description: 
     *      Adds single value to proper location in order to 
     *      maintain order (ascending or descending)
     *      
     * 
     * Params:
     *      int     : value being added
     * 
     * Returns:
     *      Nothing
     */
void inOrderPush(int val) {
        if (!front || front->data >= val) {
            pushFront(val);
            count++;
            return;
        }
        Node* temp = front;
        while (temp->next && temp->next->data < val) {
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        //count++;
    }

/**
     * Public : popFront
     * 
     * Description: 
     *      Removes single value from the front of the list 
     *      and returns that value.
     *      
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      int    : value being removed from list
     */
int popFront() {
    if (front == nullptr) {
        throw std::out_of_range("Vector is empty");
    }
    int val = front->data;
    Node *temp = front;
    front = front->next;
    delete temp;
    count--;
    if (front == nullptr) {
        rear = nullptr;
    }
    return val;
}

/**
     * Public : popRear
     * 
     * Description: 
     *      Removes single value from the rear of the list 
     *      and returns that value.
     *      
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      int    : value being removed from list
     */
int popRear() {
    
    if (rear == nullptr) {
        throw std::out_of_range("Vector is empty");
    }
    int val = rear->data;
    
    Node *previous = nullptr;
    Node *current = front;
  
    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }
  
    val = current->data;
    delete current;
   
    rear = previous;
    rear->next = nullptr;
    count--;
    return val;
}

/**
     * Public : popAt
     * 
     * Description: 
     *      Removes single value from an indexed location if 
     *      index between 0 and size of list -1.
     *      
     * Params:
     *      None
     * 
     * Returns:
     *      int    : Index location of value being removed from list
     */
int popAt(int loc) {
    if (loc < 0 || loc >= count) {
        throw std::out_of_range("Invalid index");
    }
    int value;
    if (loc == 0) {
        value = popFront();
    } else if (loc == count - 1) {
        value = popRear();
    } else {
        Node *previous = nullptr;
        Node *current = front;
        for (int i = 0; i < loc; i++) {
            previous = current;
            current = current->next;
        }
        value = current->data;
        previous->next = current->next;
        delete current;
        count--;
    }
    return value;
}

/**
     * Public : find
     * 
     * Description: 
     *      Finds the location of item (index) if it exists
     *      and returns that value.
     *      
     * Params:
     *      None
     * 
     * Returns:
     *      int    : Index location of value being searched for
     */
int find(int val) const {
    Node *current = front;
    int index = 0;
    while (current != nullptr) {
        if (current->data == val) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

/**
     * Public : print
     * 
     * Description: 
     *      Prints the contents of the Vector class to the screen 
     *      and a text file in a format similar to [v1, v2, v3,...,vn]
     *      
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
void print() const {
  ofstream fout;
  fout.open ("test.out", fstream::app);

    cout << "[";
    fout << "[";
    Node *current = front;
    while (current != nullptr) {
        cout << current->data;
        fout << current->data;
        if (current->next != nullptr) {
            cout << ", ";
            fout << ", ";
        }
        current = current->next;
    }
    cout << "]" << endl;
    fout << "]" << endl;
}

};

/**
     * Public : printHeading
     * 
     * Description: 
     *      Prints the output heading to the screen 
     *      and a text file.
     *      
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
void printHeading() {
  ofstream fout;
  fout.open ("test.out", fstream::app);


  cout << "Name: Ernuel Tonge" << endl 
       << "Date: 02/07/2023" << endl 
       << "Spring 2143" << endl << endl;
  
  fout << "Name: Ernuel Tonge" << endl 
       << "Date: 02/07/2023" << endl 
       << "Spring 2143" << endl << endl;
}


int main() {  

    printHeading();
                
    ofstream fout;
    fout.open ("test.out", fstream::app);
                
      Vector V1;
    
        V1.pushFront(56);
        V1.pushFront(42);
        V1.pushFront(30);
        V1.pushFront(48);
    
    int x = 0;
    
    Vector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print();
    // [25, 20, 18, 18, 20, 25]
    
    int A[] = {11,25,33,47,51};
    Vector v2(A,5);
    v2.print();
    // [11, 25, 33, 47, 51]
    
    v2.pushFront(9);
    //v2.inOrderPush(27);
    v2.pushRear(63);
    v2.print();
    // [9, 11, 25, 33, 47, 51, 63]
    
    v1.pushRear(v2);
    v1.print();
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]
    
    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print();
    // [18, 20, 25, 9, 11, 25, 33, 47, 51, 63]
    cout<<x<<endl;
    fout<<x<<endl;
    // 18
    
    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print();
    // [18, 20, 25, 9, 11, 25, 27, 33]
    cout<<x<<endl;
    fout<<x<<endl;
    // 47
    
    x = v2.popAt(3);
    v2.print();
    // [9, 11, 25, 47, 51, 63]
    cout<<x<<endl;
    fout<<x<<endl;            
    // 33
    
    x = v2.find(51);
    cout<<x<<endl;
    fout<<x<<endl;            
    // 4
    
    x = v2.find(99);
    cout<<x<<endl;
    fout<<x<<endl;            
    // -1
    
    Vector v3(v1);
    v3.print();
    // [18, 20, 25, 9, 11, 25, 33]
    
    v3.pushFront(v2);
    v3.print();
    //[9, 11, 25, 47, 51, 63, 18, 20, 25, 9, 11, 25, 33]
    
    Vector v4("input.dat");
    v4.pushRear(v3);
    v4.print();
    // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
  

};