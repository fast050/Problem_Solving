#pragma once
#include "clsDblLinkedList.h"
template <class T>
class clsMyQueue
{

protected:
	clsDblLinkedList<T> _MyList;

public:
	void push(T value) {
		_MyList.InsertAtEnd(value);
	}

	void Print() {
		_MyList.PrintList();
	}

	void pop() {
		_MyList.DeleteFirstNode();
	}

	T front() {
	   return _MyList.GetItem(0);
	}

	T back() {
		return _MyList.GetItem(Size() - 1);
	}

	int Size() {
		return _MyList.Size();
	}

	void Reverse() {
		_MyList.Reverse();
	}

	void InsertAtFront(T value) {
		_MyList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value) {
		_MyList.InsertAtEnd(value);
	}

	void Clear() {
		_MyList.Clear();
	}

	T GetItem(int index) {
		return _MyList.GetItem(index);
	}

	void InsertAfter(int index, T value) {
		 _MyList.InsertAfter(index, value);
	}

	bool UpdateItem(int index, T value) {
		return _MyList.UpdateItem(index, value);
	}

};

