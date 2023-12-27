/*
Autore: Tommaso Ulian
Data: 27/12/2023
Problema: CodeForces 1850 F
Rating: 1300
Tags: Brute Force, Implementation, Math, Number Theroy
*/


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
L'idea più semplice è quella di tenere conto per ogni casella
da 1 ad N tenere conto di quante rane ci sono passate, andando quindi
per ogni rana ad aumentare nell'array tutti i suoi multipli di 1. Per 
poi andare a trovare il massimo di questo array.
Questo approccio certamente funziona, ma non è abbastanza efficiente
per i limiti imposti, nel peggiore dei casi, quindi con Ai = 1, n = 2*10^5.
Per ogni rana andiamo a scorrere l'array nella sua totalità.
E' possibile ovviare al problema tenendo prima conto di quante rane abbiamo
per ogni distanza di salto. Per poi ripetere il procedimento di sopra, ma aggiungendo
invece che 1 alla volta, direttamente il numero di rane.
Ipotizzando di avere una rana per tipo allora avremo il seguente numero di passaggi
n(1 + 1/2 + 1/3 + 1/4 + 1/5 + ..... + 1/n)
Questa in matematica è chiamata serie armonica e viene indicata con Hn
Hn ≈ ln(n)+ γ + 1/(2n) 
Dove γ è una costante e 1/(2n) tende a 0 per numeri molto grandi
La complessità è dunque O(N*logN)
*/

void solve(){
    int n; cin >> n;
    // !!ATTENZIONE!! Il problema usa indici a partiere da 1
    vector<int> cnt(n+1,0), m(n+1,0);
    for(int j = 0; j < n; j++){
        int x; cin >> x;
        if(x <= n){
            cnt[x]++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i)m[j]+=cnt[i];
    }
    cout << *max_element(m.begin(),m.end()) << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}