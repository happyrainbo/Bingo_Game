#include<stdio.h>
#include<stdlib.h>
//檢查數字是否已經輸入 
int input_check(int num[],int n) 
{
	int i;//for迴圈使用 
	int c=0;//檢查數字是否已經輸入，c=1已輸入，c=0未輸入
	
	//將使用者輸入的數字和陣列內的數字一一比對 
	for(i=0;i<25;i++)
	{
		if(n==num[i])//若相同則代表已經輸入 
		{
			c=1;
		}
	}
	return c;
}
