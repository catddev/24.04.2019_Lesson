#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Stack {
private:
	T* ptr;
	int cur_size;
	int buf_size;
public:
	Stack();
	Stack(const Stack<T>& obj);
	~Stack();
	int size();

	void push(T el);
	void pop();
	T &top();
	bool empty()const;
	void print();
	Stack<T> operator=(const Stack<T>& obj); //когда конструктор можно не писать <T>, а когда метод то обязательно
};

template<typename T>
inline Stack<T>::Stack()
{
	ptr = 0;
	cur_size = 0;
	buf_size = 0;
}

template<typename T>
inline Stack<T>::Stack(const Stack<T>& obj)
{
	cur_size = obj.cur_size;
	buf_size=obj.buf_size;
	ptr = new T[buf_size];
	for (int i = 0; i < cur_size; i++)
		ptr[i] = obj.ptr[i];
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] ptr;
}

template<typename T>
inline int Stack<T>::size()
{
	return cur_size;
}

template<typename T>
inline void Stack<T>::push(T el)
{
	if (buf_size == 0) {
		buf_size = 4;
		ptr = new T[buf_size];
	}
	else if (cur_size == buf_size) {
		buf_size *= 2;
		T*tmp = new T[buf_size];
		for (int i = 0; i < cur_size; i++)
			tmp[i] = ptr[i];
		delete[] ptr;
		ptr = tmp;
	}
	ptr[cur_size++] = el;
}

template<typename T>
inline void Stack<T>::pop()
{
	cur_size--;
}

template<typename T>
inline T& Stack<T>::top()
{
	return ptr[cur_size-1];
}

template<typename T>
inline bool Stack<T>::empty() const
{
	return (cur_size==0);
}

template<typename T>
inline void Stack<T>::print()
{
	for (int i = 0; i < cur_size; i++)
		cout << ptr[i] << endl;
	cout << endl;
}

template<typename T>
inline Stack<T> Stack<T>::operator=(const Stack<T>& obj)
{
	cur_size = obj.cur_size;
	buf_size = obj.buf_size;
	ptr = new T[buf_size];
	for (int i = 0; i < cur_size; i++)
		ptr[i] = obj.ptr[i];
}
