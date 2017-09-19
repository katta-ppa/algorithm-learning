#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define gcd __gcd
#define bitcount __builtin_popcount
#define forall(i,a,b) for(int i=a;i<b;i++)

void leaders(int a[],int n)
{
	vector<int> v;

	stack<int> st;
	v.push_back(a[n-1]);
	st.push(a[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		while(!st.empty()&&st.top()<a[i])
		{
			st.pop();
		}
		if(st.empty())
		{
			v.push_back(a[i]);
		}
		st.push(a[i]);
	}
	for(std::vector<int>::iterator i=v.begin();i!=v.end();i++)
		cout<<*i<<" ";
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
		leaders(a,n);
		cout<<endl;
	}
}