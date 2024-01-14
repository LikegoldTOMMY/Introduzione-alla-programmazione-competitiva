/*
Autore: Tommaso Ulian
Data: 14/01/2024
Problema: Codeforces 1909 B
Rating: 1200
Tags: Bitmasks, Constructive algorithms, Math, Number theory
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

vector<ll> v;

ll mods(ll k){
    set<ll> s;
    for(auto x: v){
        s.insert(x%k);
    }
    return s.size();
}

void solve(){
    ll n; cin >> n;
    v.clear();
    ll m = 0;
    while(n--){
        ll x; cin >> x;
        v.push_back(x);
        m = max(m,x);
    }
    ll left = 1, right = 57;
    while(left <= right){
        ll c = left + (right-left)/2;
        ll a = mods(1ll << c);
        if(a == 2){
            cout << (1ll << c) << endl; 
            return;
        }
        if(a > 2){
            right = c;
        }
        else{
            left = c+1;
        }
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
