#include <iostream>
#include <stack>

using namespace std;

int main()
{

    stack <int> numbers1;
    stack <int> numbers2;


    numbers1.push(10);
    numbers1.push(20);
    numbers1.push(30);
    numbers1.push(40);
    numbers1.push(50);

    numbers2.push(60);
    numbers2.push(70);
    numbers2.push(80);
    numbers2.push(90);
    numbers2.push(100);

    numbers1.swap(numbers2);


    cout << "stack1 size is " << numbers1.size() << endl;

    while (!numbers1.empty()) {

        cout << numbers1.top() << endl;

        numbers1.pop();
    }

    cout << endl;

    cout << "stack2 size is " << numbers2.size() << endl;

    while (!numbers2.empty()) {

        cout << numbers2.top() << endl;

        numbers2.pop();
    }


    system("pause>0");

    return 0;
}
