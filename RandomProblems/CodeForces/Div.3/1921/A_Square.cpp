/*
Autore: Tommaso Ulian
Data: 18/01/2024
Problema: Codeforces 1921 A
Rating: 800
Tags:Greedy, Math
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    vector<pair<int,int>> v(4);
    for(int i = 0; i < 4; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    cout << abs(v[0].second-v[1].second) * abs(v[0].second-v[1].second) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
