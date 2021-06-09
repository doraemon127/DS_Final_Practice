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

    int deleted_count = 0;
    node* p;
    object.delete2Smallest(object.getRoot(), p, deleted_count);

 




    object.display();	//displays again after!
   
    return 0;
}