#include <stdio.h>

int main(int argc, char *argv[])
{
	int numFiles = 0;
	while (argv[numFiles] != NULL)
	{
		numFiles += 1;
	}
	int curFile = 0;
	int charsInCurFile = 0;
	int wordsInCurFile = 0;
	int linesInCurFile = 0;
	int charsTotal = 0;
	int wordsTotal = 0;
	int linesTotal = 0;
	for (curFile; curFile < numFiles; curFile++)
	{
		if (argv[1] == NULL)
		{
			printf("ffwc: no file input\n");
			return 0;
		}
		FILE *file = fopen(argv[curFile], "r");
		if (file == NULL)
		{
			printf("ffwc: cannot open file\n");
			return 1;
		}
		char c;
		if (file && curFile != 0)
		{
			charsInCurFile = 0;
			wordsInCurFile = 0;
			linesInCurFile = 0;
			while ((c = getc(file)) != EOF)
			{
				charsInCurFile += 1;
				charsTotal += 1;
				if (c == ' ' || c == '\t')
				{
					wordsInCurFile += 1;
					wordsTotal += 1;
				}
				if (c == '\n' || c == '\0')
				{
					linesInCurFile += 1;
					linesTotal += 1;
				}
			}
			printf("Current File: %s\n", argv[curFile]);
			printf("\tChar Count: %d\n", charsInCurFile);
			printf("\tWord Count: %d\n", wordsInCurFile);
			printf("\tLine Count: %d\n", linesInCurFile);
		}
		fclose(file);
	}
	printf("Total Result:\n");
	printf("\tChar Count: %d\n", charsTotal);
	printf("\tWord Count: %d\n", wordsTotal);
	printf("\tLine Count: %d\n", linesTotal);
	return 0;
}
