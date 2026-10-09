FUNCTION_BLOCK "FB_GestioneArrayEMatrici"
{ S7_Optimized_Access := 'TRUE' }
VERSION : 0.1

VAR
    // ==========================================
    // 1. SEZIONE DI DICHIARAZIONE (VAR)
    // ==========================================
    
    // Un Array monodimensionale: 5 pompe (da 1 a 5) con valore di pressione in REAL
    #PressioniPompe : ARRAY[1..5] OF REAL;
    
    // Una Matrice (Array 2D): 3 linee di produzione e 4 parametri per linea (INT)
    #MatriceParametri : ARRAY[1..3, 1..4] OF INT;
    
    // Variabili di appoggio per i contatori dei cicli FOR
    #i : INT; // Indice per l'array semplice
    #riga : INT;     // Indice per le righe della matrice
    #colonna : INT;  // Indice per le colonne della matrice
    
    #SommaTotalePressioni : REAL;
END_VAR

BEGIN
    // ==========================================
    // 2. UTILIZZO CON IL CICLO FOR (Array Semplice)
    // ==========================================
    
    #SommaTotalePressioni := 0.0;

    // Il ciclo FOR scorre l'array dal primo (1) all'ultimo (5) elemento
    FOR #i := 1 TO 5 DO
        // Sommiamo in automatico la pressione della pompa puntata dall'indice #i
        #SommaTotalePressioni := #SommaTotalePressioni + #PressioniPompe[#i];
    END_FOR;


    // ==========================================
    // 3. UTILIZZO CON LA MATRICE (Array 2D + FOR Annidati)
    // ==========================================
    
    // Per scorrere una matrice a due dimensioni servono DUE cicli FOR (uno dentro l'altro)
    FOR #riga := 1 TO 3 DO
        FOR #colonna := 1 TO 4 DO
            // Esempio: azzeriamo o impostiamo un valore cella per cella nella tabella
            #MatriceParametri[#riga, #colonna] := 0;
        END_FOR;
    END_FOR;

END_FUNCTION_BLOCK
