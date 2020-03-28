#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct stop{
    int d;
    int fuel;
    bool operator < (const stop &b){
        return this->d>b.d;
    }
};
int main(){
    int n;
    cin>>n;
    stop *s=new stop[n+1];
    for(int i=0;i<n;i++)
        cin>>s[i].d>>s[i].fuel;
    int start_d,start_fuel;
    cin>>start_d>>start_fuel;
    sort(s,s+n);
    priority_queue<int> Q;
    Q.push(start_fuel);
    s[n].d=0;
    s[n].fuel=0;
    int ans=0,f=0,i=0; 
    while(start_d>0&&Q.empty()==false){
        ans++;
        f=Q.top();
        Q.pop();
        start_d-=f;
        while(i<n&&start_d<=s[i].d)
            Q.push(s[i++].fuel);
    }
    if(start_d<=0)
        cout<<ans-1<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}