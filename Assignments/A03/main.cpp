/*****************************************************************************
*                    
*  Author:           Ernuel Tonge
*  Email:            ernuel0910@gmail.com
*  Label:            A04
*  Title:            Commenting Code
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        This program implements a class that allows a dynamically alocated array to be used just like 
*        a Queue. 
*
*
*        
*  Usage: 
*       - This will demonstrate the use of an array bases Queue. 
*       
*  Files:            
*       main.cpp    : driver program 
*  
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * Class Name: CircularArrayQue
 * 
 * Description:
 *      This class creates, traverses, and manipulates a dynamically allocated array based Queue.
 * 
 * Public Methods:
 *                          CircularArrayQue()    
 *                          CircularArrayQue(int size) 
 *      void                Push(int item)
 *      int                 Pop()
 * 
 * Private Methods:
 *      void                init(int size = 0)
 *      bool                full()
 * 
 * Usage: 
 * 
 *      CircularArrayQue C1(5);                         // Create Que array and initialize size
 *      C1.Push(34);                                    // Push interger value onto the Que
 *      C1.Pop(54);                                     // Pops interger value off of the Que.
 */

class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    
    /**
     * Private : init
     * 
     * Description:
     *      Initialize member variables.
     * 
     * Params:
     *     int     :  initial value of member variables 
     * 
     * Returns:
     *      - nothing
     */
    
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private : Full
     * 
     * Description:
     *      Checks the status of the Que buy comparing the total space of the Que to the space being occupied. 
     * 
     * Params:
     *      - none
     * 
     * Returns:
     *      bool   : Status of the Que.
     */
    
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    
    /**
     * Public : CircularArrayQue()
     * 
     * Description:
     *      Creates an array of predetermined size 10.
     * 
     * Params:
     *      - non
     * 
     * Returns:
     *      - nothing
     */
    
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    
    /**
     * Public : CircularArrayQue(int size)
     * 
     * Description:
     *      Creates an array to be used as a Que, of a size corresponding with the integer value passed to the function.
     * 
     * Params:
     *     int     :  array size
     *      
     * Returns:
     *      - nothing
     */
    
    
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public : Push
     * 
     * Description:
     *      Checks the status of the Que and if not full pushes a value onto the Que and if full prints "FULL" to the screen. 
     * 
     * Params:
     *      int     :  value to be added to Que
     * 
     * Returns:
     *      - nothing
     */
    
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public : Pop
     * 
     * Description:
     *      Pops value off of the Que.
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      int  : the value removed from the Que.
     */

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}#include <iostream>

int main() {
  std::cout << "Hello World!\n";
}