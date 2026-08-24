# ⚙️ OpenPLC + Python Web App + Raspberry Pi — Corso Oltre Formazione

## 📚 Presentazione del Corso

Questo repository contiene il materiale didattico, le esercitazioni pratiche e i progetti sviluppati per il corso di **Python web app per IoT fatto in open plc su Linux ** erogato da **Oltre Formazione**.

Il percorso si articola in due moduli principali da **16 ore ciascuno**:
1. **Modulo Automazione OpenPLC (16 Ore)**: Logica PLC, programmazione Ladder, test hardware e collaudo.
2. **Modulo Python Web App (16 Ore)**: Interfaccia web di controllo, protocollo Modbus/TCP, collaudo e supervisione IoT.

---

## ❓ Cos'è OpenPLC?

**OpenPLC** è la prima piattaforma PLC (Programmable Logic Controller) completamente open-source conforme allo standard **IEC 61131-3**.

Il sistema è composto da due elementi fondamentali:
* **OpenPLC Editor**: Software di sviluppo per PC utilizzato per la progettazione, la simulazione e la compilazione dei programmi in linguaggio **Ladder (LD)**.
* **OpenPLC Runtime**: Il motore di esecuzione installato sul target (**Raspberry Pi**) che esegue la logica di controllo in tempo reale e gestisce direttamente i pin GPIO di I/O (pulsanti, sensori, LED, relè e contattori).

---

## 🛠️ Architettura e Hardware del Sistema

```text
 [ UTENTE / CLIENT ] ◄── Browser Web ──► [ PYTHON WEB APP ]
                                                 │
                                            Modbus/TCP
                                                 │
                                          ┌──────▼──────┐
                                          │   OpenPLC   │ (Runtime su Raspberry Pi)
                                          └──────┬──────┘
                                                 │
                                       [ GPIO Raspberry Pi ]
                                                 │
                 ┌───────────────────────────────┼───────────────────────────────┐
                 ▼                               ▼                               ▼
       [ LED & Indicatori ]             [ Contattori K1/K2 ]            [ Sensori / Pulsanti ]




Modulo 16 ore  — OpenPLC
​01_accensione_led
​02_porte_logiche
​03_contatore_avanti_ctu
​04_timer_ton_tof_tim
​05_teleinversione_k1_k2
​06_collaudo_modulo_1

Struttura e Programma dei Moduli
​🔹 MODULO 1: Automazione con OpenPLC e Raspberry Pi (16 Ore)
​📌 Programma Dettagliato
​Introduzione ad OpenPLC & Primo Avvio:
​Cos'è OpenPLC e architettura del Runtime su Raspberry Pi.
​Configurazione del ciclo di Scan Time (Lettura Ingressi ➔ Logica ➔ Scrittura Uscite).
​Test Pratico: Accensione e gestione base di LED fisici/virtuali.
​Porte Logiche in Ladder Diagram:
​Trasposizione della logica Booleana in linguaggio Ladder.
​Implementazione delle porte logiche standard: AND, OR, NOT, NAND, NOR, XOR.
​Gestione dei Contatori (Counter):
​Programmazione ed uso del contatore incrementale CTU (Contatore Avanti).
​Gestione dei limiti di conteggio e reset logico.
​Temporizzatori (Timer IEC 61131-3):
​TON (Timer On-Delay — Ritardo all'attivazione).
​TOF (Timer Off-Delay — Ritardo alla disattivazione).
​TP / TIM (Timer Pulse — Impulso temporizzato / Generazione temporizzazioni).
​Teleinversione di Marcia & Sicurezza:
​Circuito di comando per la teleinversione di marcia di un motore (Avanti/Indietro).
​Gestione dei contattori K1 (Marcia Avanti) e K2 (Marcia Indietro).
​Configurazione degli interblocchi elettrici e logici (evita il cortocircuito da attivazione simultanea).
​Test e Collaudo Finale Modulo 1:
​Verifiche funzionali e collaudo del programma Ladder completo su scheda Raspberry Pi.
