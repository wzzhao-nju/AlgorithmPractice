#include<iostream>
#include<queue>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        int *parent=new int[n];
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++){
            int num,count,*child;
            cin>>num>>count;
            if(count>0){
                child=new int[count];
                for(int j=0;j<count;j++){
                    cin>>child[j];
                    parent[child[j]-1]=num-1;
                }
            }
        }//build tree
        int tofind_a,tofind_b;
        cin>>tofind_a>>tofind_b;
        queue<int> a_parent,b_parent;
        tofind_a--;
        tofind_b--;
        while(parent[tofind_a]!=tofind_a){
            a_parent.push(tofind_a);
            tofind_a=parent[tofind_a];
        }
        a_parent.push(tofind_a);
        while(parent[tofind_b]!=tofind_b){
            b_parent.push(tofind_b);
            tofind_b=parent[tofind_b];
        }
        b_parent.push(tofind_b);
        while(a_parent.size()>b_parent.size())
            a_parent.pop();
        while(a_parent.size()<b_parent.size())
            b_parent.pop();
        while(a_parent.front()!=b_parent.front()){
            a_parent.pop();
            b_parent.pop();
        }
        cout<<a_parent.front()+1<<endl;
    }
    return 0;
}