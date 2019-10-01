#include <stdio.h>

void printRectangleWhile(int width, int height)
{
    if (width < 1 || height < 1) return;
    int curWidth = width;
    int curHeight = height;
    while (curWidth > 0)
    {
        printf("+");
        curWidth--;
    }
    printf("\n");
    if (height == 1) return;
    while (curHeight > 2)
    {
        if (width > 1) printf("+");
        curWidth = width;
        while (curWidth > 2)
        {
            printf("-");
            curWidth--;
        }
        printf("+\n");
        curHeight--;
    }
    curWidth = width;
    while (curWidth > 0)
    {
        printf("+");
        curWidth--;
    }
    printf("\n");
}

void printTriangleFor(int height)
{
    if (height < 1) return;
    for (int i = 0; i < height - 1; i++)
    {
        printf(" ");
    }
    printf("+\n");
    if (height ==1 ) return;
    int curHeight = 0;
    for (int j = height - 1; j > 1; j--)
    {
        for (int k = j - 1; k > 0; k--) {
            printf(" ");
        }
        printf("+");
        for (int l = 0; l < curHeight; l++)
        {
            printf("-");
        }
        printf("+\n");
        curHeight++;
    }
    for (int m = 0; m < height; m++)
    {
        printf("+");
    }
    printf("\n");
}