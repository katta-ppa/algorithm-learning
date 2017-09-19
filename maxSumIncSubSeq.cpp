#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define gcd __gcd
#define bitcount __builtin_popcount
#define forall(i,a,b) for(int i=a;i<b;i++)


void maxSumIncSubSeq(int a[],int n)
{
	int dp[n],i,j,max_so_far;

	dp[0]=a[0];
	for(i=1;i<n;i++)
	{
		max_so_far=INT_MIN;
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				max_so_far=max(max_so_far,dp[j]+a[i]);
			}
		}
		dp[i]=max_so_far;
	}
	max_so_far=INT_MIN;
	for(i=0;i<n;i++)
	{
		max_so_far=max(max_so_far,dp[i]);
	}
	cout<<max_so_far<<endl;
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		forall(i,0,n)
		{
			cin>>a[i];
		}
		//write your code here
		maxSumIncSubSeq(a,n);
	}
}