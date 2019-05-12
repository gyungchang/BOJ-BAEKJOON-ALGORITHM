#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;



bool visited[100001];
int n,m;
queue<pair <int , int> > q;

int bfs(int subin, int bro)
{
	q.push(make_pair(subin, 0 ));//subin�̰� �ִ��� ��  0�ʷ� pair �ϰ�  
	visited[subin]=true; //������ ���� ���մ�����  visited�ϱ�  
	while(!q.empty())
	{
		int subin_location=q.front().first;
		int subin_time=q.front().second;
		q.pop();
		if(subin_location==bro)//�������� ����  
			return subin_time;
		//������ �迭������ �����̵��� ����ϴϱ� 3�������
		if(subin_location*2<100001 && visited[subin_location*2]==false)
		{
			q.push(make_pair(subin_location*2,subin_time+1));
			visited[subin_location*2]=true;	
		}	//������ �����̵��� ���
		
		//�̾Ʒ����ʹ� �׳� ������ �迭�϶� Ž��  
		if(subin_location-1>=0 &&visited[subin_location-1]==false)
		{
			q.push(make_pair(subin_location-1,subin_time+1));
			visited[subin_location-1]=true;
		 } 
		 if(subin_location+1<100001 && visited[subin_location+1]==false)
		 {
		 	q.push(make_pair(subin_location+1,subin_time+1));
		 	visited[subin_location+1]=true;
		 }
		 
	}
}

int main()
{
	cin>>n>>m;
	cout<<bfs(n,m)<<endl;	
}
