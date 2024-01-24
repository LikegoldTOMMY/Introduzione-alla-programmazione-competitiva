/*
Autore: Tommaso Ulian
Data: 24/01/2024
Problema: Codeforces 1922 B
Rating: 1200
Tags: Combinatorics, Constructive algorithms, Math, Sortings
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    int n; cin >> n;
    map<int,int> m;
    while(n--){
        int x; cin >> x; m[x]++;
    }
    ll sum = 0;
    ll ans = 0;
    for(auto x: m){
        int cnt = x.second;
        if(cnt >= 3){
            ans += (cnt * (cnt-1) * (cnt-2)) / 6;
        }
        if(cnt >= 2){
            ans += sum* (cnt*(cnt-1)/2);
        }
        sum += cnt;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
