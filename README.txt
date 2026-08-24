# ⚙️ OpenPLC + Python + Raspberry Pi — Percorso di Automazione Industriale

## 📚 Descrizione

Questo repository raccoglie un percorso pratico di **automazione industriale** sviluppato con **OpenPLC**, **Python** e **Raspberry Pi**.

Il progetto nasce con l'obiettivo di combinare la programmazione dei PLC con sistemi embedded e logica di automazione, partendo dai concetti fondamentali fino alla realizzazione di piccoli impianti simulati.

### Tecnologie utilizzate

* 🟢 OpenPLC
* 🐍 Python
* 🍓 Raspberry Pi
* ⚡ Ladder Logic (LD)
* 🔌 Porte logiche
* 🔄 Contattori
* ⏱️ Timer
* 🔁 Teleinversione
* 🏭 Automazione industriale

---

# 🎓 Percorso delle 7 lezioni

## Lezione 1 — Introduzione a OpenPLC

Introduzione alla programmazione PLC e all'ambiente OpenPLC.

### Obiettivi

* Comprendere la struttura di un PLC
* Creare un nuovo progetto
* Configurare gli ingressi e le uscite
* Utilizzare il linguaggio Ladder
* Effettuare la compilazione e il test del programma

### Progetto

**Comando base ON/OFF**

Un pulsante di START attiva un'uscita mentre un pulsante di STOP interrompe il funzionamento.

---

## Lezione 2 — Porte logiche

Studio delle principali funzioni logiche utilizzate nei sistemi di automazione.

### Logiche studiate

* AND
* OR
* NOT
* NAND
* NOR
* XOR

### Progetto

Realizzazione di circuiti logici in Ladder utilizzando contatti normalmente aperti e normalmente chiusi.

Esempio concettuale:

```text
INPUT A ──┐
          ├── AND ── OUTPUT
INPUT B ──┘
```

### Obiettivo

Comprendere come le porte logiche possono essere trasformate in logiche PLC.

---

# Lezione 3 — Autoritenuta e contattori

Introduzione ai circuiti di comando con **autoritenuta** e alla gestione dei contattori.

### Argomenti

* START
* STOP
* Autoritenuta
* Bobina del contattore
* Contatti ausiliari
* Interblocchi
* Sicurezza del comando

### Progetto

**Avviamento di un motore tramite contattore**

```text
START ──┬──────────────( K1 )
        │
K1  ────┘
```

Il contatto ausiliario di K1 mantiene attivo il comando dopo il rilascio del pulsante START.

---

# Lezione 4 — Timer PLC

Utilizzo dei temporizzatori per creare sequenze temporizzate.

### Timer studiati

* TON — Timer On Delay
* TOF — Timer Off Delay
* TP — Timer Pulse

### Progetto

**Avvio temporizzato**

Quando viene premuto START, il PLC attende un determinato intervallo di tempo prima di attivare l'uscita.

Esempio:

```text
START
  │
  ▼
[ TON 5s ]
  │
  ▼
MOTORE ON
```

### Applicazioni

* Ritardi di avviamento
* Temporizzazione luci
* Ventilazione
* Sequenze industriali
* Ritardi tra motori

---

# Lezione 5 — Teleinversione

Realizzazione di un circuito di **teleinversione di un motore**, con comando avanti/indietro.

### Componenti logici

* Contattore K1 — MARCIA AVANTI
* Contattore K2 — MARCIA INDIETRO
* START AVANTI
* START INDIETRO
* STOP
* Interblocco elettrico
* Interblocco logico

### Regola fondamentale

K1 e K2 **non devono essere attivi contemporaneamente**.

```text
START AVANTI ──► K1
                   │
                   └── INTERBLOCCO K2

START INDIETRO ─► K2
                   │
                   └── INTERBLOCCO K1
```

### Obiettivo

Simulare una logica industriale reale per il controllo della direzione di rotazione di un motore.

> ⚠️ I circuiti reali con tensioni industriali e motori devono essere realizzati esclusivamente con adeguate protezioni e da personale qualificato. La simulazione OpenPLC non sostituisce le protezioni elettriche reali.

---

# Lezione 6 — OpenPLC + Raspberry Pi + Python

Integrazione tra PLC, Raspberry Pi e Python.

### Architettura

```text
              ┌─────────────────┐
              │     OpenPLC     │
              │   PLC Runtime   │
              └────────┬────────┘
                       │
                       │
              ┌────────▼────────┐
              │   Raspberry Pi  │
              │                 │
              │     Python      │
              └────────┬────────┘
                       │
             ┌─────────┴─────────┐
             ▼                   ▼
          SENSORI             USCITE
```

### Python

Python viene utilizzato per creare applicazioni di supporto all'automazione, acquisire dati e interagire con il sistema.

Esempio concettuale:

```python
def controlla_impianto(stato):
    if stato:
        print("Impianto attivo")
    else:
        print("Impianto fermo")

controlla_impianto(True)
```

### Obiettivi

* Utilizzare Raspberry Pi come piattaforma embedded
* Integrare Python con sistemi di automazione
* Gestire ingressi e uscite
* Creare applicazioni di supervisione
* Collegare software e controllo industriale

---

# Lezione 7 — Progetto finale

## 🏭 Mini Impianto Automatico

Il progetto finale unisce gli argomenti affrontati durante il percorso.

### Funzioni

* Pulsante START
* Pulsante STOP
* Autoritenuta
* Porte logiche
* Contattori
* Timer
* Teleinversione
* Gestione degli stati
* Raspberry Pi
* Python
* OpenPLC

### Schema generale

```text
                  ┌───────────────┐
                  │    SENSORI    │
                  └───────┬───────┘
                          │
                          ▼
                  ┌───────────────┐
                  │    OpenPLC    │
                  │               │
                  │ LOGICA PLC    │
                  └───────┬───────┘
                          │
             ┌────────────┼────────────┐
             ▼            ▼            ▼
          TIMER       CONTATTO       K1 / K2
             │        LOGICO       AVANTI/IND.
             └────────────┬────────────┘
                          ▼
                  ┌───────────────┐
                  │   RASPBERRY   │
                  │      PI       │
                  └───────┬───────┘
                          │
                          ▼
                     🐍 Python
```

---

# 🧠 Competenze acquisite

Al termine del percorso vengono affrontati:

| Area            | Competenze                            |
| --------------- | ------------------------------------- |
| PLC             | Programmazione Ladder                 |
| OpenPLC         | Creazione e simulazione programmi PLC |
| Logica          | AND, OR, NOT, XOR, NAND, NOR          |
| Comando         | START, STOP, autoritenuta             |
| Automazione     | Contattori e interblocchi             |
| Temporizzazione | TON, TOF, TP                          |
| Motori          | Logica di teleinversione              |
| Embedded        | Raspberry Pi                          |
| Programmazione  | Python                                |
| Integrazione    | PLC + Raspberry Pi + Python           |

---

# 📁 Struttura del repository

```text
OpenPLC-Python-RaspberryPi/
│
├── README.md
│
├── Lezione_01/
│   ├── progetto_on_off/
│   └── README.md
│
├── Lezione_02/
│   ├── porte_logiche/
│   └── README.md
│
├── Lezione_03/
│   ├── autoritenuta_contattore/
│   └── README.md
│
├── Lezione_04/
│   ├── timer/
│   └── README.md
│
├── Lezione_05/
│   ├── teleinversione/
│   └── README.md
│
├── Lezione_06/
│   ├── raspberry_pi/
│   ├── python/
│   └── README.md
│
└── Lezione_07/
    ├── progetto_finale/
    ├── openplc/
    ├── python/
    └── README.md
```

---

# 🚀 Obiettivo del progetto

L'obiettivo è costruire un percorso completo che parte dalla **logica digitale** e arriva alla realizzazione di un sistema di **automazione industriale simulato**.

Il progetto permette di sviluppare competenze trasversali:

**Logica → PLC → OpenPLC → Automazione → Raspberry Pi → Python**

---

# 🛠️ Possibili sviluppi futuri

* [ ] Aggiungere una HMI
* [ ] Aggiungere sensori reali
* [ ] Creare una dashboard Python
* [ ] Registrare i dati dell'impianto
* [ ] Aggiungere comunicazione Modbus
* [ ] Collegare Raspberry Pi a OpenPLC
* [ ] Creare allarmi
* [ ] Aggiungere modalità AUTOMATICA/MANUALE
* [ ] Realizzare un sistema SCADA
* [ ] Aggiungere database per lo storico

---

# 👨‍💻 Conclusione

Questo repository rappresenta un percorso pratico di apprendimento nell'ambito dell'**automazione industriale**, combinando PLC, programmazione Ladder, Python e Raspberry Pi.

L'obiettivo finale è passare dalla semplice logica di comando alla progettazione di sistemi automatici sempre più completi e vicini alle applicazioni industriali reali.

⭐ **Se il progetto ti è utile, lascia una Star al repository!**
