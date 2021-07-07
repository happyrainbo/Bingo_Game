#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int p_num[25];//儲存玩家的數字 
	int p_check[25];//儲存已經圈選過的數字 
	int c_num[25];//儲存電腦的數字 
	int c_check[25];//儲存已經圈選過的數字
	int c_comp[10]={0,1,2,3,4,5,6,7,8,9};//儲存電腦已經完成之行或列 
	int p_line;//儲存玩家連線數 
	int c_line;//儲存電腦連線數 
	int over=0;//判斷遊戲是否結束 
	int load;//判斷遊戲是否有存檔 
	
	print_rule();//->print_rule，輸出遊戲規則 
	load=loadgame(p_num,p_check,c_num,c_check);//->loadgame，確認遊戲是否有存檔 
	if(load==0)//若沒有遊戲存檔 
	{
		generate_number(p_check,0);//->generate_number，產生「確認是否數字已圈選」的陣列 
		generate_number(c_check,1);//->generate_number，產生「確認是否數字已圈選」的陣列 
		player_input(p_num,p_check);//->player_input，讓使用者決定自行輸入數字或由電腦自動產生 
		generate_number(c_num,1);//->generate_number，自動產生電腦的數字 
	}
	print_player(p_num,p_check);//->print_player，顯示目前使用者的數字 
	while(over<1)//判斷遊戲是否結束，結束狀態為1=玩家獲勝，2=電腦獲勝，3=平手 
	{
		player_choose(p_num,p_check,c_num,c_check);//->player_choose，使用者選擇欲圈選的數字 
		p_line=line_count(p_num,p_check);//->line_count，計算玩家連線數 
		c_line=line_count(c_num,c_check);//->line_count，計算電腦連線數
		print_line_count(p_line,0);//->print_line_count ，顯示玩家連線數 
		print_line_count(c_line,1);//->print_line_count ，顯示電腦連線數
		over=gameover(p_line,c_line);//->gameover，判斷遊戲是否結束 
		if(over>0)//如果遊戲結束，跳出whie迴圈，顯示遊戲最後結果 
			break;
		print_computer(c_num,c_check);//->print_computer，顯示目前電腦情況 
		print_player(p_num,p_check);//->print_player，顯示目前使用者的數字 
		computer_choose(c_num,c_check,p_check,c_comp);//->computer_choose，電腦選擇欲圈選的數字
		p_line=line_count(p_num,p_check);//->line_count，計算玩家連線數
		c_line=line_count(c_num,c_check);//->line_count，計算電腦連線數
		print_line_count(p_line,0);//->print_line_count ，顯示玩家連線數
		print_line_count(c_line,1);//->print_line_count ，顯示電腦連線數
		over=gameover(p_line,c_line);//->gameover，判斷遊戲是否結束
		if(over>0)//如果遊戲結束，跳出whie迴圈，顯示遊戲最後結果
			break;
		print_computer(c_num,c_check);//->print_computer，顯示目前電腦情況
		print_player(p_num,p_check);//->print_player，顯示目前使用者的數字 
	}
	print_computer(c_num,c_check);//->print_computer，顯示目前電腦情況
	print_player(p_num,p_check);//->print_player，顯示目前使用者的數字
	print_gameover(over,p_line,c_line);//->print_gameove，顯示遊戲結束資訊 
	system("pause");
	return 0;
}
