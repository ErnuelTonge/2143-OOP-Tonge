/*****************************************************************************
*                    
*  Author:           Ernuel Tonge
*  Email:            eetonge0423@my.msutexas.edu
*  Label:            P03
*  Title:            Graphviz Class
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        This program implements a class that will generate graphviz "dot" syntax to facilitate 
*        the visualization of output for various data structures. Graphviz is used for "graph 
*        visualization" and provides a simple way to visualize linked data structures. The  
*        program allows the user to add Nodes and Edges initialized with default attributes  
*        stored in a map,and then if desired edit or update these attributes for each selected 
*        Node or Edge. These are then Printed in graphviz "dot" syntax as  simple connected  
*        Nodes, as a Linked List, as a Doubly Linked List, or a Binary Search Tree. This class  
*        only implements a small portion of the features that Graphviz offers and the output 
*        is then pasted into the online Graphviz editor.
*                 
*        
*  Usage: 
*       - $ ./main filename
*       - This will call functions to add and change various nodes and Edges as defined by 
          the user as well as call the overloaded print function wich will print the  
          structures in different formats depending on arguments given by the user.
*       
*  Files:            
*       main.cpp    : driver program
*       test.out    : output file with print function results 
*****************************************************************************/

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;



 /**
 * Node
 * 
 * Description:
 *      This class creates a node container holding an integer as the 
 *      nodes data value and a map of strings to strings to store the various 
 *      attributes of each node as it is defaulted, initialized and edited. 
 *      Ostream has also been overloaded to allow the nodes attributes to 
 *      be directly printed out. 
 *
 * Public Methods:
 *                          Node()
 *                          Node(int value)
 *                          Node(int dataValue, string key, string value)
 *      void                addAttribute(string key, string val)
 *      void                addAttributes(map<string, string> atts)
 *      ostream             &operator<<(ostream &os, Node &e)
 *      
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 * 
 *    vector<Node> Nodes;                        // creates a vector of Nodes
 *    Nodes.push_back(Node());                   // pushes a new Node onto a 
 *                                                  vector of nodes 
 *    Nodes.push_back(Node(value));              // Adds a new Node with an 
 *                                                  initialived data value
 *    Nodes.push_back(Node(data, key, value));   // Adds a new Node with an 
 *                                                  initialived data value and 
 *                                                  specified attribute
 *      
 */
class Node {

protected:
  map<string, string> att; // attributes

public:
  int data;

    /**
     * Public : Node
     * 
     * Description:
     *      Overloaded constructor. Sets attributes to default values.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
  Node() {
    att["color"] = "black"; // default color
    att["shape"] = "record";   // default arrow shape
    data = 0;
   
  }

    /**
     * Public : Node
     * 
     * Description:
     *      Overloaded constructor. Sets attributes to default values
     *      and allows the user to initalize the data value of the node.
     * 
     * Params:
     *      int     :  node data value
     * 
     * Returns:
     *      Nothing
     */
Node(int value) {
    att["color"] = "black"; // default color
    att["shape"] = "record";   // default arrow shape
    data = value;
  }

    /**
     * Public : Node
     * 
     * Description:
     *      Overloaded constructor. Sets attributes to default values and
     *      allows the user to initalize the data value of the node as well 
     *      as one of its attributes
     * 
     * Params:
     *      int       :  node's data value
     *      string    :  map key 
     *      string    :  map value
     * 
     * Returns:
     *      Nothing
     */
Node(int dataValue, string key, string value){
  att["color"] = "black"; // default color
  att["shape"] = "record";   // default arrow shape
  att[key] = value;
  data = dataValue;
}

    /**
     * Public : addAttribute
     * 
     * Description:
     *      This function recieves a key value pair and uses it
     *      to modify the map of attributes. Assumes key is valid.
     * 
     * Params:
     *      string     :  attribute map key
     *      string     :  attribute map value
     * 
     * Returns:
     *      Nothing
     */
  void addAttribute(string key, string val) { att[key] = val; }

    /**
     * Public : addAttributes
     * 
     * Description:
     *      Takes a map of attributes. Loops over them and saves them
     *      locally.
     * 
    * Params:
     *      map<string, string>    :  map of attributes
     *      
     * 
     * Returns:
     *      Nothing
     */
  void addAttributes(map<string, string> atts) {
    for (auto const &x : atts) {
      cout << x.first << "=" << x.second << endl;
      att[x.first] = x.second;
    }
  }

    /**
     * Public : &operator<<
     * 
     * Description:
     *      Prints Node attributes form the map in Graphviz dot
     *      code
     * 
     * Params:
     *      ostream    :  instance of ostream
     *      Node       :  graph node being printed
     * 
     * Returns:
     *      ostream   : an instance of ostream.
     */
  friend ostream &operator<<(ostream &os, Node &e) {
   
    int i = 0;
    for (auto const &x : e.att) {
      os << x.first << "="
         << "\"" << x.second << "\"";
      if (i < e.att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    os << "]";
    return os;
  }
};

 /**
 * Edge
 * 
 * Description:
 *      This class creates an edge container with holding a map of strings 
 *      to Edge pointers to store the various attributes of each edge as 
 *      it is defaulted, initialized or edited. 
 *      Ostream has also been overloaded to allow the nodes attributes to 
 *      be directly printed out.
 *
 * Public Methods:
 *                          Edge()
 *                          Edge(string color, string arrow)
 *      void                updateAttribute(string key, string val)
 *      void                updateAttribute(map<string, string> atts)
 *      void                updateAttribute(map<string, string> atts)
 *      ostream             &operator<<(ostream &os, Edge &e)
 *      string              getEdgeSide(Edge &e)
 *      void                addAttribute(string key, string value)
 * 
 * Private Methods:
 * 
 * Usage: 
 * 
 *      vector<Edge> Edges;                  // creates a vector of Edges
 *      map<string, Edge *> edges;           // creates a map of strings 
 *                                              to Edge pointers
 *      edges[makeEid(w, v)] = new Edge();   // adds Edge pointer to map 
 *                                              container
 * 
 *      
 */
class Edge {

protected:
map<string, string> att;            // map of attributes

public:

    /**
     * Public : Edge
     * 
     * Description:
     *      Overloaded constructor. Sets attributes to default values.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
  Edge() {
    att["color"] = "black";       // default color
    att["arrow_type"] = "vee";    // default arrow shape
    att["dir"] = "forward";       // default edge direction
    att["side"] = "left";         // default edge position
  }

    /**
     * Public : Edge
     * 
     * Description:
     *      Overloaded constructor. Initializes the color and 
     *      arrow type attribute in the map.
     * 
     * Params:
     *      string    :  color value
     *      string    :  arrow value
     * 
     * Returns:
     *      Nothing
     */
  Edge(string color, string arrow) {
    att["color"] = color;           // initialize color
    att["arrow_type"] = arrow;      // initialize arrow shape
    att["side"] = "left";           // default edge position
  }

    /**
     * Public : updateAttribute
     * 
     * Description:
     *      Update an edge attribute. Assumes key is valid.
     * 
     * Params:
     *      string     :  attribute map key
     *      string     :  attribute map value
     * 
     * Returns:
     *      Nothing
     */
  void updateAttribute(string key, string val) { att[key] = val; }

    /**
     * Public : updateAttribute
     * 
     * Description:
     *      Takes a map of attributes. Loops over them and saves them
     *      locally.
     * 
     * Params:
     *      map<string, string>    :  map of attributes
     * 
     * Returns:
     *      Nothing
     */
  void updateAttribute(map<string, string> atts) {
    for (auto const &x : att) {
      att[x.first] = x.second;
    }
  }


    /**
     * Public : &operator<<
     * 
     * Description:
     *      Prints Edge attributes form the map in Graphviz dot
     *      code
     * 
     * Params:
     *      ostream    :  instance of ostream
     *      Edge       :  graph edge being printed
     * 
     * Returns:
     *      ostream    : an instance of ostream.
     */
  friend ostream &operator<<(ostream &os, Edge &e) {
    os << "[";
    int i = 0;
    for (auto const &x : e.att) {
      if (x.first != "side"){         // prints everything but side attribute
          os << x.first << "=" <<"\""
             <<x.second<<"\"";
          if(i < e.att.size()-2){
            os << ", ";
          }
        i++;
      }
    }
    os <<"]";
    return os;
  }

    /**
     * Public : getEdgeSide
     * 
     * Description:
     *      This function recieves an instance of an Edge and
     *      goes through the attributes and returns the vaule
     *      associated with that key.
     * 
     * Params:
     *      string     :  attribute map key
     *      string     :  attribute map value
     * 
     * Returns:
     *      string     :  the value stored in the map with the "side" key
     */
string getEdgeSide(Edge &e){
  int i = 0;
    for (auto const &x : e.att) {
      if (x.first == "side"){
          return x.second;
        i++;
      }
    }
}

    /**
     * Public : addAttribute
     * 
     * Description:
     *      This function recieves a key value pair and uses it
     *      to modify the map of attributes. 
     * 
     * Params:
     *      string     :  attribute map key
     *      string     :  attribute map value
     * 
     * Returns:
     *      Nothing
     */
void addAttribute(string key, string value) { att[key] = value; }

};

/**
 * Graph
 * 
 * Description:
 *      This class implements a set of Graph functionalities that will
 *      later be inherited by the GraphViz class in including keeping 
 *      track of the number of nodes and edges being added to the graph.
 * 
 * Public Methods:
 *                          Graph(bool directed = true)
 *                          Graph(int V, bool directed = true)
 * 
 * Protected Methods:
 *      void                checkResize(int v)
 * 
 */
class Graph {
protected:
  int V;                   // number of vertices
  bool directed;           // id graph directed or undirected
  vector<vector<int>> adj; // adjacency list

  void checkResize(int v) {
    if (v >= this->V - 1) {
      adj.resize(v + 1);
      this->V = v + 1;
    }
  }

public:
  // Default constructor
  // Params:
  //    bool directed : is graph directed or not
  Graph(bool directed = true) {
    this->V = 0;
    this->directed = directed;
  }

  // Overloaded constructor
  // Params:
  //   int V : number of nodes to be in graph
  //   bool directed : is graph directed or not
  Graph(int V, bool directed = true) {
    this->V = V;
    adj.resize(V);
    this->directed = directed;
  }
};

/**
 * GraphViz
 * 
 * Description:
 *      This class implements a complete graph container consisting of a vector
 *      of Edges, a vector of Nodes, and a map in which to store the attributes
 *      of these nodes and edges. The class stores each node and edge 
 *      indevidually and allows the to add and edit any node, edge or 
 *      attribute. The class then prints the contents of this class in one of 4
 *      formats the generic format, Linked List format, Doubly Linked List  
 *      format, Binary Search Tree format. The graph's default is set to  
 *      drirected = true which prints the first 3 formats but must be change to 
 *      false during declarationto print in the undirected format for the  
 *      Binary Search Tree Graphviz dot code syntax. 
 *
 * 
 * Public Methods:
 *                          GraphViz()
 *                          GraphViz(bool dir)
 *      void                addNode()
 *      void                addNode(int value)
 *      void                addNode(int data, string key, string value)
 *      void                updateNodeAttribute(int index, string key, 
 *                          string value)
 *      void                addEdge(int v, int w)
 *      void                addEdge(int v, int w, string place)
 *      void                editEdge(int from, int to, string key, string val)
 *      void                editEdge(string eid, string key, string val)
 *      void                printGraph(string graphName, string format)
 *      void                printGraph(string format)
 *      void                printGraph()
 * 
 * Private Methods:
 *    string                makeEid(int start, int end)
 * 
 * Usage: 
 * 
 *  GraphViz g                                     // Create Instance of 
                                                       GraphViz
 *  GraphViz g(false);                             // Create instance of 
 *                                                     GraphViz initializing the
 *                                                     graph direction to 
 *                                                     undirectional by passing
 *                                                     in false. 
 *                                                   
 *  g.addNode();                                   // Adds a Node to the Vector
 *                                                     of nodes with all default 
 *                                                     values
 *  g.addNode(1);                                  // Adds Node with 
 *                                                     initialized data value 
 *  g.addNode(7,"color","purple");                 // Add Node with initialized
 *                                                     data value and Node 
 *                                                     Attribute 
 *  g.updateNodeAttribute(2, "color", "red");      // Changes or adds an 
 *                                                     attribute to the node 
 *                                                     specified by the first 
 *                                                     argument  
 *
 *  g.addEdge(0, 1);                               // Adds edge with the nodes
 *                                                     from and to specified by 
 *                                                     two integers respectivly 
 *  g.addEdge(3, 5, "right");                      // Adds edge with the 
 *                                                     attribute side specified,
 *                                                     used to print Binary 
 *                                                     search trees.
 *
 *  g.editEdge(4, 5, "color", "red");              // Change or add edge 
 *                                                     attributes to specific 
 *                                                     edges
 *  g.editEdge(2, 3,"side", "right");               // Change the edge side 
 *                                                     when printing as a Binary
 *                                                     search tree.
 *
 *  g.printGraph();                                // Prints Nodes and Edges 
 *                                                     with generic syntax 
 *  g.printGraph("BST");                           // Prints Nodes and Edges in
 *                                                     the format passed into 
 *                                                     the function as a string
 *                                                     ("LL" Linked List) 
 *                                                     ("DLL" Doubly Linked List)
 *                                                     ("BST" Binary Search Tree) 
 *  g.printGraph("ernuelgraph","BST");             // Prints graph with passed
 *                                                     in graph name and format 
 *                                                     as strings
 *
 *      
 */
class GraphViz : public Graph, public Edge, public Node{
 
  bool directed = true;
  
  vector<Edge> Edges;          // creates a vector of Edges
  vector<Node> Nodes;          // creates a vector of Nodes
  map<string, Edge *> edges;   // container of edge types

    /**
     * Public : makeEid
     * 
     * Description:
     *      Takes start and end points of the edge and
     *      concatenates them into a single string which
     *      is then returned as the edge id and used to
     *      store and locate the edges attributes.
     * 
     * Params:
     *      int     :  start point 
     *      int     :  end point
     * 
     * Returns:
     *      String   : unique edge id.
     */
  string makeEid(int start, int end) {
    return to_string(start) + "-" + to_string(end);
  }

public:
  
  
    /**
     * Public : GraphViz
     * 
     * Description:
     *      Default Constructor
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
  GraphViz() { }

    /**
     * Public : GraphViz
     * 
     * Description:
     *      Constructor setting dirtected variable upon 
     *      instance declaration. Graph must be set to
     *      undirected (directed = false) in order to print 
     *      graph in Binary Search Tree (BST) Graphviz dot 
     *      code format.
     * 
     * Params:
     *      bool    :  graph direction
     * 
     * Returns:
     *      nothing
     */
  GraphViz(bool dir) {
     directed = dir;
    
  }

    /**
     * Public : addNode
     * 
     * Description:
     *      Creates an instance of the Node class and pushes
     *      it onto a vector of Nodes.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
void addNode(){
  //Pushes
  Nodes.push_back(Node());
}

    /**
     * Public : addNode
     * 
     * Description:
     *      Creates an instance of the Node class with 
     *      initialized node data value and pushes it 
     *      onto a vector of Nodes.
     * 
     * Params:
     *      int     :  Node data value
     * 
     * Returns:
     *      Nothing
     */
void addNode(int value){
  //Pushes
  Nodes.push_back(Node(value));
}

    /**
     * Public : addNode
     * 
     * Description:
     *      Creates an instance of the Node class with 
     *      initialized node data value and one attribute
     *      in the form of a key value pair and pushes 
     *      it onto a vector of Nodes.
     * 
     * Params:
     *      int        :  Node data value
     *      string     :  attribute map key
     *      string     :  attribute map value
     * 
     * Returns:
     *      Nothing
     */
void addNode(int data, string key, string value){
  Nodes.push_back(Node(data, key, value));
  
}

    /**
     * Public : addNode
     * 
     * Description:
     *      Access a particular Node in the vector of nodes 
     *      using the index variable and then uses the key 
     *      value pair and the Node member function to access
     *      in the form of a key value pair and pushes 
     *      the attribute in key and set it to value.
     * 
     * Params:
     *      int        :  index of node in the vector
     *      string     :  attribute map key
     *      string     :  attribute map value
     * 
     * Returns:
     *      Nothing
     */
void updateNodeAttribute(int index, string key, string value){
  
  Nodes[index].addAttribute(key, value);
}

    /**
     * Public : addEdge
     * 
     * Description:
     *      Tracks the edges coming from each node and adds 
     *      to the edge adjacency vector the end point that 
     *      each edge will be going to. If the graph is
     *      undirected a second edge will be added from the 
     *      previous endpoint to to the original node.
     * 
     * Params:
     *      int        :  edge start point 
     *      int        :  edge end point
     * 
     * Returns:
     *      Nothing
     */
void addEdge(int v, int w) {
    checkResize(v);
    checkResize(w);

    // add connection from v to w
    adj[v].push_back(w);

    // if undirected, we add an edge gong from w to v as well.
    if (!directed) {
      adj[w].push_back(v);
      edges[makeEid(w, v)] = new Edge();
    }

    // add an edge type for graphviz
    edges[makeEid(v, w)] = new Edge();
    
}

    /**
     * Public : addEdge
     * 
     * Description:
     *      Tracks the edges coming from each node and adds 
     *      to the edge adjacency vector the end point that 
     *      each edge will be going to. If the graph is
     *      undirected a second edge will be added from the 
     *      previous endpoint to to the original node. This 
     *      function also allows the user to set the side of
     *      the node from which the node will start. This is
     *      used when printing as a Binary search Tree.
     * 
     * Params:
     *      int        :  edge start point 
     *      int        :  edge end point
     *      string     :  value for attribute side
     * 
     * Returns:
     *      Nothing
     */
void addEdge(int v, int w, string place) {
  
    checkResize(v);
    checkResize(w);

    // add connection from v to w
    adj[v].push_back(w);

    // if undirected, we add an edge gong from w to v as well.
    if (!directed) {
      adj[w].push_back(v);
    }

    // add an edge type for graphviz
    edges[makeEid(v, w)] = new Edge();
 
  // changes the side from default to user defined
  editEdge(v, w, "side", place);
  
}

    /**
     * Public : editEdge
     * 
     * Description:
     *      Uses variables from and to in order to create a
     *      unique id which is then used to acces the attributes
     *      of a specific edge and change it using the key value pair.
     * 
     * Params:
     *      int        :  edge start point 
     *      int        :  edge end point
     *      string     :  attribute map key
     *      string     :  attribute map value
     * 
     * Returns:
     *      Nothing
     */
void editEdge(int from, int to, string key, string val) { 
  editEdge(makeEid(from, to), key, val);
  }

    /**
     * Public : editEdge
     * 
     * Description:
     *      Uses alredy established edge id passed in as a string 
     *      argument (eid ) and is then used to acces the attributes
     *      of a specific edge and change it using the key value pair.
     * 
     * Params:
     *      string     :  edge id
     *      string     :  attribute map key
     *      string     :  attribute map value
     * 
     * Returns:
     *      Nothing
     */
void editEdge(string eid, string key, string val) {
    edges[eid]->updateAttribute(key, val); 
  }

    /**
     * Public : printGraph
     * 
     * Description:
     *      Prints contents of GraphViz instance in the format
     *      passed by the user as a string. If the passed string 
     *      is "LL" then the Graphviz dot format will take the
     *      form of a Linked List, "DLL" will give Doubly Linked
     *      List format, and "BST" will print in Binary Search
     *      Tree format. If the shape attribute is changed in any
     *      of these formats then the format will be disrupted
     *      In order for the DLL format to print correctly the
     *      directed variable must be changed at initialization
     *      This function prints both to the screen and to a file.
     *      This function also allows the name of the graph to 
     *      be changed to something user defined. 
     * 
     * Params:
     *      string     :  graph name 
     *      string     :  graph print format 
     * 
     * Returns:
     *      Nothing
     */
void printGraph(string graphName, string format) {
  ofstream fout;
  fout.open ("test.out");

  cout << "Name: Ernuel Tonge" << endl 
       << "Date: 03/09/2023" << endl 
       << "Fall 2143" << endl << endl;
  
  fout << "Name: Ernuel Tonge" << endl 
       << "Date: 03/09/2023" << endl 
       << "Fall 2143" << endl << endl;
  
  cout << "digraph " << graphName << " {\n";
  fout << "digraph " << graphName << " {\n";
  
    if (format == "LL"){
      if (Nodes.size() > 0)
      {
        
        cout << "\t" << "rankdir=LR;" << endl;
        fout << "\t" << "rankdir=LR;" << endl;
        // Loops through vector of Nodes and outputs to console
        for (int i = 0; i < Nodes.size(); i++) {
          
          string firstPart = "[label=\"{ <data> ";
          string secondPart = " | <next>  }\",";
          cout << "\t" << i << " "
               << firstPart << Nodes[i].data << secondPart
               << "  " << Nodes[i] << endl;

          fout << "\t" << i << " "
               << firstPart << Nodes[i].data << secondPart
               << "  " << Nodes[i] << endl;
        } 
      }
      
      if (edges.size() > 0)
      {
        
        for (int v = 0; v < V; v++) {
          if(adj[v].size()){
          
            for (auto i : adj[v]) {
              cout << "\t" << v << ":next:c -> "
                   << i << ":data " << *edges[makeEid(v, i)] << " "
                   << endl;
  
              fout << "\t" << v << ":next:c -> "
                   << i << ":data " << *edges[makeEid(v, i)] << " "
                   << endl;
            }
          }
        }
      cout << "\t" << (V-1) << ":next:e -> NULL" << endl;
      fout << "\t" << (V-1) << ":next:e -> NULL" << endl;
      }
        
    }
    else if (format == "DLL"){
      if (Nodes.size() > 0)
      {
       
        cout << "\t" << "rankdir=LR;" << endl;
        fout << "\t" << "rankdir=LR;" << endl;
        // Loops through vector of Nodes and outputs to console
        for (int i = 0; i < Nodes.size(); i++) {
          string firstPart = "[label=\"{ <prev> | <data> ";
          string secondPart = " | <next>  }\",";
          cout << "\t" << i << " "
               << firstPart << Nodes[i].data << secondPart
               << "  " << Nodes[i] << endl;

          fout << "\t" << i << " "
               << firstPart << Nodes[i].data << secondPart
               << "  " << Nodes[i] << endl;
        }
        cout << "\n";
        fout << "\n";
      }
        
      if (edges.size() > 0)
      {
         
        cout << "\t" << "0:prev -> null" << endl;
        fout << "\t" << "0:prev -> null" << endl;
         int j = 0;
         for (int v = 0; v < V; v++) {
           
              if(adj[v].size()){
                
                  for (auto i : adj[v]) {
                    if ( j % 2 == 0){    
                      cout << "\t" << v << ":next:n -> "
                           << i << ":prev " << *edges[makeEid(v, i)] << " "
                           << endl;

                      fout << "\t" << v << ":next:n -> "
                           << i << ":prev " << *edges[makeEid(v, i)] << " "
                           << endl;
                        j++;
                    }
                    else if ( j % 2 == !0){             // prints every other 
                                                        // edge as a return to
                                                        // the previous node
                      
                      cout << "\t" << v << ":prev:s -> "
                           << i << ":next " << *edges[makeEid(v, i)] << " "
                           << endl;
                      
                      fout << "\t" << v << ":prev:s -> "
                           << i << ":next " << *edges[makeEid(v, i)] << " "
                           << endl;
                      j++;
                    }
                  }
              }
          }
        cout << "\t" << (V-1) << ":next:e -> NULL" << endl;
        fout << "\t" << (V-1) << ":next:e -> NULL" << endl;
      }   
    }
    else if (format == "BST"){
      if (Nodes.size() > 0)
      {
          //printNodesBST();
        cout << "\t" << "rankdir=TB;" << endl;
        fout << "\t" << "rankdir=TB;" << endl;
          // Loops through vector of Nodes and outputs to console
          for (int i = 0; i < Nodes.size(); i++) {
            string firstPart = "[label=\"{ <data> ";
            string secondPart = " | { <left> | <right> } }\",";
            
            cout << "\t" << i << " "
                 << firstPart << Nodes[i].data << secondPart
                 << "  " << Nodes[i] << endl;

            fout << "\t" << i << " "
                 << firstPart << Nodes[i].data << secondPart
                 << "  " << Nodes[i] << endl;
          }
        cout << "\n";
        fout << "\n";
      }
        
      if (edges.size() > 0)
      {
        //printEdgesBST();
        for (int v = 0; v < V; v++) {
          if(adj[v].size()){
              
            for (auto i : adj[v]) {
                                          // retrives side attributes value 
                                          // form the map for each edge
                string side = getEdgeSide(*edges[makeEid(v, i)]);
                
              cout << "\t" << v << ":" << side << ":c -> "
                     << i << " " << *edges[makeEid(v, i)] << " " << endl;

              fout << "\t" << v << ":" << side << ":c -> "
                     << i << " " << *edges[makeEid(v, i)] << " " << endl;
            }
             
          }
        } 
      }
        
    }
  cout << "}\n\n";
  fout << "}\n\n";
}

    /**
     * Public : printGraph
     * 
     * Description:
     *      Prints contents of GraphViz instance in the format
     *      passed by the user as a string. If the passed string 
     *      is "LL" then the Graphviz dot format will take the
     *      form of a Linked List, "DLL" will give Doubly Linked
     *      List format, and "BST" will print in Binary Search
     *      Tree format. If the shape attribute is changed in any
     *      of these formats then the format will be disrupted
     *      In order for the DLL format to print correctly the
     *      directed variable must be changed at initialization
     *      This function prints both to the screen and to a file.
     * 
     * Params:
     *      string     :  graph print format 
     * 
     * Returns:
     *      Nothing
     */
void printGraph(string format) {
  ofstream fout;
  fout.open ("test.out");


  cout << "Name: Ernuel Tonge" << endl 
       << "Date: 03/09/2023" << endl 
       << "Fall 2143" << endl << endl;
  
  fout << "Name: Ernuel Tonge" << endl 
       << "Date: 03/09/2023" << endl 
       << "Fall 2143" << endl << endl;
  
  cout << "digraph " << "somegraph" << " {" << endl;
  fout << "digraph " << "somegraph" << " {" << endl;
  
    if (format == "LL"){
      if (Nodes.size() > 0)
      {
        
        cout << "\t" << "rankdir=LR;" << endl;
        fout << "\t" << "rankdir=LR;" << endl;
        // Loops through vector of Nodes and outputs to console
        for (int i = 0; i < Nodes.size(); i++) {
          
          string firstPart = "[label=\"{ <data> ";
          string secondPart = " | <next>  }\",";
          cout << "\t" << i << " "
               << firstPart << Nodes[i].data << secondPart
               << "  " << Nodes[i] << endl;

          fout << "\t" << i << " "
               << firstPart << Nodes[i].data << secondPart
               << "  " << Nodes[i] << endl;
        } 
      }
      
      if (edges.size() > 0)
      {
        
        for (int v = 0; v < V; v++) {
          if(adj[v].size()){
          
            for (auto i : adj[v]) {
              cout << "\t" << v << ":next:c -> "
                   << i << ":data " << *edges[makeEid(v, i)] << " "
                   << endl;
  
              fout << "\t" << v << ":next:c -> "
                   << i << ":data " << *edges[makeEid(v, i)] << " "
                   << endl;
            }
          }
        }
      cout << "\t" << (V-1) << ":next:e -> NULL" << endl;
      fout << "\t" << (V-1) << ":next:e -> NULL" << endl;
      }
        
    }
    else if (format == "DLL"){
      if (Nodes.size() > 0)
      {
        
        cout << "\t" << "rankdir=LR;" << endl;
        fout << "\t" << "rankdir=LR;" << endl;
        // Loops through vector of Nodes and outputs to console
        for (int i = 0; i < Nodes.size(); i++) {
          string firstPart = "[label=\"{ <prev> | <data> ";
          string secondPart = " | <next>  }\",";
          cout << "\t" << i << " "
               << firstPart << Nodes[i].data << secondPart
               << "  " << Nodes[i] << endl;

          fout << "\t" << i << " "
               << firstPart << Nodes[i].data << secondPart
               << "  " << Nodes[i] << endl;
        }
        cout << "\n";
        fout << "\n";
      }
        
      if (edges.size() > 0)
      {
         
        cout << "\t" << "0:prev -> null" << endl;
        fout << "\t" << "0:prev -> null" << endl;
         int j = 0;
         for (int v = 0; v < V; v++) {
           
              if(adj[v].size()){
                
                  for (auto i : adj[v]) {
                    if ( j % 2 == 0){
                      cout << "\t" << v << ":next:n -> "
                           << i << ":prev " << *edges[makeEid(v, i)] << " "
                           << endl;

                      fout << "\t" << v << ":next:n -> "
                           << i << ":prev " << *edges[makeEid(v, i)] << " "
                           << endl;
                        j++;
                    }
                    else if ( j % 2 == !0){
                      cout << "\t" << v << ":prev:s -> "
                           << i << ":next " << *edges[makeEid(v, i)] << " "
                           << endl;
                      
                      fout << "\t" << v << ":prev:s -> "
                           << i << ":next " << *edges[makeEid(v, i)] << " "
                           << endl;
                      j++;
                    }
                  }
              }
          }
        cout << "\t" << (V-1) << ":next:e -> NULL" << endl;
        fout << "\t" << (V-1) << ":next:e -> NULL" << endl;
      }   
    }
    else if (format == "BST"){
      if (Nodes.size() > 0)
      {
        
        cout << "\t" << "rankdir=TB;" << endl;
        fout << "\t" << "rankdir=TB;" << endl;
          // Loops through vector of Nodes and outputs to console
          for (int i = 0; i < Nodes.size(); i++) {
            string firstPart = "[label=\"{ <data> ";
            string secondPart = " | { <left> | <right> } }\",";
            
            cout << "\t" << i << " "
                 << firstPart << Nodes[i].data << secondPart
                 << "  " << Nodes[i] << endl;

            fout << "\t" << i << " "
                 << firstPart << Nodes[i].data << secondPart
                 << "  " << Nodes[i] << endl;
          }
        cout << "\n";
        fout << "\n";
      }
        
      if (edges.size() > 0)
      {
        
        for (int v = 0; v < V; v++) {
          if(adj[v].size()){
              
            for (auto i : adj[v]) {
                string side = getEdgeSide(*edges[makeEid(v, i)]);
                
              cout << "\t" << v << ":" << side << ":c -> "
                     << i << " " << *edges[makeEid(v, i)] << " " << endl;

              fout << "\t" << v << ":" << side << ":c -> "
                     << i << " " << *edges[makeEid(v, i)] << " " << endl;
            }
             
          }
        } 
      }
        
    }
  cout << "}\n\n";
  fout << "}\n\n";
}

    /**
     * Public : printGraph
     * 
     * Description:
     *      Prints contents of GraphViz instance in the generic 
     *      format as simple nodes connected by simple 
     *      edges. This format is the only one in which the shape
     *      attribute can be freely changed without affecting the
     *      formatting. This function prints both to the screen
     *      and to a file.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
void printGraph() {
  ofstream fout;
  fout.open ("test.out");


  cout << "Name: Ernuel Tonge" << endl 
       << "Date: 03/09/2023" << endl 
       << "Fall 2143" << endl << endl;
  
  fout << "Name: Ernuel Tonge" << endl 
       << "Date: 03/09/2023" << endl 
       << "Fall 2143" << endl << endl;
  
  cout << "digraph " << "somegraph" << " {" << endl;
  fout << "digraph " << "somegraph" << " {" << endl;
  
    
      if (Nodes.size() > 0)
      {
      
        cout << "\t" << "rankdir=LR;" << endl;
        fout << "\t" << "rankdir=LR;" << endl;
        // Loops through vector of Nodes and outputs to console
        for (int i = 0; i < Nodes.size(); i++) {
          
          cout << "\t" << i << "  [" << Nodes[i] << endl;
          fout << "\t" << i << "  [" << Nodes[i] << endl;

        } 
      }
      
      if (edges.size() > 0)
      {
        //printEdges();
        for (int v = 0; v < V; v++) {
          if(adj[v].size()){
          
            for (auto i : adj[v]) {
              cout << "\t" << v << " -> "
                   << i << " " << *edges[makeEid(v, i)] << " "
                   << endl;
  
              fout << "\t" << v << " -> "
                   << i << " " << *edges[makeEid(v, i)] << " "
                   << endl;
            }
          }
        }
      cout << "\t" << (V-1) << " -> NULL" << endl;
      fout << "\t" << (V-1) << " -> NULL" << endl;
      }
        
  cout << "}\n\n";
  fout << "}\n\n";
}


};

int main() {
  
  
//===============================================================
  //Prints graph in generic format
  GraphViz g;
  
  g.addNode();
  g.addNode(1);
  g.addNode(2);
  g.addNode(3);
  g.addNode(7,"color","purple");
  g.addNode(4);
  g.addNode(5);
 
  //key and value must be entered as strings using " ".
  g.updateNodeAttribute(2, "color", "red");
  g.updateNodeAttribute(2, "xlabel", "2nd Node");
  g.updateNodeAttribute(2, "shape", "star");
  g.updateNodeAttribute(4, "shape", "star");
  g.updateNodeAttribute(2, "fillcolor", "turquoise");
  g.updateNodeAttribute(2, "style", "filled");

  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(5, 6);
  

  g.editEdge(4, 5, "color", "red");
  g.editEdge(4, 5, "arrow_type", "block");
  g.editEdge(4, 5, "dir", "both");

  g.printGraph();
//===============================================================
  // Print in linked list format. Pass string "LL" into print function
  GraphViz a;

  a.addNode();
  a.addNode(1);
  a.addNode(2);
  a.addNode(3);
  a.addNode(7,"color","purple");
  a.addNode(4);
  a.addNode(5);
  
  a.addEdge(0, 1);
  a.addEdge(1, 2);
  a.addEdge(2, 3);
  a.addEdge(3, 4);
  a.addEdge(4, 5);
  a.addEdge(5, 6);

  a.editEdge(4, 5, "color", "red");
  a.editEdge(4, 5, "arrow_type", "block");
  a.editEdge(4, 5, "dir", "both");
  
  a.printGraph("LinkedListGraph","LL");
//===============================================================
  // Print in linked list format. Pass string "DLL" into print function
  // Edges only need to be added in a single direction.
  
  GraphViz b(false); // Must set in order to print the Double Linked List.

  b.addNode();
  b.addNode(1);
  b.addNode(2);
  b.addNode(3);
  b.addNode(7,"color","purple");
  b.addNode(4);
  b.addNode(5);
  
  b.addEdge(0, 1);
  b.addEdge(1, 2);
  b.addEdge(2, 3);
  b.addEdge(3, 4);
  b.addEdge(4, 5);
  b.addEdge(5, 6);
  
  // Edges must be added before they can be edited 
  b.editEdge(4, 5, "color", "red");
  b.editEdge(4, 5, "arrow_type", "block");
  b.editEdge(3, 4, "dir", "both");
  
  b.printGraph("DoublyLinkedListGraph","DLL");

//===============================================================
  GraphViz d;

  d.addNode();
  d.addNode(1);
  d.addNode(2);
  d.addNode(3);
  d.addNode(7,"color","purple");
  d.addNode(4);
  d.addNode(5);

  d.addEdge(0, 1, "left");
  d.addEdge(0, 2);
  d.addEdge(2, 3, "right");
  d.addEdge(2, 4, "right");
  d.addEdge(1, 5, "right");
  d.addEdge(5, 6, "left");

  d.editEdge(0, 1,"side", "right");
  d.editEdge(0, 2,"side", "left");
  d.editEdge(2, 3,"side", "right");
  d.editEdge(2, 4,"side", "left");
  
  d.printGraph("BinarySearchTreeGraph","BST");

//===============================================================


  return 0;
}