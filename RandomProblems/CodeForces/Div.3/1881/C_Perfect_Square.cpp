/*
Autore: Tommaso Ulian
Data: 12/01/2024
Problema: Codeforces 1881 C
Rating: 1200
Tags: Brute force, Implementation
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> m(n);
    for(int i = 0; i < n; i++){
       cin >> m[i];
    }
    ll c = 0;
    char a, b;
    for(int i = 0; i < n; i++){
        
        for(int j = i; j <n; j++){
            a = m[n-i-1][j], b =  m[j][i];
            c += (int)((max(a,b) - min(a,b)));
            m[n-i-1][j] = max(a,b); m[j][i] = max(a,b);

            a = m[n-j-1][i], b =  m[i][j];
            c += (int)((max(a,b) - min(a,b)));
            m[n-j-1][i] = max(a,b); m[i][j] = max(a,b);

            a = m[i][n-j-1], b =  m[j][i];
            c += (int)((max(a,b) - min(a,b)));
            m[i][n-j-1] = max(a,b); m[j][i] = max(a,b);
 
        }
    }
    cout << c << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
