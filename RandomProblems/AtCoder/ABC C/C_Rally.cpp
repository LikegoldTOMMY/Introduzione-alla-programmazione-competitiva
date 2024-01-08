/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: AtCoder Beginner Contest 156 C
Rating: 85
*/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
Date le dimensioni massime di N e Xi (<100) basta usare brute force.
Calcolo quindi per ogni punto la fatica totale e ritorno il minimo.
*/


vector<int> v;

ll dist(int n){
    ll d = 0;
    for(auto x: v){
        d += pow(x-n,2);
    }
    return d; 
}

void solve(){
    int n; cin >> n;
    while(n--){
        int x; cin >> x; 
        v.push_back(x);
    }n = v.size();
    ll m = INFINITY;
    for(int i = 1; i <= *max_element(v.begin(),v.end()); i++){
        m = min(m, dist(i));
    }
    cout << m << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
