"""
/*****************************************************************************
*                    
*  Author:           Ernuel Tonge
*  Email:            terry.griffin@msutexas.edu
*  Label:            P04
*  Title:            Roll them Bones!
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        This project implements a Die and Dice classes in Python, using a c++ code as
*        a template. It implements a standard roll just to sum up all dice and return that
*        value and also implements the min, max and avg roll methods.
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

import sys
from rich import print
import random

"""
/**
 * Class Die
 * 
 * Description:
 *      This class creates an instannce of a Die simulates the way it works
 *      using a random number generator.
 * 
 * Public Methods:
 *      - constructor __init__(self, sides=None)  
 *      - roll(self)
 *      - __str__(self)
 * 
 * 
 * Usage: 
 * 
 *      - self.dice.append(Die(sides))    #Adds instance of Die to a list
 *      - d1 = Die()                      #Create Instance of Die
 *      
 */
"""
class Die(object):

  """
  /**
     * Public : init (constructor)
     * 
     * Description:
     *      assigns the number of sides that a particular instance will have
     * 
     * Params:
     *      self          :  instance of Die
     *      sides (int)   :  number of sides Die will have
     * 
     * Returns:
     *      nothing
     */
  """
  def __init__(self, sides=None):
    if not sides:
      self.sides = 6
    else:
      if not isinstance(sides, int):
        print("error: sides is not an integer!")
        sys.exit()
      self.sides = sides
"""
  /**
     * Public : roll
     * 
     * Description:
     *      simulates the rolling of a Die
     * 
     * Params:
     *      self          :  instance of Die
     * 
     * Returns:
     *      int   :  a random number between 1 and the number of sides 
     */
  """
  def roll(self):
    values = [x for x in range(self.sides)]

    random.shuffle(values)

    return values[0] + 1
    
"""
  /**
     * Public : __str__
     * 
     * Description:
     *      prints the contents of an instance of the Die class
     * 
     * Params:
     *      self          :  instance of Die
     * 
     * Returns:
     *      str   :  contents of an instance of the Die class as a string
     */
  """
  def __str__(self):
    return f"[sides: {self.sides}]"


"""
/**
 * Class Dice
 * 
 * Description:
 *      This class creates an instannce of a Dice that incorperates the use  
 *      of multiple Die. Dice also simulates the rolling of multiple Die at 
 *      once. It also provides added functionality through the sum, max, min
 *      and avg methods. 
 * 
 * Public Methods:
 *      - constructor __init__(self, sides=None, num_dice=1)  
 *      - sum(self)
 *      - max(self)
 *      - min(self)
 *      - avg(self)
 *      - roll(self, rollType=None)
 *      - __str__(self)
 * 
 * 
 * Usage: 
 * 
 *      - d3 = Dice(10, 5)                #Create Instance of Dice and assigns it to a varible
 *      
 */
"""
class Dice:
"""
  /**
     * Public : __init__ (constructor)
     * 
     * Description:
     *      creates a list of Die objects
     * 
     * Params:
     *      self          :  instance of Dice
     *      sides         :  number of sides each of each Die
     *      num_dice      :  number of Die in list
     * 
     * Returns:
     *      nothing
     */
  """
  def __init__(self, sides=None, num_dice=1):
    if not sides:
      print("Need to pass in sides!!!")
      sys.exit()
    

    self.sides = sides

    # create a container
    self.dice = []

    for die in range(num_dice):
      self.dice.append(Die(sides))
"""
  /**
     * Public : sum
     * 
     * Description:
     *      sums the values of each individual role
     * 
     * Params:
     *      self          :  instance of Dice
     * 
     * Returns:
     *      the sum of all the roles
     */
  """
  def sum(self):
    total = 0
    for d in self.dice:
      total += d.roll()

    return total
    
"""
  /**
     * Public : max
     * 
     * Description:
     *      Finds the highest rolled value of a series of Die.
     * 
     * Params:
     *      self          :  instance of Dice
     * 
     * Returns:
     *      the highest of all the roles
     */
  """
  def max(self):
    roleResult = []
    
    for d in self.dice:
      roleResult.append(d.roll())
    
    highest_integer = max(roleResult)
    
    return highest_integer

"""
  /**
     * Public : min
     * 
     * Description:
     *      Finds the lowest rolled value of a series of Die.
     * 
     * Params:
     *      self          :  instance of Dice
     * 
     * Returns:
     *      the lowest of all the roles
     */
  """
  def min(self):
    roleResult = []
    
    for d in self.dice:
      roleResult.append(d.roll())
      
    lowest_integer = min(roleResult)
    return lowest_integer
  
"""
  /**
     * Public : avg
     * 
     * Description:
     *      Finds the average rolled value of a series of Die.
     * 
     * Params:
     *      self          :  instance of Dice
     * 
     * Returns:
     *      the average of all the roles
     */
  """
  def avg(self):
    total = 0
    for d in self.dice:
      total += d.roll()

    return total/len(self.dice)

"""
  /**
     * Public : roll
     * 
     * Description:
     *      recieves the type of roll to be carried out and executes that code block
     *      based on the desired type of role. 
     * 
     * Params:
     *      self          :  instance of Die
     *      rollType      :  specifies the type of role that is to be executed 
     * 
     * Returns:
     *      int   :  the max, min or average of a series of roles based on the requested
     *               role type. 
     */
  """  
  def roll(self, rollType=None):

    if rollType == 'max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()
      
"""      
/**
     * Public : __str__
     * 
     * Description:
     *      prints the contents of an instance of the Dice class
     * 
     * Params:
     *      self          :  instance of Die
     * 
     * Returns:
     *      int   :  the contents of an instance of the Dice class as a string
     */
  """
  def __str__(self):
    s = "Dice:[\n    "
    for d in self.dice:
      s = s + str(d)
    s = s + "\n]\n"
    return s

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


"""
