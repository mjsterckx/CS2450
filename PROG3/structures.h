#define TEXT_SIZE 80
#define NUM_DVDS 4

typedef struct {
    char title[TEXT_SIZE];
    char director[TEXT_SIZE];
    int playTime;
} dvd_t;

void getOneDVD(dvd_t *dvd);
void printOneDVD(dvd_t);
void getCollection(dvd_t[], int);
void printCollection(dvd_t[], int);