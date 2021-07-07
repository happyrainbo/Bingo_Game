#include<stdio.h>
#include<stdlib.h>

//判斷使用者欲圈選的數字是否已經圈選過 
int used_check(int check[], int input)
{
	int i;//for迴圈使用 
	int result=1;//檢查數字是否已經圈選，result=0還沒圈選，result=1已圈選 
	
	//將數字和陣列內的數字一一比對 
	for(i=0;i<25;i++)
	{
		if(input==check[i])//如果相同則代表未圈選 
		{
			result=0;
			check[i]=0;//改成0，下次檢測時就會是已圈選 
		}
	}
	return result;
}
