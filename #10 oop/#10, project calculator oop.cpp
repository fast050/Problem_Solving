#include <iostream>

using namespace std;

class clsCalculator {

    enum enOperator {
        eAdd,
        eSubtract,
        eMultiply,
        eDivide
    };

    float _Result = 0;
    float _LastNumber = 0;
    string _OprandName = "";

    void setLastNumber(int number) {
        _LastNumber = number;
    }

    void setOprandName(enOperator opertor) {

        switch (opertor)
        {
        case clsCalculator::eAdd:
            _OprandName =  "Adding";
            break;
        case clsCalculator::eSubtract:
            _OprandName = "Subtracting";
            break;
        case clsCalculator::eMultiply:
            _OprandName = "Multiplying";
            break;
        case clsCalculator::eDivide:
            _OprandName = "Dividing";
            break;
        default:
            break;
        }
    }

public:
    void Add(float number) {
        setLastNumber(number);
        setOprandName(eAdd);
        _Result += number;
    }

    void Subtract(float number) {
        setLastNumber(number);
        setOprandName(eSubtract);
        _Result -= number;
    }

    void Muliply(float number) {
        setLastNumber(number);
        setOprandName(eMultiply);
        _Result *= number;
    }

    void Divide(float number) {
        if (number == 0)
            number = 1;
        setOprandName(eDivide);
        setLastNumber(number);
        _Result /= number;
    }

    void PrintResult() {
        cout << "Result After " << _OprandName + " " << _LastNumber << " is: " << _Result << endl;
    }

    int GetFinalResult() {
        return _Result;
    }

    void Clear() {
        _OprandName = "";
        _LastNumber = 0;
        _Result = 0;
    }
};

int main()
{
    clsCalculator Calculator;

    Calculator.Add(4);
    Calculator.PrintResult();

    Calculator.Muliply(4);
    Calculator.PrintResult();

    Calculator.Divide(4);
    Calculator.PrintResult();

    Calculator.Subtract(6);
    Calculator.PrintResult();

    Calculator.Clear();
    Calculator.PrintResult();

    Calculator.Add(4);
    Calculator.PrintResult();

    Calculator.Divide(0);
    Calculator.PrintResult();

}