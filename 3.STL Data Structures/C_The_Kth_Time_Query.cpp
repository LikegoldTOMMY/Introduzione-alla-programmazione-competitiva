/*
Autore: Tommaso Ulian
Data: 30/12/2023
Problema: AtCode Beginner Round Contest 235 C
Tags: Data Structures
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Per ogni numero che compare nell'array teniamo conto di tutt le posizioni in cui
compare in un array. Memorizziamo questi array di posizioni per ogni numero in una
mappa. Per ogni query, se il numero richiesto non è presente nella mappa o l'array 
di posizioni di quel numero non ha almeno tanti indici quanto stiamo chiedendo allora 
ritorniamo -1, sennò ritorniamo la posizione.
*/

void solve(){
    int n, q; cin >> n >> q;
    unordered_map<int,vector<int>> m;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(m.find(x) == m.end())m[x] = {};
        m[x].push_back(i+1);
    }
    while(q--){
        int x, i; cin >> x >> i;
        if(m.find(x) == m.end() || m[x].size() < i) cout << -1 << endl;
        else cout <<  m[x][i-1] << endl;
    }
}
int main(){
solve();
    return 0;
}