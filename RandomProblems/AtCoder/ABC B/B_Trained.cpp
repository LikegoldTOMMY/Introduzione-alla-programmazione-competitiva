/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: AtCoder Beginner Contest 065 B
Rating: 458
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    unordered_set<ll> visited;
    bool running = true;
    ll pos = 0, count = 0;
    while(running){
        if(pos == 1)running = false;
        else if(visited.find(pos) != visited.end())running = false;
        else{
            visited.insert(pos);
            pos = v[pos]-1;
            count++;
        }
    }
    cout << ((pos == 1) ? count : -1) << endl;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
