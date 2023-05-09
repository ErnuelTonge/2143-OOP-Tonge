## P03 - Graphviz Class
### Ernuel Tonge
### Description:


This program implements a class that will generate graphviz "dot" syntax to facilitate the visualization of output for various data structures. Graphviz is used for "graph visualization" and provides a simple way to visualize linked data structures. The program allows the user to add Nodes and Edges initialized with default attributes stored in a map,and then if desired edit or update these attributes for each selected Node or Edge. These are then Printed in graphviz "dot" syntax as  simple connected Nodes, as a Linked List, as a Doubly Linked List, or a Binary Search Tree. This class only implements a small portion of the features that Graphviz offers and the output is then pasted into the online Graphviz editor.



### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [main.cpp](https://github.com/ErnuelTonge/2143-OOP-Tonge/blob/main/Assignments/P03/main.cpp)        | Main driver of my project                          |
|   2   | [test.out](https://github.com/ErnuelTonge/2143-OOP-Tonge/blob/main/Assignments/P03/test.out)      | Out put file generated using test code             |

### Instructions

This project implements a complete graph container consisting of a vector of Edges, a vector of Nodes. The Graphviz class of this project then prints its contents of this class in one of 4 formats which has to be passed in by the user, the generic format, Linked List format, Doubly Linked List format, Binary Search Tree format. The graph's default is set to drirected = true which prints the first 3 formats but must be change to false during declarationto print in the undirected format for the  Binary Search Tree Graphviz dot code syntax. The Nodes and Edges are then printed to the test.out textfile in Graphviz dot code syntax where it can be coppied and pasted into graphviz.org.

