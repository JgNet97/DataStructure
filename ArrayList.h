#pragma once
/****************
	ArrayList
****************/
template<typename T>
class ArrayList
{
private:
	int _capacity;
	int _size;
	T* _data;

public:
	// 연산자 오버로딩
	const T& operator[](int i) { return _data[i]; }
	const T& operator[](int i) const { return _data[i]; }

public:
	ArrayList() : _capacity(1), _size(0), _data(nullptr)
	{
		_data = new T[_capacity];
	}

	~ArrayList()
	{
		if (_data)
		{
			delete[] _data;
		}
	}

	// capacity 할당
	void Reserve(int capacity)
	{
		T* newData = new T[capacity];
		::memcpy(newData, _data, _size * sizeof(T));
		delete[] _data;
		_data = newData;
		_capacity = capacity;
	}

	// 데이터 추가
	void PushBack(const T& value)
	{
		int newSize = _size + 1;
		if (newSize > _capacity)
		{
			Reserve(_capacity * 2);
		}
		_data[_size] = value;
		_size = newSize;
	}

	// 데이터 삭제
	void PopBack()
	{
		if (_size == 0)
		{
			throw::std::runtime_error("데이터 삭제 중 에러 PopBack");
		}

		_size--;
	}

	// 비어있는지 확인
	bool Empty()
	{
		return _size == 0;
	}

	// 크기 확인
	int Size()
	{
		return _size;
	}
};