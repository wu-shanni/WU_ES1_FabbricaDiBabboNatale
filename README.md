ESERCIZIO 1 - La Fabbrica di Babbo Natale
Scrivi un programma che simula la fabbrica di Babbo Natale usando fork e pipe.
Il processo padre (Babbo Natale) legge da tastiera quanti regali deve preparare
Crea un processo figlio (elfo) usando fork()
Babbo Natale conta i regali e manda il numero all'elfo tramite pipe
L'elfo riceve il numero, calcola quante scatole servono sapendo che ogni scatola contiene 3 regali (arrotonda per eccesso)
L'elfo stampa: "Servono X scatole per Y regali"
