VAR
    AVANTI : BOOL;
    INDIETRO : BOOL;
    MIO_RESET: BOOL;
    CONT1 : CTUD;
    VALORE_ATTUALE : INT;
    LIMITE_RAGGIUNTO : BOOL;
END_VAR


// Chiamata del blocco contatore Up/Down
CONT1(
    CU := AVANTI,
    CD := INDIETRO,
    R := MIO_RESET,
    LD := FALSE,
    PV := 10
);


// Lettura delle uscite del blocco
VALORE_ATTUALE := CONT1.CV; // Valore attuale del conteggio
LIMITE_RAGGIUNTO := CONT1.QU; // True se CV >= PV (10)

