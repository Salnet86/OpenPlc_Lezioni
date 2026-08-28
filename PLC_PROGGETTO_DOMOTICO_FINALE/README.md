🏠 Progetto Domotica – OpenPLC su Raspberry Pi
📌 Descrizione

Questo progetto è stato realizzato come esercitazione finale di gruppo utilizzando OpenPLC e Raspberry Pi.

Il progetto consiste nella realizzazione di un sistema di automazione domestica programmato tramite Ladder Diagram (LD).

Il PLC gestisce diversi dispositivi e ambienti della casa, tra cui:

illuminazione della cucina;
illuminazione della camera;
illuminazione di tre camere/dormitori;
tapparella;
cancello automatico.

Il programma comprende inoltre la gestione degli stati tramite memorie interne, interblocchi, finecorsa, fotocellula, temporizzatore e funzioni di reset.

⚙️ Hardware e software
Hardware
Raspberry Pi
Modulo/PLC OpenPLC
Ingressi digitali
Uscite digitali
Pulsanti e comandi
Finecorsa
Fotocellula
Software
OpenPLC
Ladder Diagram (LD)
🏗️ Funzionamento del sistema

Il Raspberry Pi esegue il programma PLC tramite OpenPLC.

Gli ingressi vengono letti dal PLC e utilizzati dalla logica Ladder per determinare lo stato delle uscite.

Schema generale:

        INGRESSI
           │
           ▼
    ┌───────────────┐
    │    OpenPLC    │
    │               │
    │ Ladder Logic  │
    └───────┬───────┘
            │
            ▼
         USCITE


Le memorie interne vengono utilizzate per mantenere e gestire lo stato dei diversi ambienti.

💡 Gestione illuminazione

Il programma gestisce cinque ambienti:

Cucina
Camera
Dormitorio 1
Dormitorio 2
Dormitorio 3

Per ogni ambiente viene utilizzata una memoria interna M_Stato_*.

La memoria viene impostata tramite una bobina SET e riportata allo stato iniziale tramite una bobina RESET.

Esempio per la cucina:

I_Cucina
   │
   ▼
M_Stato_Cucina
   │
   ▼
Q_Cucina


Lo stesso principio viene utilizzato per gli altri ambienti.

🪟 Gestione tapparella

La tapparella viene controllata tramite due uscite:

Q_Salita
Q_Discesa


I comandi disponibili sono:

P_Salita
P_Discesa
P_Stop


Sono inoltre presenti due finecorsa:

FC_Alto
FC_Basso


La logica Ladder impedisce il funzionamento contemporaneo dei due movimenti.

Salita

La salita viene comandata tramite P_Salita e viene interrotta quando:

viene premuto P_Stop;
viene raggiunto FC_Alto;
viene attivata la condizione di interblocco con la discesa.
Discesa

La discesa viene comandata tramite P_Discesa e viene interrotta quando:

viene premuto P_Stop;
viene raggiunto FC_Basso;
viene attivata la condizione di interblocco con la salita.
🚪 Gestione cancello

Il cancello viene controllato tramite:

Q_Cancello_Avanti
Q_Cancello_Indietro


Sono presenti:

comando a chiave;
fotocellula;
finecorsa di apertura;
finecorsa di chiusura;
temporizzatore;
interblocco tra apertura e chiusura.

Le principali variabili utilizzate sono:

I_Chiave
Fotocellula
FC_Aperto
FC_Chiuso

Q_Cancello_Avanti
Q_Cancello_Indietro


L'apertura e la chiusura vengono gestite in modo che i due comandi non possano essere attivi contemporaneamente.

La fotocellula viene utilizzata come condizione di sicurezza durante la gestione del cancello.

⏱️ Temporizzatore

Nel programma è presente un temporizzatore di tipo TON.

TON0
PT = T#5000ms


Il tempo preimpostato è quindi:

5000 ms = 5 secondi

Il temporizzatore viene utilizzato nella logica di gestione del cancello.

🔄 Gestione degli stati

Per mantenere lo stato delle varie zone vengono utilizzate memorie interne:

M_Stato_Cucina
M_Stato_Camera
M_Stato_Dormi1
M_Stato_Dormi2
M_Stato_Dormi3


Queste variabili permettono al PLC di memorizzare lo stato di ciascun ambiente.

La gestione utilizza bobine di tipo:

SET
RESET

🔄 Reset

Il programma contiene una sezione dedicata al reset degli stati e delle uscite.

Vengono resettate le memorie:

M_Stato_Cucina
M_Stato_Camera
M_Stato_Dormi1
M_Stato_Dormi2
M_Stato_Dormi3


e le uscite relative alla movimentazione:

Q_Salita
Q_Discesa
Q_Cancello_Avanti
Q_Cancello_Indietro


Il reset permette di riportare il sistema in una condizione iniziale e controllata.

🪜 Ladder Diagram

Il programma è stato sviluppato utilizzando il linguaggio Ladder Diagram.

Di seguito viene riportato il disegno completo del programma:

Salvare l'immagine del Ladder nella cartella docs con il nome ladder.png.

Il Ladder comprende:

gestione delle luci;
memorie SET/RESET;
gestione tapparella;
gestione cancello;
finecorsa;
pulsanti;
fotocellula;
interblocchi;
temporizzatore;
reset delle uscite e degli stati.
📋 Variabili del progetto
Ingressi
Variabile	Descrizione
I_Cucina	Comando cucina
I_Camera	Comando camera
I_Dormitorio1	Comando dormitorio 1
I_Dormitorio2	Comando dormitorio 2
I_Dormitorio3	Comando dormitorio 3
P_Salita	Pulsante salita tapparella
P_Discesa	Pulsante discesa tapparella
P_Stop	Pulsante di stop
FC_Alto	Finecorsa superiore tapparella
FC_Basso	Finecorsa inferiore tapparella
I_Chiave	Comando a chiave del cancello
Fotocellula	Fotocellula di sicurezza
FC_Aperto	Finecorsa cancello aperto
FC_Chiuso	Finecorsa cancello chiuso
Memorie interne
Variabile	Descrizione
M_Stato_Cucina	Memoria stato cucina
M_Stato_Camera	Memoria stato camera
M_Stato_Dormi1	Memoria stato dormitorio 1
M_Stato_Dormi2	Memoria stato dormitorio 2
M_Stato_Dormi3	Memoria stato dormitorio 3
Uscite
Variabile	Descrizione
Q_Cucina	Uscita illuminazione cucina
Q_Camera	Uscita illuminazione camera
Q_Dormitorio1	Uscita illuminazione dormitorio 1
Q_Dormitorio2	Uscita illuminazione dormitorio 2
Q_Dormitorio3	Uscita illuminazione dormitorio 3
Q_Salita	Comando salita tapparella
Q_Discesa	Comando discesa tapparella
Q_Cancello_Avanti	Comando apertura cancello
Q_Cancello_Indietro	Comando chiusura cancello
Temporizzatore
Variabile	Tipo	Valore	Descrizione
TON_Q	TON	—	Temporizzatore
PT	TIME	T#5000ms	Tempo impostato
📁 Struttura del repository

Il repository contiene esclusivamente il progetto OpenPLC:

progetto-openplc/
│
├── README.md
│
├── openplc/
│   └── programma.xml
│
└── docs/
    └── ladder.png


Il file XML contiene il programma PLC utilizzato da OpenPLC.

La cartella docs contiene il disegno del Ladder utilizzato per la documentazione del progetto.

🧪 Test effettuati

Sono state verificate le principali funzioni del programma:

 Comando cucina
 Comando camera
 Comando dormitorio 1
 Comando dormitorio 2
 Comando dormitorio 3
 Salita tapparella
 Discesa tapparella
 Stop tapparella
 Finecorsa alto
 Finecorsa basso
 Apertura cancello
 Chiusura cancello
 Fotocellula
 Finecorsa cancello aperto
 Finecorsa cancello chiuso
 Temporizzatore
 Reset degli stati
 Reset delle uscite
🎯 Obiettivo dell'esercitazione

L'obiettivo finale è stato realizzare un sistema di automazione domestica tramite OpenPLC e Raspberry Pi, applicando i concetti di:

programmazione PLC;
Ladder Diagram;
gestione degli ingressi e delle uscite;
memorie interne;
SET e RESET;
temporizzatori;
finecorsa;
interblocchi;
dispositivi di sicurezza.

Il progetto rappresenta un'esercitazione pratica di automazione nella quale diverse funzioni domotiche vengono gestite attraverso un unico programma PLC.

👥 Progetto di gruppo

Esercitazione finale di gruppo – OpenPLC / Raspberry Pi

Progetto Esercizio finale 



🪜 PLC Ladder

Il programma PLC è stato realizzato in linguaggio Ladder Diagram (LD) tramite OpenPLC.

Illuminazione cucina
(* --- CUCINA --- *)

I_Cucina       M_Stato_Cucina       M_Stato_Cucina
---| |----+----------[/]----------------( S )---
          |
M_Stato_Cucina
---| |----+

M_Stato_Cucina                         Q_Cucina
---| |-----------------------------------( )---

Illuminazione camera
(* --- CAMERA --- *)

I_Camera       M_Stato_Camera        M_Stato_Camera
---| |----+----------[/]----------------( S )---
          |
M_Stato_Camera
---| |----+

M_Stato_Camera                          Q_Camera
---| |------------------------------------( )---

Dormitorio 1
(* --- DORMITORIO 1 --- *)

I_Dormitorio1    M_Stato_Dormi1      M_Stato_Dormi1
---| |------+----------[/]---------------( S )---
            |
M_Stato_Dormi1
---| |------+

M_Stato_Dormi1                         Q_Dormitorio1
---| |-------------------------------------( )---

Dormitorio 2
(* --- DORMITORIO 2 --- *)

I_Dormitorio2    M_Stato_Dormi2      M_Stato_Dormi2
---| |------ +----------[/]---------------( S )---
             |
M_Stato_Dormi2
---| |------+

M_Stato_Dormi2                         Q_Dormitorio2
---| |-------------------------------------( )---

Dormitorio 3
(* --- DORMITORIO 3 --- *)

M_Stato_Dormi3                         M_Stato_Dormi3
---| |------ +----------[/]---------------( S )---
             |
M_Stato_Dormi3
---| |------+

M_Stato_Dormi3                         Q_Dormitorio3
---| |-------------------------------------( )---

🛗 Comando salita
(* --- SALITA --- *)

P_Salita       P_Stop       FC_Alto       Q_Discesa
---| |-----------|/|----------|/|-----------|/|----( Q_Salita )

🛗 Comando discesa
(* --- DISCESA --- *)

P_Discesa      P_Stop       FC_Basso      Q_Salita
---| |-----------|/|----------|/|-----------|/|----( Q_Discesa )

🚪 Apertura cancello
(* --- APERTURA CANCELLO --- *)

I_Chiave       FC_Aperto       Fotocellula       Q_Cancello_Indietro
---| |-----------|/|---------------| |---------------|/|----( Q_Cancello_Avanti )

⏱️ Temporizzatore cancello
(* --- TEMPORIZZATORE --- *)

FC_Aperto
---| |--------------------[ TON0 ]
                            PT = T#5000ms

TON_Q
---| |-------------------------------> Q

🚪 Chiusura cancello
(* --- CHIUSURA CANCELLO --- *)

TON_Q          FC_Chiuso       Fotocellula       Q_Cancello_Avanti
---| |-----------|/|---------------|/|---------------|/|----( Q_Cancello_Indietro )

🛑 Reset degli stati
(* --- RESET CUCINA --- *)

I_Cucina
---| |--------------------------------( R ) M_Stato_Cucina


(* --- RESET CAMERA --- *)

I_Camera
---| |--------------------------------( R ) M_Stato_Camera


(* --- RESET DORMITORIO 1 --- *)

I_Dormitorio1
---| |--------------------------------( R ) M_Stato_Dormi1


(* --- RESET DORMITORIO 2 --- *)

M_Stato_Dormi2
---| |--------------------------------( R ) M_Stato_Dormi2


(* --- RESET DORMITORIO 3 --- *)

M_Stato_Dormi3
---| |--------------------------------( R ) M_Stato_Dormi3


Nota: lo schema riportato sopra è la rappresentazione testuale del programma Ladder OpenPLC. Il file PLCopen XML originale contiene tutti i collegamenti, le posizioni e i blocchi del programma.

🐧 Installazione su Linux

Per installare OpenPLC Runtime su Linux seguire i seguenti passaggi.

1. Installazione di Git

Aprire il terminale e installare Git:

sudo apt-get install git

2. Clonazione del repository

Clonare il repository ufficiale di OpenPLC:

git clone https://github.com/thiagoralves/OpenPLC_v3.git

3. Entrare nella cartella di OpenPLC
cd OpenPLC_v3

4. Eseguire lo script di installazione

Avviare l'installazione per Linux:

./install.sh linux


Lo script installerà e configurerà i componenti necessari per eseguire OpenPLC Runtime su Linux.

⚠️ Attenzione

Durante l'installazione potrebbero essere richiesti i permessi di amministratore o ulteriori dipendenze. In caso di errore, verificare il messaggio mostrato dal terminale prima di procedere.


🖥️ Installazione OpenPLC Editor

Per utilizzare l'editor OpenPLC, clonare il repository e accedere alla relativa cartella:

git clone https://github.com/Autonomy-Logic/openplc-editor.git
cd openplc-editor


A questo punto ci troviamo all'interno della cartella openplc-editor, dove sono presenti i file dell'editor utilizzato per creare e modificare il programma Ladder.


┌──────────────────────┐
│   OpenPLC Editor     │
│                      │
│  CREI IL LADDER      │
└──────────┬───────────┘
           │
           │ programma PLC
           ▼
┌──────────────────────┐
│   OpenPLC Runtime    │
│   Raspberry Pi/Linux │
│                      │
│  ESEGUE IL LADDER    │
└──────────┬───────────┘
           │
           │
           ▼
      localhost:8080
       interfaccia web
🚀 Avvio di OpenPLC Runtime

Dopo aver completato l'installazione, avviare OpenPLC Runtime.

Dalla cartella OpenPLC_v3:

./start_openplc.sh


Una volta avviato il Runtime, aprire un browser e accedere all'interfaccia web:

http://localhost:8080


L'interfaccia web permette di gestire il PLC e di caricare il programma.

📥 Caricamento del programma

Dall'interfaccia web di OpenPLC:

Accedere a localhost:8080.
Aprire la sezione dedicata al caricamento del programma.
Selezionare il file del progetto PLC.
Effettuare la compilazione.
Avviare il PLC.

Una volta avviato, OpenPLC Runtime esegue il programma Ladder.

🪜 Programma Ladder

Il programma è stato sviluppato utilizzando il linguaggio Ladder Diagram (LD).

Il Ladder gestisce le funzioni di automazione del progetto attraverso:

ingressi digitali;
memorie interne;
uscite digitali;
contatti normalmente aperti e normalmente chiusi;
bobine Set/Reset;
temporizzatori TON.
🔌 Variabili utilizzate
Ingressi
I_Cucina
I_Camera
I_Dormitorio1
I_Dormitorio2
P_Salita
P_Discesa
P_Stop
I_Chiave
FC_Alto
FC_Basso
FC_Aperto
FC_Chiuso
Fotocellula

Memorie
M_Stato_Cucina
M_Stato_Camera
M_Stato_Dormi1
M_Stato_Dormi2
M_Stato_Dormi3

Uscite
Q_Cucina
Q_Camera
Q_Dormitorio1
Q_Dormitorio2
Q_Dormitorio3
Q_Salita
Q_Discesa
Q_Cancello_Avanti
Q_Cancello_Indietro

Temporizzatore
TON0
TON_Q
T#5000ms

⚙️ Funzionamento

Il sistema riceve i comandi dagli ingressi e modifica lo stato delle relative memorie interne.

Le memorie M_Stato_* vengono utilizzate per mantenere lo stato delle utenze.

Le uscite Q_* vengono attivate in base alle condizioni definite nel programma Ladder.

Per la gestione dei movimenti sono presenti interblocchi che impediscono l'attivazione contemporanea dei comandi incompatibili.

Nel controllo del cancello vengono utilizzati anche i finecorsa e la fotocellula per gestire correttamente le condizioni di apertura e chiusura.

⏱️ Temporizzatore

Nel programma viene utilizzato un blocco TON con un tempo preimpostato di:

T#5000ms


corrispondente a 5 secondi.

Il temporizzatore viene utilizzato nella sequenza di gestione del cancello.

📁 Struttura del progetto
progetto/
│
├── README.md
├── OpenPLC_v3/
│
├── openplc-editor/
│
└── programma.xml


programma.xml contiene il programma PLCopen utilizzato dal progetto.

💻 Tecnologie utilizzate
Python
Web App
Raspberry Pi
Linux
OpenPLC Runtime
OpenPLC Editor
Ladder Diagram (LD)
PLCopen XML
👥 Progetto di gruppo

Il progetto è stato realizzato come esercitazione finale di gruppo con l'obiettivo di sviluppare un sistema di automazione controllato tramite PLC e Raspberry Pi.


🔄 Differenza tra OpenPLC Editor e OpenPLC Runtime
🪜 OpenPLC Editor

OpenPLC Editor serve per progettare il programma PLC.

Con l'Editor si crea la logica di automazione, ad esempio il programma Ladder (LD) utilizzato nel nostro progetto.

In pratica:

Editor = creo e modifico il programma PLC

⚙️ OpenPLC Runtime

OpenPLC Runtime serve invece per eseguire il programma PLC.

Una volta creato il programma con l'Editor, questo viene caricato nel Runtime. Il Runtime esegue la logica e gestisce gli ingressi e le uscite del Raspberry Pi.

In pratica:

Runtime = eseguo il programma PLC

📌 Differenza in breve
OpenPLC Editor	OpenPLC Runtime
Crea il programma	Esegue il programma
Modifica il Ladder	Gestisce il Ladder
Utilizzato per la programmazione	Utilizzato durante il funzionamento
Prepara il progetto PLC	Esegue il progetto sul Raspberry Pi
È l'ambiente di sviluppo	È il motore PLC
🔗 Come lavorano insieme
OPENPLC EDITOR
      │
      │  programma Ladder
      ▼
   PROGRAMMA PLC
      │
      │  caricamento
      ▼
OPENPLC RUNTIME
      │
      ▼
RASPBERRY PI
      │
      ▼
 INGRESSI / USCITE


Quindi non sono due versioni dello stesso programma: l'Editor serve a creare il PLC, mentre il Runtime serve a farlo funzionare.

Installazione
1. OpenPLC Runtime

Il runtime OpenPLC è il componente che esegue realmente il programma PLC e il codice Ladder. Viene utilizzato per controllare gli ingressi e le uscite del sistema.

Su Linux:

sudo apt-get update
sudo apt-get install git

git clone https://github.com/thiagoralves/OpenPLC_v3.git
cd OpenPLC_v3
./install.sh linux


Dopo l'installazione, il runtime OpenPLC può essere utilizzato tramite l'interfaccia web disponibile normalmente su:

http://localhost:8080

2. OpenPLC Editor

L'OpenPLC Editor è invece il programma utilizzato per creare e modificare il progetto PLC, compreso il programma Ladder.

Per scaricarlo:

git clone https://github.com/Autonomy-Logic/openplc-editor.git
cd openplc-editor


L'Editor e il Runtime hanno quindi funzioni differenti.

Differenza tra OpenPLC Runtime e OpenPLC Editor
Componente	Funzione
OpenPLC Runtime	Esegue il programma PLC e gestisce ingressi e uscite
OpenPLC Editor	Permette di creare e modificare il programma PLC/Ladder
localhost:8080	È l'indirizzo web dell'interfaccia del Runtime OpenPLC

In pratica:

OpenPLC Editor
      │
      │  Programma Ladder
      ▼
OpenPLC Runtime
      │
      │  Gestione I/O
      ▼
Raspberry Pi / Modulo PLC


Quindi non sono due versioni dello stesso programma: l'Editor serve per sviluppare il programma, mentre il Runtime serve per eseguirlo.

Installazione dei due componenti

Per utilizzare il progetto completo è quindi necessario distinguere:

OpenPLC Runtime

git clone https://github.com/thiagoralves/OpenPLC_v3.git
cd OpenPLC_v3
./install.sh linux


OpenPLC Editor

git clone https://github.com/Autonomy-Logic/openplc-editor.git
cd openplc-editor


Il Runtime è il componente principale necessario per eseguire il progetto sul Raspberry Pi. L'Editor viene utilizzato per realizzare o modificare il programma Ladder prima di trasferirlo al Runtime.
