#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=n*(n+1)/2;
    if(sum%2==1){
        cout<<"0"<<endl;
    }else{
        sum/=2;
        long long int *subset=new long long int[sum+1];
        for(int i=0;i<sum+1;i++)
            subset[i]=0;
        subset[0]=1;
        for(int i=0;i<n;i++)
            for(int j=sum;j>=i;j--)
                subset[j]+=subset[j-i];
        cout<<subset[sum]/2<<endl;
    }
    return 0;
}