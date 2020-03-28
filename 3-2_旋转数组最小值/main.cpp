#include<iostream>
using namespace std;
int f(int a[],int start,int end)
{
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]>a[end])
            start=mid+1;
        else if(a[mid]==a[end])
            end=end-1;
        else
            end=mid;
    }
    return a[start];
}
int main()
{
    int a[100000];
    int x,n=0;
    while(cin>>x)
        a[n++]=x;
    if(n==0)
        cout<<"0"<<endl;
    else
        cout<<f(a,0,n-1)<<endl;
    return 0;
}