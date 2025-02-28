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

	LinkedList<int>::Iterator start = list.Begin();
	++start;
	++start;
	list.Insert(start, 10);
	std::cout << *start << std::endl;
	list.Erase(start);

	for (LinkedList<int>::Iterator it = list.Begin(); it != list.End(); ++it) 
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
	return 0;
}