#include<stdio.h>
#include<stdlib.h>
//判斷遊戲是否結束 
int gameover(int p, int c)
{
	int over=0;//判斷遊戲是否結束 
	if(p>=5&&c>=5&&p==c)//使用者和電腦的連線數都達5且連線數相同，平手 
	{
		over=3;
	}
	else if(p>=5&&p>c)//使用者連線數達5且連線數大於電腦，使用者獲勝 
	{
		over=1;
	}
	else if(c>=5&&c>p)//電腦連線數達5且連線數大於玩家，電腦獲勝 
	{
		over=2;
	}
	return over;
}
