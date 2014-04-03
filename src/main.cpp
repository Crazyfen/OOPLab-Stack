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
//объявляем все используемые в программе функции:   
	stack* Create(void);             //создание контейнера
	void Delete(pstack &begin);      //удаление контейнера
	stack* AddLeftElement(pstack &begin, char* s);  //добавление элемента в начало
	stack* AddRightElement(pstack &end, char* s);   //добавление элемента в конец
	stack* Search(pstack &begin, char *s);      //поиск элемента
	stack* ExtractLeft(pstack &begin);      //извлечение элемента из начала
	stack* ExtractRight(pstack &end);		//извлечение элемента из конца
	void IteratorFromLeft(pstack &begin);   //прямой итератор
	void IteratorFromRight(pstack &end);	  //обратный итератор
	void ClearDubles(pstack &begin, pstack &end);		//удаление дублирующих элементов
	int NumberOfElements(pstack &begin);  //подсчет элементов в контейнере 
	stack* Revers(pstack &begin, pstack &end);  //реверс контейнера
	void WriteInFile(pstack &begin);		//запись контейнера в файл
	stack* ReadFromFile(pstack &begin);		//чтение контейнера из файла 
//------------------------------------------------------------------------------
void main() 
{ 
	int k=15;
	while (k!=0)	//выводим меню пользователя
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
		printf ("0. Otmena \n");	//выход из меню при вводе 0
		printf ("Dlya prodolzheniya viberite nomer punkta: ");
		scanf("%d",&k);

		switch(k) 
		{		//каждой функции соответствует свой номер:
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
stack* Create(void)  //описание работы функции, создающей контейнер
{	
	pstack cont;
	cont=NULL;
	printf("Konteiner udachno sozdan \n");
	return begin; 
}  
//------------------------------------------------------------------------------
void Delete(pstack &begin) //описание работы функции, уничтожающей контейнер
{
	if(flag==false)      //проверка наличия контейнера
		printf("Konteiner ne sozdan \n");   
	else             
	{                          
		pstack dop=new stack; //выделение динамической памяти под новую переменную
		dop=begin;
		begin=dop->next;
		delete dop;      //освобождение динамической памяти
		if(begin!=NULL)
		Delete(begin);   //рекурсивный вызов функции
 	}  	
		printf("Udachno udaleno \n"); 
}
//------------------------------------------------------------------------------
stack* AddLeftElement(pstack &begin, char *s)    //добавляет элемент в начало
{
	if(flag)
	{                             
		int size;
		pstack str=new stack;  //выделение динамической памяти под новую переменную
		size=strlen(s);
		if (str!=NULL) 
			printf("Element dobavlen \n");
		else
			printf("Error!");
		if(begin==NULL)	//если элемент первый
		{						 	
			str->mean=new char[size+1];	    //выделение памяти
			strcpy(str->mean, s);	     //копируем значение
			str->prev=NULL;		   //заполнение полей
			str->next=NULL;
			begin=str;
			end=begin;
		}
		else 
		{
			str->mean=new char[size+1];	    //выделение памяти
			strcpy(str->mean, s);	   //копируем значение
			str->next=begin;	  //заполнение полей
			str->prev=NULL;
			begin->prev=str;   
			begin=str;
		}
		return begin;
	}
	else printf("Konteiner ne sozdan \n");    
}
//------------------------------------------------------------------------------
stack* AddRightElement(pstack &begin, char *s)    //добавляет элемент в конец
{
	if(flag)
	{     
		int size;
		pstack str=new stack;  //выделение динамической памяти под новую переменную
		size=strlen(s);
		if (str!=NULL) 
			printf("Element dobavlen \n");
		else
			printf("Error!");
		if(begin==NULL)	//если элемент первый
		{						 	
			str->mean=new char[size+1];	    //выделение памяти
			strcpy(str->mean, s);	     //копируем значение
			str->prev=NULL;		   //заполнение полей
			str->next=NULL;
			end=str;
			begin=str;
		}
		else 
		{
			str->mean=new char[size+1];	    //выделение памяти
			strcpy(str->mean, s);	   //копируем значение
			str->next=NULL;	  //заполнение полей
			str->prev=end;
			end->next=str;
			end=str;
		}
		return end;
	}
	else printf("Konteiner ne sozdan \n");    
}
//------------------------------------------------------------------------------
stack* Search(pstack &begin, char *s)  //выясняет, есть ли в деке элемент
{
	if(begin!=NULL)		//есть ли элементы
	{	
		int a=0;
		pstack step=new stack;   //выделяем память
		step=begin;
		while(step!=NULL)   //пробегаем по деку
		{
			if(strcmp(step->mean, s)==0)	 //условие совпадения строк
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
stack* ExtractLeft(pstack &begin)     //извлечение элемента из начала
{
	if(begin!=NULL)		//есть ли элементы
	{
		pstack extr=new stack;   //выделяем память
		extr=begin;
		if(extr)						 //если не ноль
			printf("%s", extr->mean);   //выводим значение первого элемента
		begin=extr->next;  
		delete extr;       //очищаем память
		begin->prev=NULL;
		return begin;
	}
	else 
	printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
stack* ExtractRight(pstack &end)     //извлечение элемента из конца
{
	if(begin!=NULL)			//есть ли элементы
	{
		pstack extr=new stack;   //выделяем память
		extr=end;
		if(extr)						//если не ноль
			printf("%s", extr->mean);   //выводим значение последнего элемента
		end=extr->prev;
		delete extr;                 //очищаем память
		end->next=NULL;
		return end;
	}
	else 
	printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
void IteratorFromLeft(pstack &begin)		//итератор от начала к концу
{
	if(begin!=NULL)			//есть ли элементы
	{                     
		pstack step=new stack;
		step=begin;
		while(step!=NULL)  //пока не наткнемся на ноль
		{
			printf("%s \n", step->mean);    //вывод на экран дека
			step=step->next;  //проходим от начала до конца
		}
	}
	else printf("Konteiner ne sozdan \n");   
}
//------------------------------------------------------------------------------
void IteratorFromRight(pstack &end)		//итератор от конца к началу
{
	if(begin!=NULL)			//есть ли элементы
	{
		pstack step=new stack;
		step=end;
		while(step!=NULL)   //пока не наткнемся на ноль
		{ 
			printf("%s \n", step->mean);  //вывод на экран дека
			step=step->prev;     //проходим с конца в начало
		}
	}
	else printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
void ClearDubles(pstack &begin, pstack &end)	//очисткf повторяющихся элементов
{
	if(begin!=NULL)		//есть ли элементы
	{      
		pstack ptr=new stack;
		pstack dop=new stack;
		for (dop=begin; dop!=end; dop=dop->next)  //обходим дек
		{
			for (ptr=dop->next; ptr!=NULL; ptr=ptr->next)  //еще раз проходим
						//по всему списку, сравнивая каждый элемент с value
			{
				if (strcmp(ptr->mean, dop->mean)==0 && ptr->next==NULL)	//если
									  //значения совпали и при этом элемент 
										  //сравнения оказался последним
				{
					ptr=ptr->prev;			//удаление
					ptr->next=NULL;
					end=ptr;
				}
				else 
					if (strcmp(ptr->mean, dop->mean)==0)   //если значения 
													//совпали
					{
						ptr=ptr->prev;				//удаление найденного
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
int NumberOfElements(pstack &begin)  //функция подсчитывает элементы в контейнере 
{
	if(begin!=NULL)			//есть ли элементы
	{
		int sum=0;           //сюда будет записываться количество элементов
		pstack pnt=new stack;    //выделяем динамическую память
		pnt=begin;			 //устанавливаем курсор на начало контейнера 
		while(pnt!=NULL)	 //проходим до конца контейнера
		{
			sum++;			 //подсчитываем элементы
			pnt=pnt->next;
		}
		printf("%d", sum);   //выводим получившееся количество
		return sum;
	}
	else 
		if (begin==NULL && flag==true) 
			printf("Net elementov v konteinere \n");
	else 
		printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
stack* Revers(pstack &begin, pstack &end)   //реверс контейнера
{
	if(begin!=NULL)			//есть ли элементы
	{
		int sum=0;
		pstack pnt=new stack;
		pnt=begin;
		while(pnt!=NULL)	//вычисляем длину списка
		{
			sum++;
			pnt=pnt->next;
		}					//в sum хранится количество элементов контейнера
		int  t;
		char s[120];
		t=sum/2;		     //определение количества операций
		pstack pntBeg=new stack;
		pstack pntEnd=new stack;
		pntBeg=begin;
		pntEnd=end;
		while(t!=0)			  //реверс дека
		{
			strcpy(s, pntEnd->mean);             //меняем местами
			strcpy(pntEnd->mean, pntBeg->mean);  //данные в 1х и последних
			strcpy(pntBeg->mean, s);			 //элементах
			pntBeg=pntBeg->next;
			pntEnd=pntEnd->prev;
			t--;
		}
		return begin;
	}
	else printf("Konteiner ne sozdan /n");
}

//------------------------------------------------------------------------------
void WriteInFile(pstack &begin)   //записываем контейнер в файл
{
	if(begin!=NULL)			//есть ли элементы
	{
		int str;
		pstack pnt=new stack;
		pnt=begin;						//установление указателя на первый элемент
		FILE *file;
		file= fopen("Proba.txt","wb");
		if (file==NULL) 
			printf("Faila net \n");			//Ошибка открытия файла
		while(pnt!=NULL)
		{
			str=strlen(pnt->mean);		//вычисление длины строки
			fprintf(file,"%d",str);		//занесение в файл длины строки
			fputs(pnt->mean, file);		//занесение строки
			pnt=pnt->next;
		}
		fputs("end",file);
		fclose(file);			//закрываем файл
	}
	else printf("Konteiner ne sozdan \n");
}
//------------------------------------------------------------------------------
stack* ReadFromFile(pstack &begin)    //считываем контейнер из файла 
{
	int size;           //размер строки
	int n=0;            //номер элемента
	char s[120];
	size=strlen(s);
	begin=new stack;	
	end=new stack;
	FILE *file;
	file = fopen("Proba.txt","rb");	   //открытие файла
	if (file==NULL) 
		printf("Faila net /n");			//ошибка открытия файла
	fseek(file,0,SEEK_SET);			//передвижка указателя на начало файла
	for(;;)
	{				
		fgets(s,size+1,file);		//считывание строки из файла
		if (strcmp(s,"end")==0)     //если конец файла
			break;						
		if (n==0)						//если элемент первый
		{				
			pstack pnt=new stack;			//создание нового узла
			pnt->mean=new char;			//выделение памяти 
			strcpy(pnt->mean, s);		//занесение значения 
			pnt->next=NULL;
			pnt->prev=NULL;
			begin=pnt;
			end=pnt;
			n++;
		}
		else
		{
			pstack pnt=new stack;			//создание нового узла
			pnt->mean=new char;			//выделение памяти 
			strcpy(pnt->mean, s);		//занесение значения 
			pnt->prev=end;
			end->next=pnt;
			end=pnt;
			end->next=NULL;
		}
	}
	fclose(file);	     //закрытие файла
	return begin;
}