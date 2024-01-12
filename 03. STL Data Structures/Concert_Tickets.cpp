/*
Autore: Tommaso Ulian
Data: 30/12/2023
Problema: CSES Concert Tickets
Tags: Data Structures, Binary Search
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Il modo più semplice per risolvere il problema è trovare una
struttura di dati che ci permetta di trovare il primo elemento più piccolo
di X, questa struttura di dati dovrà quindi essere ordinata per utilizzare
il binary search, e che ci permetta di rimuovere elementi in tempo costante.
In questo case quindi si possono usare si una mappa che un multiset, anche se la
sintassi necessaria per la mappa è più complessa.
Inseriamo quindi tutti i biglietti in un multiset, poi per cercare il bigietto da vendere
usiamo la funzione upper_bound() che però ritorna il primo elemento più grande di X, quindi
bisogna utilizzare l'iteratore precedente a quello ritornato.
Se invece ritorna l'inizio del multiset allora vuol dire che non ci sono valori più piccoli 
di X e quindi nulla da vendere.
Quando poi troviamo un biglietto da vendere lo rimuoviamo dall'multiset con erase().
*/

void solve(){
    ll n, m; cin >> n >> m;
    multiset<ll> ms;
    while(n--){
        int x; cin >> x;
        ms.insert(x);
    }
    while(m--){
        ll x; cin >> x;
        auto it = ms.upper_bound(x);
        if(it == ms.begin())cout << -1 << endl;
        else{
            --it;
            cout << *it << endl;
            ms.erase(it);
        }
    }    
}
int main(){
    solve();
    return 0;
}