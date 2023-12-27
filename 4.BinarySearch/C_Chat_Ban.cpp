/*
Autore: Tommaso Ulian
Data: 27/12/2023
Problema: CodeForces 1612 C
Rating: 1300
Tags: Binary Search, Math
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/* 
Questa funzione è usata per contare quente emote sono presenti nel 
triangolo di dimensione K fino alla riga M. Se M è minore di k posso 
usare la formula matematica per la somma dei numeri da 1 a N. N*(N+1)/2
Sennò devo aggiungere alla somma da 1 a K, la somma dei numeri da k+1 a M
con la formula (k-1)*(k-1+1)/2 - m*(m+1)/2
*/

ll number_emotes(ll m,ll k){
    if(m < k)return m*(m+1)/2;
    else{
        ll x = 2*k - 1 - m;
        return (k*(k+1)/2) + ((k-1)*k/2) - (x*(x+1)/2);
    }
}


//Nota: E' importante utilizzare long long e non int per via della dimensione dell'input
//Nota 2: La normale ricerca con for non funziona per i limiti del problema.

/*
Il problema è risolvibile in modo molto semplice utilizzando il binary search, 
in quanto stiamo cercando per quale valore la funzione sopra diventa maggiore di un 
certo valore X. In quanto la funzione sopra è monotonica crescente possiamo utilizzare il 
binary search. 
*/

void solve(){
    ll k,x;
    cin >> k >> x;
    ll left = 1, right = k*2 -1;
    //E' importante impostare la risposta di default a tutti i messaggi,
    // Dato che se non soddisfiamo mai la condizione, allora possiamo inviare tutti i messaggi
    ll ans = k*2 -1;
    while(left <= right){
        ll m = left + floor((right-left)/2);
        if(number_emotes(m,k) >= x){
            right = m-1;
            ans = m;
        }
        else{
            left = m +1;
        }
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}