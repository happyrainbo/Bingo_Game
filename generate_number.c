#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//玻ネ计皚
void generate_number(int num[],int name)
{
	int i;//for癹伴ㄏノ 
	int ran;//纗繦诀睹计ノ∕﹚ㄢ计ユ传 
	int temp;//ノ计ユ传既 
	
	//盢0~24恶皚 
	for(i=0;i<25;i++)
		num[i]=i+1;
	//∕﹚睹计贺	
	if(name==0)
		srand(time(NULL));
	else if(name==1)
		srand(time(NULL)+1);
	//皚计ユ传Θ繦诀篈		
	for(i=0;i<25;i++)
	{
		ran=rand()%25;
		temp=num[i];
		num[i]=num[ran];
		num[ran]=temp;
	}
	return;
}
