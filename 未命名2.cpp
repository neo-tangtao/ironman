#include<bits/stdc++.h>
using namespace std;
short stepState=1;//����˭����һ�� 
short x,y;//����Ҫ�µ�λ�� 
short state[3][3]= {{0,0,0},
					{0,0,0},
					{0,0,0},
					};//�������̵�״̬ 
int checkState()//��������Ƿ�Ϸ� 
{
	if(x>2||y>2)//����������� 
	{
		return 1;//���Ϸ� 
	}
	if(state[x][y]!=0)//��������¹� 
	{
		return 1;//���Ϸ� 
	}
	//��������¼�δ���� 
	return 0;//�Ϸ� 
} 
int getWin()//�����û����Ӯ 
{
	/*�ж�1�Ƿ�Ӯ*/ 
	if(state[0][0]==1&&state[0][1]==1&&state[0][2]==1)//�жϵ�һ���Ƿ�1�������� 
	{
		return 1; //���� ��1��Ӯ 
	}
	if(state[1][0]==1&&state[1][1]==1&&state[1][2]==1)//�жϵڶ����Ƿ�1�������� 
	{
		return 1; //���� ��1��Ӯ 
	}
	if(state[2][0]==1&&state[2][1]==1&&state[2][2]==1)//�жϵ������Ƿ�1�������� 
	{
		return 1; //���� ��1��Ӯ 
	}
	if(state[0][0]==1&&state[1][1]==1&&state[2][2]==1)//�ж� / �Ƿ�1�������� 
	{
		return 1; //���� ��1��Ӯ 
	}
	if(state[0][2]==1&&state[1][1]==1&&state[2][0]==1)//�ж� \ �Ƿ�1�������� 
	{
		return 1; //���� ��1��Ӯ 
	}
	
	
	
	/*�ж�2�Ƿ�Ӯ*/ 
	if(state[0][0]==2&&state[0][1]==2&&state[0][2]==2)//�жϵ�һ���Ƿ�2�������� 
	{
		return 2; //���� ��2��Ӯ 
	}
	if(state[1][0]==2&&state[1][1]==2&&state[1][2]==2)//�жϵڶ����Ƿ�2�������� 
	{
		return 2; //���� ��2��Ӯ 
	}
	if(state[2][0]==2&&state[2][1]==2&&state[2][2]==2)//�жϵ������Ƿ�2�������� 
	{
		return 2; //���� ��2��Ӯ 
	}
	if(state[0][0]==2&&state[1][1]==2&&state[2][2]==2)//�ж� / �Ƿ�2�������� 
	{
		return 2; //���� ��2��Ӯ 
	}
	if(state[2][0]==2&&state[1][1]==2&&state[2][0]==2)//�ж� \ �Ƿ�2�������� 
	{
		return 2; //���� ��2��Ӯ 
	}
	return 0;//���û��Ӯ������0	
}
int changeStep()//�ı�������� 
{
	if(stepState==1)//��1�¹�ʱ 
	{
		stepState=2;//��2�� 
	}else//���� 
	{
		stepState=1;//��1�� 
	}
}
int changeState()//���µ���ͬ�������� 
{
	state[x][y]=stepState;
}
int print()//������ 
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
int clean()//���� 
{
	system("cls");
}
int getState()//��ȡ����ֵ 
{
	cout<<"It's "<<stepState<<" time"<<endl;
	cin>>x>>y;
	if(checkState()==1){//������Ϸ� 
		return 1;//����1���˳� 
	}//��������Ƿ�Ϸ� 
	changeState(); //�ı����� 
	changeStep();//�ı�������� 
	return 0; 
} 
int main()//������ 
{
	while(getWin()==0){//������˻�ʤ 
		print();//��� 
		if(getState()==1)
		{
			cout<<"Error step!";
			_sleep(1000);//ȷ��������Ϣ����ˢ�� 
		}//���� 
		clean();//���� 
	}
	print();//ȷ���������� 
	cout<<getWin()<<" is win!"; 
}

