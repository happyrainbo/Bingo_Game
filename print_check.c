#include<stdio.h>
#include<stdlib.h>
//�ˬd�Ʀr�O�_�w�g��� 
int print_check(int check[], int input)
{
	int i;//for�j��ϥ� 
	int result=1;//�ˬd�Ʀr�O�_�w�g����Aresult=0�����Aresult=1�w��� 
	
	//�N�Ʀr�M�}�C�����Ʀr�@�@��� 
	for(i=0;i<25;i++)
	{
		if(input==check[i])//�Y�ۦP�h�N��Ʀr����� 
		{
			result=0;
		}
	}
	return result; 
}
