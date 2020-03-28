#include<iostream>
#include<queue>
using namespace std;
const int MAX=100001;
int BFS(int n, int k, int sign[]){
    queue<int> Q;
    int cur,next;
    sign[n]=1;
    Q.push(n);
    while(Q.empty()==false){
        cur=Q.front();
        Q.pop();
        next=cur-1;
        if(next>=0&&next<=MAX-1&&sign[next]==0){
            if(next==k)
                return sign[cur];
            Q.push(next);
            sign[next]=sign[cur]+1;
        }
        //case 1
        next=cur+1;
        if(next>=0&&next<=MAX-1&&sign[next]==0){
            if(next==k)
                return sign[cur];
            Q.push(next);
            sign[next]=sign[cur]+1;
        }
        //case 2
        next=cur*2;
        if(next>=0&&next<=MAX-1&&sign[next]==0){
            if(next==k)
                return sign[cur];
            Q.push(next);
            sign[next]=sign[cur]+1;
        }
        //case 3
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    int sign[MAX];
    for(int i=0;i<MAX;i++)
        sign[i]=0;
    if(n>=k)
        cout<<n-k<<endl;
    else
        cout<<BFS(n,k,sign)<<endl;
    return 0;
}