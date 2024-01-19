/*
Autore: Tommaso Ulian
Data: 18/01/2024
Problema: Codeforces 1921 B
Rating: 800
Tags:Greedy, Implementation
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;


void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int count = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0' && t[i] == '1'){
            if(count > 0)res++;
            count--;
        }
        if(s[i] == '1' && t[i] == '0'){
            if(count < 0)res++;
            count++;
        }
    }
    cout << res + abs(count) << endl;
}   
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
