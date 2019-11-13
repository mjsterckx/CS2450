#include <stdio.h>
#include <string.h>

#define LIMIT 10000
#define LINE_SIZE 128

//For part 1
void assemble(char[]);
int findOrigin(FILE*);
int firstPass(FILE*, int[], int);
void printLabels(int[]);
void toUpper(char*);
char* removeSpaces(char*);

//For part 2
int getAdd(char[]);
int getAnd(char[]);
int getTrap(char[]);
int getNot(char[]);
int getLd(char[], int[], int);
int getLdr(char[]);
int getSt(char[], int[], int);
int getStr(char[]);
int getBr(char[], int[], int);
int getIt(int, char[]);
int secondPass(FILE*, int[], int);

void assemble(char filename[])
{
	//Open the file for reading
    FILE *infile = fopen( filename , "r" );
    
	if (infile != NULL) 
	{    
		//Create labels array and set all elements to -1.  
		int labels[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
		
		int lc = findOrigin(infile);
		
		if (lc > -1)
		{
			//Read in label values
			if (!firstPass(infile, labels, lc))
			{
				//Show the labels.
				printLabels();
				
				//The following is for part 2
				//secondPass(infile, labels, lc);
			}
		}
		
		//Close the file
		fclose(infile);
		
	} 
	else 
	{	
		printf("Can't open input file.\n");		
	}    

}


int findOrigin(FILE *infile)
{
	char line[LINE_SIZE];
	int lineCount = 0; //
	int done = 0;
	char c;
	int origin = -1;
	while (fscanf(infile, "%[^\n]s", line) != EOF && lineCount < LIMIT && !done)
	{
		lineCount++;
		fscanf(infile, "%c", &c);
		char* clean = removeSpaces(line);
		toUpper(clean);
        if (clean[0] != ';' && clean[0] != '\n' && clean[0] != 0)
        {
            char* orig = ".ORIG";
            for (int i = 0; i < 5; i++)
            {
                if (clean[i] != orig[i])
                {
                    printf("ERROR 1: Missing origin directive. Origin must be first line in program.");
                    return -1;
                }
            }
            if (clean[5] == 'X')
            {
                char* p = &clean[6];
                sscanf(p, "%x", &origin);
            } else
            {
                char* p = &clean[6];
                sscanf(p, "%d", &origin);
            }
            done = 1;
        }
		line[0] = 0;
	}
	if (!done || origin == -1)
    {
        printf("ERROR 1: Missing origin directive. Origin must be first line in program.");
        return -1;
    }
	if (origin > 0xFFFF)
    {
	    printf("ERROR 2: Bad origin address. Address too big for 16 bits.");
	    return -1;
    }
	return origin;
}

void toUpper(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32;
    }
}

char* removeSpaces(char *s)
{
    char* out = s;
    int pos = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != ' ' && s[i] != 9)
        {
            out[pos] = s[i];
            pos++;
        }
    }
    out[pos] = 0;
    return out;
}

int firstPass(FILE *infile, int labels[], int lc)
{
	//Create a while loop similar to findOrigin.
	//You can rewind if you want to but you shouldn't have to.
	
	//Read a line.
		//If the line is a comment, a blank line or the .orig directive, don’t do anything.
		//If the line is a label on a line by itself, save the lc to the labels array at the appropriate position.
		//	For example, if L3, store the lc value in labels[3].
		//If the line is a label followed by .fill, save the lc in labels AND increment lc.
		//If the line is .end, return 0 for done with no error.
		//If the end of file is reached before .end is found print the error and return -1.
		//If the line is one of the allowed instructions (ADD, AND, NOT, LD, LDR, ST, STR, BR, and TRAP) increment the lc.
		//If the line is anything else print the unknown instruction error and return -1.

}


