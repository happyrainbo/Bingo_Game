#include<stdio.h>
#include<stdlib.h>
//��ܹC��������T 
void print_gameover(int over,int p_line, int c_line)
{
	printf("�ССССССССССССССССС�\n");
	printf("�C�������A�q�� %d ���s�u: �z %d ���s�u\n",c_line,p_line);
	if(over==1)//���a��� 
	{
		printf("���߱z���ѤF�q��\n\n");
	}
	else if(over==2)//�q����� 
	{
		printf("�z�鵹�q���F�A�U���[�o\n\n");
	}
	else if(over==3)//���� 
	{
		printf("�z�M�q����������F�A�A�Ӥ@���a\n\n");
	}
	return;
}
