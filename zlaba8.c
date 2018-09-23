#include <stdio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000

void delite_prev_word ( char [] );

void main ( void )
{
	
	char line[MAXLINE];

	printf("Введите строку символов: ");
	gets( line );

	delite_prev_word( line );

	puts( line );
}

void delite_prev_word ( char bufer[] )
{
	char *buf_ptr;//указатель на адрес обрабатываемого элемента строки
	char *start_ptr;//указатель на адрес элемента начала слова
	char *stop_ptr;//указатель на адрес элемента конца слова
    char *prev_start_ptr;//указатель на адрес элемента начала предыдущего слова
    char *prev_stop_ptr;//указатель на адрес элемента конца предыдущего слова
	
	int flag;
	
	
	start_ptr = stop_ptr = buf_ptr =  bufer;
	
	flag = NO;
	
	do
	{
		
		//если втречен разделитель
		if (*buf_ptr ==' ' || *buf_ptr ==',' || *buf_ptr =='.' || *buf_ptr =='!' || *buf_ptr =='?' || *buf_ptr =='\0' || *buf_ptr == '\n')
		{
			if( flag == YES)
			{	
				stop_ptr = buf_ptr - 1;
				
				flag = NO;
			}
		}
		else
		{
			if (flag == NO)
			{
				prev_stop_ptr = stop_ptr;//запоминаем адрес конца предыдущего слова
				prev_start_ptr = start_ptr;//запоминаем адрес начала предыдущего слова
				
				start_ptr = buf_ptr;
				
				flag = YES;
			}
		}


		buf_ptr++;
		
	}
	while( *buf_ptr != '\0');
	
	prev_stop_ptr += 2;
	
	for( ; *prev_start_ptr != '\0'; prev_start_ptr++) 
	{ 
		*prev_start_ptr = *prev_stop_ptr; 
		prev_stop_ptr++; 
	} 
	*prev_stop_ptr = '\0';
}