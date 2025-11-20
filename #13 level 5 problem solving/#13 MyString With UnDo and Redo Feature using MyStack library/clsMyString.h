#pragma once
#include <string>
#include "clsMyStackArr.h"

class clsMyString
{

protected:
	std::string _Value;
	clsMyStackArr<string> _UndoStack;
	clsMyStackArr<string> _RedoStack;

public:
	void SetValue(string value) {
		_UndoStack.push(_Value);
		_Value = value;
	}

	string GetValue() {
		return _Value;
	}

	_declspec(property(get = GetValue, put = SetValue)) string Value;

	void Undo() {
		if (!_UndoStack.IsEmpty()) {
			_RedoStack.push(_Value);
			_Value = _UndoStack.Top();
			_UndoStack.pop();
		}
	}

	void Redo() {

		if (!_RedoStack.IsEmpty()) {
			_UndoStack.push(_Value);
			_Value = _RedoStack.Top();
			_RedoStack.pop();
		}
	}


};

