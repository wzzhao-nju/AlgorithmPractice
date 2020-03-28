#include<iostream>
using namespace std;
class stacks{
    public:
        int *parent,*dis,*cnt;
        stacks(int n){
            parent=new int[n];
            dis=new int[n];
            cnt=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=i;
                dis[i]=0;
                cnt[i]=1;
            }
        }
        void move(int src, int dest){
            int fsrc=find(src),fdest=find(dest);
            if(fsrc==fdest)
                return;
            parent[fsrc]=fdest;
            dis[fsrc]=cnt[fdest];
            cnt[fdest]+=cnt[fsrc];
        }
        int find(int src){
            if(parent[src]==src)
                return src;
            int temp=find(parent[src]);
            dis[src]+=dis[parent[src]];
            parent[src]=temp;
            return temp;
        }
};
int main(){
    ios::sync_with_stdio(false);
    char op;
    int n,a,b;
    cin>>n;
    stacks stks(n);
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op=='M'){
            cin>>a>>b;
            stks.move(a-1,b-1);
        }
        else{
            cin>>a;
            int x=stks.find(a-1);
            cout<<stks.dis[a-1]<<endl;
        }
    }
    return 0;
}