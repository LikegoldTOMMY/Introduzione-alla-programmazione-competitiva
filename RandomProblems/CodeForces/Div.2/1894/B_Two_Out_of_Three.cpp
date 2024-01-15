/*
Autore: Tommaso Ulian
Data: 12/01/2024
Problema: Codeforces 1894 B
Rating: 1000
Tags: Constructive algorithms
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> v;
    unordered_map<int,vector<int>> m;
    int i = 0;
    while(n--){
        int x; cin >> x;
        v.push_back(x);
        m[x].push_back(i);
        i++;
    }n = v.size();
    int c = 2;
    vector<int> ans(n,1);
    for(auto x: m){
        if(x.second.size() > 1 && c <= 3){
            ans[x.second[0]] = c;
            c++;
        }
    }
    if(c <= 3){
        cout << -1 << endl; return;
    }

    for(auto x: ans)cout << x << " ";
    cout <<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
