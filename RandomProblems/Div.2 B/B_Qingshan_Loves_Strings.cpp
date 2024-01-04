/*
Autore: Tommaso Ulian
Data: 04/01/2024
Problema: Codeforces 1890 B
Rating: 800
Tags: Constructive Algorithms, Implementation
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
E' utile suddividere il problema in casi, S può essere good o no, e stessa cosa per T
Se S è good allora non serve fare nulla.
Se S non è good e T non lo è allora non ha senso proseguire.
Se S non è good ma T lo è, controlliamo dove troviamo due caratteri ripetutti in S 
e se T non inizia e finisce con un carattere diverso da quelli ripetuti allora non è possibile
e non ha senso continuare, se invece possiamo inserire T sempre dove S si ripete allora 
possiamo rispondere di si.
*/


int isGood(string s){
    int count = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i-1])count ++;
    }
    return count;
}
void solve(){
    int n, m;
    cin >> n >> m;
    string s,t; cin >> s >> t;
    if(isGood(s) == 0){cout << "Yes" << endl; return;}
    if(isGood(t) != 0 ){cout << "No" << endl; return;}
    bool good = true;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            if(!((s[i] == '0' && t[0] == '1' && t[m-1] == '1') || (s[i] == '1' && t[0] == '0' && t[m-1] == '0')))good = false;
        }
    }
    if(good)cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}