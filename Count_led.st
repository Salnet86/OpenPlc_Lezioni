VAR
    AVANTI : BOOL;
    INDIETRO : BOOL;
    RESET : BOOL;
    CONTATORE : INT;
    LED : BOOL;
END_VAR


IF RESET THEN
    CONTATORE := 0;
ELSE
    IF AVANTI THEN
        CONTATORE := CONTATORE + 1;
    ELSE
        IF INDIETRO THEN
            IF CONTATORE > 0 THEN
                CONTATORE := CONTATORE - 1;
            END_IF;
        END_IF;
    END_IF;
END_IF;


// LED acceso quando il contatore arriva a 10
LED := CONTATORE >= 10;