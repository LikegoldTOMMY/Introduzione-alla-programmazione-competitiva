/*
Autore: Tommaso Ulian
Data: 12/01/2024
Problema: Codeforces 1898 A
Rating: 1500
Tags: Greedy, math
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
    n = v.size();
    reverse(v.begin(),v.end());
    ll m = v[0];
    ll count = 0;
    for(ll i = 1; i < n; i++){
        if(v[i] >= m){
            ll a = ceil(v[i]/(double)m);
            count += a-1;
            m = floor(v[i]/a);
        }
        m = min(m,v[i]);
    }
    cout  << count << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}