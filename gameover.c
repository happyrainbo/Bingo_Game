#include<stdio.h>
#include<stdlib.h>
//�P�_�C���O�_���� 
int gameover(int p, int c)
{
	int over=0;//�P�_�C���O�_���� 
	if(p>=5&&c>=5&&p==c)//�ϥΪ̩M�q�����s�u�Ƴ��F5�B�s�u�ƬۦP�A���� 
	{
		over=3;
	}
	else if(p>=5&&p>c)//�ϥΪ̳s�u�ƹF5�B�s�u�Ƥj��q���A�ϥΪ���� 
	{
		over=1;
	}
	else if(c>=5&&c>p)//�q���s�u�ƹF5�B�s�u�Ƥj�󪱮a�A�q����� 
	{
		over=2;
	}
	return over;
}
