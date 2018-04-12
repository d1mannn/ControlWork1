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

	long CountChar = 0; // создал дл€ подсета чаров в файле

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
	
	while (!feof(file)) // подситал кол-во чаров
	{
		fgetc(file);
		CountChar++;
	}
	rewind(file); // вернул файл в начало
	printf("%d", CountChar);
	CountChar -= 1; // сделал -1 чтобы послденим элементом был \n
	system("pause");
	for (int i = 0; i < CountChar; i++)
	{
		fscanf_s(file, "%c", &buffer[i]); // заполнил буффер посимвольно чарами из файла
	}

	// buffer заполне€тс€ полностью без каких либо проблем - провер€л неоднакратно
	//puts(buffer);
	system("pause");
	int countOfchar = 0;
	char countName[5];
	int ccc = 0; // создал дл€ проверки как работает заполнение каждого файла при делении
	int z = 0;
	for (int i = 0; i < CountChar; i++)
	{	
		if (buffer[i] == '\n' && buffer[i + 1] == '\t')
		{	
			z = 0;
			char *arr = (char*)calloc(countOfchar + 1, sizeof(char));
			for (int  j = i - countOfchar; j < i; j++)
			{
				arr[z] = buffer[j];
				z++;
			}
			if (ccc == 1)
			{
				ccc++;
			}
			if (ccc == 3)
				ccc++;
			if (ccc == 0)
			{
				FILE * fff;
				errno_t errr = fopen_s(&fff, "123.txt", "w");
				if (err != 0)
				{
					perror("ERROR");
					system("pause");
					exit(1);
				}
				for (int j = 0; j < z; j++)
				{
					fprintf(fff, "%c", arr[j]);
				}
				ccc++;
				i++; // делать об€зательно чтобы файл начинал с табул€ции
				fclose(fff);
			}
			if (ccc == 2)
			{
				FILE * fff;
				errno_t errr = fopen_s(&fff, "321.txt", "w");
				if (err != 0)
				{
					perror("ERROR");
					system("pause");
					exit(1);
				}
				for (int j = 0; j < z; j++)
				{
					fprintf(fff, "%c", arr[j]);
				}
				fclose(fff);
				i++; // делать об€зательно чтобы файл начинал с табул€ции
				ccc++;
			}
			
			if (ccc == 4)
			{
				FILE * fff;
				errno_t errr = fopen_s(&fff, "Test123.txt", "w");
				if (err != 0)
				{
					perror("ERROR");
					system("pause");
					exit(1);
				}
				for (int j = 0; j < z; j++)
				{
					fprintf(fff, "%c", arr[j]);
				}
				ccc++;
				i++; // делать об€зательно чтобы файл начинал с табул€ции
				fclose(fff);
			}
			
			
			countOfchar = 0;
			
		}
		countOfchar++;
	}
	for (int i = CountChar - 100; i < CountChar; i++)
	{
		printf("%c", buffer[i]);
	}
	printf("!%c!", buffer[CountChar]);

	//puts(buffer);
	free(buffer);
	system("pause");
	return 0;





	int count = 0;
	int n;
	int j = 0;
	int b = 0;
	char arr[10];
	for (long i = 0; i < 50; i++)
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