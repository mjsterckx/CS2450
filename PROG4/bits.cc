#include <stdio.h>

void printIP(int address)
{
	int first, second, third, fourth;
	first = address >> 24;
	second = (address >> 16) & 0x000000FF;
	third = (address >> 8) & 0x000000FF;
	fourth = address & 0x000000FF;
	printf("%d.%d.%d.%d", first, second, third, fourth);
}

int reverseEndian(int number)
{
	int first, second, third, fourth;
	first = number << 24;
	second = (number << 8) & 0x00FF0000;
	third = (number >> 8) & 0x0000FF00;
	fourth = number >> 24;
	return first + second + third + fourth;
}

int countGroups(int number)
{
	int groups = 0;
	int n = number;
	int lastbit = 0;
	for (int i = 0; i < 32; i++)
	{
		if (n % 2 == 0)
		{
			if (lastbit == 1) groups++;
			lastbit = 0;
		}
		else
		{
			lastbit = 1;
		}
		n = n >> 1;
	}
	if (lastbit = 1) groups++;
	return groups;
}