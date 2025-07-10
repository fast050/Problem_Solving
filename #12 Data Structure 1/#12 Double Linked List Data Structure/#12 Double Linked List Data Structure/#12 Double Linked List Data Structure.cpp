
#include <iostream>

using namespace std;

class Node {

public:
    int value;
    Node* next;
    Node* previous;

};

void InsertNodeAtBeginning(Node* &Head, int Value) {

    Node* new_node = new Node();
    
    if(Head!=NULL)
    Head->previous = new_node;

    new_node->previous = NULL;
    new_node->next = Head;
    new_node->value = Value;

    Head = new_node;
}

void InsertNodeAfter(Node* CurrentNode, int Value) {

    if (CurrentNode == NULL)
        return;

    Node* new_node = new Node();    
    new_node->value = Value;
    new_node->previous = CurrentNode;

    if(CurrentNode->next!=NULL)
    new_node->next = CurrentNode->next;


    CurrentNode->next = new_node;

    if(CurrentNode->next!=NULL)
    CurrentNode->next->previous = new_node;
}

void InsertNodeAtEnd(Node*& Head, int Value) {

    Node* new_node = new Node();
    new_node->value = Value;
    new_node->next = NULL;

    if (Head == NULL) {
        new_node->previous = NULL;
        Head = new_node;
        return;
    }

    Node* LastNode = Head;
    while (LastNode->next != NULL) {
        LastNode = LastNode->next;
    }
    
    LastNode->next = new_node;
    new_node->previous = LastNode;
}

Node* Find(Node* Head , int Value) {

    while (Head != NULL) {
    
        if (Head->value == Value)
            return Head;

        Head = Head->next;
    }

    return NULL;
}

void PrintLinkedList(Node* Head) {

    while (Head != NULL) {
        cout << Head->value << " ";
        Head = Head->next;
    }
}

void PrintNodeDetails(Node* head)
{

    if (head->previous != NULL)
        cout << head->previous->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }
}

// Print the linked list
void PrintList(Node* head)

{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";

}

void DeleteNode(Node* &Head, int Value) {

    if (Head == NULL)
    {
        cout << "Empty Linked List!";
        return;
    }

    if (Head->value == Value) {
        Head = Head->next;
        return;
    }

    Node* Previous = Head , *Current = Head;
    while (Current != NULL) {

        if (Current->value == Value) {
            Current->next->previous = Previous;
            Previous->next = Current->next;
            delete Current;
            return;
        }

        Previous = Current;
        Current = Current->next;
    }

}

void DeleteNode(Node*& Head, Node* NodeToDelete) {

    if (Head == NULL || NodeToDelete == NULL) {
        return;
    }

    if (Head == NodeToDelete) {
        Head = Head->next;
    }

    if (NodeToDelete->next != NULL) {
        NodeToDelete->next->previous = NodeToDelete->previous;
    }

    if (NodeToDelete->previous != NULL) {
        NodeToDelete->previous->next = NodeToDelete->next;
    }


    delete NodeToDelete;
}

void DeleteFirstNode(Node*& Head) {

    if (Head == NULL) {
        return;
    }

    Node* Current = Head;
    Head = Current->next;

    if(Head!=NULL)
    Head->previous = NULL;

    delete Current;
}

void DeleteLastNode(Node*& Head) {

    if (Head == NULL) {
        return;
    }


    if (Head->next == NULL) {
        delete Head;
        Head = NULL;
        return;
    }

    Node* LastNode = Head;

    while (LastNode->next != NULL) {
        LastNode = LastNode->next;
    }

   
    LastNode->previous->next = NULL;
    delete LastNode;
}


int main()
{

    Node* Head = NULL;

    InsertNodeAtBeginning(Head, 3);
   // InsertNodeAtBeginning(Head, 2);
    //InsertNodeAtBeginning(Head, 1);
    InsertNodeAtEnd(Head, 4);
    
    DeleteLastNode(Head);

    PrintList(Head);
    PrintListDetails(Head);


  
    system("pause>0");
}
