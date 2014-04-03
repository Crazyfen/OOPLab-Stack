//#include <stdafx.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//------------------------------------------------------------------------------
struct stack
{ 
	char* mean;
	stack* next;
	stack* prev;
};
typedef stack* pstack; 
pstack begin, end, pnt;
bool flag=false;
typedef char* pchar;
char s[120];
//��������� ��� ������������ � ��������� �������:   
	stack* Create(void);             //�������� ����������
	void Delete(pstack &begin);      //�������� ����������
	stack* AddLeftElement(pstack &begin, char* s);  //���������� �������� � ������
	stack* AddRightElement(pstack &end, char* s);   //���������� �������� � �����
	stack* Search(pstack &begin, char *s);      //����� ��������
	stack* ExtractLeft(pstack &begin);      //���������� �������� �� ������
	stack* ExtractRight(pstack &end);		//���������� �������� �� �����
	void IteratorFromLeft(pstack &begin);   //������ ��������
	void IteratorFromRight(pstack &end);	  //�������� ��������
	void ClearDubles(pstack &begin, pstack &end);		//�������� ����������� ���������
	int NumberOfElements(pstack &begin);  //������� ��������� � ���������� 
	stack* Revers(pstack &begin, pstack &end);  //������ ����������
	void WriteInFile(pstack &begin);		//������ ���������� � ����
	stack* ReadFromFile(pstack &begin);		//������ ���������� �� ����� 
//------------------------------------------------------------------------------
void main() 
{ 
	int k=15;
	while (k!=0)	//������� ���� ������������
	{
		system("cls");
		printf ("1. Sozdat' konteiner \n");
		printf ("2. Unichtozhenie konteinera \n");
		printf ("3. Dobavit' element sleva \n");
		printf ("4. Dobavit' element sprava \n");
		printf ("5. Poisk elementa \n");
		printf ("6. Izvlechenie elementa sleva \n");
		printf ("7. Izvlechenie elementa sprava \n");
		printf ("8. Iterator sleva napravo \n");
		printf ("9. Iterator sprava nalevo \n");
		printf ("10. Udalenie dublei \n");
		printf ("11. Kolichestvo elementov v konteinere \n");
		printf ("12. Revers konteinera \n");
		printf ("13. Zapis' v fail \n");
		printf ("14. Chtenie iz faila \n"); 
		printf ("0. Otmena \n");	//����� �� ���� ��� ����� 0
		printf ("Dlya prodolzheniya viberite nomer punkta: ");
		scanf("%d",&k);

		switch(k) 
		{		//������ ������� ������������� ���� �����:
			case 1: 
				{
					begin=new stack;
					begin=NULL;
					begin=Create();
					getch();
					flag=true;
					break;

				}
			case 2: 
				{
					Delete(begin);
					getch();
					flag=false;
					break;
				}
			case 3:
				{
					printf ("Vvedite znachenie dobavlyzemogo elementa: \n");
					scanf ("%s", &s);
					AddLeftElement(begin, s);
					getch();
					break;
				}
			case 4: 
				{
					printf ("Vvedite znachenie dobavlyzemogo elementa: \n");
					scanf ("%s", &s);
					AddRightElement(end, s);
					getch();
					break;
				}
			case 5:
				{
					printf ("Vvedite znachenie raziskivaemogo elementa: \n");
					scanf ("%s", &s);
					Search(begin, s);
					getch();
					break;
				}
			case 6: 
				{
					ExtractLeft(begin);
					getch();
					break;
				}
			case 7:
				{
					ExtractRight(end);
					getch();
					break;
				}
			case 8: 
				{
					IteratorFromLeft(begin);
					getch();
					break;
				}
			case 9: 
				{
					IteratorFromRight(end);
					getch();
					break;
				}
			case 10: 
				{
					ClearDubles(begin, end);
					getch();
					break;
				}
			case 11: 
				{
					NumberOfElements(begin);
					getch();
					break;
				}
			case 12: 
				{
					Revers(begin, end);
					getch();  
					break;
				}
			case 13:
				{
					WriteInFile(begin);
					getch();
					break;
				}
			case 14:
				{
					ReadFromFile(begin);
					getch();
					break;
				} 
		}
	}
}
//------------------------------------------------------------------------------
stack* Create(void)  //�������� ������ �������, ��������� ���������
{	
	pstack cont;
	cont=NULL;
	printf("Konteiner udachno sozdan \n");
	return begin; 
}  
//------------------------------------------------------------------------------
void Delete(pstack &begin) //�������� ������ �������, ������������ ���������
{
	if(flag==false)      //�������� ������� ����������
		printf("Konteiner ne sozdan \n");   
	else             
	{                          
		pstack dop=new stack; //��������� ������������ ������ ��� ����� ����������
		dop=begin;
		begin=dop->next;
		delete dop;      //������������ ������������ ������
		if(begin!=NULL)
		Delete(begin);   //����������� ����� �������
 	}  	
		printf("Udachno udaleno \n"); 
}
//------------------------------------------------------------------------------
stack* AddLeftElement(pstack &begin, char *s)    //��������� ������� � ������
{
	if(flag)
	{                             
		int size;
		pstack str=new stack;  //��������� ������������ ������ ��� ����� ����������
		size=strlen(s);
		if (str!=NULL) 
			printf("Element dobavlen \n");
		else
			printf("Error!");
		if(begin==NULL)	//���� ������� ������
		{						 	
			str->mean=new char[size+1];	    //��������� ������
			strcpy(str->mean, s);	     //�������� ��������
			str->prev=NULL;		   //���������� �����
			str->next=NULL;
			begin=str;
			end=begin;
		}
		else 
		{
			str->mean=new char[size+1];	    //��������� ������
			strcpy(str->mean, s);	   //�������� ��������
			str->next=begin;	  //���������� �����
			str->prev=NULL;
			begin->prev=str;   
			begin=str;
		}
		return begin;
	}
	else printf("Konteiner ne sozdan \n");    
}
//------------------------------------------------------------------------------
stack* AddRightElement(pstack &begin, char *s)    //��������� ������� � �����
{
	if(flag)
	{     
		int size;
		pstack str=new stack;  //��������� ������������ ������ ��� ����� ����������
		size=strlen(s);
		if (str!=NULL) 
			printf("Element dobavlen \n");
		else
			printf("Error!");
		if(begin==NULL)	//���� ������� ������
		{						 	
			str->mean=new char[size+1];	    //��������� ������
			strcpy(str->mean, s);	     //�������� ��������
			str->prev=NULL;		   //���������� �����
			str->next=NULL;
			end=str;
			begin=str;
		}
		else 
		{
			str->mean=new char[size+1];	    //��������� ������
			strcpy(str->mean, s);	   //�������� ��������
			str->next=NULL;	  //���������� �����
			str->prev=end;
			end->next=str;
			end=str;
		}
		return end;
	}
	else printf("Konteiner ne sozdan \n");    
}
//------------------------------------------------------------------------------
stack* Search(pstack &begin, char *s)  //��������, ���� �� � ���� �������
{
	if(begin!=NULL)		//���� �� ��������
	{	
		int a=0;
		pstack step=new stack;   //�������� ������
		step=begin;
		while(step!=NULL)   //��������� �� ����
		{
			if(strcmp(step->mean, s)==0)	 //������� ���������� �����
			{	
				printf("Znachenie naideno \n");
				a++;
				return step;
				break;
			}
			step=step->next;
		}
		if (a==0)
			printf("Znachenie ne naideno \n");
	}
	else("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
stack* ExtractLeft(pstack &begin)     //���������� �������� �� ������
{
	if(begin!=NULL)		//���� �� ��������
	{
		pstack extr=new stack;   //�������� ������
		extr=begin;
		if(extr)						 //���� �� ����
			printf("%s", extr->mean);   //������� �������� ������� ��������
		begin=extr->next;  
		delete extr;       //������� ������
		begin->prev=NULL;
		return begin;
	}
	else 
	printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
stack* ExtractRight(pstack &end)     //���������� �������� �� �����
{
	if(begin!=NULL)			//���� �� ��������
	{
		pstack extr=new stack;   //�������� ������
		extr=end;
		if(extr)						//���� �� ����
			printf("%s", extr->mean);   //������� �������� ���������� ��������
		end=extr->prev;
		delete extr;                 //������� ������
		end->next=NULL;
		return end;
	}
	else 
	printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
void IteratorFromLeft(pstack &begin)		//�������� �� ������ � �����
{
	if(begin!=NULL)			//���� �� ��������
	{                     
		pstack step=new stack;
		step=begin;
		while(step!=NULL)  //���� �� ��������� �� ����
		{
			printf("%s \n", step->mean);    //����� �� ����� ����
			step=step->next;  //�������� �� ������ �� �����
		}
	}
	else printf("Konteiner ne sozdan \n");   
}
//------------------------------------------------------------------------------
void IteratorFromRight(pstack &end)		//�������� �� ����� � ������
{
	if(begin!=NULL)			//���� �� ��������
	{
		pstack step=new stack;
		step=end;
		while(step!=NULL)   //���� �� ��������� �� ����
		{ 
			printf("%s \n", step->mean);  //����� �� ����� ����
			step=step->prev;     //�������� � ����� � ������
		}
	}
	else printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
void ClearDubles(pstack &begin, pstack &end)	//������f ������������� ���������
{
	if(begin!=NULL)		//���� �� ��������
	{      
		pstack ptr=new stack;
		pstack dop=new stack;
		for (dop=begin; dop!=end; dop=dop->next)  //������� ���
		{
			for (ptr=dop->next; ptr!=NULL; ptr=ptr->next)  //��� ��� ��������
						//�� ����� ������, ��������� ������ ������� � value
			{
				if (strcmp(ptr->mean, dop->mean)==0 && ptr->next==NULL)	//����
									  //�������� ������� � ��� ���� ������� 
										  //��������� �������� ���������
				{
					ptr=ptr->prev;			//��������
					ptr->next=NULL;
					end=ptr;
				}
				else 
					if (strcmp(ptr->mean, dop->mean)==0)   //���� �������� 
													//�������
					{
						ptr=ptr->prev;				//�������� ����������
						ptr->next=ptr->next->next;
						ptr=ptr->next;
						ptr->prev=ptr->prev->prev;
						ptr=ptr->prev;
					}
			}
		}
	}
	else printf("Konteiner ne sozdan \n");   
}
//------------------------------------------------------------------------------
int NumberOfElements(pstack &begin)  //������� ������������ �������� � ���������� 
{
	if(begin!=NULL)			//���� �� ��������
	{
		int sum=0;           //���� ����� ������������ ���������� ���������
		pstack pnt=new stack;    //�������� ������������ ������
		pnt=begin;			 //������������� ������ �� ������ ���������� 
		while(pnt!=NULL)	 //�������� �� ����� ����������
		{
			sum++;			 //������������ ��������
			pnt=pnt->next;
		}
		printf("%d", sum);   //������� ������������ ����������
		return sum;
	}
	else 
		if (begin==NULL && flag==true) 
			printf("Net elementov v konteinere \n");
	else 
		printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
stack* Revers(pstack &begin, pstack &end)   //������ ����������
{
	if(begin!=NULL)			//���� �� ��������
	{
		int sum=0;
		pstack pnt=new stack;
		pnt=begin;
		while(pnt!=NULL)	//��������� ����� ������
		{
			sum++;
			pnt=pnt->next;
		}					//� sum �������� ���������� ��������� ����������
		int  t;
		char s[120];
		t=sum/2;		     //����������� ���������� ��������
		pstack pntBeg=new stack;
		pstack pntEnd=new stack;
		pntBeg=begin;
		pntEnd=end;
		while(t!=0)			  //������ ����
		{
			strcpy(s, pntEnd->mean);             //������ �������
			strcpy(pntEnd->mean, pntBeg->mean);  //������ � 1� � ���������
			strcpy(pntBeg->mean, s);			 //���������
			pntBeg=pntBeg->next;
			pntEnd=pntEnd->prev;
			t--;
		}
		return begin;
	}
	else printf("Konteiner ne sozdan /n");
}

//------------------------------------------------------------------------------
void WriteInFile(pstack &begin)   //���������� ��������� � ����
{
	if(begin!=NULL)			//���� �� ��������
	{
		int str;
		pstack pnt=new stack;
		pnt=begin;						//������������ ��������� �� ������ �������
		FILE *file;
		file= fopen("Proba.txt","wb");
		if (file==NULL) 
			printf("Faila net \n");			//������ �������� �����
		while(pnt!=NULL)
		{
			str=strlen(pnt->mean);		//���������� ����� ������
			fprintf(file,"%d",str);		//��������� � ���� ����� ������
			fputs(pnt->mean, file);		//��������� ������
			pnt=pnt->next;
		}
		fputs("end",file);
		fclose(file);			//��������� ����
	}
	else printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
stack* ReadFromFile(pstack &begin)    //��������� ��������� �� ����� 
{
	int size;           //������ ������
	int n=0;            //����� ��������
	char s[120];
	size=strlen(s);
	begin=new stack;	
	end=new stack;
	FILE *file;
	file = fopen("Proba.txt","rb");	   //�������� �����
	if (file==NULL) 
		printf("Faila net /n");			//������ �������� �����
	fseek(file,0,SEEK_SET);			//���������� ��������� �� ������ �����
	for(;;)
	{				
		fgets(s,size+1,file);		//���������� ������ �� �����
		if (strcmp(s,"end")==0)     //���� ����� �����
			break;						
		if (n==0)						//���� ������� ������
		{				
			pstack pnt=new stack;			//�������� ������ ����
			pnt->mean=new char;			//��������� ������ 
			strcpy(pnt->mean, s);		//��������� �������� 
			pnt->next=NULL;
			pnt->prev=NULL;
			begin=pnt;
			end=pnt;
			n++;
		}
		else
		{
			pstack pnt=new stack;			//�������� ������ ����
			pnt->mean=new char;			//��������� ������ 
			strcpy(pnt->mean, s);		//��������� �������� 
			pnt->prev=end;
			end->next=pnt;
			end=pnt;
			end->next=NULL;
		}
	}
	fclose(file);	     //�������� �����
	return begin;
}