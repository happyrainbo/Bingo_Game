#include<stdio.h>
#include<stdlib.h>
//��s�q�����@��ΦC�w�g�����s�u
void computer_complete_update(int comp[],int n) 
{
	int i;//for�j��ϥ�
	
	//��ƩM�}�C������Ƥ@�@��� 
	for(i=0;i<10;i++)
	{
		if(n==comp[i])//�Y�ۦP�h�N���]�w���w�s�u 
		{
			comp[i]=-1;
		}
	}
	return;
}
