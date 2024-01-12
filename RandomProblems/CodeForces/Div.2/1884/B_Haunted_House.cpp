/*
Autore: Tommaso Ulian
Data: 02/01/2024
Problema: Codeforces 1884B
Rating: 1100
Tags: Binary search, Greedy, Math, Two Pointers
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Inanzitutto un numero è divisibile per 2^n se tutti i bit da 0 a n-1 sono 0.
Ad esempio 0000001 è divisibile solo per 2^0, 11010000 per 2^4 ma 11010010 solo per 2^1
Quindi la potenza di due più grande per cui una stringa binaria di lunghezza N può diventare
divibile è 2^(N-C) dove C è il numero di 1 nella stringa.
Quindi basta iterare da 0 a N-C e nel resto rispondere automaticamente -1
Ora bisogna trovare quanti spostamenti bisogna fare per ogni 1, che in altre parole significa 
trovare il primo 0 disponibile, cioè alla destra dell 1 che stiamo spostando.
Scorrere l'array finchè non lo troviamo è problematico perchè richiede O(N) e va ripetuto per ogni 1
Per optare a questo memoriziamo le posizioni di tutti gli 1 in un set per poi poter usare lower_bownd 
per trovare lo zero più vicino alla posizione del 1. Una volta trovato lo rimuoviamo dal set perchè 
ora è un 1. 
Complessità di tempo O(N*logN)
*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int count = 0;
    set<int> zeros;
    reverse(s.begin(),s.end());
    for(int i = 0; i < n; i++){
        if(s[i] == '1')count++;
        else zeros.insert(i);
    }
    ll res = 0;
    for(int i = 0; i  < n-count; i++){
        set<int>::iterator it = zeros.lower_bound(i);
        res += *it -i;
        cout << res << " ";
        zeros.erase(it);
    }
    for(int i = 0; i < count; i++){
        cout << -1 << " ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}