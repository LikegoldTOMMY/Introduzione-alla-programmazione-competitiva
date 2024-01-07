/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: Codeforces 1900 C
Rating: 1300
Tags: DFS and similar, DP, Trees
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
Immaginando di trovarci sul nodo 0, possiamo immaginare che ogni connessione fra i
nodi sia pesata, infatti in base alla lettera che c'è scritta sul nodo, gli spostamenti hanno
i seguenti costi:
- U -> Sinistra 1, Destra 1
- L -> Sinistra 0, Destra 1
- R -> Sinistra 1, Destra 0
In questo modo basta usare DFS per e ritornare il risultato minore possibile per raggiungere
una foglia, trovabile perchè avrà entrambi i figli 0,0.
*/

string moves;
vector<pair<int,int>> btree;

int dfs(int node, int count){
    if(btree[node].first == -1 && btree[node].second == -1)return count;
    int a = INFINITY, b = INFINITY;
    if(btree[node].first != -1){
        a = dfs(btree[node].first,(moves[node] == 'L')? count : count+1);
    }
    if(btree[node].second != -1){
        b = dfs(btree[node].second,(moves[node] == 'R') ? count : count+1);
    }
    return min(a,b);
}

void solve(){
    int n; cin >> n;
    moves.clear();
    cin >> moves;
    btree.clear();
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        btree.push_back({l-1,r-1});
    }
    cout << dfs(0,0) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
