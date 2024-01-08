/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: AtCoder Beginner Contest 139 B
Rating: 123
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
IN ogni multi presa che utlizzo una presa è occpuata dalla 
multi-presa successiva, quindi dividiamo b / a-1 per ottenere
il numero di multi prese necessarie, può succedere però che 
venga usata una multi presa di troppo perchè stiamo considerando l'ultima
multipresa con una presa già occupata quando potrebbe non averla.
Controlliamo quindi per questa evenienza.
*/

void solve(){
    double a, b; cin >> a >> b;
    ll x = ceill(b/(a-1));
    cout << (((a-1)*(x-2)+a >= b) ? x-1 : x) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
