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
	cout << "Положительные числа последовательности: " << endl;
	while (stack.count())
	{
		int number = stack.pop();
		if (number > 0)
		{
			cout << number << endl;
		}
	}
}