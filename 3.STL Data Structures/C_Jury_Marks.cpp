/*
Autore: Tommaso Ulian
Data: 29/12/2023
Problema: CodeForces 831 C
Rating: 1700
Tags: Brute force, Constructive algorithms
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Allora immaginando di avere un valore iniziale X, ogni valore aggiunto o 
sottratto dai giudici vale Bi  e ogni punteggio parziale che simao riusciti a 
sentire Ki. Se Ki è stato ascoltato in un qualunque momento, ad esempio N
allora Xi = Ki - (B1 + B2 + B3 .... + BN)
Se ripetiamo questo processo quindi per ogni K e per ogni posizione, otteniamo
varie Xi possibili, se una di queste Xi è presente in ogni K allora è un valore 
possibile, e verra quindi contato.
Per il primo esempio, l'array dei punteggi B è [-5, 5, 0, 20]
Quindi se nella iesiama posizione invece del valore assegnato inseriamo la somma dei
parziali fino ad i otteniamo [-5,0,0,20], chiamiamo questo array Scores.
L' array K invece è [10], quindi le possibili X per 10 sono [10 - (-5), 10-0,10-0,10-20]
Quindi [5,0,20] sono possibili soluzioni.
Nel secondo esempio B = [-2000, -2000] e K = [3998000, 4000000]
Scores = [-2000, -4000]
Per K1 le possibili X sono [4000000, 4002000]
Per K2 le pissibili X sono [4002000, 4004000]
L'unica X probabile è quindi 4002000.
E' importante notare che nel primo esempio mentre calcolavamo le Prefix Sums di B ci siamo imbattuti in dei
duplicati, questo porta ad un valore di X che viene inserito più volte per una sola K, e quindi 
a contare delle X che non sono corrette. 
*/

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> scores;
    ll sum = 0;
    //Per evitare di contare delle prefix sums uguali immagazino i valori inseriti in un set
    //E inserisco solo se non presenti
    unordered_set<ll> present;
    while(n--){
        int x; cin >> x;
        sum += x;
        if(present.find(sum) == present.end())scores.push_back(sum);
        present.insert(sum);
        } 
    vector<ll> heard;
    while(k--){
        ll x; cin >> x;
        heard.push_back(x);
    }
    k = heard.size();
    //Memorizzo tutte le possibili X in una mappa assieme a quante volte sono comparse
    unordered_map<ll,ll> possible_start;
    for(auto x: heard){
        for(auto y: scores){
            ll a = x-y;
            if(possible_start.find(a) == possible_start.end())possible_start[a] = 0;
            possible_start[a]++;
        }
    }
    ll count = 0;
    //Se una X è comparsa K volte allora la conto come valida
    for(auto x: possible_start){
        if(x.second == k){
            count ++;
        }
    }
    cout << count << endl;
}
int main(){
    solve();
    return 0;
}