/*
Autore: Tommaso Ulian
Data: 05/01/2024
Problema: Codeforces 1913 C
Rating: 1400
Tags: Constructive algorithms, Greedy
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    ll n; cin >> n;
    vector<ll> v;
    while(n--){
        ll x; cin >> x;
        v.push_back(x);
    }
    vector<ll> suffix(v.size()+1, 0);
    for(int i = v.size()-1; i >= 0; i--){
        suffix[i] = suffix[i+1] + v[i];
    }
    ll res = suffix[0];
    for(ll i = 1; i < v.size(); i++){
        if(suffix[i] > 0)res += suffix[i];
    }
    cout << res << endl;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
