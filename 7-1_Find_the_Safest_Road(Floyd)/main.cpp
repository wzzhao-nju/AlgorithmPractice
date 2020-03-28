#include<iostream>
#include<iomanip>
using namespace std;
double graph[1000][1000];
void floyd(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(graph[k][i]==0)
                continue;
            for(int j=0;j<n;j++)
                graph[i][j]=max(graph[i][j],graph[i][k]*graph[k][j]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    floyd(n);
    int q,u,v;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        if(graph[u-1][v-1]==0)
            cout<<"What a pity!"<<endl;
        else
            cout<<fixed<<setprecision(3)<<graph[u-1][v-1]<<endl;
    }
    return 0;
}