#pragma once
#include <container.h>
#include <stdexcept>

using namespace std;

/// <summary>
/// Класс Queue реализует очередь с использованием связного списка.
/// Очередь работает по принципу "первый пришел — первый вышел" (FIFO).
/// </summary>
template <typename T>
class Queue
{
private:
	Container<T>* top;
	Container<T>* bottom;
	int amount;
public:
	/// <summary>
	/// Конструктор по умолчанию, инициализирует пустую очередь.
	/// </summary>
	Queue() : top(nullptr), bottom(nullptr), amount(0) {}

	/// <summary>
	/// Деструктор, освобождает память, занятую очередью.
	/// </summary>
	~Queue()
	{
		clear();
	}

	/// <summary>
	/// Добавляет элемент в конец очереди.
	/// </summary>
	void queue(T value)
	{
		Container<T>* temp = new Container<T>;
		temp->data = value;
		temp->next = nullptr;
		if (bottom == nullptr)
		{
			bottom = temp;
			top = temp;
		}
		else
		{
			top->next = temp;
			top = temp;
		}
		amount++;
	}

	/// <summary>
	/// Удаляет элемент из начала очереди и возвращает его значение.
	/// </summary>
	/// <returns>Значение, удаленное из очереди.</returns>
	/// <exception cref="std::runtime_error">Выбрасывается, если очередь пуста.</exception>
	T unqueue()
	{
		if (bottom == nullptr)
		{
			throw "Queue is empty";
		}
		Container<T>* temp = bottom->next;
		T value = bottom->data;
		delete bottom;
		bottom = temp;
		amount--;
		return value;
	}

	/// <summary>
	/// Возвращает количество элементов в очереди.
	/// </summary>
	/// <returns>Количество элементов в очереди.</returns>
	int count() const
	{
		return amount;
	}

	/// <summary>
	/// Очищает очередь, удаляя все элементы.
	/// </summary>
	void clear()
	{
		while (bottom != nullptr)
		{
			Container<T>* temp = bottom;
			bottom = bottom->next;
			delete temp;
		}
		top = nullptr;
		amount = 0;
	}
};
