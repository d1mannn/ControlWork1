#include "Header.h"

int main()
{	

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	FILE *file;
	errno_t err = fopen_s(&file, "ppriceCode.txt", "r");
	if (err != 0)
	{
		perror("Error");
		system("pause");
		exit(1);
	}
	long CountChar = 0;
	fseek(file, 0, SEEK_END);
	long fSize = ftell(file);
	rewind(file);
	char *buffer = (char*)calloc(fSize, sizeof(char));
	if (buffer == NULL)
	{
		printf("ERROR\n");
		system("pause");
		exit(1);
	}
	
	while (!feof(file))
	{
		fgetc(file);
		CountChar++;
	}
	rewind(file);
	printf("%d", CountChar);
	CountChar -= 1;
	system("pause");
	for (int i = 0; i < CountChar; i++)
	{
		fscanf_s(file, "%c", &buffer[i]);
	}

	int countOfchar = 0;
	for (int i = 0; i < CountChar - 1; i++)
	{
		if (buffer[i] == '\t' && buffer[i + 1] == '\n')
		{

		}
		countOfchar++;
	}
	printf("!%c!", buffer[CountChar - 1]);

	//puts(buffer);
	free(buffer);
	system("pause");
	return 0;

	int count = 0;
	int n;
	int j = 0;
	int b = 0;
	char arr[10];
	for (long i = 0; i < fSize; i++)
	{
		if (count == 2)
		{
			j = i;
			while (buffer[j] != '\t')
			{
				arr[b] = buffer[j];
				b++;
				j++;
			}
			n = atoi(arr);
			printf("%d\n", n);
			count++;
		}
		if (count == 4)
		{
			j = i;
			b = 0;
			while (buffer[j] != '\n')
			{
				arr[b] = buffer[j];
				b++;
				j++;
			}
			n = atoi(arr);
			printf("%d\n", n);
			break;
		}
		if (buffer[i] == '\t' || buffer[i] == '\n')
			count++;
	}
	puts(buffer);
	free(buffer);
	fclose(file);
	return 0;



	while (!feof(file))
	{	
		fgets(buffer,100,file);
		count++;
	}
	//printf("%d\n", count);
	puts(buffer);

	// 
	fclose(file);

	return 0;


	/*
	count = 0;
	int n;
	int j = 0;
	int b = 0;
	char arr[10];
	for (int i = 0; i < strlen(buffer); i++)
	{	
		if (count == 2)
		{
			j = i;
			while (buffer[j] != '\t')
			{
				arr[b] = buffer[j];
				b++;
				j++;
			}
			n = atoi(arr);
			printf("%d\n", n);
			count++;
		}
		if (count == 4)
		{	
			j = i;
			b = 0;
			while (buffer[j] != '\n')
			{
				arr[b] = buffer[j];
				b++;
				j++;
			}
			n = atoi(arr);
			printf("%d\n", n);
			break;
		}
		if (buffer[i] == '\t' || buffer[i] == '\n')
			count++;
	}
	fclose(file);*/
}