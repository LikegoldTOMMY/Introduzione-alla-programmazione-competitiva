# Breadth First Search 
>Appunti basati su questo [pdf](https://moodle2.units.it/pluginfile.php/438805/mod_resource/content/1/Lecture_16_handout.pdf) riguardante i grafi e le lezioni in preparazione alle gare regionali dell'università LUISS

****

## Teoria
La ***Breadth First Search*** (Ricerca in ampiezza), chiamata più comunemente ***BFS***, è un algortmo di ricerca per i grafi che permette di verificare se da nodo di partenza è possibile arrivare ad un altro nodo del grafo.  
Per esempio possiamo verificare se un grafo è bipartito, ovvero se è suddivisibile in 2 sottoinsiemi di punti tali che ogni punto di un insieme è collegato solo a punti appartenenti all'altro.

Questo esempio lo tratteremo in seguito, dopo aver visto come funziona questo algoritmo.

Utilizziamo come esempio il seguente albero:  
<img src="https://github.com/LikegoldTOMMY/Introduzione-alla-programmazione-competitiva/blob/main/Useful%20Files/Graph.png?raw=true)" width="340" height="260">

Esso può essere descritto come una lista di adiacenza, costruita come una mappa di set in cui la chiave della mappa è il nodo padre e il set corrispondente è l'insieme dei figli.
Detto ciò possiamo inizializzare la lista come:

    map<int, set<int>> graph;

Ora possiamo iterare per inserire il grafo nella lista. In input deve essere fornito un numero *n* che rappresenta il numero degli archi e successivamente altri *2n* numeri, che rappresentano rispettivamente il nodo di partenta e il nodo di arrivo.

    int n;
    cin>>n;
    while(n--){
        int x, y;
        cin>>x>>y;
        graph[x].insert(y);
    }

Questa iterazione salva solo i grafi orientati. Nel caso volessimo salvare un grafo non orientato l'iterazione diventerebbe:

    int n;
    cin>>n;
    while(n--){
        int x, y;
        cin>>x>>y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

Dal momento che il nostro grafo è un albero, possiamo usare il primo metodo per prenderlo in input. L'inpur sarà quindi:

    8
    1 2
    1 3
    2 4
    3 5
    4 6
    4 7
    5 7
    5 8

La nostra mappa risulterà quindi:

    //chiave: {set di valori}
    1: {2, 3}
    2: {4}
    3: {5}
    4: {6, 7}
    5: {7, 8}

Come si può notare i nodi 6, 7, 8 non sono presenti tra le chiavi dal momento che non hanno figli

Ora, per spiegare e comprendere a pieno il concetto di BFS è conveniente suddividere l'albero precedentemente creato in livelli, chiamati layer:
<img src="https://github.com/LikegoldTOMMY/Introduzione-alla-programmazione-competitiva/blob/main/Useful%20Files/Layers.png?raw=true)" width="340" height="260">

La BFS deve il suo nome al modo in cui ricerca un nodo nel grafo: esso, in contrapposizione alla ricerca DFS, esegue una ricerca sul grafo passando da un layer a quello sottostante.  
La ricerca itererà sui layer fino a quando non trova il nodo desiderato, quindi prima sul nodo 0 (Layer 0), poi sui nodi 2 e 3 (Layer 1), successivamente su 4 e 5 (Layer 2) e infine su 6, 7 e 8 (Layer 3).

Ora che abbiamo compreso in che modo lavora la BFS possiamo fare una implementazione in pseudocodice:

    mappa(interi, set(interi)) grafo

    funzione BFS(da_trovare):
        coda Q
        inserisci 1 in Q

        while Q non è vuota:
            t = Q.rimuovi()

            if t è uguale a da_trovare:
                return t
            for nodo in grafo[t]:
                Q.aggiungi(nodo)

Questo è una versione "ridotta" e funzionante nel caso in cui si parli di un grafo orientato.  
Nel caso in cui fosse non orientato bisogna tenere conto dei nodi già visitati in un array di bool:

    mappa(interi, set(interi)) grafo

    funzione BFS(da_trovare):
        coda Q
        vettore visitati
        inserisci 1 in Q
        visitati[1] = true

        while Q non è vuota:
            t = Q.rimuovi()
            if t è uguale a da_trovare:
                return t

            for nodo in grafo[t]:
                if visitati[nodo] non è true: 
                    Q.aggiungi(nodo)
***

## Complessità
L'algoritmo è utilizzabile sia su grafi orientati, sia su quelli non orientati e il peso degli archi non influenza la BFS, a differenza dell'[Algoritmo di Dijkstra](https://github.com/LikegoldTOMMY/Introduzione-alla-programmazione-competitiva/blob/main/13.%20Dijkstra/Dijkstra.md) e dall'Algoritmo di Bellman-Ford.

**Dato un grafo G = (*V*, *E*),** in cui *V* è l'insieme dei nodi e *E* è l'insieme degli archi, la complessità dell'algoritmo è:
> ***O( |V| + |E| )***

***

## Esempio di applicazione del BFS