#include "Header.h"


void RandomFileName(char * arr, int * count)
{
	arr[strlen(arr) - 1] = *count;
}

void FilesCreation(int start, int end, int * count)
{
	FILE *newFile;
	char a = fromIntToChar();
	char fileName[] = "File # ";
	itoa(1, fileName, a);
//	errno_t err = fopen_s(&newFile, fileName, "w");
}

int fromIntToChar()
{
	int n;
	scanf_s("%i", &n);
	char* c;
	c = (char *)malloc(10 * sizeof(char));
	int v = 0; //количество цифр в числе n
			   //разбиваем на отдельные символы число n
	while (n > 9)
	{
		c[v++] = (n % 10) + '0';
		n = n / 10;
	}
	c[v++] = n + '0';
	c[v] = '\0';
	char t;
	//инвертируем массив символов
	for (int i = 0; i < v / 2; i++)
	{
		t = c[i];
		c[i] = c[v - 1 - i];
		c[v - 1 - i] = t;
	}
	v = 0;
	while (c[v] != '\0')
		printf("%c", c[v++]);
	printf("\n");
	return *c;
	free(c);
}