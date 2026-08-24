# ⚙️ OpenPLC + Python Web App + Raspberry Pi — Corso Oltre Formazione

## 📚 Presentazione del Corso

Questo repository contiene il materiale didattico, le esercitazioni pratiche e i progetti sviluppati per il corso di **Automazione Industriale e IoT** erogato da **Oltre Formazione**.

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
