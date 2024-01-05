#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

/*
A primo impatto può sembrare che il problema non possa essere risolto
senza generare tutte le stringhe ottenibili, ma questa soluzione non 
è abbastanza efficiente per ilimiti di memoria e tempo.
L'osservazione più importante per risolvere il problema è che se 
eseguiamo la seconda operazione e poi la prima il risultato è lo stesso
di rimuovere due volte la prima. Quindi rimuovendo sempre la seconda 
possiamo ottenere la prima lettere + tutte le opzioni.
ababc ad esempio per la prima lettera possiamo ottenere:
ababc senza fare nulla, aabc con un operazione, abc con due, ac con tre, a con quattro.
Rimuoviamo poi la prima lettera e ripetiamo con la seconda lettera come prima.
babc senza fare nulla, bbc con un operazione, bc con due, b con tre.
Se ripetendo questa operazione incontriamo come prima lettere una che è stata già 
incontrata allora tutte le stringhe ottenibili sono già state incontrate.
abc senza fare nulla, ac con un operazione, a con due.
stesso discorso per bc.
Per ogniuno di questi passaggi aggiungiamo al totale delle stringhe ottenute
la lunghezza della stringa di partenza. Nel primo passaggio n, nel secondo n-1,
nel terzo n-2, e così via. Ma aggiungiamo solo se non abbiamo già incontrato la 
lettera prima.
*/

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<bool> a(26,0);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[s[i]-'a'] == false){
            ans += n-i;
            a[s[i]-'a'] = true;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
