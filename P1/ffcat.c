#include <stdio.h>

int main(int argc, char *argv[])
{
	int numFiles = 0;
	while (argv[numFiles] != NULL)
	{
		numFiles += 1;
	}
	int curFile = 0;
	for (curFile; curFile < numFiles; curFile++)
	{
		if (argv[curFile] == NULL)
		{
			printf("ffcat: no file input\n");
			return 0;
		}
		FILE *file = fopen(argv[curFile], "r");
		if (file == NULL)
		{
			printf("ffcat: cannot open file\n");
			return 1;
		}
		char c;
		if (file && curFile != 0)
		{
			while ((c = getc(file)) != EOF)
			{
				putchar(c);
			}
		}
		fclose(file);
	}
	return 0;
}
