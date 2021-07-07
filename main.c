#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int p_num[25];//�x�s���a���Ʀr 
	int p_check[25];//�x�s�w�g���L���Ʀr 
	int c_num[25];//�x�s�q�����Ʀr 
	int c_check[25];//�x�s�w�g���L���Ʀr
	int c_comp[10]={0,1,2,3,4,5,6,7,8,9};//�x�s�q���w�g��������ΦC 
	int p_line;//�x�s���a�s�u�� 
	int c_line;//�x�s�q���s�u�� 
	int over=0;//�P�_�C���O�_���� 
	int load;//�P�_�C���O�_���s�� 
	
	print_rule();//->print_rule�A��X�C���W�h 
	load=loadgame(p_num,p_check,c_num,c_check);//->loadgame�A�T�{�C���O�_���s�� 
	if(load==0)//�Y�S���C���s�� 
	{
		generate_number(p_check,0);//->generate_number�A���͡u�T�{�O�_�Ʀr�w���v���}�C 
		generate_number(c_check,1);//->generate_number�A���͡u�T�{�O�_�Ʀr�w���v���}�C 
		player_input(p_num,p_check);//->player_input�A���ϥΪ̨M�w�ۦ��J�Ʀr�Υѹq���۰ʲ��� 
		generate_number(c_num,1);//->generate_number�A�۰ʲ��͹q�����Ʀr 
	}
	print_player(p_num,p_check);//->print_player�A��ܥثe�ϥΪ̪��Ʀr 
	while(over<1)//�P�_�C���O�_�����A�������A��1=���a��ӡA2=�q����ӡA3=���� 
	{
		player_choose(p_num,p_check,c_num,c_check);//->player_choose�A�ϥΪ̿�ܱ���諸�Ʀr 
		p_line=line_count(p_num,p_check);//->line_count�A�p�⪱�a�s�u�� 
		c_line=line_count(c_num,c_check);//->line_count�A�p��q���s�u��
		print_line_count(p_line,0);//->print_line_count �A��ܪ��a�s�u�� 
		print_line_count(c_line,1);//->print_line_count �A��ܹq���s�u��
		over=gameover(p_line,c_line);//->gameover�A�P�_�C���O�_���� 
		if(over>0)//�p�G�C�������A���Xwhie�j��A��ܹC���̫ᵲ�G 
			break;
		print_computer(c_num,c_check);//->print_computer�A��ܥثe�q�����p 
		print_player(p_num,p_check);//->print_player�A��ܥثe�ϥΪ̪��Ʀr 
		computer_choose(c_num,c_check,p_check,c_comp);//->computer_choose�A�q����ܱ���諸�Ʀr
		p_line=line_count(p_num,p_check);//->line_count�A�p�⪱�a�s�u��
		c_line=line_count(c_num,c_check);//->line_count�A�p��q���s�u��
		print_line_count(p_line,0);//->print_line_count �A��ܪ��a�s�u��
		print_line_count(c_line,1);//->print_line_count �A��ܹq���s�u��
		over=gameover(p_line,c_line);//->gameover�A�P�_�C���O�_����
		if(over>0)//�p�G�C�������A���Xwhie�j��A��ܹC���̫ᵲ�G
			break;
		print_computer(c_num,c_check);//->print_computer�A��ܥثe�q�����p
		print_player(p_num,p_check);//->print_player�A��ܥثe�ϥΪ̪��Ʀr 
	}
	print_computer(c_num,c_check);//->print_computer�A��ܥثe�q�����p
	print_player(p_num,p_check);//->print_player�A��ܥثe�ϥΪ̪��Ʀr
	print_gameover(over,p_line,c_line);//->print_gameove�A��ܹC��������T 
	system("pause");
	return 0;
}
