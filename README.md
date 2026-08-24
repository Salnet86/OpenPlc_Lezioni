⚙️ OpenPLC + Python Web App + Raspberry Pi — Corso Oltre Formazione (16 Ore)
​📚 Descrizione del Corso
​Questo repository raccoglie il materiale didattico e i progetti del corso di Automazione Industriale e IoT della durata di 16 ore, erogato da Oltre Formazione.
​Il percorso formativo guida i corsisti dalla programmazione base dei PLC fino allo sviluppo di un modulo Web App in Python per il controllo remoto e la supervisione dell'impianto gestito da OpenPLC su Raspberry Pi.
​❓ Cos'è OpenPLC?
​OpenPLC è un ambiente di sviluppo e controllo industriale open-source conforme allo standard IEC 61131-3.
​Si compone di due strumenti principali:
​OpenPLC Editor: Software per PC impiegato per la progettazione e la simulazione di schemi a contatti in linguaggio Ladder (LD).
​OpenPLC Runtime: Il motore di esecuzione installato sul dispositivo target (Raspberry Pi) che gestisce la logica di controllo e interagisce direttamente con i pin GPIO di ingresso/uscita (pulsanti, sensori, LED, relè e contattori).
​🛠️ Architettura del Sistema


  [ UTENTE ] ◄── Browser Web ──► [ WEB APP PYTHON ]
                                       │
                                   Modbus/TCP
                                       │
                                ┌──────▼──────┐
                                │   OpenPLC   │ (Runtime su Raspberry Pi)
                                └──────┬──────┘
                                       │
                             [ GPIO Raspberry Pi ]
                                       │
                      ┌────────────────┴────────────────┐
                      ▼                                 ▼
              [ LED / Indicatori ]             [ Contattori K1/K2 ]
Hardware: Raspberry Pi (gestione I/O fisici tramite GPIO).
​Software PLC: OpenPLC Runtime.
​Linguaggio di programmazione PLC: Ladder Diagram (LD).
​Supervisione IoT: Web App Python (Flask/FastAPI) via protocollo Modbus/TCP.
​🎓 Programma delle 16 Ore
​Modulo 1: Introduzione ad OpenPLC e Primo Avvio
​Cos'è un PLC e architettura funzionale di OpenPLC.
​Configurazione dell'Editor su PC e installazione del Runtime su Raspberry Pi.
​Struttura del ciclo di scansione (Scan Time: Lettura Ingressi ➔ Logica ➔ Scrittura Uscite).
​Esercitazione Pratica: Cablaggio virtuale/fisico e programma per l'accensione e lo spegnimento di un LED tramite pulsanti di START e STOP.
​Modulo 2: Logica Booleana e Porte Logiche in Ladder
​Conversione dagli schemi elettrici cablati alla logica Ladder.
​Studio ed esecuzione delle principali porte logiche:
​AND (contatti in serie)
​OR (contatti in parallelo)
​NOT, NAND, NOR, XOR
​Esercitazione Pratica: Circuiti di abilitazione a più condizioni e logiche di sicurezza.
​Modulo 3: Autoritenuta, Contattori e Teleinversione
​Concetto di autoritenuta per comandi ad impulso e memorizzazione dello stato.
​Gestione dei contattori e dei contatti ausiliari per la risposta del sistema.
​Circuito di Teleinversione di Marcia (Comando Avanti/Indietro per motori elettrici).
​Configurazione degli interblocchi elettrici e logici a salvaguardia del circuito.
​Esercitazione Pratica: Programmazione della teleinversione assicurando l'impossibilità di attivazione simultanea dei contattori K1 e K2.
​Modulo 4: Gestione dei Temporizzatori (Timer)
​Utilizzo dei blocchi funzione temporizzati standard:
​TON (Timer On-Delay — Ritardo all'attivazione)
​TOF (Timer Off-Delay — Ritardo alla disattivazione)
​TP (Timer Pulse — Generazione di impulsi di durata fissa)
​Esercitazione Pratica: Sequenza temporizzata di avvio impianti e lampeggio di segnalazione anomalie/LED.
​Modulo 5: Modulo Python Web App & Supervisione IoT
​Comunicazione tra la Web App Python e OpenPLC Runtime su Raspberry Pi.
​Implementazione del protocollo Modbus/TCP per la lettura e scrittura dei registri PLC.
​Creazione dell'interfaccia web per:
​Visualizzazione in tempo reale dello stato di LED, timer e contattori.
​Invio di comandi remoti (START, STOP, cambio direzione teleinversione).
​Gestione della diagnostica e degli stati di emergenza.
​Progetto Finale: Integrazione dell'impianto di automazione completo gestito e supervisionato via interfaccia Web.
