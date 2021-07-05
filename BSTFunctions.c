///////////////////////////////////////////////////
///                                             ///
///                By RockFall                  ///
///                                             ///
///////////////////////////////////////////////////

#include "BSTHeader.h"

// Creates a new tree on this node
void CreateNewTree(NodePointer* root){
    *root = NULL;
}

// Creates a new node with given data
NodePointer CreateNewNode (int data){
    // Creates and allocates a new Node
    NodePointer temp = (NodePointer)malloc(sizeof(NodeType));

    // Add Node's data and null childs
    temp->data = data;
    temp->left = temp->right = NULL;

    // Return the new node
    return temp;
}

// Add new data in the tree under this node
void AddData(NodePointer* root,int data){

    // Adds it to current node
    if (*root == NULL){
        *root = CreateNewNode(data);
        return;
    }

    if ((*root)->data < data){
        AddData(&((*root)->right), data);
    }else if ((*root)->data > data){
        AddData(&((*root)->left), data);
    }
}



// Remove data from the tree under this node
void RemoveData(NodePointer* root, int data){

}

// Search given data in the tree under this node
NodePointer SearchData(NodePointer root, int data){
    // If NULL or data in the first node, return
    if (root == NULL || root->data == root->data){
        return root;
    }

    // Key is greater than root's key 
    if (root->data < data) 
       return SearchData(root->right, data); 
  
    // Key is smaller than root's key 
    return SearchData(root->left, data); 
}

// Prints the tree in In-Order (crescent order)
void PrintTreeInOrder(NodePointer root){

    if (root != NULL){
        PrintTreeInOrder(root->left);
        printf("%d \n", root->data);
        PrintTreeInOrder(root->right);  
    }
}

// Prints the tree in Pre-Order (depth-first)
void PrintTreePreOrder(NodePointer root){
    if (root != NULL){
        printf("%d \n", root->data);
        PrintTreePreOrder(root->left);
        PrintTreePreOrder(root->right);  
    }
}

// Prints the tree in Post-Order (breadth-first)
void PrintTreePostOrder(NodePointer root){
    if (root != NULL){
        PrintTreePostOrder(root->left);
        PrintTreePostOrder(root->right);  
        printf("%d\n", root->data);
    }
}

// Prints all levels of a tree
void PrintTreeAllTransversalLevel(NodePointer root){
    for (int d = 1; d <= GetHeight(root); d++){
        // Print every level of the ttree
        PrintCurrentTransversalLevel(root, d);
    }
}

// Prints a given level of a tree
void PrintCurrentTransversalLevel(NodePointer root, int level){
    if (root == NULL){
        // NULL node, let's get the heck out of here
        return;
    }
    if (level == 1){
        // If current level is 1, this level is the target level, print it
        printf("%d\n", root->data);
    } else if (level > 1){
        // Goes down the tree until reach target level
        PrintCurrentTransversalLevel(root->left, level - 1);
        PrintCurrentTransversalLevel(root->right, level - 1);
    }
}

// Return the number of transversal levels of the tree
int GetHeight(NodePointer root){
    if (root == NULL){
        // NULL root bruh, get back
        return 0;
    } else {
        // Height of each subtree
        int lHeight = GetHeight(root->left); 
        int rHeight = GetHeight(root->right); 
  
        // use the larger one
        if (lHeight > rHeight) 
            return(lHeight+1); 
        else return(rHeight+1); 
    }
}


/////////////////////////////////////////////////////////////////////////////
