#include <stdio.h>

void printIP(int address)
{
	printf("%d.%d.%d.%d\n", address >> 24, (address >> 16) & 255, (address >> 8) & 255, address & 255);
}

int reverseEndian(int number)
{
	return (number << 24) + ((number << 8) & 16711680) + ((number >> 8) & 65280) + (number >> 24);
}

int countGroups(int number)
{
	int groups = 0;
	int lastbit = 0;
	for (int i = 0; i < 33; i++)
	{
		if ((number % 2 == 0 || i == 32) && lastbit != 0) groups++;
		lastbit = number % 2;
		number = number >> 1;
	}
	return groups;
}