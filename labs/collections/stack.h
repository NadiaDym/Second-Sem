#pragma once
#include <stdexcept>

using namespace std;
/// <summary>
/// Класс Stack реализует стек с использованием связного списка.
/// Коллекция обеспечивает доступ к данным по принципу "последний пришел — первый вышел" (LIFO).
/// </summary>
template <typename T>
class Stack
{
private:
    struct Container
    {
        T data;
        Container* next;
    };

    Container* top;
    int counter;

public:
    Stack() : top(nullptr), counter(0) {}

    /// <summary>
    /// Особый метод класса, который срабатывает во время уничтожения объектов класса.
    /// Его роль заключается в том, чтобы освободить динамическую память
    /// </summary>
    ~Stack()
    {
        clear();
    }

    /// <summary>
    /// Добавляет элемент на вершину стека.
    /// </summary>
    /// <param name="value">Значение, которое нужно добавить в стек.</param>
    void push(T value)
    {
        Container* temp = new Container();
        temp->data = value;
        temp->next = top;
        top = temp;
        counter++;
    }

    /// <summary>
    /// Удаляет верхний элемент из стека и возвращает его значение.
    /// </summary>
    /// <returns>Значение верхнего элемента стека.</returns>
    /// <exception cref="runtime_error">Выбрасывается ошибка, если стек пуст.</exception>
    T pop()
    {
        if (top == nullptr)
        {
            throw ("Stack is empty!");
        }
        Container* temp = top->next;
        T value = top->data;
        delete top;
        top = temp;
        counter--;
        return value;
    }

    /// <summary>
    /// Возвращает значение верхнего элемента стека. Удаления не происходит.
    /// </summary>
    /// <returns>Значение верхнего элемента стека.</returns>
    /// <exception cref="runtime_error">Выбрасывается ошибка, если стек пуст.</exception>
    T peek() const
    {
        if (top == nullptr)
        {
            throw ("Stack is empty!");
        }
        return top->data;
    }

    /// <summary>
    /// Возвращает текущее количество элементов в стеке.
    /// </summary>
    /// <returns>Количество элементов в стеке.</returns>
    int count() const
    {
        return counter;
    }

    /// <summary>
    /// Очищает стек, удаляя все элементы.
    /// </summary>
    void clear()
    {
        while (top != nullptr)
        {
            Container* temp = top->next;
            delete top;
            top = temp;
        }
        counter = 0;
    }
};