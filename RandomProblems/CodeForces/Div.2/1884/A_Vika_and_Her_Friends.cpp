/*
Autore: Tommaso Ulian
Data: 02/01/2024
Problema: Codeforces 1884B
Rating: 900
Tags: Games, Math
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    int dx,dy,k; cin >> dx >> dy >> k;
    int x, y; cin >> x >> y;
    bool c = true;
    while(k--){
        int a,b; cin >> a >> b;
        if((a%2 + b%2)%2 == (x%2 +y%2)%2){
            c = false;
        }
    }
    cout << ((c) ? "YES" : "NO")<< endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
