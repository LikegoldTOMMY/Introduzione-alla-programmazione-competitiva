/*
Autore: Tommaso Ulian
Data: 31/12/2023
Problema: AtCode Beginner Round Contest 241 D
Tags: Data Structures
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Per risolvere il problema dobbiamo trovare il K-esimo elemento più grande/piccolo
di X in complessità di tempo minore O(n), perchè venendo eseguire Q richieste in 
questo caso la complessità totale sarebbe O(q*n), e date le dimensioni massime di Q 
e N risulterebbe in TLE. 
Trovare il primo valore più grande o piccolo di X è un caso classico di binary search,
ma per poterlo fare l'array deve essere ordinato.
Per mantenere un array ordinato utilizziamo un multiset, che inoltre implementa con i 
metodi lower_bownd e upper_bownd il binary search.
*/

void solve() {
    ll q; cin >> q;
    multiset<ll> s;
    while (q--) {
        ll t; cin >> t;

        if (t == 1) {
            ll x; cin >> x;
            s.insert(x);
        } else if (t == 2) {
            ll x, k; cin >> x >> k;
            auto it = s.upper_bound(x);
            while (k > 0 && it != s.begin()) {
                k--; it--;
            }
            cout << (k > 0 ? -1 : *it) << endl;
        } else {
            ll x, k; cin >> x >> k;
            auto it = s.lower_bound(x);
            while (k > 1 && it != s.end()) {
                k--; it++;
            }
            cout <<  (it == s.end() ? -1 : *it) << endl;
        }
    }

    return;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    solve();
    return 0;
}