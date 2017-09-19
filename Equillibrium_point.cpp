#include <iostream>

using namespace std;

int main()
{
	int t,n,prevsum,aftersum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		cin>>a[0];
		int flag=0;
		for(int i=1;i<n;i++)
		{
			cin>>a[i];
			a[i]+=a[i-1];
		}
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				prevsum=0;
				aftersum=a[n-1]-a[i];
			}
			else
			{
				prevsum=a[i-1];
				aftersum=a[n-1]-a[i];
			}
			
			if(prevsum==aftersum)
			{
				cout<<i+1<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"-1"<<endl;
		}
	}
}