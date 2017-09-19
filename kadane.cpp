#include <iostream>
using namespace std;

int max(int a,int b)
{
    return (a>b)?a:b;
}

int func(int a[],int n)
{
    int curr_max=a[0];
    int max_so_far=a[0];
    for(int i=1;i<n;i++)
    {
        curr_max=max(a[i],curr_max+a[i]);
        max_so_far=max(curr_max,max_so_far);
    }
    return max_so_far;
}

int main() {
	int t,n,i;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
      for(i=0;i<n;i++)
        cin>>a[i];
	    cout<<func(a,n)<<endl;
	}
	return 0;
}
