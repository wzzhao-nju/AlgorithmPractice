#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class interval
{
    private:
        string start;
        string end;
    public:
        interval(string s, string e) {start=s;end=e;}
        string Start() {return start;}
        string End() {return end;}
        void setend(string e) {end=e;}
        void print() {cout<<start<<" "<<end<<endl;}
};
bool lessthan(string a, string b)
{
    if(a.length()==b.length())
        return a<b;
    else
        return a.length()<b.length();
}
bool cmp(interval a,interval b) {return lessthan(a.Start(),b.Start());}
int main()
{
    vector<interval> in,res;
    int n;
    string s,e;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        interval inter(s,e);
        in.push_back(inter);
    }
    sort(in.begin(),in.end(),cmp);
    for(int i=0;i<n;i++)
    {
        //in[i].print();
        int size=res.size();
        if(size==0||lessthan(res[size-1].End(),in[i].Start()))
            res.push_back(in[i]);
        else if(lessthan(res[size-1].End(),in[i].End()))
            res[size-1].setend(in[i].End());
    }
    for(int i=0;i<res.size();i++)
        res[i].print();
    return 0;
}