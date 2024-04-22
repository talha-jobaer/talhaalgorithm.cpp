#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct act
{
    int fi;
    int en;
};
vector<act>ar;
bool re( act a, act b)
{
    return a.en<b.en;
}
void select(vector<act>ar)
{
    sort(ar.begin(),ar.end(),re);
    cout<<"Activities ";
    cout<<ar[0].fi<<":"<<ar[0].en<<" ";
    int last=ar[0].en;
    for(int i=1;i<ar.size();i++)
    {
        if(ar[i].fi>=last)
        {
            cout<<ar[i].fi<<":"<<ar[i].en<<" ";
            last=ar[i].en;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        ar.push_back({a,b});
    }
    select(ar);
    return 0;
}
