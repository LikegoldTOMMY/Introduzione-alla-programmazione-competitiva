/*
Autore: Tommaso Ulian
Data: 24/01/2024
Problema: Codeforces 1922 B
Rating: 800
Tags: Constructive algorithms, Implementation, Strings
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

void solve(){
    int n; cin >> n;
    string a,b,c; cin >> a >> b >> c;
    bool ca = false;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i] && c[i] != b[i]) ca = true;
        else if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i])ca = true;
    }
    cout << ((ca) ? "YES" : "NO") << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
