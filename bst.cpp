#include "bst.h"

bst::bst(){root = NULL;}

void bst::build() {
  srand((unsigned)time(0));
  int arrayLength = rand()%5+10;
  int values[arrayLength];
  for (int a = 0; a < arrayLength; a++){values[a] = -1;}
  for (int a = 0; a < arrayLength; a++) {
    bool duplicate = false;
    do {
      duplicate = false;
      values[a] = rand()%30+1;
      for (int b = 0; b < arrayLength; b++) {
        if ((a != b) && (values[a] == values[b])) {duplicate = true;}
      }
    } while (duplicate == true);
  }
  for (int a = 0; a < arrayLength; a++) {
    node* newnode = new node();
    newnode->data = values[a];
    node* current = root;
    if (root == NULL) {
      root = newnode;
    }
    else {
      while(current != NULL) {
        if (newnode->data < current->data) {
          if (current->left == NULL) {
            current->left = newnode;
	    break;
	  }
	  else {
            current = current->left;
	  }
	}
	else {
          if (current->right == NULL) {
            current->right = newnode;
	    break;
	  }
	  else {
            current = current->right;
	  }
	}
      }
    }
  }
}

void bst::display_tree(node* current, int level) {
  if (current->right != NULL) {display_tree(current->right, level+1);}
  for (int a = 0; a < level; a++) {cout << "\t";}
  cout << current->data << " (";
  if (current->left != NULL) cout << current->left->data << ",";
  else cout << ",";
  if (current->right != NULL) cout << current->right->data << ")" << endl;
  else cout << ")" << endl;
  if (current->left != NULL) {display_tree(current->left, level+1);}
}

void bst::display() {
  cout << "---------Tree Printout----------" << endl;
  display_tree(root, 0);
  cout << "--------------------------------" << endl;
}

//---------------------------------------------------------------------------------------------------



node* bst::getRoot() {
  return root;
}



//function to count number of nodes in BST
int bst::countNodes(node* root)
{
  if (root == NULL) {
    return 0;
  }
  //otherwise
  return 1 + countNodes(root->left) + countNodes(root->right);
}



//function to count the number of leaves (nodes with no children) in BST
int bst::countLeaves(node* root)
{
  if (root == NULL) {
    return 0;
  }

  if (root->right == NULL & root->left == NULL) {
    return 1;
  }
  else {
    return countLeaves(root->right) + countLeaves(root->left);
  }

}



//function to count and return the number of times a given number num occurs in BST
int bst::countNumOccurrence(node* root, int num)
{
  if (root == NULL) {
    return 0;
  }
  else if (root->data == num) {
    return countNumOccurrence(root->left, num) + 1 + countNumOccurrence(root->right, num);
  }
  else {
    return countNumOccurrence(root->left, num) + countNumOccurrence(root->right, num);
  }

}



//function to find second largest node
//when this function is first called in main, count should be passed in as 0
//https://www.geeksforgeeks.org/second-largest-element-in-binary-search-tree-bst/
void bst::secondLargest(node* root, int & count)
{
  if (count >=2 || root == NULL) {
    return;
  }

  secondLargest(root->right, count);
  count++;

  if (count == 2) {
    cout << "Second Largest Element: " << root->data << endl;
    return;
  }

  secondLargest(root->left, count);
}








/* function to remove the smallest value (the "most left leaf" child) and return the new root
2 DELETION CASES
CASE 1: The leaf has a right child (there can't be a left child node because that would be smaller). In that case, replace the current left node with the smallest node of the right subtree.
CASE 2: The leaf has no child nodes. In that case set the according entry in the parent to null.

To call in main:
node* p;
object.removeSmallest(object.getRoot(), p);
*/
void bst::removeSmallest(node* current, node* parent)
{
  if(current->left == NULL){ //leftmost (smallest node) found
    if(current->right != NULL){ //CASE 1: right child
      if(current == root){ //smallest is root
        root = current->right;
        delete current;
        return;
      }
      else { //smallest is not root
        cout << current->data << " has a right child" << endl;
        parent->left = current->right;
        delete current;
        return;
      }
    }
    else if(current->right == NULL){ //CASE 2: no childrem
      cout << current->data << " is a leaf node" << endl;
      parent->left = NULL;
      delete current;
      return;
    }
  }

  if(current->left != NULL){ //if smallest node not yet found, keep traversing
    removeSmallest(current->left, current);
  }

  return;
}





//function to delete 2 smallest nodes in BST
//current is initially passed in as root in the main function
//parent is initially passed in as an empty node (ex. declare node* p; in main and then pass in p)
//count is initially passed in as 0
void bst::delete2Smallest(node* current, node* parent, int & count)
{  
  if(current->left == NULL){

    if(current->right != NULL){
      if(current == root){
        root = current->right;
        delete current;
        current = root;
        count+=1;
      }
      else{
        cout << current->data << " has a right child" << endl;
        parent->left = current->right;
        delete current;
        current = root;
        count+=1;
      }
    }

    else if(current->right == NULL){
      cout << current->data << " is a leaf node" << endl;
      parent->left = NULL;
      delete current;
      current = root;
      count+=1;
    }

  }

  if(current->left != NULL && count < 2){
    delete2Smallest(current->left, current, count);
  }

  return;

}




//function to remove largest node
//current and parent both initially passed in as root when calling this function from main
//have to keep track of its parent, so you can update the parent's right pointer (set it to NULL)
void bst::removeLargest(node* current, node* parent){

  if(current->right == NULL){
    if(current->left != NULL){ //CASE 1: has left child
      if(current == root){ //largest is root
        cout << "Deleting: " << current->data << endl;
        root = current->left;
        delete current;
        return;
      }
      else { //largest is not root
        cout << "Deleting: " << current->data << endl;
        parent->right = current->left;
        delete current;
        return;
      }
    }
    else if(current->left == NULL){ //CASE 2: no children
      cout << "Deleting: " << current->data<< endl;
      parent->right = NULL;
      delete current;
      return;
    }
  }

  if(current->right != NULL){
    removeLargest(current->right, current);
  }

} //end of function




/* function to delete 2 largest nodes
To call in main:
  int deleted_count = 0;
  node* p;
  object.delete2Smallest(object.getRoot(), p, deleted_count);
*/
void bst::delete2Largest(node* current, node* parent, int & count) 
{  
  if(current->right == NULL){
    if(current->left != NULL){ //CASE 1: has left child
      if(current == root){ //largest is root
        root = current->left;
        delete current;
        current = root;
        count+=1;
      }
      else{ //largest is not root
        cout << current->data << " has a left child" << endl;
        parent->right = current->left;
        delete current;
        current = root;
        count+=1;
      }
    }

    else if(current->left == NULL){ //CASE 2: no children
      cout << current->data << " is a leaf node" << endl;
      parent->right = NULL;
      delete current;
      current = root;
      count+=1;
    }

  }

  if(current->right != NULL && count < 2){
    delete2Largest(current->right, current, count);
  }

  return;
}





//function to delete all nodes except root in bst
void bst::delete_all() {
  if (root != NULL) {
    delete_util(root->left);
    delete_util(root->right);
    root->left = NULL;
    root->right = NULL;

  }
}

void bst::delete_util(node* current) {
  if (current != NULL && current->left != NULL) {
    delete_util(current->left);
  }
  if (current != NULL && current->right != NULL) {
    delete_util(current->right);
  }

  if (current != NULL) {
    delete current;
  }

}





//function to delete all nodes larger than root in bst
void bst::delete_right() {
  if (root != NULL) {
    delete_util(root->right);
    root->right = NULL;

  }
}

void bst::delete_right_util(node* current) {
  if (current != NULL && current->right != NULL) {
    delete_util(current->right);
  }

  if (current != NULL) {
    delete current;
  }

}





/* This function traverses tree 
in post order to delete each 
and every node of the tree */
void bst::deleteTree(node* root) 
{ 
    if (root == NULL) return; 
  
    /* first delete both subtrees */
    deleteTree(root->left); 
    deleteTree(root->right); 
      
    /* then delete the node */
    cout << "\n Deleting node: " << root->data; 
    delete root;
} 
  




/* Function to find sum of all the elements*/
int bst::find_sum(node* root)
{
    if (root == NULL)
        return 0;
    return (root->data + find_sum(root->left) + find_sum(root->right));
}





/*
find sum of all the levels in a BST
https://www.geeksforgeeks.org/sum-of-all-the-levels-in-a-binary-search-tree/
MAIN:
  int levels = object.maxDepth(object.getRoot()) + 1; //Count of levels in the given binary tree
  int sum[levels] = { 0 }; // To store the sum at every level
  object.calculateLevelSum(object.getRoot(), 0, sum);
  object.printArr(sum, levels); // Print the required sums
*/
// Utility function to print the contenets of an array
void bst::printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

//function to find the height of a binary tree
int bst::maxDepth(node* root)
{
  if (root == NULL) {
    return 0;
  }
  else {
    //compute depth of each subtree
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    //use the larger one
    if (left_depth > right_depth) {
      return (left_depth + 1);
    }
    else {
      return (right_depth + 1);
    }
  }
} //end of function
 

// Recursive function to update sum[] array
// such that sum[i] stores the sum
// of all the elements at ith level
void bst::calculateLevelSum(node* node, int level, int sum[])
{
    if (node == NULL)
        return;
  
    // Add current node data to the sum
    // of the current node's level
    sum[level] += node->data;
  
    // Recursive call for left and right sub-tree
    calculateLevelSum(node->left, level + 1, sum);
    calculateLevelSum(node->right, level + 1, sum);
}






/*
//function to find and display the root's in-order predecessor
//the in-order predecessor is the previous greater element in a binary search tree 
//https://www.techiedelight.com/find-inorder-predecessor-given-key-bst/
void bst::inOrderPredecessor(node* root, int & count)
{

}
*/




//function to find and return the smallest node
node* bst::findSmallest(node* root) {
  if (root->left != NULL) {
    return findSmallest(root->left);
  }
  return root;
}


//function to find and display the root's in-order successor
//the in-order successor is the next node in in-order traversal (smallest in the right subtree)
//a node's in-order successor is the node with the least value in the right subtree 
//aka the right subtree's leftmost child
//https://www.techiedelight.com/find-inorder-successor-given-key-bst/
void bst::inOrderSuccessor(node* root, node* & succ, int key)
{
  // base case
  if (root == NULL)
  {
      succ = NULL;
      return;
  }

  // if a node with the desired value is found, the successor is the minimum value
  // node in its right subtree (if any)
  if (root->data == key)
  {
      if (root->right) {
          succ = findSmallest(root->right);
      }
  }
  // if the given key is less than the root node, recur for the left subtree
  else if (key < root->data)
  {
      // update successor to the current node before recursing in the left subtree
      succ = root;
      inOrderSuccessor(root->left, succ, key);
  }

  // if the given key is more than the root node, recur for the right subtree
  else {
      inOrderSuccessor(root->right, succ, key);
  }
  
}





//------------------------remove all nodes outside a given range
//https://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/



//-----------------------clone binary tree
//https://www.techcrashcourse.com/2016/06/c-program-to-create-duplicate-binary-tree.html




//------------------------------BST TRAVERSAL------------------------------

/* Given a binary tree, print its nodes in preorder
PREORDER:
void traverse_preorder(node* root)
{
  If tree is not empty, then...
    Visit node at root (maybe display)
    traverse_preorder(left subtree) until NULL
    traverse_preorder(right subtree) until NULL
}
*/
void bst::printPreorder(node* n)
{
    if (n == NULL)
        return;
 
    /* first print data of node */
    cout << n->data << " ";
 
    /* then recur on left sutree */
    printPreorder(n->left);
 
    /* now recur on right subtree */
    printPreorder(n->right);
}



/* Given a binary tree, print its nodes in inorder
INORDER
void traverse_inorder(node* root)
{
  If tree is not empty, then...
    traverse_inorder(left subtree) until NULL
    Visit node at root (maybe display)
    traverse_inorder(right subtree) until NULL
}
*/
void bst::printInorder(node* n)
{
  if (n == NULL)
        return;
 
    /* first recur on left child */
    printInorder(n->left);
 
    /* then print the data of node */
    cout << n->data << " ";
 
    /* now recur on right child */
    printInorder(n->right);
}



/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. 
POSTORDER:
void traverse_postorder(node* root)
{
  If tree is not empty, then...
    traverse_postorder(left subtree) until NULL
    traverse_preorder(right subtree) until NULL
    Visit node at root (maybe display)
}
*/
void bst::printPostorder(node* n)
{
    if (n == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(n->left);
 
    // then recur on right subtree
    printPostorder(n->right);
 
    // now deal with the node
    cout << n->data << " ";
}


//-------------------------------------------------------------------------



//function to remove node from tree
node* bst::remove_node(node* root, int num) {

  if (root->data > num) {
    root->left = remove_node(root->left, num);
  }
  else if (root->data < num) {
    root->right = remove_node(root->right, num);
  }
  else { //match found
    if (root->left == NULL) {
      node* temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      node* temp = root->left;
      delete root;
      return temp;
    }
    else { //case for two children
      node* temp = findSmallest(root->right); //store in order successor into temp
      root->data = temp->data; //copy in order successor into root
      root->right = remove_node(root->right, temp->data); //delete in order successor
    }
    
  }

  return root;
}

