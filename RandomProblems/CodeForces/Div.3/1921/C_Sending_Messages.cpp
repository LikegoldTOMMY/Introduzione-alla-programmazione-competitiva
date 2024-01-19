/*
Autore: Tommaso Ulian
Data: 18/01/2024
Problema: Codeforces 1921 C
Rating: 900
Tags:Greedy, Math
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    ll n,f,a,b; cin >> n >> f >> a >> b;
    ll sum = 0;
    ll prev = 0;
    while(n--){
        ll x; cin >> x;
        ll p = min(b, a*(x-prev));
        sum += p;
        prev = x;
    }
    cout << ((sum < f) ? "YES" : "NO") << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
