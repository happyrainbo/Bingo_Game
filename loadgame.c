#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Ū���C�� 
int loadgame(int num[], int p_check[],int c_num[], int c_check[])
{
	typedef struct
	{
		char* name[20];
		int pass;
	}USER;//User����A�]�t�ϥΪ̦W��(�r��)�A�ϥΪ̱K�X(�Ʀr)
	FILE* sp;//�ɮ�
	int i;//for�j��ϥ� 
	char* name[20];//�x�s�ϥΪ̿�J�ϥΪ̱b�� 
	int pass;//�x�s�ϥΪ̿�J�ϥΪ̱K�X 
	int cmp;//�ˬd�ϥΪ̱b���O�_�ۦP 
	int load=0;//�s�ɪ��A 
	int try_t=3;//�K�X���զ��� 
	char zero[20]="0";//�Ω󪽱��}�l�s�C�� 
	
	USER user;//�إ�user���� 
	sp=fopen("savegame.txt","r");//�}�ҹC���s���ɮ�
	
	if(fscanf(sp,"%s",&user.name)==EOF)//�P�_���L�C���s�� 
		return load;//���o�{�s�� 
	printf("�o�{�s��\n");
	//�ШϥΪ̿�J�ϥΪ̱b�� 
	printf("�п�J�ϥΪ̱b��:(�ο�J0�����}�l�s�C��)\n");
	scanf("%s",&name);
	cmp=strcmp(name,zero);
	if(cmp==0)
	{
		fclose(sp);//�����ɮ� 
		sp=fopen("savegame.txt","w");//�M���ɮ� 
		fclose(sp);//�����ɮ� 
		return load;//�����}�l�s�C��
	}	 
	//����J���ϥΪ̱b���M�s�ɪ��ϥΪ̱b�� 
	cmp=strcmp(name,user.name);
	if(cmp!=0)//�ϥΪ̱b�����۲� 
	{
		printf("�ϥΪ̱b�����۲�\n");
		printf("�N�}�l�s���@��\n");
		printf("�ССССССССС�\n");
		fclose(sp);//�����ɮ� 
		sp=fopen("savegame.txt","w");//�M���ɮ� 
		fclose(sp);//�����ɮ� 
	}
	else//�ϥΪ̱b���۲� 
	{
		fscanf(sp,"%d",&user.pass);
		while(try_t>0)//�@�T�����տ�J�K�X���| 
		{
			printf("�п�J�ϥΪ̱K�X:\n");
			scanf("%d",&pass);
			//����J���ϥΪ̱K�X�M�s�ɪ��ϥΪ̱K�X 
			if(pass==user.pass)
			{
				load=1;//���\�T�{�ϥΪ� 
				break;//���Xwhile�j�� 
			}
			else
			{
				try_t--;//���վ��|-1 
				if(try_t>0)
				{
					printf("�K�X���~�A�z�٦�%d�����|\n",try_t);
				}
			}
		}
		if(load==0)//�T�{�ϥΪ̥��� 
		{
			printf("���~���ƹF3���A�N�}�l�s���@��\n");
			printf("�СССССССССССССС�\n");
			fclose(sp);//�����ɮ� 
			sp=fopen("savegame.txt","w");//�M���ɮ� 
			fclose(sp);//�����ɮ� 	
		}
		else if(load==1)//���\�T�{�ϥΪ� 
		{
			//Ū���ϥΪ̼Ʀr���}�C 
			for(i=0;i<25;i++)
			{
				fscanf(sp,"%d",&num[i]);
			}
			//Ū���u�T�{�ϥΪ̪��Ʀr�v���}�C 
			for(i=0;i<25;i++)
			{
				fscanf(sp,"%d",&p_check[i]);
			}
			//Ū���q���Ʀr���}�C 
			for(i=0;i<25;i++)
			{
				fscanf(sp,"%d",&c_num[i]);
			}
			//Ū���u�T�{�q�����Ʀr�v���}�C
			for(i=0;i<25;i++)
			{
				fscanf(sp,"%d",&c_check[i]);
			}
		}
	}
	return load;
}
