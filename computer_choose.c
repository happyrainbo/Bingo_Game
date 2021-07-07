#include<stdio.h>
#include<stdlib.h>
//電腦選擇欲圈選的數字 
void computer_choose(int num[], int c_check[], int p_check[],int comp[]) 
{
	int i,j;//for迴圈使用 
	int c=1;//檢查是否已經選取 
	int l=0;//最多單行或列選取數 
	int n=0;//儲存哪行或列選取數最多 
	int cmp;//檢查哪行或列已經連線 
	int horizontal=0;//儲存水平線的選取數 
	int vertical=0;//儲存垂直線的選取數
	
	//優先選擇完成斜線的連線 
	for(i=0; i<25&&c==1; i+=6) 
	{
		c=used_check(c_check,num[i]);//->used_check，檢查數字是否已經圈選，c=0還沒圈選，c=1已圈選 
		if(c==0) //若未圈選則執行圈選 
		{
			printf("－－－－－－－－－－\n");
			printf("電腦圈選了數字%d\n",num[i]);
			used_check(p_check,num[i]);//->used_check，更新另一個已圈選數字的陣列 
			break;//跳出for迴圈 
		}
	}
	//次優先選擇完成反斜線的連線 
	for(i=4; i<21&&c==1; i+=4) 
	{
		c=used_check(c_check,num[i]);//->used_check，檢查數字是否已經圈選，c=0還沒圈選，c=1已圈選
		if(c==0) //若未圈選則執行圈選
		{
			printf("－－－－－－－－－－\n");
			printf("電腦圈選了數字%d\n",num[i]);
			used_check(p_check,num[i]);//->used_check，更新另一個已圈選數字的陣列
			break;//跳出for迴圈 
		}
	}
	//完成斜線的圈選後，判斷哪行或列的已圈選數較多，優先完成該條連線 
	if(c==1) 
	{
		//判斷水平線的已圈選數 
		for(i=0; i<25; i+=5) 
		{
			horizontal=0;
			cmp=computer_complete_check(comp,i/5);//->computer_complete_check，判斷是否該水平線已經連線，result=1已完成，result=0未完成 
			if(cmp==1)//若該水平線已完成連線則換下一條 
				continue;
			for(j=i; j<i+5; j++) 
			{
				c=print_check(c_check,num[j]);//->print_check，檢查數字是否已經圈選，c=0還沒圈選，c=1已圈選
				if(c==1) //數字已圈選 
				{
					horizontal++;//水平線圈選數+1 
					if(horizontal>l) //若圈選數大於其他條線 
					{
						l=horizontal;//紀錄最大圈選數 
						n=i/5;//紀錄水平線編號 
						if(l==5)//若最大圈選數達5，代表已經連線 
						{
							computer_complete_update(comp,n);//->computer_complete_update，更新已連線的水平線編號 
							computer_choose(num,c_check,p_check,comp);
						}
					}
				}
			}
		}
		//判斷垂直線的已圈選數
		for(i=0; i<5; i++) 
		{
			vertical=0;
			cmp=computer_complete_check(comp,i+5);//->computer_complete_check，判斷是否該垂直線已經連線，result=1已完成，result=0未完成
			if(cmp==1)//若該垂直線已完成連線則換下一條 
				continue;
			for(j=i; j<25; j+=5) 
			{
				c=print_check(c_check,num[j]);//->print_check，檢查數字是否已經圈選，c=0還沒圈選，c=1已圈選
				if(c==1) //數字已圈選
				{
					vertical++;//垂直線圈選數+1 
					if(vertical>l) //若圈選數大於其他條線
					{
						l=vertical;//紀錄最大圈選數 
						n=i+5;//紀錄t垂直線編號 
						if(l==5)//若最大圈選數達5，代表已經連線
						{
							computer_complete_update(comp,n);//->computer_complete_update，更新已連線的垂直線編號 
							computer_choose(num,c_check,p_check,comp);
						}
					}
				}
			}
		}
		//若水平線的圈選數較多 
		if(n>=0&&n<=4)
		{
			for(i=n*5; i<n*5+5; i++) 
			{
				c=used_check(c_check,num[i]);//->used_check，檢查數字是否已經圈選，c=0還沒圈選，c=1已圈選
				if(c==0) //若未圈選則執行圈選 
				{
					printf("－－－－－－－－－－\n");
					printf("電腦圈選了數字%d\n",num[i]);
					used_check(p_check,num[i]);//->used_check，更新另一個已圈選數字的陣列
					break;//跳出for迴圈 
				}
			}
		}
		//若垂直線的圈選數較多
		else if(n>=5&&n<=9)
		{
			for(i=n-5; i<25; i+=5)
			{
				c=used_check(c_check,num[i]);//->used_check，檢查數字是否已經圈選，c=0還沒圈選，c=1已圈選
				if(c==0) //若未圈選則執行圈選 
				{
					printf("－－－－－－－－－－\n");
					printf("電腦圈選了數字%d\n",num[i]);
					used_check(p_check,num[i]);//->used_check，更新另一個已圈選數字的陣列
					break;//跳出for迴圈
				}
			}
		}
	}
	return;
}
