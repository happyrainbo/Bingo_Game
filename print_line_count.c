#include<stdio.h>
#include<stdlib.h>
//顯示連線數 
void print_line_count(int line,int name)
{
	if(name==0)//使用者的顯示字串 
	{
		printf("  您目前有%d條連線\n",line);
	}
	else if(name==1)//電腦的顯示字串 
	{
		printf("電腦目前有%d條連線\n",line);
	}
	return;
}
