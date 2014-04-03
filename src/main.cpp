//#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

struct stack{
	char *mean;
	stack *next;
	stack *priv;};

typedef stack *pstack;
pstack begin, end, pol;

typedef char *pchar;
char s[128];
	stack* create(void);
	stack* add_elem_left(pstack &begin, char *s);
	stack* add_elem_right(pstack &end, char *s);
	void left_right(pstack &begin);
	void right_left(pstack &end);
	stack* pull_left(pstack &begin);
	stack* pull_right(pstack &end);
	int amount(pstack &begin);
	void search(pstack &begin, char *s);
	void duble(pstack &begin);
	void del(pstack &begin);
	void writeinfile(pstack &begin);
	stack* readfile(pstack &begin);
	stack* revers(pstack &begin, pstack &end);


	void main(){
		int k;
		for(;;){
			system("cls");
printf("1. Cozdat konteiner.\n");                               //���������� ������� ����
printf("2. Dobavit element sleva.\n");
printf("3. Dobavit element sprava.\n");
printf("4. Iterator sleva napravo.\n");
printf("5. Iterator sprava nalevo.\n");
printf("6. izvlechenie sleva.\n");
printf("7. izvlechenie sprava.\n");
printf("8. chislo elementov.\n");
printf("9. poisk.\n");
printf("10. udalenie dubley.\n");
printf("11. udalenie konteinera.\n");
printf("12. revers.\n");
printf("13. zapis v file.\n");
printf("14. chenie iz file.\n");
printf("15. vixod.\n");
printf("Vvedite nomer pynkta:");
scanf("%d",&k);  

switch (k) {  
	case 1: {
		system("cls");
		create();
		break;}
	case 2: {
		system("cls");
		printf("vvedite znachenie\n");
scanf("%s", &s);
		add_elem_left(begin, s);
		break;}
	case 3:{
		system("cls");
		printf("vvedite znachenie\n");
scanf("%s", &s);
		add_elem_right(end, s);
		break;}
	case 4:{
		system("cls");
		left_right(begin);
		break;}
	case 5:{
		system("cls");
		right_left(end);
		break;}
	case 6:{
		system("cls");
		pull_left(begin);
		break;}
	case 7:{
		system("cls");
		pull_right(end);
		break;}
	case 8:{
		system("cls");
		amount(begin);
		break;}
	case 9:{
		system("cls");
		printf("vvedite znachenie\n");				//������� �����
scanf("%s", &s);
		search(begin, s);
		break;}
	case 10:{
		system("cls");
		duble(begin);
		break;}
	case 11:{
		system("cls");
		del(begin);
		break;}
	case 12:{
		system("cls");
		revers(begin, end);
		break;}
	case 13:{
		system("cls");
		writeinfile(begin);
		break;}
	case 14:{
		system("cls");
		readfile(begin);
		break;}}

if (k==15) break;
getch();}}



	stack* create(void)
	{
begin=new stack;	
end=new stack;
pol=new stack;
	if (pol!=NULL) 
		printf("konteyner sozdan\n");
	else
		printf("error");

pol->mean=NULL;
pol->next=NULL;
pol->priv=NULL;
begin=pol;
end=pol;
	return begin;
	}

stack* add_elem_left(pstack &begin, char *s)
{
	if(begin!=NULL){
	int size;
pstack str=new stack;
if (str!=NULL) 
		printf("element dobavlen\n");
	else
		printf("error");
size=strlen(s);
if(begin->mean==NULL)	{						//���� ������� ������ 	
str=begin;
str->mean=new char[size+1];		//��������� ������ ��� obj
strcpy(str->mean, s);					//��������� �������� � obj
str->priv=NULL;				//���������� �����
str->next=NULL;}
else {
str->mean=new char[size+1];		//��������� ������ ��� obj
strcpy(str->mean, s);					//��������� �������� � obj
str->next=begin;					//���������� �����
str->priv=NULL;
begin->priv=str;
begin=str;}
return begin;
	}
	else printf("sozdayte konteuner");}

stack* add_elem_right(pstack &end, char *s)
	{
		if(begin!=NULL){
	int size;
pstack str=new stack;
if (str!=NULL) 
		printf("element dobavlen\n");
	else
		printf("error");
size=strlen(s);
	if(begin->mean==NULL)				//���� ������� ������ 	
	{
		str=begin;
		str->mean=new char[size+1];		//��������� ������ ��� obj
		strcpy(str->mean, s);					//��������� �������� � obj	
		str->priv=NULL;		//���������� �����
		str->next=NULL;
		end=str;
	}
	else
	{
		str->mean=new char[size+1];		//��������� ������ ��� obj
		strcpy(str->mean, s);					//��������� �������� � obj
		str->next=NULL;					//���������� �����
		str->priv=end;
		end->next=str;
		end=str;
	}
	return end;
		}
		else printf("sozdayte konteyner");}


void left_right(pstack &begin)
	{
		if(begin!=NULL){
pstack cur=new stack;
cur=begin;
while(cur!=NULL)			//���� �� ����� ������, ���������� 
		{
		printf("%s\n", cur->mean);
		cur=cur->next;
		}
		}
	}

void right_left(pstack &end){
	if(begin!=NULL){
pstack cur=new stack;
cur=end;
	while(cur!=NULL)			//���� �� ����� ������, ���������� 
		{
		printf("%s\n", cur->mean);
		cur=cur->priv;
		}
	}}

stack* pull_left(pstack &begin)
	{
		if(begin!=NULL&&begin->priv!=NULL){
pstack cur=new stack;
cur=begin;
	if(cur)
		printf("%s", cur->mean);
begin=cur->next;
delete cur;
begin->priv=NULL;
return begin;
		}
		else printf("sozdayte konteyner, esli konteyner sozdan vvedite znachenie");}

stack* pull_right(pstack &end)
	{
			if(begin!=NULL&&begin->next!=NULL){
pstack cur=new stack;
cur=end;
	if(cur)
		printf("%s", cur->mean);
end=cur->priv;
delete cur;
end->next=NULL;
return end;
			}
else printf("sozdayte konteyner, esli konteyner sozdan vvedite znachenie");
}

int amount(pstack &begin)
{
	int sum=0;
pstack cur=new stack;
cur=begin;
	while(cur!=NULL)
	{
		sum++;
		cur=cur->next;
	}
printf("%d", sum);
return sum;
}

void search(pstack &begin, char *s)
{
	if(begin!=NULL){
	int d=0;
	pstack cur=new stack;
	cur=begin;
cur=begin;
	while(cur!=NULL)
	{
		if(strcmp(cur->mean, s)==0)			//���� ������ ���������
				d++;
		cur=cur->next;
	}
		if(d!=0)
				printf("znachenie naydeno");
					else printf("znachenie ne naydeno");
	}
	else("sozdayte konteyner");}

void duble(pstack &begin)
{
	if(begin!=NULL){
	char val[128];
	pstack cur=new stack;
	pstack point=new stack;
	for (point=begin; point!=end; point=point->next)
	{
		strcpy(val, point->mean);											//��������� ��������
		for (cur=point->next; cur!=NULL; cur=cur->next)		//�������� ���� ���������
		{
			if (strcmp(cur->mean, val)==0 && cur->next==NULL)			//���������� ���� �� ������
			{
				cur=cur->priv;
				end->priv=NULL;
				cur->next=NULL;
				end->mean=NULL;
				end=cur;
			}
else
			if (strcmp(cur->mean, val)==0)
			{
				cur=cur->priv;
				cur->next=cur->next->next;
				cur=cur->next;
				cur->priv=cur->priv->priv;
			}
		}
	}
	}
else("sozdayte konteyner");}


void del(pstack &begin)
{
	if(begin==NULL)
		printf("konteynera netu\n");
	else
	{
pstack cur=new stack;
cur=begin;
begin=cur->next;
delete cur;
	if(begin!=NULL)
		del(begin);
	}			//����������� ����� �������
}

stack* revers(pstack &begin, pstack &end)
{
	if(begin!=NULL){
int sum=0;
pstack cur=new stack;
cur=begin;
	while(cur!=NULL)			//���������� ����� ������
	{
		sum++;
		cur=cur->next;
	}
int  t;
char s[128];
t=sum/2;					//����������� ���������� ��������
pstack curl=new stack;;
pstack curr=new stack;
curl=begin;
curr=end;
		while(t!=0)			//������ ����
		{
			strcpy(s, curr->mean);
			strcpy(curr->mean, curl->mean);
			strcpy(curl->mean, s);
			curl=curl->next;
			curr=curr->priv;
			t--;
		}
		return begin;}
	else printf("sozdayte konteyner");}

void writeinfile(pstack &begin){
	if(begin!=NULL){
	int n;
pstack cur=new stack;
cur=begin;						//������������ ��������� �� ������ �������
FILE *file = fopen("C:\\QQQ.txt","wb");
	if (file==NULL) 
		printf("Faila nety.");			//������ �������� �����
	while(cur!=NULL)
	{
		n=strlen(cur->mean);		//���������� ����� ������
		fprintf(file,"%d",n);			//��������� � ���� ����� ������
		fputs(cur->mean, file);			//��������� ������
		cur=cur->next;
	}
	fputs("3end",file);
fclose(file);
	}
	else printf("sozdayte konteyner");}


stack* readfile(pstack &begin){
	int size;
	int n=0;
char s[128];
begin=new stack;	
end=new stack;
	FILE *file;
	file = fopen("C:\\QQQ.txt","rb");	            //�������� �����
	if (file==NULL) 
		printf("Faila nety.");			//������ �������� �����
									
fseek(file,0,SEEK_SET);						//���������� ��������� �� ������ �����
	for(;;)
	{				
		fgets(s,size+1,file);								//���������� ������ �� ����
		if (strcmp(s,"end")==0) break;			//���� ����� �����

		if (n==0)								//���� ������� ������
		{				
			pstack cur=new stack;				//�������� ������ ����
			cur->mean=new char;				//��������� ������ ��� obj
			strcpy(cur->mean, s);					//��������� �������� � obj
			cur->next=NULL;
			cur->priv=NULL;
			begin=cur;
			end=cur;
			n++;
		}
		else
		{
			pstack cur=new stack;				//�������� ������ ����
			cur->mean=new char;				//��������� ������ ��� obj
			strcpy(cur->mean, s);					//��������� �������� � obj
			cur->priv=end;
			end->next=cur;
			end=cur;
			end->next=NULL;
		}
	}
fclose(file);								//�������� �����
return begin;
}
