#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("Specify a file name:\n");
	char *filename;
	int bufsize = 100;
	int length = 0;
	filename = (char *)malloc(bufsize * sizeof(char));
	length = getline(&filename, &bufsize, stdin);
	if (length == -1)
	{
		puts("No input detected!\n");
	}
	else
		printf("You have a file named %s", filename);
	/*open the  file  in read/write mode, if this file doesn't exist , then create it*/
	filename[length - 1] = '\0';
	FILE *fp = fopen(filename, "w+");
	free(filename);
	/* check if we hav successfully opened this file*/
	if (fp)
	{
		printf("File open successful! And write something to that file:\n");
		char *content;
		content = (char *)malloc(bufsize * sizeof(char));
		int content_size = getline(&content, &bufsize, stdin);
		/* write to file*/
		if (content_size == -1)
		{
			puts("You input nothing.\n");
		}
		else
			fprintf(fp, content);
		/* close file */
		free(content);
		if (fclose(fp) == 0)
		{
			printf(" File closed successful\n");

			return 0;
		}
		else
		{
			printf("Failed to close file \n");

			exit(1);
		}
	}
	else
	{
		printf("Failed to open file\n");
		system("pause");
		exit(1);
	}
}
