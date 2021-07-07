#include<stdio.h>
#include<stdlib.h>
//更新電腦哪一行或列已經完成連線
void computer_complete_update(int comp[],int n) 
{
	int i;//for迴圈使用
	
	//行數和陣列中的行數一一比較 
	for(i=0;i<10;i++)
	{
		if(n==comp[i])//若相同則將之設定為已連線 
		{
			comp[i]=-1;
		}
	}
	return;
}
