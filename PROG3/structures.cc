#include <stdio.h>
#include <string.h>
#include "structures.h"

void getOneDVD(dvd_t *dvd)
{
    char c;
    printf("Enter title: ");
    scanf("%79[^\n]s", dvd->title);
    scanf("%c", &c);
    printf("Enter director: ");
    scanf("%79[^\n]s", dvd->director);
    scanf("%c", &c);
    printf("Enter play time in minutes: ");
    scanf("%d", &dvd->playTime);
}

void printOneDVD(dvd_t dvd)
{
    printf("%s:%s:%d\n", dvd.title, dvd.director, dvd.playTime);
}

void getCollection(dvd_t dvds[], int number)
{
    for (int i = 0; i < number; i++) getOneDVD(&dvds[i]);
}

void printCollection(dvd_t dvds[], int number)
{
    for (int i = 0; i < number; i++) printOneDVD(dvds[i]);
}