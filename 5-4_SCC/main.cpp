#include<iostream>
#include<vector>
#include<stack>
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
    bool instack;
    vector<edge> e;
};

void DFS(int u, vertex *vtx){
    dfs_clock++;
    vtx[u].discovertime=dfs_clock;
    vtx[u].back=dfs_clock;
    vtx[u].instack=true;
    for(int i=0;i<vtx[u].e.size();i++){
        int v=vtx[u].e[i].v;
        if(vtx[v].discovertime==0){
            DFS(v, vtx);
            vtx[u].back=min(vtx[u].back,vtx[v].back);
        }
        else if(vtx[v].instack==true)
            vtx[u].back=min(vtx[u].back,vtx[v].discovertime);
    }
    if(vtx[u].discovertime==vtx[u].back)
        count++;
    vtx[u].instack=false;
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
        vtx[i].instack=false;
    }
    while(cin>>u){
        int v;
        while(cin>>v){
            if(v==-1)
                break;
            else{
                edge edge1(u,v);
                vtx[u].e.push_back(edge1);
            }
        }
    }
    //input and initial
    for(int i=0;i<vn;i++)
        if(vtx[i].discovertime==0)
            DFS(i,vtx);
    cout<<count<<endl;
    return 0;
}