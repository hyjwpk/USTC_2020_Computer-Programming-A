//图书管理
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


struct book_list//链表
{
    char name[101];
	char info[1001];
    struct book_list *next;
} ;

struct book_list* insert(struct book_list *p)
{
	system("cls");
	printf("[insert]\n");
	int n;//n为插入的图书数量
	printf("n:");
	scanf("%d",&n);
	getchar();
	for (int i=1; i<=n; i++) 
	{
		p->next=(struct book_list*) malloc(sizeof(struct book_list));
		p=p->next;
		printf("name:");
		gets(p->name);
		printf("info:");
		gets(p->info);		
	}
	return p;
}

struct book_list* search(struct book_list *p)
{
	system("cls");
	printf("[search]\n");
	char name[101];
	printf("searchname:");
	gets(name);
	while (p->next!=NULL)
	{
		p=p->next;
		if(strcmp(name,p->name)==0)
		{
			return p;
		}
	}
	return NULL;
}

void delete(struct book_list *p,struct book_list **tail)
{
	system("cls");
	printf("[delete]\n");
	struct book_list *target;
	char name[101];
	printf("deletename:");
	gets(name);
	while (p->next!=NULL)
	{
		target=p;//存储当前书目的上一节点
		p=p->next;
		if(strcmp(name,p->name)==0)
		{
			break;
		}
		target=NULL;//若未查询到target为NULL
	}
	if(target==NULL)
	{
		printf("Fail\n");
	}
	else
	{
		printf("name:");
		puts(p->name);
		printf("info:");
		puts(p->info);
		printf("DeleteSuccess\n");
		target->next=p->next;
		if(p->next==NULL) *tail=target;
		free(p);
	}
}

int main()
{
	struct book_list head, *tail,*target,*p;
    char command[10];
	tail=p=&head;
	tail->next=NULL;
    while (strlen(gets(command))!=0)
	{
		if(strcmp(command,"insert")==0)
		{
			tail=insert(tail);
			tail->next=NULL;
		}
		else if(strcmp(command,"search")==0)
		{
			target=search(&head);
			if(target==NULL)
			{
				printf("Fail\n");
			}
			else
			{
				printf("name:");
				puts(target->name);
				printf("info:");
				puts(target->info);
			}
		}
		else if(strcmp(command,"delete")==0)
		{
			delete(&head,&tail);
		}
	}
	return 0;
}