/*
Autore: Tommaso Ulian
Data: 30/12/2023
Problema: AtCoder Beginner Contest 229 C
Tags: Greedy, Sorting
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Il problema è molto semplice e ultilizza la tattica greedy + sorting
Sapendo che vogliamo ottentere il valore massimo di bontà basta
sommare il più possibile dei formaggi, partendo dal più buono
Utiliazziamo un array di pair per tenere conto di ogni formaggio
il valore della bontà sarà il primo e la quantità disponibile il
secondo, ordiniamo l'array in base alla bontà e sommiamo finchè non 
otteniamo un peso uguale a k, o finchè finimao il formaggio
*/

void solve(){
    ll n; cin >> n; int k; cin >> k;
    vector<pair<ll,ll>> v;
    while(n--){
        ll d,w; cin >> d >> w;
        v.push_back({d,w});
    }
    n = v.size();
    //La funzione sort normalmente ordina in ordine crescente, usando rbegin e rend, 
    //lo oridna al contrario, quindi in ordine crescente.
    //Per i vettori di pair sort() usa il primo valore per i confronti
    sort(v.rbegin(), v.rend());
    ll i = 0;
    ll total = 0;
    while(i < n && k > 0){
        if(v[i].second <= k){
            total += v[i].first * v[i].second;
            k -= v[i].second;
        }
        else{
            total += k * v[i].first;
            k = 0;
        }
        i++;
    }
    cout << total << endl;
}
int main(){
    solve();
    return 0;
}