#include<stdio.h>
#include<stdlib.h>
//�����q�����@��ΦC�w�g�����s�u 
int computer_complete_check(int comp[],int n) 
{
	int i;//for�j��ϥ� 
	int result=1;//�P�_�O�_�w�g�����s�u�Aresult=1�w�����Aresult=0������ 
	
	//��ƩM�}�C����Ƥ@�@��� 
	for(i=0;i<10;i++)
	{
		if(n==comp[i])//�Y�ۦP�N������ 
		{
			result=0;
		}
	}
	return result;
}
