#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
   
    clsDblLinkedList <int> MydblLinkedList;

   /* MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);*/

    MydblLinkedList.InsertAtEnd(1);
    MydblLinkedList.InsertAtEnd(2);
    MydblLinkedList.InsertAtEnd(3);
    MydblLinkedList.InsertAtEnd(4);
    MydblLinkedList.InsertAtEnd(5);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node* N1 = MydblLinkedList.Find(2);

    if (N1 != NULL)
        cout << "\nNode with value 2 is Found :-)\n";
    else
        cout << "\nNode Is not found :-(\n";

    MydblLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter Inserting 500 after 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAtEnd(700);
    cout << "\nAfter Inserting 700 at end:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node* N2 = MydblLinkedList.Find(4);
    MydblLinkedList.DeleteNode(N2);
    cout << "\nAfter Deleting 4:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MydblLinkedList.PrintList();

    cout << "\nAfter Deleting Last Node:\n";
    MydblLinkedList.DeleteLastNode();
    MydblLinkedList.PrintList();

    cout << "number of item in double linked list = "<<MydblLinkedList.Size() << endl;

    if (MydblLinkedList.IsEmpty())
        cout << "Empty list" << endl;
    else
        cout << "is not empty with size = " << MydblLinkedList.Size() << endl;

  /*  cout << "Excuting Clear():" << endl;
    MydblLinkedList.Clear();

    cout << "number of item in double linked list = " << MydblLinkedList.Size() << endl;*/

    cout << "\nAfter Reverse Linked List:\n";
    MydblLinkedList.Reverse();
    MydblLinkedList.PrintList();

    cout << "\nAfter Reverse Linked List:\n";
    MydblLinkedList.ReverseV2();
    MydblLinkedList.PrintList();


    clsDblLinkedList<int>::Node* N = MydblLinkedList.GetNode(0);

    cout << "node at index 0, value is: " << N->value << endl;

    cout << "item Value is: " << MydblLinkedList.GetItem(2) << endl;


    MydblLinkedList.UpdateItem(2, 12);
    cout << "After update Item(2)" << endl;
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAfter(0, 11);
    MydblLinkedList.PrintList();



    
}