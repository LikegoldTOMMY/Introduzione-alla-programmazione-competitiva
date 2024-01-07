/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: Codeforces 1919 A
Rating: 800
Tags: Games, Math
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
Entrambi scambieranno solamente se hanno un numero minore dell'altro
Il gioco finisce quando entrambi hanno 0 monete, e dato che il gioco diminuisce le monete
totali una alla volta, Alice può vincere solo se la somma delle monete è dispari.
*/

void solve(){
    ll a, b; cin >> a >> b;
    if((a+b)& 1)cout << "Alice" << endl;
    else cout << "Bob" << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
