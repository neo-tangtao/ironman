#include<bits/stdc++.h>
using namespace std;
short stepState=1;//定义谁下下一步 
short x,y;//储存要下的位子 
short state[3][3]= {{0,0,0},
					{0,0,0},
					{0,0,0},
					};//储存棋盘的状态 
int checkState()//检查输入是否合法 
{
	if(x>2||y>2)//如果在数组外 
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
int getWin()//检查有没有人赢 
{
	/*判断1是否赢*/ 
	if(state[0][0]==1&&state[0][1]==1&&state[0][2]==1)//判断第一行是否“1”连起来 
	{
		return 1; //返回 “1”赢 
	}
	if(state[1][0]==1&&state[1][1]==1&&state[1][2]==1)//判断第二行是否“1”连起来 
	{
		return 1; //返回 “1”赢 
	}
	if(state[2][0]==1&&state[2][1]==1&&state[2][2]==1)//判断第三行是否“1”连起来 
	{
		return 1; //返回 “1”赢 
	}
	if(state[0][0]==1&&state[1][1]==1&&state[2][2]==1)//判断 / 是否“1”连起来 
	{
		return 1; //返回 “1”赢 
	}
	if(state[0][2]==1&&state[1][1]==1&&state[2][0]==1)//判断 \ 是否“1”连起来 
	{
		return 1; //返回 “1”赢 
	}
	
	
	
	/*判断2是否赢*/ 
	if(state[0][0]==2&&state[0][1]==2&&state[0][2]==2)//判断第一行是否“2”连起来 
	{
		return 2; //返回 “2”赢 
	}
	if(state[1][0]==2&&state[1][1]==2&&state[1][2]==2)//判断第二行是否“2”连起来 
	{
		return 2; //返回 “2”赢 
	}
	if(state[2][0]==2&&state[2][1]==2&&state[2][2]==2)//判断第三行是否“2”连起来 
	{
		return 2; //返回 “2”赢 
	}
	if(state[0][0]==2&&state[1][1]==2&&state[2][2]==2)//判断 / 是否“2”连起来 
	{
		return 2; //返回 “2”赢 
	}
	if(state[2][0]==2&&state[1][1]==2&&state[2][0]==2)//判断 \ 是否“2”连起来 
	{
		return 2; //返回 “2”赢 
	}
	return 0;//如果没人赢，返回0	
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
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
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
int main()//主程序 
{
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

