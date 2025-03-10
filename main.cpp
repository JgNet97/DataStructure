#include "pch.h"
#include "ArrayList.h"
using namespace std;

int main() 
{
	ArrayList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PushBack(6);
	list.PushBack(7);
	list.PushBack(8);
	list.PushBack(9);
	list.PopBack();
	list.PopBack();
	list.PopBack();
	for (int i = 0; i < list.Size(); i++) 
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}