#include <stdio.h>
int getMaxCount(double[], int);

int main()
{
    double myArray[] = {-5.3, -4.4,-5.5, 1.0, -5.1, 5.2,1.0, -5.0, 1.0};
    printf("%i", getMaxCount(myArray, 9));
}
