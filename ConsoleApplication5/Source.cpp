#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	FILE *file = fopen("ppriceCode.txt", "r");
	int count = 0;
	char a[100];
	while (count <=1)
	{	

		fgets(a,100,file);
		count++;
	}
	//printf("%d\n", count);
	puts(a);
	count = 0;
	int n;
	int j = 0;
	int b = 0;
	char arr[10];
	for (int i = 0; i < strlen(a); i++)
	{	
		if (count == 2)
		{
			j = i;
			while (a[j] != '\t')
			{
				arr[b] = a[j];
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
			while (a[j] != '\n')
			{
				arr[b] = a[j];
				b++;
				j++;
			}
			n = atoi(arr);
			printf("%d\n", n);
			break;
		}
		if (a[i] == '\t' || a[i] == '\n')
			count++;
	}
	fclose(file);
}