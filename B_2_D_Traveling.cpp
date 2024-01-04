/*
Autore: Tommaso Ulian
Data: 04/01/2024
Problema: Codeforces 1869 B
Rating: 1100
Tags: Geometry, Math, Shortest Paths, Sortings
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Anche in questo caso è utile dividere il problema in casi, A è una major city 
o non lo è, B è una major city o non lo è. 
Se sia A e B lo sono allora basta rispondere 0 perchè il volo è gratis
Se B lo è e A no, allora basta viaggiare da A alla major city più vicina, che potrebbe 
anche essere B.
Lo stesso caso vale se A lo è e B no.
Se nessuna delle due lo è allora abbiamo due opzioni:
- Viaggiare direttamente da A a B
- Viaggiare da A alla major city più vicina, poi raggiungere la major city più vicina a B
  e poi raggiungere B.
Ovviamente in questo caso fra queste due scegliamo la meno costosa.
*/

vector<pair<ll,ll>> v;

ll distance(ll a, ll b){
    return abs(v[a].first-v[b].first) + abs(v[a].second-v[b].second);
}

void solve(){
    //Input n k a b
    ll n, k, a ,b; cin >> n >> k >> a >> b;
    a--; b--;
    v.clear();
    while(n--){
        ll x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    if(a < k && b < k){cout << 0 << endl; return;}
    if(b < k){
        ll m = distance(a,b);
        for(int i = 0; i < k; i++){
            m = min(m, distance(i,a));
        }
        cout << m << endl;return;
    }
    if(a < k){
        ll m = distance(a,b);
        for(int i = 0; i < k; i++){
            m = min(m, distance(i,b));
        }
        cout << m << endl;return;
    }
    ll m = distance(a,b);
    ll a_m = distance(a,b);
    for(int i = 0; i < k; i++){
        a_m = min(a_m, distance(i,a));
    }
    ll b_m = distance(a,b);
    for(int i = 0; i < k; i++){
        b_m = min(b_m, distance(i,b));
    }
    cout << min(m, b_m+a_m) << endl;return;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}