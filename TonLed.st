VAR
    S1 : BOOL; // Pulsante
    LED1 : BOOL; // LED
    TON1 : TON; // Timer TON
END_VAR


// Avvio temporizzatore quando premo S1
TON1(IN := S1, PT := T#5s);


// Accendo il LED quando il timer è terminato
LED1 := TON1.Q;