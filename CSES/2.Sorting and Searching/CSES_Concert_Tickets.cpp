#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
 
void solve(){
    ll n, m; cin >> n >> m;
    multiset<ll> ms;
    while(n--){
        int x; cin >> x;
        ms.insert(x);
    }
    while(m--){
        ll x; cin >> x;
        auto it = ms.lower_bound(x+1);
        if(it == ms.begin())cout << -1 << endl;
        else{
            --it;
            cout << *it << endl;
            ms.erase(it);
        }
    }    
}
int main(){
    solve();
    return 0;
}
