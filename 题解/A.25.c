//图书管理
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void insert(FILE *book)
{
	system("cls");
	printf("[insert]\n");
	int n;//n为插入的图书数量
    char name[101],info[1001];
	printf("n:");
	scanf("%d",&n);
	getchar();
	for (int i=1; i<=n; i++) 
	{
		printf("name:");
		gets(name);
		printf("info:");
		gets(info);	
        fputs("name:",book);
        fputs(name,book);
        fputs("\ninfo:",book);
        fputs(info,book);
        fputs("\n",book);	
	}
}

void search(FILE *book)
{
	char *find;
	system("cls");
	printf("[search]\n");
	char name[101];
    char temp[1001];
	printf("searchname:");
	gets(name);
	fgetc(book);
	while (!feof(book))
	{
        fseek(book,-1L,SEEK_CUR);
        fgets(temp,6,book);
        fgets(temp,101,book);
		if((find=strchr(temp,'\n'))!=NULL)*find = '\0';
		if(strcmp(name,temp)==0)
		{
			puts(temp);
            fgets(temp,6,book);
            fgets(temp,1001,book);
			if((find=strchr(temp,'\n'))!=NULL)*find = '\0';
            puts(temp);
            break;
		}
		else
		{
			fgets(temp,1007,book);
		}
        fgetc(book);
	}
}

void delete(FILE *book,FILE *copy)
{
	char *find;
	system("cls");
	printf("[delete]\n");
	char name[101];
    char temp[1001];
	printf("deletename:");
	gets(name);
	fgetc(book);
	while (!feof(book))
	{
        fseek(book,-1L,SEEK_CUR);
        fgets(temp,6,book);
        fgets(temp,101,book);
		if((find=strchr(temp,'\n'))!=NULL)*find = '\0';
		if(strcmp(name,temp)!=0)
		{
			fputs("name:",copy);
        	fputs(temp,copy);
        	fputs("\ninfo:",copy);
            fgets(temp,6,book);
            fgets(temp,1001,book);
            fputs(temp,copy);
		}
		else
		{
			fgets(temp,1006,book);
		}
        fgetc(book);
	}
}

int main()
{
    FILE *book,*copy;
    char command[10];
    while (strlen(gets(command))!=0)
	{
		if(strcmp(command,"insert")==0)
		{
            book=fopen("book.txt","a");
			insert(book);
            fclose(book);
		}
        
		else if(strcmp(command,"search")==0)
		{
            if((book=fopen("book.txt","r"))==NULL)
            {
                printf("error\n");
                continue;
            }
			search(book);
            fclose(book);
		}
		else if(strcmp(command,"delete")==0)
		{
			if((book=fopen("book.txt","r"))==NULL||(copy=fopen("copy.txt","w"))==NULL)
            {
                printf("error\n");
                continue;
            }
			delete(book,copy);
			fclose(book);
			fclose(copy);
			remove("book.txt");
			rename("copy.txt","book.txt");
		}
	}
	return 0;
}