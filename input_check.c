#include<stdio.h>
#include<stdlib.h>
//�ˬd�Ʀr�O�_�w�g��J 
int input_check(int num[],int n) 
{
	int i;//for�j��ϥ� 
	int c=0;//�ˬd�Ʀr�O�_�w�g��J�Ac=1�w��J�Ac=0����J
	
	//�N�ϥΪ̿�J���Ʀr�M�}�C�����Ʀr�@�@��� 
	for(i=0;i<25;i++)
	{
		if(n==num[i])//�Y�ۦP�h�N��w�g��J 
		{
			c=1;
		}
	}
	return c;
}
