#include<stdio.h>
#include<stdlib.h>

//�P�_�ϥΪ̱���諸�Ʀr�O�_�w�g���L 
int used_check(int check[], int input)
{
	int i;//for�j��ϥ� 
	int result=1;//�ˬd�Ʀr�O�_�w�g���Aresult=0�٨S���Aresult=1�w��� 
	
	//�N�Ʀr�M�}�C�����Ʀr�@�@��� 
	for(i=0;i<25;i++)
	{
		if(input==check[i])//�p�G�ۦP�h�N����� 
		{
			result=0;
			check[i]=0;//�令0�A�U���˴��ɴN�|�O�w��� 
		}
	}
	return result;
}
