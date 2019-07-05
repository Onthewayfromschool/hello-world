#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
int map[305][305];
int visited[305][305];
int n;
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct point
{
	int x,y,t;
};
int bfs()
{
	if(map[0][0]==0)
		return -1;
	if(map[0][0] == -1)
		return 0;
	queue<point> q;
	point dian;
	dian.x=dian.y=dian.t=0;
	q.push(dian);
	visited[0][0]=1;
	while(q.size())
	{
		point s=q.front();q.pop();
		if(map[s.x][s.y]==-1)
			return s.t;
		for(int i=0;i<4;i++)
		{
			dian.x=s.x+d[i][0],dian.y=s.y+d[i][1];
			dian.t=s.t+1;
			if(dian.x>=0&&dian.y>=0&&dian.x<302&&dian.y<302&&visited[dian.x][dian.y]==0)
			{
				if(map[dian.x][dian.y]==-1)
					return dian.t;
				if(map[dian.x][dian.y]>dian.t)
				{
					visited[dian.x][dian.y]=1;
					q.push(dian);
				}
			}	
		}	
	} 
	return -1;
} 
int main()
{
	int x,y,t;
	memset(map,-1,sizeof(map));
	memset(visited,0,sizeof(visited));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&t);
		if(map[x][y]==-1)
			map[x][y]=t;
		for(int j=0;j<4;j++)
		{
			int dx=x+d[j][0],dy=y+d[j][1];
			if(dx>=0&&dy>=0&&dx<302&&dy<302)
			{
				if(map[dx][dy] == -1)
						map[dx][dy] = t;
				else	
					map[dx][dy]=min(t,map[dx][dy]);
			}
		}
	}
	cout<<bfs()<<endl;
	return 0;		
} 
