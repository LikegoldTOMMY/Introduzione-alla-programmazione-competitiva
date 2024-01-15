/*
Autore: Tommaso Ulian
Data: 04/01/2024
Problema: Codeforces 1919 B
Rating: 800
Tags: Greedy
*/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
La penalità totale sarà uguale alla summa degli elementi.
*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    ll sum = 0;
    for(char c: s){
        if(c == '-')sum--;
        else sum ++;
    }
    cout << abs(sum) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
