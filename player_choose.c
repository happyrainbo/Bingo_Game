#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define FLUSH while(getchar()!='\n')

//�ϥΪ̿�ܱ���諸�Ʀr
void player_choose(int num[], int p_check[],int c_num[], int c_check[]) 
{
	int input;//�x�s�ϥΪ̿�J 
	int result;///�Ω��ˬd�ϥΪ̬O�_��J���T
	int c;//�ˬd�Ʀr�O�_���L�Ac=0�٨S���Ac=1�w���

	while(true) //�@������ 
	{
		printf("�п�J�n��諸�Ʀr:(�i��J0�Ӧs�ɹC��)\n");
		result=scanf("%d",&input);////�ˬd�ϥΪ̿�J�Aresult=0���~�Aresult=1���T 
		if(result==0) //�ϥΪ̿�J�D�Ʀr�A���ܿ�J�Ʀr
		{
			printf("�п�J�Ʀr\n");
			printf("�ССССССССС�\n");
		} 
		else if(input==0)
		{
			savegame(num,p_check,c_num,c_check);
		}
		else if(input>25||input<1) //�ϥΪ̿�J�Ʀr�d����~�A���ܭ��s��J
		{
			printf("�d����~�A�Э��s��J\n");
			printf("�ССССССССС�\n");
		} 
		else //��J�Ʀr�d�򥿽T
		{
			c=used_check(p_check, input);//->used_check�A�ˬd�Ʀr�O�_�w�g���Ac=0�٨S���Ac=1�w���
			if(c==1)//�Ʀr�w��� 
			{
				printf("��J���Ʀr�w�g�ιL�A�Э��s���\n");
				printf("�ССССССССС�\n");
			}	
			else //�Ʀr����� 
			{
				printf("�ССССССССС�\n");
				printf("�z���F�Ʀr%d\n",input);
				used_check(c_check, input);//->used_check�A��s�t�@�Ӥw���Ʀr���}�C 
				break;//���Xwhile�j�� 
			}
		}
		FLUSH;//�p�ϥΪ̿�J���~�A�N���~���r���M��
	}

	return;
}
