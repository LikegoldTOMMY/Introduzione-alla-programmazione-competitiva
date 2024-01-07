/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: Codeforces 1903 B
Rating: 1200
Tags: Bitmasks, Brute force, Constructive algorithms, Greedy
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
E' importante osservare la rappresentazione binaria dei numeri nella matrice
Se nei numeri della riga I(o colonna, è indifferente) è presente uno 0 in una 
specifica posizione, il numero nella posizione I del'array nella sua rappresentazione 
binaria in quella posizione deve avere uno zero.
Ripetiamo questo processo per ogni numero.
E' importante poi verificare che l'array trovato rispetti i criteri.
*/

void solve(){
    int n; cin >> n;
    vector<vector<unsigned long long>> m;
    for(int i = 0; i < n; i++){
        vector <unsigned long long> v;
        for(int j = 0; j < n; j++){
            int x; cin >> x;
            v.push_back(x);
        }
        m.push_back(v);
    }
    vector<bitset<30>> b;
    for(int i = 0; i < n; i++){
        bitset<30> a((1ULL << 30)-1);
        for(int j = 0; j < n; j++){
            if(i != j)a &= m[i][j];
        }
        b.push_back(a);
    }
    bool possible = true;
    vector<unsigned long long> ans;
    for(auto x: b)ans.push_back(x.to_ullong());
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && (ans[i] | ans[j]) != m[i][j]){
                possible = false;
            }
        }
    }
    if(possible){
        cout << "YES" << endl;
        for(auto x: ans)cout << x << " ";
        cout << endl;
    }
    else{cout << "NO" << endl;}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
