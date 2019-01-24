#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	cout << "Hello" << endl;

	for (int i = 0; i < 10; i++)
	{
		int x = i;
		printf("%p: %d\n", &x, x);
	}

	return 0;
}

/*
Hello
00000011CD3EFD54: 0
00000011CD3EFD54: 1
00000011CD3EFD54: 2
00000011CD3EFD54: 3
00000011CD3EFD54: 4
00000011CD3EFD54: 5
00000011CD3EFD54: 6
00000011CD3EFD54: 7
00000011CD3EFD54: 8
00000011CD3EFD54: 9
*/