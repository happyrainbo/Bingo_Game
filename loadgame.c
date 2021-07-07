#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//讀取遊戲 
int loadgame(int num[], int p_check[],int c_num[], int c_check[])
{
	typedef struct
	{
		char* name[20];
		int pass;
	}USER;//User角色，包含使用者名稱(字串)，使用者密碼(數字)
	FILE* sp;//檔案
	int i;//for迴圈使用 
	char* name[20];//儲存使用者輸入使用者帳號 
	int pass;//儲存使用者輸入使用者密碼 
	int cmp;//檢查使用者帳號是否相同 
	int load=0;//存檔狀態 
	int try_t=3;//密碼嘗試次數 
	char zero[20]="0";//用於直接開始新遊戲 
	
	USER user;//建立user角色 
	sp=fopen("savegame.txt","r");//開啟遊戲存檔檔案
	
	if(fscanf(sp,"%s",&user.name)==EOF)//判斷有無遊戲存檔 
		return load;//未發現存檔 
	printf("發現存檔\n");
	//請使用者輸入使用者帳號 
	printf("請輸入使用者帳號:(或輸入0直接開始新遊戲)\n");
	scanf("%s",&name);
	cmp=strcmp(name,zero);
	if(cmp==0)
	{
		fclose(sp);//關閉檔案 
		sp=fopen("savegame.txt","w");//清空檔案 
		fclose(sp);//關閉檔案 
		return load;//直接開始新遊戲
	}	 
	//比對輸入的使用者帳號和存檔的使用者帳號 
	cmp=strcmp(name,user.name);
	if(cmp!=0)//使用者帳號不相符 
	{
		printf("使用者帳號不相符\n");
		printf("將開始新的一局\n");
		printf("－－－－－－－－－－\n");
		fclose(sp);//關閉檔案 
		sp=fopen("savegame.txt","w");//清空檔案 
		fclose(sp);//關閉檔案 
	}
	else//使用者帳號相符 
	{
		fscanf(sp,"%d",&user.pass);
		while(try_t>0)//共三次嘗試輸入密碼機會 
		{
			printf("請輸入使用者密碼:\n");
			scanf("%d",&pass);
			//比對輸入的使用者密碼和存檔的使用者密碼 
			if(pass==user.pass)
			{
				load=1;//成功確認使用者 
				break;//跳出while迴圈 
			}
			else
			{
				try_t--;//嘗試機會-1 
				if(try_t>0)
				{
					printf("密碼錯誤，您還有%d次機會\n",try_t);
				}
			}
		}
		if(load==0)//確認使用者失敗 
		{
			printf("錯誤次數達3次，將開始新的一局\n");
			printf("－－－－－－－－－－－－－－－\n");
			fclose(sp);//關閉檔案 
			sp=fopen("savegame.txt","w");//清空檔案 
			fclose(sp);//關閉檔案 	
		}
		else if(load==1)//成功確認使用者 
		{
			//讀取使用者數字的陣列 
			for(i=0;i<25;i++)
			{
				fscanf(sp,"%d",&num[i]);
			}
			//讀取「確認使用者的數字」的陣列 
			for(i=0;i<25;i++)
			{
				fscanf(sp,"%d",&p_check[i]);
			}
			//讀取電腦數字的陣列 
			for(i=0;i<25;i++)
			{
				fscanf(sp,"%d",&c_num[i]);
			}
			//讀取「確認電腦的數字」的陣列
			for(i=0;i<25;i++)
			{
				fscanf(sp,"%d",&c_check[i]);
			}
		}
	}
	return load;
}
