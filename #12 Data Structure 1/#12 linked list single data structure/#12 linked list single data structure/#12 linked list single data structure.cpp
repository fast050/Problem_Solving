
#include <iostream>

using namespace  std;

class Node {

public:
    int value;
    Node* next;

};

void PrintLinkedList(Node* Head) {
    
    if (Head == NULL) {
        cout << "Empty LinkedList" << endl;
        return;
    }

    while (Head != NULL) {
        cout << Head->value << " ";
        Head = Head->next;
    }

    cout << endl;
}

void InsertAtBeginning(Node* &Head, int Value) {

    Node* NewNode = new Node();
    NewNode->value = Value;
    NewNode->next = Head;

    Head = NewNode;

}

Node* Find(Node* Head, int Value) {

    while (Head != NULL) {

        if (Head->value == Value)
            return Head;

        Head = Head->next;
    }

    return NULL;
}

Node* GetLastNode(Node* Head) {

    if (Head == NULL)
        return NULL;

    while (Head->next != NULL) {
        Head = Head->next;
    }

    return Head;

}

Node* GetPeriousNode(Node* Head , int Value) {

    if (Head == NULL || Head->value == Value)
        return NULL;

    while (Head->next->value != Value) {
        Head = Head->next;

        if (Head == NULL)
            return NULL;
    }

    return Head;
}
// Insert a node after a node
void InsertAfter(Node* prev_node, int Value) {

    if (prev_node == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->value = Value;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void InsertAtEnd(Node* &Head, int Value) {
   
    Node* new_node = new Node();
    new_node->value = Value;

    if (Head == NULL) {
        Head = new_node;
        return;
    }

    Node* last_node = GetLastNode(Head);
    last_node->next = new_node;
}

void changeNumber(int* s , int value) {
    *s = value;
}

void DeleteFirstNode(Node* &Head) {

    if (Head == NULL) return;

    Node* Current = Head;

    Head = Current->next;
    delete Current;
}

void DeleteLastNode(Node* &Head) {
    if (Head == NULL)return;

    Node* LastNode = GetLastNode(Head);
    Node* PreviousLast = GetPeriousNode(Head, LastNode->value);

    //if the linkedList only have one item
    if (PreviousLast == NULL) {
       Head = NULL;
       return;
    }
        
    PreviousLast->next = NULL;

    delete LastNode;
}

void DeleteNode(Node* &Head, int Value) {

    Node* Current = Head, * Previous = Head;

    if (Head == NULL)
        return;

    //if we want to delete first item
    if (Current->value == Value) {
        DeleteFirstNode(Head);
        return;
    }

    while (Current != NULL && Current->value != Value) {
        Previous = Current;
        Current = Current->next;
    }

    //Node did not found
    if (Current == NULL) {
        return;
    }

    Previous->next = Current->next;
    delete Current;
}

int main()
{
    Node* Head = NULL;
    InsertAtEnd(Head,-1);
    DeleteLastNode(Head);

    PrintLinkedList(Head);


}
