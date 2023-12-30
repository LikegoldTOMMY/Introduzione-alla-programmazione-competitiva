/*
Autore: Tommaso Ulian
Data: 30/12/2023
Problema: cms_catalogo
Tags: Data Structures
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Il problema è triviale utilizzando una mappa

void solve(){
    unordered_map<ll,ll> m;
    int n; cin >> n;
    while(n--){
        char c; ll x;
        cin >> c >> x;
        switch(c){
            case 'a': m[x]++; break;
            case 't': m[x]--; break;
            case 'c': cout << m[x] << endl;
        }
    }
}
int main(){
    solve();
    return 0;
}