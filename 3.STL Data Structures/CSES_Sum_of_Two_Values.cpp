/*
Autore: Tommaso Ulian
Data: 30/12/2023
Problema: CSES Sum of Two Values
Tags: Data Structures
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Spendo che la somma di due numeri A e B deve essere X allor per ogni numero A posso
memorizzare in una mappa A e la posizione di A, così se più avanti nell'array
dovessi incontrare B posso facilmente controllare se ho incontrato A e dove cercando nella 
mappa X-B.
*/

void solve(){
    int n, x; cin >> n >> x;
    vector<int> v;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        m[a] = i;
        v.push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(m.find(x-v[i]) != m.end() && i != m[x-v[i]]){cout << i+1 << " " << m[x-v[i]]+1; return;}
    }
    cout << "IMPOSSIBLE" << endl;
}

int main(){
    solve();
    return 0;
}