/*
Autore: Tommaso Ulian
Data: 12/01/2024
Problema: Codeforces 1894 B
Rating: 800
Tags: Implementation, Strings
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
Dato che il vincitore dell'ultimo set giocato è certamente il vincitore
basta controllare l'ultimo carattere della stringa.
*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    cout << s[n-1] << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
