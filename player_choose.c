#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#define FLUSH while(getchar()!='\n')

//使用者選擇欲圈選的數字
void player_choose(int num[], int p_check[],int c_num[], int c_check[]) 
{
	int input;//儲存使用者輸入 
	int result;///用於檢查使用者是否輸入正確
	int c;//檢查數字是否圈選過，c=0還沒圈選，c=1已圈選

	while(true) //一直執行 
	{
		printf("請輸入要圈選的數字:(可輸入0來存檔遊戲)\n");
		result=scanf("%d",&input);////檢查使用者輸入，result=0錯誤，result=1正確 
		if(result==0) //使用者輸入非數字，提示輸入數字
		{
			printf("請輸入數字\n");
			printf("－－－－－－－－－－\n");
		} 
		else if(input==0)
		{
			savegame(num,p_check,c_num,c_check);
		}
		else if(input>25||input<1) //使用者輸入數字範圍錯誤，提示重新輸入
		{
			printf("範圍錯誤，請重新輸入\n");
			printf("－－－－－－－－－－\n");
		} 
		else //輸入數字範圍正確
		{
			c=used_check(p_check, input);//->used_check，檢查數字是否已經圈選，c=0還沒圈選，c=1已圈選
			if(c==1)//數字已圈選 
			{
				printf("輸入的數字已經用過，請重新選擇\n");
				printf("－－－－－－－－－－\n");
			}	
			else //數字未圈選 
			{
				printf("－－－－－－－－－－\n");
				printf("您圈選了數字%d\n",input);
				used_check(c_check, input);//->used_check，更新另一個已圈選數字的陣列 
				break;//跳出while迴圈 
			}
		}
		FLUSH;//如使用者輸入錯誤，將錯誤的字元清除
	}

	return;
}
