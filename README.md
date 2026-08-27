# ⚙️ OpenPLC + Python Web App + Raspberry Pi
## Corso Oltre Formazione

## 📚 Presentazione del Corso

Questo repository contiene il materiale didattico, le esercitazioni pratiche e i progetti sviluppati durante il corso **OpenPLC + Python Web App + Raspberry Pi**, dedicato alla realizzazione di sistemi di automazione e supervisione IoT su piattaforma Linux.

Il corso, erogato da **Oltre Formazione**, integra la programmazione PLC, il controllo di dispositivi fisici tramite Raspberry Pi, la comunicazione industriale Modbus/TCP e lo sviluppo di un'interfaccia web in Python.

Il percorso formativo è articolato in due moduli principali, della durata di **20 ore ciascuno**, per un totale di **40 ore**:

1. **Modulo Automazione OpenPLC — 20 Ore**
   - Fondamenti di automazione PLC
   - Programmazione Ladder (LD)
   - Logica combinatoria e sequenziale
   - Contatori e temporizzatori
   - Gestione di motori e contattori
   - Interblocchi e condizioni di sicurezza
   - Configurazione e collaudo su Raspberry Pi

2. **Modulo Python Web App e IoT — 20 Ore**
   - Sviluppo di applicazioni web con Python
   - Comunicazione Modbus/TCP
   - Lettura e scrittura delle variabili OpenPLC
   - Realizzazione di una dashboard web
   - Controllo remoto degli I/O
   - Monitoraggio dello stato dell'impianto
   - Integrazione tra PLC, Raspberry Pi e interfaccia web
   - Collaudo del sistema IoT completo

---

## ❓ Cos'è OpenPLC?

**OpenPLC** è una piattaforma open-source per la programmazione e l'esecuzione di applicazioni PLC, basata sullo standard **IEC 61131-3**.

Nel progetto viene utilizzata per sviluppare la logica di automazione e successivamente eseguirla su un **Raspberry Pi con sistema operativo Linux**.

L'ambiente è costituito principalmente da:

- **OpenPLC Editor**: ambiente di sviluppo utilizzato per progettare e programmare l'applicazione PLC attraverso i linguaggi previsti dallo standard IEC 61131-3, con particolare attenzione al **Ladder Diagram (LD)**.
- **OpenPLC Runtime**: ambiente di esecuzione installato sul Raspberry Pi, responsabile dell'esecuzione ciclica del programma PLC e della gestione delle comunicazioni e degli I/O configurati.

Il principio di funzionamento del PLC segue il classico ciclo di scansione:

```text
        ┌───────────────────────┐
        │   LETTURA DEGLI I/O   │
        └───────────┬───────────┘
                    │
                    ▼
        ┌───────────────────────┐
        │  ESECUZIONE PROGRAMMA │
        │       LADDER          │
        └───────────┬───────────┘
                    │
                    ▼
        ┌───────────────────────┐
        │   AGGIORNAMENTO I/O   │
        └───────────┬───────────┘
                    │
                    ▼
              NUOVO CICLO
                         ┌─────────────────────┐
                         │       UTENTE        │
                         │   PC / Smartphone   │
                         └──────────┬──────────┘
                                    │
                                 Browser
                                    │
                                    ▼
                         ┌─────────────────────┐
                         │   PYTHON WEB APP    │
                         │     Dashboard       │
                         └──────────┬──────────┘
                                    │
                              Modbus/TCP
                                    │
                                    ▼
                    ┌────────────────────────────┐
                    │      RASPBERRY PI          │
                    │                            │
                    │   ┌────────────────────┐   │
                    │   │   OpenPLC Runtime  │   │
                    │   └─────────┬──────────┘   │
                    │             │              │
                    │          GPIO / I/O        │
                    │             │              │
                    └─────────────┼──────────────┘
                                  │
              ┌───────────────────┼───────────────────┐
              │                   │                   │
              ▼                   ▼                   ▼
       ┌─────────────┐     ┌─────────────┐     ┌─────────────┐
       │ LED /       │     │ Contattori  │     │ Pulsanti /  │
       │ Indicatori  │     │ K1 / K2     │     │ Sensori     │
       └─────────────┘     └─────────────┘     └─────────────┘
📘 MODULO 1 — AUTOMAZIONE OPENPLC
Durata: 20 Ore
Il primo modulo introduce i principi fondamentali della programmazione PLC attraverso OpenPLC, con particolare attenzione alla realizzazione di applicazioni Ladder e alla loro esecuzione su Raspberry Pi.

L'attività didattica alterna teoria, programmazione, simulazione, esercitazioni pratiche e collaudo dell'hardware.

📋 Programma del Modulo 1
01 — Primo Avvio e Accensione LED
Durata: 3 ore

Introduzione ai sistemi PLC e all'automazione industriale.
Installazione e configurazione dell'ambiente OpenPLC.
Introduzione a OpenPLC Editor e OpenPLC Runtime.
Configurazione del Raspberry Pi come piattaforma di esecuzione.
Introduzione al ciclo di scansione PLC.
Configurazione degli ingressi e delle uscite.
Creazione del primo programma Ladder.
Comando di un'uscita digitale.
Accensione e spegnimento di LED.
Test degli I/O fisici e/o simulati.

Modulo Structured Text (ST)
Il modulo introduce la programmazione PLC in Structured Text, linguaggio testuale previsto dalla norma IEC 61131-3, mettendolo a confronto con il Ladder Diagram (LD).

Argomenti
Introduzione al linguaggio Structured Text.
Struttura di un programma ST.
Variabili, tipi di dato e dichiarazioni.
Operatori logici, aritmetici e di confronto.
Istruzioni IF / THEN / ELSE.
Strutture CASE.
Cicli FOR, WHILE e REPEAT.
Gestione di ingressi e uscite.
Utilizzo di timer e contatori in ST.
Realizzazione di sequenze automatiche.
Conversione di semplici programmi Ladder in Structured Text.
Test e simulazione con OpenPLC.
Esecuzione del programma ST sul Raspberry Pi.
Esercitazione finale con gestione di I/O e sequenza automatica.
