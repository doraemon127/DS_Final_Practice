//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
    	//These functions are supplied already
    	bst();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */

        node* getRoot();

        void printArr(int arr[], int n);
        int maxDepth(node* root);
        void calculateLevelSum(node* node, int level, int sum[]);

        int countNodes(node* root);
        int countLeaves(node* root);
        int countNumOccurrence(node* root, int num);
        int find_sum(node* root);

        void printPreorder(node* n);
        void printInorder(node* n);
        void printPostorder(node* n);

        //void inOrderPredecessor(node* root, int & count);
        //void inOrderSuccessor(node* root, int & count);
        node* findSmallest(node* root);
        void inOrderSuccessor(node* root, node* & succ, int key);

        node* remove_node(node* root, int num);

        void secondLargest(node* root, int & count);

        void removeSmallest(node* current, node* parent);
        void delete2Smallest(node* current, node* parent, int & count); //2 smallest values

        void removeLargest(node* current, node* parent);
        void delete2Largest(node* current, node* parent, int & count); //2 largest values

        void delete_all(); //everything except root
        void delete_util(node* current);

        void delete_right(); //all values larger than root
        void delete_right_util(node* current);

        void deleteTree(node* root); //whole tree
 
 
 	private:
 		node * root;
		void display_tree(node*, int);
};
  