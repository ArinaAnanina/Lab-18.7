#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct ListItem
{
	T* data;
	ListItem<T>* next;
	~ListItem() {
		delete this->data;
	}
};

template <class T>
class List
{
	int size;
	ListItem<T>* first;
	ListItem<T>* last;
	void addItem(T& value);
public:
	List(int size);
	List(List<T>& list);
	~List();

	List& operator=(const List<T>& list);

	T& operator[](int index);
	List operator+(const int value);
	int operator()();

	friend ostream& operator<< <>(ostream& out, const List<T>& list);
	friend istream& operator>> <>(istream& in, List<T>& list);
};

template <class T>
List<T>::List(int size)
{
	this->last = 0;
	this->first = 0;
	for (int i = 0; i < size; i++) {
		T* data = new T;
		cin >> (*data);
		this->addItem(*data);
	}
}

template <typename T>
List<T>::List(List<T>& list)
{
	*this = list;
}

template <typename T>
List<T>::~List()
{
	ListItem<T>* current = this->first;
	while (current) {
		ListItem<T>* rem = current;
		current = current->next;
		delete rem;
	}
}

template <typename T>
void List<T>::addItem(T& value)
{
	ListItem<T>* item = new ListItem<T>;
	item->data = &value;
	item->next = 0;

	if (!this->first) {
		this->first = item;
	}
	if (this->last) {
		this->last->next = item;
		this->last = item;
	}
	else {
		this->last = item;
	}

	this->size++;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& list)
{
	if (this == &list)
	{
		return *this;
	}

	// очистка
	this->~List();
	this->size = 0;
	this->last = 0;
	this->first = 0;

	// наполнение
	ListItem<T>* item = list.first;
	while (item) {
		T* data = new T(*(item->data));
		this->addItem(*data);
		item = item->next;
	}

	return *this;
}

template <typename T>
T& List<T>::operator[](int index)
{
	if (index > size) {
		throw;
	}
	int i = 0;
	ListItem<T>* item = this->first;
	while (i < index && item) {
		item = item->next;
		i++;
	}

	return (*item->data);
}

template <typename T>
List<T> List<T>::operator+(const int value)
{
	ListItem<T>* item = this->first;
	while (item) {
		item->data = item->data + value;
		item = item->next;
	}

	return *this;
}

template <typename T>
int List<T>::operator()()
{
	return this->size;
}

template <typename T>
ostream& operator<<(ostream& out, const List<T>& list)
{
	ListItem<T>* item = list.first;
	while (item) {
		out << (*item->data);
		item = item->next;
	}

	return out;
}

template <typename T>
istream& operator>>(istream& in, List<T>& list)
{
	ListItem<T>* item = list.first;
	while (item) {
		in >> item.data;
		item = item.next;
	}
	return in;
}