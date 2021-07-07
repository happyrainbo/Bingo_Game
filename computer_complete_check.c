#include<stdio.h>
#include<stdlib.h>
//紀錄電腦哪一行或列已經完成連線 
int computer_complete_check(int comp[],int n) 
{
	int i;//for迴圈使用 
	int result=1;//判斷是否已經完成連線，result=1已完成，result=0未完成 
	
	//行數和陣列的行數一一比較 
	for(i=0;i<10;i++)
	{
		if(n==comp[i])//若相同代表未完成 
		{
			result=0;
		}
	}
	return result;
}
