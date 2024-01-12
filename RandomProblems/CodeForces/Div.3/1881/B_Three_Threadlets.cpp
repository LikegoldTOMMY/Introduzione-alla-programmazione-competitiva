/*
Autore: Tommaso Ulian
Data: 12/01/2024
Problema: Codeforces 1881 B
Rating: 900
Tags: Math
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
Il problema può essere risolto con un apporoccio greedy, dato che un taglio
può solamente ridurre la dimensione di un segmento. Se l'array non è già 
tutto uguale è possibile sempre tagliare il segmento più grande, dividendolo 
creando due segmenti uno uguale al segmento più piccolo e quello che rimane. 
Se in tre mosse non si può raggiungere questo risultato allora non è possibile.
Dato che i numeri sono solamente tre l'array avrà dimensione massima di 6.
*/

void solve(){
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    
    for(int i = 0; i <= 3; i++){
        bool right = true;
        for(int i = 1; i < v.size(); i++){
            if(v[i] != v[i-1])right = false;
        }
        if(right){
            cout << "YES\n";return;
        }
        sort(v.begin(),v.end());
        v.push_back(v[v.size()-1]-v[0]);
        v[v.size()-2] = v[0]; 
    }
    
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
