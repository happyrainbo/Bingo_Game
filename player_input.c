#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define FLUSH while(getchar()!='\n')
//讓使用者自行決定輸入數字或由電腦自動產生
void player_input(int num[],int check[]) 
{
	int i;//for迴圈使用 
	int c;//用於檢查數字是否已經輸入
	int input;//儲存使用者輸入 
	int result;//用於檢查使用者是否輸入正確 
	int skip=0;//用於迴圈操作 
	
	//將0填入陣列 
	for(i=0;i<25;i++)
	{
		num[i]=0;
	}
	//讓使用者選擇自行輸入數字或由電腦自動產生 
	for(i=0; i<25&&skip==0; i++) 
	{
		while(true)//一直執行 
		{
			printf("請輸入1~25的數字(或輸入0由電腦自動產生):\n");
			result=scanf("%d",&input);//檢查使用者輸入，result=0錯誤，result=1正確 
			if(result==0) //使用者輸入非數字，提示輸入數字 
			{
				printf("請輸入數字\n");
				printf("－－－－－－－－－－\n");
			} 
			else if(input==0)//使用者決定由電腦自動產生數字 
			{
				generate_number(num,0);//->generate_number，由電腦自動產生玩家的數字陣列 
				skip=1;//跳出for迴圈 
				break;//跳出while迴圈 
			}
			else if(input>25||input<1)//使用者輸入數字範圍錯誤，提示重新輸入 
			{
				printf("範圍錯誤，請重新輸入\n");
				printf("－－－－－－－－－－\n");
			} 
			else //輸入數字範圍正確 
			{
				c=input_check(num, input);//->input_check，檢查數字是否已經輸入，c=1已輸入，c=0未輸入 
				if(c==1) //數字已經輸入 
				{
					printf("輸入的數字已經用過，請重新選擇\n");
					printf("－－－－－－－－－－\n");
				} 
				else //數字未輸入 
				{
					printf("－－－－－－－－－－\n");
					num[i]=input;//將使用者輸入填入陣列 
					if(i<24)//輸入24個數字之前顯示使用者的數字，輸入25個數字後使用者的數字將由main呼叫顯示 
					{
						print_player(num,check);//->print_player，顯示目前使用者的數字 
					}
					break;//輸入正確，跳出while迴圈，進行下一步for迴圈 
				}
			}
			FLUSH;//如使用者輸入錯誤，將錯誤的字元清除 
		}
	}
	return; 
}
