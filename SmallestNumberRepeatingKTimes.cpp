#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<int> a(n);
		vector<int> b(5,0);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
		}
		std::vector<int>::iterator low;
		low=lower_bound(b.begin(),b.end(),k);
		if(low==b.end())
			cout<<"-1"<<endl;
		else
			cout<<low-b.begin()+1<<endl;
	}
	return 0;
}