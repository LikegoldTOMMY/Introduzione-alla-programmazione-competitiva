/*
Autore: Tommaso Ulian
Data: 02/01/2024
Problema: Codeforces 1915E 
Rating: 1300
Tags: Greedy, Math, Data Structures
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Possiamo riscrivere il problema come A1-A2+A3-A4+A5-A6....
Ora il nostro compito è quello di trovare un sottoarray contiguo
che abbia somma totale uguale a 0. Questo è facilmente trovabile 
grazie alle prefix Sums, ci basta infatti che le prefix sums in I e J siano 
uguali per sapere che il segmento da I a J ha somma 0.
Ogni volta che calcoliamo una prefix sum la inseriamo in un set, e controlliamo se 
è già presente, se lo è allora la risposta è Sì. Se invece calcoliamo tutte le 
prefix sums senza trovare duplicati allora rispondiamo no.
*/

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      if (j % 2 == 1){
        a[j] *= -1;
      }
    }
    bool ok = false;
    set<long long> st = {0};
    long long s = 0;

    for (int j = 0; j < n; j++){
      s += a[j];
      if (st.count(s) == 1){
        cout << "YES" << endl; return;
      }
      st.insert(s);
    }
    cout << "NO" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}