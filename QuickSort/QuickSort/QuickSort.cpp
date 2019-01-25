// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void Swap(int& x, int& y);
int Partition(int arr[], int startIdx, int endIdx);
void QuickSort(int arr[], int startIdx, int endIdx);

void Swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int Partition(int arr[], int startIdx, int endIdx)
{
	int x = arr[endIdx];
	int i = startIdx - 1;
	for (int j = startIdx; j < endIdx; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			Swap(arr[i], arr[j]);
		}
	}
	i++;
	Swap(arr[i], arr[endIdx]);

	return i;
}

void QuickSort(int arr[], int startIdx, int endIdx)
{
	if (startIdx >= endIdx)
		return;
	int midIdx = Partition(arr, startIdx, endIdx);
	QuickSort(arr, startIdx, midIdx - 1);
	QuickSort(arr, midIdx + 1, endIdx);
}

#define MAX_MEMBER_COUNT 10

int main()
{
    std::cout << "Hello QuickSort!\n"; 

	int arr[] = { 5,3,2,4,6,8,9,1,0,7 };

	QuickSort(arr, 0, MAX_MEMBER_COUNT - 1);

	for (int i = 0; i < MAX_MEMBER_COUNT; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}