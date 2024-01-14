/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: Codeforces 1900 B
Rating: 900
Tags: dp, Math
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    int a,b,c; cin >> a >> b >> c;
    cout << !(b%2 ^ c%2) << " " <<  !(a%2 ^ c%2) << " " << ! (a%2 ^ b%2) <<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
