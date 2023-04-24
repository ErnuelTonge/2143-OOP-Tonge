"""
/*****************************************************************************
*                    
*  Author:           Ernuel Tonge
*  Label:            P04
*  Title:            Roll them Bones!
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        This project implements a Die and Dice classes in Python, using a c++ code as
*        a template. It implements a dieTester method which tests the functionality 
*        of the Die and Dice classes by printing thei resulting outputs to the screen. 
*        
*        
*  Usage: 
*       - file is run from the command line using command python Dice.py
*       - file can also be made to run from the command line using command python main.py
*       
*  Files:            
*       main.py     : driver program use to test ability to import and run from the command line 
*       Dice.py     : Die and Dice class definition, implementation and testing code
*       
*****************************************************************************/
"""
#from Dice import Die, Dice

from Dice import Die
from Dice import Dice


"""
/**
     * Public : dieTester
     * 
     * Description:
     *      This function implements a dieTester method which tests the functionality 
     *       of the Die and Dice classes by printing their resulting outputs 
     *       to the screen.
     * 
     * Params:
     *      die       :  instance of Die class
     *      runs      :  number of times to execute
     *      testType  :  string specifying which test to execute 
     * 
     * Returns:
     *      nothing
     */
"""

def dieTester(die, runs=10, testType="sum"):
  if isinstance(die, Die):
    print(f"Testing {die.sides} sided die for {runs} rolls:")
    print("    [ ", end="")
    for i in range(runs):
      print(die.roll(), end=" ")
    print("]")
  else:
    print(
      f"Rolling {len(die.dice)} {die.sides} sided die {runs} times to get the {testType} value:"
    )
    print("    [ ", end="")
    for i in range(runs):
      if testType == "avg":
        print(die.avg(), end=" ")
      elif testType == "min":
        print(die.min(), end=" ")
      elif testType == "max":
        print(die.max(), end=" ")
      else:
        print(die.sum(), end=" ")
    print("]")


if __name__ == '__main__':
  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)
  d4 = Dice(6, 5)
  d5 = Die(4)
  

  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 10, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")
  dieTester(d4, 4, "min")
  dieTester(d5, 6)


