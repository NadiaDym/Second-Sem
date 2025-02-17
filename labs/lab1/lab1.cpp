#include <iostream>
#include <stack.h>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    Stack<int> stack;
    int input = 1;
    while (input != 0) 
    {
        cout << "Введите число последовательности: ";
        cin >> input;
        if (input != 0) 
        {
            stack.push(input);
        }
    }
    cout << "Числа последовательности: " << endl;
    while (stack.count()) 
    {
        if (stack.peek() > 0) 
        {
            cout << stack.pop() << endl;
        }
        else 
        {
            stack.pop();
        }
    }
}