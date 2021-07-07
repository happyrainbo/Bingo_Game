#include<stdio.h>
#include<stdlib.h>
//顯示目前電腦情況
void print_computer(int num[],int check[])
{
	int i,j;//for迴圈使用 
	int c;//檢查是否數字已圈選，c=0未圈選，c=1已圈選
	
	//顯示目前電腦的狀況  
	printf("電腦的局面\n");
	printf(" ＿＿＿＿＿＿＿＿＿＿＿＿ \n");
	for(i=0;i<25;i+=5)
	{
		for(j=i;j<i+5;j++)
		{
			c=print_check(check,num[j]);//->print_check，檢查數字是否已經選取，c=0為選取，c=1已選取
			if(c==0)//數字未選取則輸出空心圓 
			{
				//printf("|%3d ",num[j]);
				printf("| ○ ");
			}
			else if(c==1)//數字已選取則輸出實心圓 
			{
				printf("| ● ");
			}
		}
		printf("|\n");
		if(i<20) 
			printf("|－－－－－－－－－－－－|\n");
	}
	printf(" ￣￣￣￣￣￣￣￣￣￣￣￣ \n");
	return;	
}
