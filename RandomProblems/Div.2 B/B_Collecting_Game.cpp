/*
Autore: Tommaso Ulian
Data: 02/01/2024
Problema: Codeforces 1904B
Rating: 1100
Tags: Binary search, dp, Greedy, Two Pointers
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


/*
Prima di tutto ordiniamo l'array, notiamo che per il numero più grande sarà possibile
rimuvere N-1 numeri, tutti tranne se stesso, per il secondo numero più grande invece sarà possibile
rimuovere o N-1 numeri se la somma di tutti i numeri più piccoli di lui è maggiore del numero più grande
o N-2 numeri se non lo è.
Basandoci su questa idea troviamo che iterando nell'array ordinato per ogni numero lascieremo o
- N-i numeri dove i è l'indice del numero dell'array ordinato
- lo stesso numero di mele che ha lasciato il numero precedente
Per trovare la somma di tutti in numeri più piccoli usiamo le prefix sums, per dare la risposta 
teniamo in oltre conto degli indici orginali quando ordiniamo l'array.
*/

void solve(){
    int n; cin >> n;
    vector<pair<ll,ll>> v;
    ll sum = 0;
    for(int i = 0; i< n; i++){
        int x; cin >> x;
        v.push_back({x,i});
        sum += x;
    }
    sort(v.rbegin(),v.rend());
    vector<ll> ans(n);
    ans[v[0].second] = n-1;
    for(int i = 1; i< n; i++){
        sum -= v[i-1].first;
        if(sum >= v[i-1].first) ans[v[i].second] = ans[v[i-1].second];
        else ans[v[i].second] = n-i-1;
    }

    for(int x: ans)cout << x << " ";
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}