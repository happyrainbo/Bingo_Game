#include<stdio.h>
#include<stdlib.h>
//�q����ܱ���諸�Ʀr 
void computer_choose(int num[], int c_check[], int p_check[],int comp[]) 
{
	int i,j;//for�j��ϥ� 
	int c=1;//�ˬd�O�_�w�g��� 
	int l=0;//�̦h���ΦC����� 
	int n=0;//�x�s����ΦC����Ƴ̦h 
	int cmp;//�ˬd����ΦC�w�g�s�u 
	int horizontal=0;//�x�s�����u������� 
	int vertical=0;//�x�s�����u�������
	
	//�u����ܧ����׽u���s�u 
	for(i=0; i<25&&c==1; i+=6) 
	{
		c=used_check(c_check,num[i]);//->used_check�A�ˬd�Ʀr�O�_�w�g���Ac=0�٨S���Ac=1�w��� 
		if(c==0) //�Y�����h������ 
		{
			printf("�ССССССССС�\n");
			printf("�q�����F�Ʀr%d\n",num[i]);
			used_check(p_check,num[i]);//->used_check�A��s�t�@�Ӥw���Ʀr���}�C 
			break;//���Xfor�j�� 
		}
	}
	//���u����ܧ����ϱ׽u���s�u 
	for(i=4; i<21&&c==1; i+=4) 
	{
		c=used_check(c_check,num[i]);//->used_check�A�ˬd�Ʀr�O�_�w�g���Ac=0�٨S���Ac=1�w���
		if(c==0) //�Y�����h������
		{
			printf("�ССССССССС�\n");
			printf("�q�����F�Ʀr%d\n",num[i]);
			used_check(p_check,num[i]);//->used_check�A��s�t�@�Ӥw���Ʀr���}�C
			break;//���Xfor�j�� 
		}
	}
	//�����׽u������A�P�_����ΦC���w���Ƹ��h�A�u�������ӱ��s�u 
	if(c==1) 
	{
		//�P�_�����u���w���� 
		for(i=0; i<25; i+=5) 
		{
			horizontal=0;
			cmp=computer_complete_check(comp,i/5);//->computer_complete_check�A�P�_�O�_�Ӥ����u�w�g�s�u�Aresult=1�w�����Aresult=0������ 
			if(cmp==1)//�Y�Ӥ����u�w�����s�u�h���U�@�� 
				continue;
			for(j=i; j<i+5; j++) 
			{
				c=print_check(c_check,num[j]);//->print_check�A�ˬd�Ʀr�O�_�w�g���Ac=0�٨S���Ac=1�w���
				if(c==1) //�Ʀr�w��� 
				{
					horizontal++;//�����u����+1 
					if(horizontal>l) //�Y���Ƥj���L���u 
					{
						l=horizontal;//�����̤j���� 
						n=i/5;//���������u�s�� 
						if(l==5)//�Y�̤j���ƹF5�A�N��w�g�s�u 
						{
							computer_complete_update(comp,n);//->computer_complete_update�A��s�w�s�u�������u�s�� 
							computer_choose(num,c_check,p_check,comp);
						}
					}
				}
			}
		}
		//�P�_�����u���w����
		for(i=0; i<5; i++) 
		{
			vertical=0;
			cmp=computer_complete_check(comp,i+5);//->computer_complete_check�A�P�_�O�_�ӫ����u�w�g�s�u�Aresult=1�w�����Aresult=0������
			if(cmp==1)//�Y�ӫ����u�w�����s�u�h���U�@�� 
				continue;
			for(j=i; j<25; j+=5) 
			{
				c=print_check(c_check,num[j]);//->print_check�A�ˬd�Ʀr�O�_�w�g���Ac=0�٨S���Ac=1�w���
				if(c==1) //�Ʀr�w���
				{
					vertical++;//�����u����+1 
					if(vertical>l) //�Y���Ƥj���L���u
					{
						l=vertical;//�����̤j���� 
						n=i+5;//����t�����u�s�� 
						if(l==5)//�Y�̤j���ƹF5�A�N��w�g�s�u
						{
							computer_complete_update(comp,n);//->computer_complete_update�A��s�w�s�u�������u�s�� 
							computer_choose(num,c_check,p_check,comp);
						}
					}
				}
			}
		}
		//�Y�����u�����Ƹ��h 
		if(n>=0&&n<=4)
		{
			for(i=n*5; i<n*5+5; i++) 
			{
				c=used_check(c_check,num[i]);//->used_check�A�ˬd�Ʀr�O�_�w�g���Ac=0�٨S���Ac=1�w���
				if(c==0) //�Y�����h������ 
				{
					printf("�ССССССССС�\n");
					printf("�q�����F�Ʀr%d\n",num[i]);
					used_check(p_check,num[i]);//->used_check�A��s�t�@�Ӥw���Ʀr���}�C
					break;//���Xfor�j�� 
				}
			}
		}
		//�Y�����u�����Ƹ��h
		else if(n>=5&&n<=9)
		{
			for(i=n-5; i<25; i+=5)
			{
				c=used_check(c_check,num[i]);//->used_check�A�ˬd�Ʀr�O�_�w�g���Ac=0�٨S���Ac=1�w���
				if(c==0) //�Y�����h������ 
				{
					printf("�ССССССССС�\n");
					printf("�q�����F�Ʀr%d\n",num[i]);
					used_check(p_check,num[i]);//->used_check�A��s�t�@�Ӥw���Ʀr���}�C
					break;//���Xfor�j��
				}
			}
		}
	}
	return;
}
