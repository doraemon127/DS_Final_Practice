#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    //node* smallest = object.findSmallest(object.getRoot());
    //cout << "Smallest: " << smallest->data << endl;

    //int numOcurrences = object.countNumOccurrence(object.getRoot(), 3);
    //cout << "numOcurrences: " << numOcurrences << endl;
    
    //int count = 0;
    //object.inOrderSuccessor(object.getRoot(), count);


    //object.removeLargest(object.getRoot(), object.getRoot());

    //object.delete_all();

    //object.delete_right();

    //node* p;
    //object.removeSmallest(object.getRoot(), p);

    //int deleted_count = 0;
    //node* p;
    //object.delete2Smallest(object.getRoot(), p, deleted_count);


    //int deleted_count = 0;
    //node* p;
    //object.delete2Largest(object.getRoot(), p, deleted_count);


    /*
	int levels = object.maxDepth(object.getRoot()) + 1; //Count of levels in the given binary tree
	int sum[levels] = { 0 }; // To store the sum at every level
	object.calculateLevelSum(object.getRoot(), 0, sum);
	object.printArr(sum, levels); // Print the required sums
	*/


    /*
    node* prec = NULL;
    object.inOrderSuccessor(object.getRoot(), prec, object.getRoot()->data);
    if (prec != NULL) {
        cout << "inOrderSuccessor: " << prec->data << endl;
    }
    else {
        cout << "The successor doesn't exist." << endl;
    }
    */

    object.display();	//displays again after!
   
    return 0;
}