#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *alltime=new int[n];
    for(int i=0;i<n;i++){
        int time,k;
        cin>>time>>k;
        int pretime=0;
        if(k>0){
            int *pre=new int[k];
            for(int j=0;j<k;j++){
                cin>>pre[j];
                pretime=max(pretime,alltime[pre[j]-1]);
            }
        }
        alltime[i]=pretime+time;
    }
    int max=alltime[0];
    for(int i=0;i<n;i++)
        if(alltime[i]>max)
            max=alltime[i];
    cout<<max<<endl;
    return 0;
}