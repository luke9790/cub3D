
1. va messa una funzione wrap per il parse del file

2. la prima cosa da parsare sono le texture
    - open(fd) ->  controllare se fallisce o VUOTO
    - matrice a 2 dimensioni (contiene tutte e 4 le righe relative a N,S,E, O) -> funzione che lo fa (get_textures(int fd)) e ci salva la matrice con le info che vogliamo -> anche qui controlli
    - parsare la matrice riga per riga (ogni riga una coordinata)

3. la seconda cosa da parsare sono i colori 
    - simile a sopra, sara' una funziona che rientra nel parse_textures generale, possiamo usare createcolors.c (?)

4. la mappa e' FATTA.

- Funzioni piccole fatte relative a 1 - 2 - 3 (paolo):
    - vedi file pixels.c, init_window.c 


