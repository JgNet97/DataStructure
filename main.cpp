#include "pch.h"
#include <list>
#include <vector>
#include <Windows.h>
using namespace std;
int main() 
{
	LinkedList<int> list;

	for (int i = 0; i < 10; i++) 
	{
		list.PushBack(i);
	}

	while (!list.Empty()) 
	{
		std::cout << list.Back() << std::endl;
		list.PopBack();
	}

	return 0;
}