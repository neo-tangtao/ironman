#include<bits/stdc++.h>
using namespace std;
short stepState=1;//定义谁下下一步 
short x,y;//储存要下的位子 
short state[20][20]={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//1
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//2
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//3
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//4
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//5
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//6
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//7
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//8
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//9
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//10
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//11
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//12
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//13
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//14
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//15
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//16
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//17
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//18
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//19
};
int start()
{
	cout<<"The game is starting ";
	for(int e=0;e<20;e++)
	{

	cout<<"\b";
	cout<<"." ;	
	printf("│");
	_sleep(100);
	
	cout<<"\b";
	cout<<"." ;	
	printf("╱");
	_sleep(100);

	cout<<"\b";
	cout<<"." ;	
	printf("─");
	_sleep(100);
	
	cout<<"\b";
	cout<<"." ;	
	printf("╲");
	_sleep(100);

	}
		system("cls");
}
int checkState()//检查输入是否合法 
{
	if(x>19||y>19)//如果在数组外 
	{
		return 1;//不合法 
	}
	if(state[x][y]!=0)//如果有人下过 
	{
		return 1;//不合法 
	}
	//如果上述事件未发生 
	return 0;//合法 
} 
int changeStep()//改变下棋的人 
{
	if(stepState==1)//当1下过时 
	{
		stepState=2;//让2下 
	}else//否则 
	{
		stepState=1;//让1下 
	}
}
int changeState()//把下的子同步到数组 
{
	state[x][y]=stepState;
}
int print()//输出棋局 
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			cout<<state[i][j];
			cout<<"   "; 
		}
		cout<<""<<endl;
		cout<<""<<endl;
	}
}
int clean()//清屏 
{
	system("cls");
}
int getState()//获取输入值 
{
	cout<<"It's "<<stepState<<" time"<<endl;
	cin>>x>>y;
	if(checkState()==1){//如果不合法 
		return 1;//返回1并退出 
	}//检查输入是否合法 
	changeState(); //改变数组 
	changeStep();//改变下棋的人 
	return 0; 
} 
int getWin()//检查有没有人赢 
{
	for(int a=1;a<=2;a++)//横 
	{
		for(int m=0;m<20;m++)
		{
			for(int n=0;n<16;n++)
			{
				if(state[m][n]==a&&state[m][n+1]==a&&state[m][n+2]==a&&state[m][n+3]==a&&state[m][n+4]==a)
				{
					return a;
				}
			}
		}
	}
	
	for(int b=1;b<=2;b++)//竖 
	{
		for(int p=0;p<20;p++)
		{
			for(int q=0;q<16;q++)
			{
				if(state[q][p]==b&&state[q+1][p]==b&&state[q+2][p]==b&&state[q+3][p]==b&&state[q+4][p]==b)
				{
					return b;
				}
			}
		}
	}
	
	for(int c=1;c<=2;c++)/* \ */
	{
		for(int m=0;m<16;m++)
		{
			for(int n=0;n<16;n++)
			{
				if(state[m][n]==c&&state[m+1][n+1]==c&&state[m+2][n+2]==c&&state[m+3][n+3]==c&&state[m+4][n+4]==c)
				{
					return c;
				}
			}
		}
	}
	
	for(int d=1;d<=2;d++)/* / */
	{
		for(int g=0;g<16;g++)
		{
			for(int h=20;h>4;h--)
			{
				if(state[g][h]==d&&state[g+1][h-1]==d&&state[g+2][h-2]==d&&state[g+3][h-3]==d&&state[g+4][h-4]==d)
				{
					return d;
				}
			}
		}
	}		
	
	return 0;//如果没人赢，返回0	
}
int main()
{
	start();
	while(getWin()==0){//如果无人获胜 
		print();//输出 
		if(getState()==1)
		{
			cout<<"Error step!";
			_sleep(1000);//确保错误信息不被刷新 
		}//输入 
		clean();//清屏 
	}
	print();//确保最后有棋局 
	cout<<getWin()<<" is win!"; 
}
