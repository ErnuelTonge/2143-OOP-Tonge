import sys
from rich import print
import random

class Die(object):

  def __init__(self, sides=None):
    if not sides:
      self.sides = 6
    else:
      if not isinstance(sides, int):
        print("error: sides is not an integer!")
        sys.exit()
      self.sides = sides

  def roll(self):
    values = [x for x in range(self.sides)]

    random.shuffle(values)

    return values[0] + 1

  def __str__(self):
    return f"[sides: {self.sides}]"


class Dice:

  def __init__(self, sides=None, num_dice=1):
    if not sides:
      print("Need to pass in sides!!!")
      sys.exit()
    

    self.sides = sides

    # create a container
    self.dice = []

    for die in range(num_dice):
      self.dice.append(Die(sides))

  def sum(self):
    total = 0
    for d in self.dice:
      total += d.roll()

    return total

  def max(self):
    roleResult = []
    
    for d in self.dice:
      roleResult.append(d.roll())
    
    highest_integer = max(roleResult)
    
    return highest_integer

  def min(self):
    roleResult = []
    
    for d in self.dice:
      roleResult.append(d.roll())
      
    lowest_integer = min(roleResult)
    return lowest_integer
  

  def avg(self):
    total = 0
    for d in self.dice:
      total += d.roll()

    return total/len(self.dice)

  
  def roll(self, rollType=None):

    if rollType == 'max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()
      

  def __str__(self):
    s = "Dice:[\n    "
    for d in self.dice:
      s = s + str(d)
    s = s + "\n]\n"
    return s


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
