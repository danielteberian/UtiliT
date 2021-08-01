#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	// Ensure that an argument has been provided.
	if(argc < 2)
	{
		printf("ERROR: You need to provide a string to be reversed.\n");
		printf("EX: 'revstr hello'\n");
	}

	// Ensure that the provided argument is a string.
	for(int j=1;j<= argc-1;j++)
	{
		for(int k=0;argv[j][k]!='\0';k++)
		{
			if(isalpha(argv[j][k])== 0)
			{
				printf("ERROR: Make sure that you have provided a string.\n");
				return 2;
			}
		}
	}

	// The code that is in charge of the actual reversing process.
	for (int i = argc - 1; i > 0; i--)
	{
		for (int j = strlen(argv[i]) - 1; j >= 0; j--)
			printf("%c", argv[i][j]);
	}
	printf("\n");

return 0;
}
