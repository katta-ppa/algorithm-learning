#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define gcd __gcd
#define bitcount __builtin_popcount
#define forall(i,a,b) for(int i=a;i<b;i++)

int row[] = {2,2,1,1,-1,-1,-2,-2};
int col[] = {1,-1,2,-2,2,-2,1,-1};
string turn[] = {"down","up","right","left"};

struct node
{
	int x;
	int y;
	int no_of_turns;
	string prevturn;
};

bool valid(int x,int y,vector<vector<int>>& a,int n,int m)
{
	if(x<0||y<0||x>=n||y>=m||a[x][y]==0)
		return false;
	return true;
}

int min_turns(vector<vector<int>>& a,node start,node stop,int n,int m)
{
	vector<vector<bool>> visited(n,std::vector<bool>(m,false));
	
	queue<node> q;
	q.push(start);
	while(!q.empty())
	{
		node cell=q.front();
		q.pop();

		int x=cell.x;
		int y=cell.y;
		string prevturn=cell.prevturn;
		int no_of_turns=cell.no_of_turns;

		if(x==stop.x&&y==stop.y)
			return no_of_turns;

		if(!visited[x][y])
		{
			visited[x][y]=true;
			
			for(int i=0;i<4;i++)
			{
				int x1=x+row[i];
				int y1=y+col[i];
				int no_of_turns1;
				string prevturn1;
				if(valid(x1,y1,a,n,m)&&visited[x1][y1]==false)
				{
					if(prevturn=="NULL")
					{
						no_of_turns1=no_of_turns;
						prevturn1=turn[i];
					}
					else
					{
						if(prevturn!=turn[i])
						{
							no_of_turns1=no_of_turns+1;
							prevturn1=turn[i];

						}
						else
						{
							no_of_turns1=no_of_turns;
							prevturn1=prevturn;
						}
					}
					node cell1;
					cell1.x=x1;
					cell1.y=y1;
					cell1.prevturn=prevturn1;
					cell1.no_of_turns=no_of_turns1;
					//cout<<x1<<" "<<y1<<" "<<prevturn1<<" "<<no_of_turns1<<endl;
					q.push(cell1);
				}
			}
		}
	}
	return -1;
}

int main()
{
	int n,m,i,j;
	char sc;
	node start,stop;
	cin>>n>>m;
	vector<vector<int>> a(n,std::vector<int>(m,0));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>sc;

			if(sc=='V')
			{
				start.x=i;
				start.y=j;
				start.prevturn="NULL";
				start.no_of_turns=0;
				a[i][j]=1;
			}
			if(sc=='H')
			{
				stop.x=i;
				stop.y=j;
				stop.prevturn="NULL";
				a[i][j]=1;
			}
			if(sc=='.')
			{
				a[i][j]=1;
			}
			if(sc=='*')
			{
				a[i][j]=0;
			}
		}
	}
	
	cout<<min_turns(a,start,stop,n,m);
}