#pragma once
template<class T>
class clsDblLinkedList
{
public:
	class Node {
	  public:
		T value;
		Node* next;
		Node* prev;
	};
private:
	Node* _Head = NULL;

	Node* PreviousNode(Node* node) {

		if (_Head == NULL) {
			return NULL;
		}

		if (node == NULL) {
			return NULL;
		}


		if (node->prev == NULL)
			return NULL;
		else
			return node->prev;
	}

	Node* AfterNode(Node* node) {
		if (_Head == NULL) {
			return NULL;
		}

		if (node == NULL) {
			return NULL;
		}

		if (node->next == NULL)
			return NULL;
		else
			return node->next;

	}

	Node* GetLastNode() {
		if (_Head == NULL) {
		   return NULL;
		}
			
		Node* readNode = _Head;
		while (readNode->next != NULL) {
			readNode = readNode->next;
		}
		
		return readNode;
	}

	//bool IsLastNode(Node* node) {
	//	return AfterNode(node) == NULL;
	//}

	//bool IsFirstNode(Node* node) {
	//	return node == _Head;
	//}

	//bool IsOnlyNode(Node* node) {
	//	return IsFirstNode(node) && IsLastNode(node);
	//}

protected:
	int _Size = 0;


public:
	clsDblLinkedList() {
	}

	void InsertAtBeginning(T value) {

		Node* newNode = new Node();
		newNode->value = value;	
		newNode->next = _Head;
		newNode->prev = NULL;

		if (_Head != NULL) {
          _Head->prev = newNode;
		}

		_Head = newNode;

		_Size++;
	}

	void PrintList() {
		if (_Head == NULL) {
			std::cout << "empty List" << std::endl;
			return;
		}
		Node* readingNode = _Head;

		while (readingNode != NULL) {
			std::cout << readingNode->value << " ";
			readingNode = readingNode->next;
		}
		std::cout << std::endl;

		//PrintListReverse();
	}

	void PrintListReverse() {
		if (_Head == NULL) {
			std::cout << "empty List" << std::endl;
			return;
		}
		Node* readingNode = GetLastNode();

		while (readingNode != NULL) {
			std::cout << readingNode->value << " ";
			readingNode = readingNode->prev;
		}
		std::cout << std::endl;
	}

    Node* Find(T value) {

		Node* readingNode = _Head;

		while (readingNode != NULL) {

			if (readingNode->value == value) {
				return readingNode;
			}

			readingNode = readingNode->next;
	   }

		return NULL;
	}

	void InsertAfter(Node* node, T value) {

		if (node == NULL) {
			std::cout << "not a valid node to be add after it" << std::endl;
			return;
		}

		Node* newNode = new Node;
		newNode->value = value;
		newNode->prev = node;
		newNode->next = node->next;


		if (node->next != NULL) {
			node->next->prev = newNode;
		}

		node->next = newNode;
		_Size++;
	}

	bool InsertAfter(int index, T value) {

		Node* node = GetNode(index);

		if (node == NULL) {
			return false;
		}

		InsertAfter(node, value);
		return true;
	}

	void InsertAtEnd(T value) {
		
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = NULL;
		newNode->prev = NULL;
		
		if (_Head == NULL) {
			_Head = newNode;
		}
		else {
         Node* readNode = GetLastNode();

		 readNode->next = newNode;
		 newNode->prev = readNode;

		}

		_Size++;


	}

	void DeleteNode(Node*& node) {

		if (_Head == NULL) {
			std::cout << "empty list!"<< std::endl;
			return;
		}

		if (node == NULL) {
			std::cout << "node is NULL!" << std::endl;
			return;
		}

		if (_Head == node)
			_Head = node->next;

		if (AfterNode(node) != NULL) 
			AfterNode(node)->prev = PreviousNode(node);
		

		if(PreviousNode(node)!=NULL)
		   PreviousNode(node)->next = AfterNode(node);	

		delete node;

		_Size--;
	}

	void DeleteFirstNode(){
		if (_Head == NULL) {
			std::cout << "empty list!" << std::endl;
			return;
		}

		Node* nodeToDelete = _Head;
		_Head = _Head->next;

		if(_Head != NULL)
		_Head->prev = NULL;

		delete nodeToDelete;

		_Size--;
	}

	void DeleteLastNode() {

		if (_Head == NULL) {
			std::cout << "empty list!" << std::endl;
			return;
		}

		Node* deleteNode = GetLastNode();

		if (deleteNode == _Head) {
			delete _Head;
			_Head = NULL;
			_Size--;
			return;
		}
		Node* prev = deleteNode->prev;
		if( prev != NULL)
			prev->next = NULL;

		delete deleteNode;
		_Size--;
	}

	int Size() {
		return _Size;
	}

	bool IsEmpty() {
		return _Size == 0;
	}

	void Clear() {
		for (int i = _Size; i > 0 ; i--)
		{
			DeleteLastNode();
 		}
	}

	void Reverse() {

		if (_Head == NULL || _Head->next == NULL)
			return;

		Node* readNode = _Head->next;

		while (readNode != NULL) {
			InsertAtBeginning(readNode->value);
			Node* next = readNode->next;
			DeleteNode(readNode);
			readNode = next;
		}
	}

	void ReverseV2() {

		if (_Head == NULL || _Head->next == NULL)
			return;

		Node* readNode = _Head;
		Node* tempNode = NULL;
		while (readNode != NULL) {
			tempNode = readNode->prev;
			readNode->prev = readNode->next;
			readNode->next = tempNode;

			readNode = readNode->prev;
		}

		_Head = tempNode->prev;
	}

	Node* GetNode(int index) {

		if (index >= _Size || index < 0)
			return NULL;

		Node* readNode = _Head;
		
		for (int i = 0; i < index ; i++)
		{
			readNode = readNode->next;
		}

		return readNode;

	}

	T GetItem(int index) {

		Node* itemNode = GetNode(index);

		if (itemNode == NULL)
			return NULL;
       
		return itemNode->value;
	}

	bool UpdateItem(int index, T value) {

		Node* nodeItem = GetNode(index);

		if (nodeItem == NULL)
			return false;

		nodeItem->value = value;
		return true;
	}

};

