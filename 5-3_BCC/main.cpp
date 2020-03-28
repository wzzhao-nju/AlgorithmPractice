#include<iostream>
#include<vector>
using namespace std;

int dfs_clock=0, count=0;

struct edge{
    int u,v;
    edge(){};
    edge(int x, int y) {u=x; v=y;}
};

struct vertex{
    int num;
    int discovertime;
    int back;
    vector<edge> e;
};

void DFS(int u, int parent, vertex *vtx){
    dfs_clock++;
    vtx[u].discovertime=dfs_clock;
    vtx[u].back=dfs_clock;
    for(int i=0;i<vtx[u].e.size();i++){
        int v=vtx[u].e[i].v;
        if(vtx[v].discovertime==0){
            DFS(v, u, vtx);
            vtx[u].back=min(vtx[u].back,vtx[v].back);
            if(vtx[v].back>=vtx[u].discovertime)
                count++;
        }
        else if(vtx[v].discovertime<vtx[u].discovertime&&v!=parent)
            vtx[u].back=min(vtx[u].back,vtx[v].discovertime);
    }
}

int main(){
    ios::sync_with_stdio(false);
    int vn, u;
    cin>>vn;
    vertex *vtx=new vertex[vn];
    for(int i=0;i<vn;i++){
        vtx[i].num=i;
        vtx[i].discovertime=0;
        vtx[i].back=0;
    }
    while(cin>>u){
        int v;
        while(cin>>v){
            if(v==-1)
                break;
            else{
                edge edge1(u,v);
                edge edge2(v,u);
                vtx[u].e.push_back(edge1);
                vtx[v].e.push_back(edge2);
            }
        }
    }
    //input and initial
    for(int i=0;i<vn;i++)
        if(vtx[i].discovertime==0)
            DFS(i, -1, vtx);
    cout<<count<<endl;
    return 0;
}