#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define FLUSH while(getchar()!='\n')
//���ϥΪ̦ۦ�M�w��J�Ʀr�Υѹq���۰ʲ���
void player_input(int num[],int check[]) 
{
	int i;//for�j��ϥ� 
	int c;//�Ω��ˬd�Ʀr�O�_�w�g��J
	int input;//�x�s�ϥΪ̿�J 
	int result;//�Ω��ˬd�ϥΪ̬O�_��J���T 
	int skip=0;//�Ω�j��ާ@ 
	
	//�N0��J�}�C 
	for(i=0;i<25;i++)
	{
		num[i]=0;
	}
	//���ϥΪ̿�ܦۦ��J�Ʀr�Υѹq���۰ʲ��� 
	for(i=0; i<25&&skip==0; i++) 
	{
		while(true)//�@������ 
		{
			printf("�п�J1~25���Ʀr(�ο�J0�ѹq���۰ʲ���):\n");
			result=scanf("%d",&input);//�ˬd�ϥΪ̿�J�Aresult=0���~�Aresult=1���T 
			if(result==0) //�ϥΪ̿�J�D�Ʀr�A���ܿ�J�Ʀr 
			{
				printf("�п�J�Ʀr\n");
				printf("�ССССССССС�\n");
			} 
			else if(input==0)//�ϥΪ̨M�w�ѹq���۰ʲ��ͼƦr 
			{
				generate_number(num,0);//->generate_number�A�ѹq���۰ʲ��ͪ��a���Ʀr�}�C 
				skip=1;//���Xfor�j�� 
				break;//���Xwhile�j�� 
			}
			else if(input>25||input<1)//�ϥΪ̿�J�Ʀr�d����~�A���ܭ��s��J 
			{
				printf("�d����~�A�Э��s��J\n");
				printf("�ССССССССС�\n");
			} 
			else //��J�Ʀr�d�򥿽T 
			{
				c=input_check(num, input);//->input_check�A�ˬd�Ʀr�O�_�w�g��J�Ac=1�w��J�Ac=0����J 
				if(c==1) //�Ʀr�w�g��J 
				{
					printf("��J���Ʀr�w�g�ιL�A�Э��s���\n");
					printf("�ССССССССС�\n");
				} 
				else //�Ʀr����J 
				{
					printf("�ССССССССС�\n");
					num[i]=input;//�N�ϥΪ̿�J��J�}�C 
					if(i<24)//��J24�ӼƦr���e��ܨϥΪ̪��Ʀr�A��J25�ӼƦr��ϥΪ̪��Ʀr�N��main�I�s��� 
					{
						print_player(num,check);//->print_player�A��ܥثe�ϥΪ̪��Ʀr 
					}
					break;//��J���T�A���Xwhile�j��A�i��U�@�Bfor�j�� 
				}
			}
			FLUSH;//�p�ϥΪ̿�J���~�A�N���~���r���M�� 
		}
	}
	return; 
}
