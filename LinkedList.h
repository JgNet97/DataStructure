#pragma once
/****************
	LinkedList
****************/
template<typename T>
class LinkedList
{
	/*
		Node 
	*/
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

	/*
		Iterator
	*/
public:
	class Iterator
	{
	private:
		Node* current;
	
	public:
		Iterator(Node* node) : current(node) {}
		
		T& operator*() { return current->data; } 
		Iterator& operator++() { current = current->back; return *this; }
		Iterator& operator--() { current = current->front; return *this; }
		bool operator!=(const Iterator& other) const { return current != other.current; }
		bool operator==(const Iterator& other) const { return current == other.current; }	
	};


private:
	Node _head;
	Node _tail;
	int	 _size;

public:
	LinkedList() : _size(0)
	{
		_head.front = &_head;
		_head.back = &_tail;

		_tail.front = &_head;
		_tail.back = &_tail;
	}

	~LinkedList()
	{

	}

	// Iterator 지원을 위한 함수
	Iterator Begin() { return Iterator(_head.back); }
	Iterator End() { return Iterator(&_tail); }

	// 뒤에 데이터 추가
	void PushBack(const T& data)
	{
		Node* tailFrontNode = _tail.front;
		Node* newNode = new Node(data);
		tailFrontNode->back = newNode;
		newNode->front = tailFrontNode;
		_tail.front = newNode;
		newNode->back = &_tail;

		_size++;
	}

	// 뒤에 데이터 삭제
	void PopBack()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("삭제할 데이터가 없을때 PopBack");
		}

		Node* deleteNode = _tail.front;
		Node* deleteNodeFront = deleteNode->front;

		deleteNodeFront->back = &_tail;
		_tail.front = deleteNodeFront;

		delete deleteNode;
		_size--;
	}

	// 맨 처음 데이터 조회
	const T& Front()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("데이터가 없을때 Front");
		}

		Node* frontNodePtr = _head.back;
		return frontNodePtr->data;
	}

	// 맨 마지막 데이터 조회
	const T& Back()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("데이터가 없을때 Back");
		}

		Node* BackNodePtr = _tail.front;
		return BackNodePtr->data;
	}


	// 데이터 없는지 확인
	bool Empty()
	{
		return _size == 0;
	}
};

