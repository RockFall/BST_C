///////////////////////////////////////////////////
///                                             ///
///                By RockFall                  ///
///                                             ///
///////////////////////////////////////////////////

#ifndef __HEADER_H_
#define __HEADER_H_

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// Points to a Node
typedef struct NodeType* NodePointer;

// Node - Has a key value and holds it's childs pointers
typedef struct NodeType {
    // Information holded by this node
    int data;
    // Node's childs
    NodePointer left, right;
} NodeType;

// Creates a new tree on this node
void CreateNewTree(NodePointer* root);

// Creates a new node with given data
NodePointer CreateNewNode (int data);

// Add new data in the tree under this node
void AddData(NodePointer* root,int data);

// Remove data from the tree under this node
void RemoveData(NodePointer* root, int data);

// Search given data in the tree under this node
NodePointer SearchData(NodePointer root, int data);


///////////////////////////////////////////////
//      PRINTING RELATED FUNCTIONS          ///
///////////////////////////////////////////////
//
// Returns the number of levels on the tree (root is level 0)
int LevelsCount(NodePointer root, int currentLevel);
//
// Print the tree under this node in PRE-ORDER, IN-ORDER and POST-ORDER
void PrintTreePreOrder(NodePointer root);
void PrintTreeInOrder(NodePointer root);
void PrintTreePostOrder(NodePointer root);
//
// Print the tree in TRANSVERSAL LEVEL ORDER
void PrintTreeAllTransversalLevel(NodePointer root);
void PrintCurrentTransversalLevel(NodePointer root, int level);
int GetHeight(NodePointer root);
//
////////////////////////////////////////////////




/////////////////////////////////////////////////////
//      BEAUTIFUL PRINTING RELATED FUNCTIONS      ///
/////////////////////////////////////////////////////
//            Base code from internet              //
//          Beautiful debug purpose only           //
/////////////////////////////////////////////////////

typedef struct asciinode_struct asciinode;
struct asciinode_struct
{
  asciinode * left, * right;

  //length of the edge from this node to its children
  int edge_length; 
    
  int height;      

  int lablen;

  //-1=I am left, 0=I am root, 1=right   
  int parent_dir;   
                         
  //max supported unit32 in dec, 10 digits max
  char label[11];  
};

asciinode * build_ascii_tree_recursive(NodeType * t);
void free_ascii_tree(asciinode *node) ;
void compute_lprofile(asciinode *node, int x, int y) ;
void compute_rprofile(asciinode *node, int x, int y) ;
void compute_edge_lengths(asciinode *node) ;
void print_level(asciinode *node, int x, int level) ;
void PrintGorgeousTree(NodeType * t) ;

#endif