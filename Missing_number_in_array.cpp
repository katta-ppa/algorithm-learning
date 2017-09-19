#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void subArraySum(int arr[], int n, int sum)
{
   
    int curr_sum=arr[0],i,start=0;
    for(i=1;i<n;i++)
    {
    	while(curr_sum>sum&&start<i-1)
    	{
    		curr_sum-=arr[start];
    		start++;
    	}
    	if(curr_sum==sum)
    	{
    		cout<<start+1<<" "<<i;
    		return;
    	}
    	if(i<n)
    	{
    		curr_sum+=arr[i];
    	}
    }
    printf("-1\n");
}

int main()
{
	int t,n,sum,start,end,flag;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>sum;
		int a[n];
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			
		}
		subArraySum(a,n,sum);
		
	}
}