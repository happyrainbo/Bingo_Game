#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//���ͼƦr���}�C
void generate_number(int num[],int name)
{
	int i;//for�j��ϥ� 
	int ran;//�x�s�H���üơA�Ω�M�w����ӼƦr�洫 
	int temp;//�Ω�Ʀr�洫�Ȧs 
	
	//�N0~24��J�}�C 
	for(i=0;i<25;i++)
		num[i]=i+1;
	//�M�w�üƺؤl	
	if(name==0)
		srand(time(NULL));
	else if(name==1)
		srand(time(NULL)+1);
	//�}�C���Ʀr�洫�A�Φ��H�������A		
	for(i=0;i<25;i++)
	{
		ran=rand()%25;
		temp=num[i];
		num[i]=num[ran];
		num[ran]=temp;
	}
	return;
}
