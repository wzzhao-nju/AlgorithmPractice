#include<iostream>
using namespace std;
int main()
{
    int n,max=0;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int index=i,temp=i;
        while(a[temp]!=0)
        {
            b[index]++;
            temp=a[temp]-1;
        }
        b[index]++;
    }
    for(int i=0;i<n;i++)
        if(b[i]>b[max])
            max=i;
    cout<<b[max]<<endl;
    return 0;
}