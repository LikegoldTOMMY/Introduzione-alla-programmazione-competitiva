/*
Autore: Tommaso Ulian
Data: 30/12/2023
Problema: AtCode Beginner Contest 206 C
Tags: Data Structures, Combinatorics
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
L'idea fondamentale per risolvere il problema è quella 
di rimuovere dal numero di coppie totali il numero di coppie ugali
Il numero di coppie totali è ottenibile con la formula "N scegli 2"
n(n-1)/2
Per contare quante volte un numero è presente lo memorizziamo in una mappa
e poi per rimuovere le coppie duplicate usiamo sempre la stessa formula, ma 
con il numero di duplicati.
*/

void solve(){
    ll n; cin >> n;
    unordered_map<ll,ll> m;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        m[x]++;
    }
    ll res = n*(n-1)/2;
    for(auto x: m){
        res -= x.second*(x.second-1)/2;
    }
    cout << res << endl;
}
int main(){
    solve();
    return 0;
}