/*
Autore: Tommaso Ulian
Data: 07/01/2024
Problema: Codeforces 1907 C
Rating: 1100
Tags: Constructive algorithms, Greedy, Math, Strings
*/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
Innanzi tutto se n è dispari non potremo mai rimovere tutte le lettere.
Se un caratere compare più di n/2 volte la stringa finale sarà composta
solamente da questo carattere, il numero di caratteri rimanenti sarà uguale 
al numero di ripetizioni del carattere più ripetuto meno il numero di caratteri 
diversi.
*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(26,0);
    for(auto c: s)cnt[c-'a']++;
    int m = *max_element(cnt.begin(), cnt.end());
    cout << max(n%2, m - (n-m)) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
