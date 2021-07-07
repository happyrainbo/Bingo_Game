#include<stdio.h>
#include<stdlib.h>
//顯示遊戲結束資訊 
void print_gameover(int over,int p_line, int c_line)
{
	printf("－－－－－－－－－－－－－－－－－－\n");
	printf("遊戲結束，電腦 %d 條連線: 您 %d 條連線\n",c_line,p_line);
	if(over==1)//玩家獲勝 
	{
		printf("恭喜您打敗了電腦\n\n");
	}
	else if(over==2)//電腦獲勝 
	{
		printf("您輸給電腦了，下次加油\n\n");
	}
	else if(over==3)//平手 
	{
		printf("您和電腦打成平手了，再來一局吧\n\n");
	}
	return;
}
