#pragma once

using namespace std;

template<class T>
class clsDynamicArray
{

	void swap(T& value1, T& value2) {

		T temp = value1;
		value1 = value2;
		value2 = temp;

	}

	/*
	* Valid index for the
		 - access and delete operation includeSize = false, 0 <= index < _Size
		 - inseration operation includeSize = true, 0<= index <= _Size
	*
	*/
	bool isValidIndex(int index, bool includeSize = false) {
		return index >= 0 && (index < _Size || (index == _Size && includeSize));
	}

protected:
	int _Size = 0;


public:
	T* _Items;

	clsDynamicArray(int size = 0) {
		if (size < 0)
			size = 0;

		_Size = size;
		_Items = new T[size];
	}

	~clsDynamicArray() {
		delete[] _Items;
	}

	bool SetItem(int index, T value) {

		if (index < 0 || _Size <= index)
			return false;

		_Items[index] = value;
		return true;
	}

	int Size() {
		return _Size;
	}

	bool IsEmpty() {
		return Size() == 0;
	}

	void PrintList() {
		for (int i = 0; i < _Size; i++)
		{
			cout << *(_Items + i) << " ";
		}
		cout << endl;
	}

	void Resize(int size) {

		if (size < 0) {
			size = 0;
		}

		T* newItems = new T[size];

		int newSize = (size > _Size) ? _Size : size;

		for (int i = 0; i < newSize; i++)
		{
			newItems[i] = _Items[i];
		}

		delete[] _Items;
		_Items = newItems;
		_Size = size;

	}

	void Reverse() {

		for (int i = 0; i < _Size / 2; i++)
		{
			swap(_Items[i], _Items[_Size - i - 1]);
		}
	}

	void Clear() {
		Resize(0);
	}

	T GetItem(int index) {
		return _Items[index];
	}

	bool DeleteItemAt(int index) {

		if (!isValidIndex(index))
			return false;



		T* newItem = new T[_Size - 1];


		for (int i = 0; i < index; i++)
		{
			newItem[i] = _Items[i];
		}

		for (int i = index + 1; i < _Size; i++)
		{
			newItem[i - 1] = _Items[i];
		}


		delete[] _Items;
		_Items = newItem;
		_Size--;

		return true;
	}

	bool DeleteFirstItem() {
		return DeleteItemAt(0);

	}

	bool DeleteLastItem() {
		return DeleteItemAt(_Size - 1);
	}

	int Find(T value) {

		for (int i = 0; i < _Size; i++)
		{
			if (_Items[i] == value)
				return i;
		}

		return -1;
	}

	bool DeleteItem(T value) {
		int index = Find(value);
		return DeleteItemAt(index);
	}

	bool InsertAt(int index, T value) {

		if (!isValidIndex(index, true))
			return false;

		T* newItems = new T[_Size + 1];

		for (int i = 0; i < index; i++)
		{
			newItems[i] = _Items[i];
		}

		newItems[index] = value;

		for (int i = index; i < _Size; i++)
		{
			newItems[i + 1] = _Items[i];
		}


		delete[] _Items;
		_Items = newItems;
		_Size++;
		return true;
	}

	bool InsertAtBeginning(T value) {
		return InsertAt(0, value);
	}

	bool InsertBefore(int index, T value) {
		if (index < 0) {
			return InsertAtBeginning(value);
		}
		return InsertAt(index - 1, value);
	}

	bool InsertAfter(int index, T value) {

		if (index >= _Size) {
			return InsertAtEnd(value);
		}

		return InsertAt(index + 1, value);
	}

	bool InsertAtEnd(T value) {
		return InsertAt(_Size, value);
	}

};

