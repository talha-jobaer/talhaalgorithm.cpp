#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edg;
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        edg.push_back({wt, {a, b}});
    }
    sort(edg.begin(), edg.end());
    for (auto &it : edg)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        cout << "Weight: " << wt << " Source: " << u << " -> " << v << endl;
    }

    return 0;
}
