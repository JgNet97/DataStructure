#pragma once
template<typename T>
class Queue
{
private:
	class Node
	{
	public:	
		Node* front;
		Node* back;
		T data;

	public:
		Node(const T& pData) : data(pData), front(nullptr), back(nullptr) {}
		Node() : front(nullptr), back(nullptr) {}
		~Node() {}
	};

private:
	Node _front;
	Node _back;
	int  _size;

public:
	Queue() : _size(0)
	{

	}

	~Queue()
	{

	}

	void PushBack(const T& data)
	{

	}

	void PopBack()
	{

	}

	bool Empty()
	{
		return _szie == 0;
	}

	int Size()
	{
		return _size;
	}
};

