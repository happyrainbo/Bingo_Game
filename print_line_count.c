#include<stdio.h>
#include<stdlib.h>
//��ܳs�u�� 
void print_line_count(int line,int name)
{
	if(name==0)//�ϥΪ̪���ܦr�� 
	{
		printf("  �z�ثe��%d���s�u\n",line);
	}
	else if(name==1)//�q������ܦr�� 
	{
		printf("�q���ثe��%d���s�u\n",line);
	}
	return;
}
