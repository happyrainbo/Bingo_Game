#include<stdio.h>
#include<stdlib.h>
//�p�⪱�a�s�u��
int line_count(int num[],int check[])
{
	int i,j;//for�j��ϥ� 
	int c;//�ˬd�Ʀr�O�_�w�g��� 
	int cross=0;//�����׽u������ 
	int vertical=0;//���������u������
	int horizontal=0;//���������u������ 
	int total=0;//�����`�s�u��
	
	//�p��׽u���s�u�� 
	for(i=0;i<25;i+=6)//0,6,12,18,24 
	{
		c=print_check(check,num[i]);//-> print_check�A�ˬd�Ʀr�O�_�w�g����Ac=1�w����Ac=0����� 
		if(c==1)//�Ʀr�w��� 
		{
			cross++;//�׽u�����+1 
			if(cross==5)//�׽u����ƹF5�A�N��w�s�u 
			{
				cross=0;
				total++;//�`�s�u��+1 
			}		
		}
	}
	cross=0;
	//�p��ϱ׽u���s�u�� 
	for(i=4;i<21;i+=4)//4,8,12,16,20
	{	
		c=print_check(check,num[i]);//-> print_check�A�ˬd�Ʀr�O�_�w�g����Ac=1�w����Ac=0����� 
		if(c==1)//�Ʀr�w���
		{
			cross++;//�׽u�����+1
			if(cross==5)//�׽u����ƹF5�A�N��w�s�u
			{
				cross=0;
				total++;//�`�s�u��+1
			}
		}
	}
	//�p������u���s�u�� 
	for(i=0;i<25;i+=5)//0,5,10,15,20
	{
		horizontal=0;
		for(j=i;j<i+5;j++)//i,i+1,i+2,i+3,i+4
		{
			c=print_check(check,num[j]);//-> print_check�A�ˬd�Ʀr�O�_�w�g����Ac=1�w����Ac=0�����
			if(c==1)//�Ʀr�w���
			{
				horizontal++;//�����u�����+1
				if(horizontal==5)//�����u����ƹF5�A�N��w�s�u
					total++;//�`�s�u��+1	
			}
		}
	}
	//�p�⫫���u���s�u�� 
	for(i=0;i<5;i++)//0,1,2,3,4 
	{
		vertical=0;
		for(j=i;j<25;j+=5)//i,i+5,i+10,i+15,i+20
		{
			c=print_check(check,num[j]);//-> print_check�A�ˬd�Ʀr�O�_�w�g����Ac=1�w����Ac=0�����
			if(c==1)//�Ʀr�w���
			{
				vertical++;//�����u�����+1
				if(vertical==5)//�����u����ƹF5�A�N��w�s�u
					total++;//�`�s�u��+1	
			}
		}
	}
	return total;
}
