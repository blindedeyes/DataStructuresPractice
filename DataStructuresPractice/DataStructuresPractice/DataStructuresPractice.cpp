// DataStructuresPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DynamicArray.h"

int main()
{
	DynamicArray<int> test;

	test.pushBack(0);
	printf("size: %d capacity: %d\n", test.size(), test.capacity());
	for (unsigned int i = 0; i < test.size(); i++)
		printf("values: %d index: %d\n", test[i], i);
	test.pushBack(1);
	test.pushBack(2);
	test.pushBack(3);
	test.pushBack(4);

	printf("size: %d capacity: %d\n", test.size(), test.capacity());
	for (unsigned int i = 0; i < test.size(); i++)
		printf("values: %d index: %d\n", test[i], i);
	test.clear();

	printf("size: %d capacity: %d\n", test.size(), test.capacity());
	test.pushBack(1);
	test.pushBack(2);
	test.pushBack(3);
	test.pushBack(4);

	printf("size: %d capacity: %d\n", test.size(), test.capacity());
	for (unsigned int i = 0; i < test.size(); i++)
		printf("values: %d index: %d\n", test[i], i);
	test.clear();
	return 0;
}