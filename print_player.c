#include<stdio.h>
#include<stdlib.h>
//��ܥثe�ϥΪ̪��Ʀr 
void print_player(int num[],int check[])
{
	int i,j;//for�j��ϥ� 
	int c;//�ˬd�O�_�Ʀr�w���Ac=0�����Ac=1�w��� 
	
	//��ܥثe�ϥΪ̪��Ʀr 
	printf("�z������\n");
	printf(" �ġġġġġġġġġġġ� \n");
	for(i=0;i<25;i+=5)
	{
		for(j=i;j<i+5;j++)
		{
			c=print_check(check,num[j]);//->print_check�A�ˬd�Ʀr�O�_�w�g����Ac=0������Ac=1�w��� 
			if(c==0)//�Ʀr������h��X�Ʀr 
			{
				printf("|%3d ",num[j]);
			}
			else if(c==1)//�Ʀr�w����h��X��߶� 
			{
				printf("| �� ");
			}
		}
		printf("|\n");
		if(i<20) 
			printf("|�ССССССССССС�|\n");
	}
	printf(" �ááááááááááá� \n");
	return;
}