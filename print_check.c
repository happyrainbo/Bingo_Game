#include<stdio.h>
#include<stdlib.h>
//檢查數字是否已經選取 
int print_check(int check[], int input)
{
	int i;//for迴圈使用 
	int result=1;//檢查數字是否已經選取，result=0未圈選，result=1已圈選 
	
	//將數字和陣列內的數字一一比對 
	for(i=0;i<25;i++)
	{
		if(input==check[i])//若相同則代表數字未圈選 
		{
			result=0;
		}
	}
	return result; 
}
