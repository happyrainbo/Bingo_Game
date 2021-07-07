#include<stdio.h>
#include<stdlib.h>
//計算玩家連線數
int line_count(int num[],int check[])
{
	int i,j;//for迴圈使用 
	int c;//檢查數字是否已經選取 
	int cross=0;//紀錄斜線的圈選數 
	int vertical=0;//紀錄垂直線的圈選數
	int horizontal=0;//紀錄水平線的圈選數 
	int total=0;//紀錄總連線數
	
	//計算斜線的連線數 
	for(i=0;i<25;i+=6)//0,6,12,18,24 
	{
		c=print_check(check,num[i]);//-> print_check，檢查數字是否已經選取，c=1已選取，c=0為選取 
		if(c==1)//數字已選取 
		{
			cross++;//斜線選取數+1 
			if(cross==5)//斜線選取數達5，代表已連線 
			{
				cross=0;
				total++;//總連線數+1 
			}		
		}
	}
	cross=0;
	//計算反斜線的連線數 
	for(i=4;i<21;i+=4)//4,8,12,16,20
	{	
		c=print_check(check,num[i]);//-> print_check，檢查數字是否已經選取，c=1已選取，c=0為選取 
		if(c==1)//數字已選取
		{
			cross++;//斜線選取數+1
			if(cross==5)//斜線選取數達5，代表已連線
			{
				cross=0;
				total++;//總連線數+1
			}
		}
	}
	//計算水平線的連線數 
	for(i=0;i<25;i+=5)//0,5,10,15,20
	{
		horizontal=0;
		for(j=i;j<i+5;j++)//i,i+1,i+2,i+3,i+4
		{
			c=print_check(check,num[j]);//-> print_check，檢查數字是否已經選取，c=1已選取，c=0為選取
			if(c==1)//數字已選取
			{
				horizontal++;//水平線選取數+1
				if(horizontal==5)//水平線選取數達5，代表已連線
					total++;//總連線數+1	
			}
		}
	}
	//計算垂直線的連線數 
	for(i=0;i<5;i++)//0,1,2,3,4 
	{
		vertical=0;
		for(j=i;j<25;j+=5)//i,i+5,i+10,i+15,i+20
		{
			c=print_check(check,num[j]);//-> print_check，檢查數字是否已經選取，c=1已選取，c=0為選取
			if(c==1)//數字已選取
			{
				vertical++;//垂直線選取數+1
				if(vertical==5)//垂直線選取數達5，代表已連線
					total++;//總連線數+1	
			}
		}
	}
	return total;
}
