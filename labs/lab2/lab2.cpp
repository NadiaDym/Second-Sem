#include <iostream>
#include <queue.h>

using namespace std;

void InsertOneBeforeNegative(Queue<int>& queue)
{
	for (int i = 0; i < queue.count(); i++)
	{
		int checkNum = queue.unqueue();
		if (checkNum < 0)
		{
			queue.queue(1);
			i++;
		}
		queue.queue(checkNum);
	}
}

void deleteNegatives(Queue<int>& queue)
{
	for (int i = 0; i < queue.count(); i++)
	{
		int checkNum = queue.unqueue();
		if (checkNum >= 0)
		{
			queue.queue(checkNum);
		}
		else
		{
			i--;
		}
	}
}

int countOccurrences(Queue<int>& queue, int testNum)
{
	int counter = 0;
	for (int i = 0; i < queue.count(); i++)
	{
		int checkNum = queue.unqueue();
		queue.queue(checkNum);
		if (checkNum == testNum)
		{
			counter++;
		}
	}
	return counter;
}

void displayOccurrences(int testNum, int counter)
{
	if (counter != 0)
	{
		cout << "Число " << testNum << " встречается " 
			<< counter << " раз/раза." << endl;
	}
	else
	{
		cout << "Данное число не встречается в очереди."
			<< endl;
	}
}

void displayMenu()
{
	cout << "0 - Показ меню\n"
		<< "1 - Ввод числа\n"
		<< "2 - Извлечение числа\n"
		<< "3 - Вставка перед отрицательным числом элемента со значением 1\n"
		<< "4 - Удаление всех отрицательных чисел из очереди\n"
		<< "5 - Подсчет количества вхождений в очередь введенного значения\n"
		<< "6 - Подсчет количества чисел в очереди\n"
		<< "7 - Удаление всех чисел из очереди\n"
		<< "8 - Выход из программы\n";
}

int main()
{
	setlocale(LC_ALL, "RU");
	Queue<int> queue;
	displayMenu();
	while (true)
	{
		int command;
		cout << "Выберите функцию: ";
		cin >> command;
		switch (command)
		{
		case 0:
			displayMenu();
			break;

		case 1:
			int input;
			cout << "Введите число последовательности: ";
			cin >> input;
			queue.queue(input);
			break;

		case 2:
			cout << "Из очереди было извлечено значение: " << queue.unqueue() << endl;
			break;

		case 3:
			InsertOneBeforeNegative(queue);
			break;

		case 4:
			deleteNegatives(queue);
			break;

		case 5:
		{
			int testNum;
			cout << "Введите число для проверки: ";
			cin >> testNum;
			int amount = countOccurrences(queue, testNum);
			displayOccurrences(testNum, amount);
		}
			break;

		case 6:
			cout << queue.count() << endl;
			break;

		case 7:
			queue.clear();
			break;

		case 8:
			cout << "Вы завершили работу программы!\n";
			return 0;

		default:
			cout << "Некорректный ввод, попробуйте снова.\n";
			break;
		}
	}
}
