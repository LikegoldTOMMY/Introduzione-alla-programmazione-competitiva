# Appunti Binary Search 
> Appunti basati su questo [video](https://www.youtube.com/watch?v=GU7DpgHINWQ&t=2s) di Errichto e sul capitolo 3 del Competitive Programmer Handbook.
----

### Abstract
> E' un algoritmo usato per trovare:
> - Un valore in un array ordinato o in una funzione monotonica
> - Il primo / ultimo elemento di un array che soddisfa una condizione
>
> Al contrario della semplice ricerca ha complessita di tempo O(logN)
----
Usato per trovare un valore specifico, o il primo valore che soddisfa una condizione, in un array ordinato o in una funzione monotonica. (Una funzione è monotonica crescente se per ogni *x1 , x2* con *x1 < x2* allora *f(x1) <= f(x2)*, in parole povere se ritorna valori crescenti).

Il modo piu intuitivo per trovare questo valore è iterare in tutto l'array con un ciclo *for*, e se l'array non è ordinato, questo è anche l'unico modo.Ma se l'array è ordinato possiamo fare di meglio, con un algoritmo chiamato **binary search**, che ha complessità in tempo **O(logN)**, mentre la ricerca semplice con il ciclo *for* ha complessità O(N).

Molto probabilmente hai già usto il binary search nella tua vita scolastica, questo algoritmo è infatti quello usato per ricercare una parola in un dizionario. L'algoritmo in questo caso mantiene valida una sezione dell'array, inizialmente la sua totalità, e controlla il valore centrale in questa sezione. Se il valore centrale è più piccolo di quello desiderato allra posso escludere la parte sinistra della selezione, allo stesso modo se è più grande posso invece escludere quella di destra. Ripeto questa procedura finche non trovo il valore desiderato. 

Ogni volta che questa procedura viene ripetuta la dimensione dell'array viene dimezzata, perciò al massimo verrà ripetutto log2(n) volte, dove n è la dimensione dell'array. 

![GIF Binary Search non caricata](https://imgs.search.brave.com/Th07ISUWfOLLUyNL93qr4ahXbOg-8egksveLpaqS3yQ/rs:fit:860:0:0/g:ce/aHR0cHM6Ly9kMThs/ODJlbDZjZG0xaS5j/bG91ZGZyb250Lm5l/dC91cGxvYWRzL2Jl/UGNlVU1uU0ctYmlu/YXJ5X3NlYXJjaF9n/aWYuZ2lm.gif)
****
### Formula per l'elemento del mezzo

La formula più intuitiva per calcolare l'elemento centrale è **(L+R)/2**, dove L è l'indice di inizio della parte selezionata e R è la fine. 
Questa formula però, anche se concettualemente giusta, può portare problemi di overflow, la formula più sicura da usare è **L+(R-L)/2**. ***Usare sempre la seconda formula!***
****
### PseudoCodice

    L = 0, R = N-1
    while L <= R:
        mid = L + (R-L)/2
        if a[mid] == target: return mid
        if a[mid] > target: L = mid +1
        if a[mid] < target: R = mid -1
    return -1

Alla fine ritorno -1 perchè se esco dal ciclo significa che non ho trovato il valore, quindi ritorno la posizione -1.
****
### Radice di X
**Problema**: Dato un numero intero positivo X determinare se X è un quadrato perfetto.

**Soluzione con Binary Search:**
Considera l'intervallo [0,X], c è il centro di questo intervallo, ora applica il binary search paragonando c^2 con X. Questo è un esempio di come sia possibile utilizzare il binary seach non solamente su array, ma anche su funzioni monotoniche, in quanto c^2 è una funzione strettamente crescente.
****
### Trova il primo valore nell'array maggiore di X

Un idea che protrebbe passarvi per la mente è quella di cercare il primo numero maggiore di X con il binary search, ma questo non ritorna sempre il risultato corretto.

**Esempio:** X = 4 A = [2,3,5,6,8,10,12]

Il modo corretto per affrontare questo problema è invece quello di creare una variabile extra, dove memorizzare il riultato migliore trovato fin ora, e contiuare cercare con il binary search. 

**PsudoCodice**

    L = 0, R = N-1
    ans = -1
    while L <= R:
        mid = L + (R-L)/2
        if a[mid] >= target: 
            ans = mid
            R = mid -1
        if a[mid] > target: 
            L = mid +1
    return ans

Lo stesso codice può essere adattato per trovare valori minori di X.

****
### Trova il picco
Dato un array A che è inizialmente crescente e poi dopo un certo elemento X diventa decrescente. Trovare l'indice di X.

**Esempio:** A = [2,3,4,6,9,12,11,8,6,4,1]

Anche qui la ricerca con il *for* funziona, ma possiamo fare di meglio. 

Inanzitutto è untile pensare all'array come un array di valori booleani, in base a se rispettano o no la condizione desiderata, in questo caso a[i] > a[i-1]. ***Questo approccio è importante per tutti i problemi di binary search***.
Il problema si risolve quindi andando semplicemente a cercare il punto in cui cambia dall'essere vero, perchè crescente, all'essere fasle, quindi decrescente.

Posso quindi andare a fare binary search cercando se a[**centro**] > a[**centro**-1] se lo è allora so che fino al centro l'array è crescente, cioè il picco si trova alla destra, posso quindi memorizzare **centro** come risposta temporanea e impostare L come **cetro**+1. Se invece non è vero allora so che l'array alla sinistra del centro è decrescente, quindi il picco si trova alla sinistra, R = centro-1.

## Esercizi

Fare eserci del capitolo 4 della Roadmap, le soluzioni implementate e spiegate da me sono disponibili in questa cartella