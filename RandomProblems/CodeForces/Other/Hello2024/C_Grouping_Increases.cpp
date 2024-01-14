/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: Codeforces 1919 C
Rating: 1400
Tags: Data structures, Dp, Greedy
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
 
typedef long long ll;
using namespace std;
 
 
void solve(){
    int n; cin >> n;
    int a=n+1, b=n+1;
    int ans = 0;
    while(n--){
        int x; cin >> x;
        if(x <= a && x <= b){
            if(a < b)a = x;
            else b = x;
        }
        else if(x <= a){
            a = x;
        }
        else if(x <= b){
            b = x;
        }
        else{
            if(a < b)a = x;
            else b = x;
            ans++;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}