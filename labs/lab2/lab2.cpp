#include <iostream>
#include <queue.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	Queue<int> queue;
	int input = 1;
	int command = 0;
	int counter = 0;
	int check;
	int temp_num;
	cout << "1 - Ввод числа\n"
		<< "2 - Вывод числа\n"
		<< "3 - Вставка перед отрицательным числом элемента со значением 1\n"
		<< "4 - Удаление всех отрицательных чисел из очереди\n"
		<< "5 - Подсчет количества вхождения в очередь введенного значения\n"
		<< "6 - Подсчет количества чисел в очереди\n"
		<< "7 - Удаление всех чисел из очереди\n"
		<< "8 - Выход из программы\n";
	do
	{
		cout << "Выберите функцию: ";
		cin >> command;
		switch (command)
		{
		case 1:
			cout << "Введите число последовательности: ";
			cin >> input;
			queue.queue(input);
			break;

		case 2:
			cout << "Вы извлекаете одно число из очереди: " << queue.unqueue() << endl;
			break;

		case 3:
			for (int i = 0; i < queue.count(); i++)
			{
				temp_num = queue.unqueue();
				if (temp_num < 0)
				{
					queue.queue(1);
					i++;
				}
				queue.queue(temp_num);
			}
			break;

		case 4:
			for (int i = 0; i < queue.count(); i++)
			{
				temp_num = queue.unqueue();
				if (temp_num >= 0)
				{
					queue.queue(temp_num);
				}
				else
				{
					i--;
				}
			}
			break;

		case 5:
			cout << "Введите число для проверки: ";
			cin >> check;
			for (int i = 0; i < queue.count(); i++)
			{
				temp_num = queue.unqueue();
				queue.queue(temp_num);
				if (temp_num == check)
				{
					counter++;
				}
			}
			if (counter != 0)
				cout << "Число " << check << " встречается в очереди " << counter << " раз/раза." << endl;
			else
			{
				cout << "Такого числа нет в последовательности." << endl;
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
			break;

		default:
			cout << "Некорректный ввод, попробуйте снова.\n";
			break;
		}
	} while (command != 8);
}
