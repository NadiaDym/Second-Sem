#pragma once
#include <stdexcept>

using namespace std;

/// <summary>
/// ����� Queue ��������� ������� � �������������� �������� ������.
/// ��������� ������������ ������ � ������ �� �������� "������ ������ � ������ �����" (FIFO).
/// </summary>
template <typename T>
class Queue
{
private:

	struct Container
	{
		T data;
		Container* next;
	};

	Container* top;
	Container* bottom;
	int amount;

public:
	/// <summary>
	/// ����������� �� ���������, �������������� ������ �������.
	/// </summary>
	Queue() : top(nullptr), bottom(nullptr), amount(0) {}

	/// <summary>
	/// ����������, ����������� ������, ������� ��������.
	/// </summary>
	~Queue()
	{
		clear();
	}

	/// <summary>
	/// ��������� ������� � ����� �������.
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
	/// ������� ������� �� ������ ������� � ���������� ��� ��������.
	/// </summary>
	/// <returns>��������, ��������� �� �������.</returns>
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
	/// ���������� ���������� ��������� � �������.
	/// </summary>
	/// <returns>���������� ��������� � �������.</returns>
	int count()
	{
		return amount;
	}

	/// <summary>
	/// ������� �������, ������ ��� ��������.
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
