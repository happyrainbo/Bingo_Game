#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define FLUSH while(getchar()!='\n') 
//�x�s�C�� 
void savegame(int num[], int p_check[],int c_num[], int c_check[])
{
	typedef struct
	{
		char* name[20];
		int pass;
	}USER;//User����A�]�t�ϥΪ̦W��(�r��)�A�ϥΪ̱K�X(�Ʀr) 
	FILE* sp;//�ɮ� 
	int i;//for�j��ϥ� 
	
	USER user;//�إ�user���� 
	sp=fopen("savegame.txt","w");//�}�ҹC���s���ɮ� 
	
	//�n�D�ϥΪ̿�J�ϥΪ̱b���M�K�X 
	printf("�п�J�ϥΪ̱b��:\n");
	scanf("%s",&user.name);
	while(true)//�@������ 
	{
		printf("�п�J�Ʀr�ϥΪ̱K�X�H�ѤU���}��:\n");
		if((scanf("%d",&user.pass))!=1)
		{
			printf("��J���~�A�Э��s��J\n");
			FLUSH;
		}
		else
			break;//���Xwhile�j�� 
	}
	//�N�ϥΪ̱b���M�K�X�s�J�ɮ� 
	fprintf(sp,"%s\n",user.name);
	fprintf(sp,"%d\n",user.pass);
	//�N�ϥΪ̼Ʀr���}�C�s�J�ɮ� 
	for(i=0;i<25;i++)
	{
		fprintf(sp,"%d ",num[i]);
	}
	fprintf(sp,"\n");
	//�N�u�T�{�ϥΪ̪��Ʀr�v���}�C�s�J�ɮ�
	for(i=0;i<25;i++)
	{
		fprintf(sp,"%d ",p_check[i]);
	}
	fprintf(sp,"\n");
	//�N�q���Ʀr���}�C�s�J�ɮ� 
	for(i=0;i<25;i++)
	{
		fprintf(sp,"%d ",c_num[i]);
	}
	fprintf(sp,"\n");
	//�N�u�T�{�q�����Ʀr�v���}�C�s�J�ɮ�
	for(i=0;i<25;i++)
	{
		fprintf(sp,"%d ",c_check[i]);
	}
	fprintf(sp,"\n");
	
	fclose(sp);//�����ɮ� 
	printf("�w�s��\n");//�s�ɦ��\�T�� 
	system("pause");
	exit(0);//�����{�� 
	return;
}
