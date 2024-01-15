/*
Autore: Tommaso Ulian
Data: 12/01/2024
Problema: Codeforces 1881 B
Rating: 800
Tags: Brute force, strings
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
 
typedef long long ll;
using namespace std;

/*
E'sufficiente utilizzare il brute force, limitandosi a 6 ripetizini dell'operzione
dato che la lunghezza massima è 5.
*/

void solve(){
    int n,m; cin >> n >> m;
    string x, s; cin >> x >> s;
    int i = 0;
    while(i < 6&& x.find(s) == string::npos){
        x = x+x;
        i++;
    }
    if(i >= 6)cout << -1 << endl;
    else cout << i << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}