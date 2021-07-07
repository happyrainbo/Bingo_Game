#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define FLUSH while(getchar()!='\n') 
//儲存遊戲 
void savegame(int num[], int p_check[],int c_num[], int c_check[])
{
	typedef struct
	{
		char* name[20];
		int pass;
	}USER;//User角色，包含使用者名稱(字串)，使用者密碼(數字) 
	FILE* sp;//檔案 
	int i;//for迴圈使用 
	
	USER user;//建立user角色 
	sp=fopen("savegame.txt","w");//開啟遊戲存檔檔案 
	
	//要求使用者輸入使用者帳號和密碼 
	printf("請輸入使用者帳號:\n");
	scanf("%s",&user.name);
	while(true)//一直執行 
	{
		printf("請輸入數字使用者密碼以供下次開啟:\n");
		if((scanf("%d",&user.pass))!=1)
		{
			printf("輸入錯誤，請重新輸入\n");
			FLUSH;
		}
		else
			break;//跳出while迴圈 
	}
	//將使用者帳號和密碼存入檔案 
	fprintf(sp,"%s\n",user.name);
	fprintf(sp,"%d\n",user.pass);
	//將使用者數字的陣列存入檔案 
	for(i=0;i<25;i++)
	{
		fprintf(sp,"%d ",num[i]);
	}
	fprintf(sp,"\n");
	//將「確認使用者的數字」的陣列存入檔案
	for(i=0;i<25;i++)
	{
		fprintf(sp,"%d ",p_check[i]);
	}
	fprintf(sp,"\n");
	//將電腦數字的陣列存入檔案 
	for(i=0;i<25;i++)
	{
		fprintf(sp,"%d ",c_num[i]);
	}
	fprintf(sp,"\n");
	//將「確認電腦的數字」的陣列存入檔案
	for(i=0;i<25;i++)
	{
		fprintf(sp,"%d ",c_check[i]);
	}
	fprintf(sp,"\n");
	
	fclose(sp);//關閉檔案 
	printf("已存檔\n");//存檔成功訊息 
	system("pause");
	exit(0);//關閉程式 
	return;
}
