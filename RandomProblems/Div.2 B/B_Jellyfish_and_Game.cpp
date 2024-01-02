/*
Autore: Tommaso Ulian
Data: 02/01/2024
Problema: Codeforces 1875B
Rating: 1200
Tags: Brute force, Greedy, Implementation
*/


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> g,j;
    while(n--){
        int x; cin >> x; g.push_back(x);
    }
    while(m--){
        int x; cin >> x; j.push_back(x);
    }

    sort(g.begin(),g.end());
    sort(j.begin(),j.end());

    if(g[0] < j[j.size()-1])swap(g[0],j[j.size()-1]);

    sort(g.begin(),g.end());
    sort(j.begin(),j.end());
    k--;
    if(k & 1)swap(j[0],g[g.size()-1]);
    ll res = 0;
    for(int i = 0; i < g.size(); i++){
        res += g[i];
    }
    cout << res << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}