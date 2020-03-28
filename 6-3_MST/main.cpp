#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Union{
private:
    int *parent;
public:
    Union(int n) {
        parent=new int[n];
        for(int i=0;i<n;i++)
            parent[i]=i;
    };
    int find(int x){
        if(parent[x]==x)
            return x;
        else
            return find(parent[x]);
    }
    void U(int x, int y){
        parent[find(y)]=parent[find(x)];
    }
};
struct Edge{
    int v1;
    int v2;
    int weight;
    Edge(int u, int v, int w) { v1=u; v2=v; weight=w;}
    bool operator < (const Edge &b){
        return this->weight<b.weight;
    }
};
int main(){
    int total;
    cin>>total;
    while(total--){
        int n,m;
        cin>>n>>m;
        vector<Edge> edge;
        Union un(n);
        int u,v,w;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            Edge e(u-1,v-1,w);
            edge.push_back(e);
        }
        sort(edge.begin(),edge.end());
        int count=0,res=0;
        for(int i=0;i<m;i++){
            if(count==n-1)
                break;
            if(un.find(edge[i].v1)!=un.find(edge[i].v2)){
                un.U(edge[i].v1,edge[i].v2);
                res+=edge[i].weight;
                count++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}