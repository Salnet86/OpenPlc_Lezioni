Simulazione led plc python
import time

def TimerOf():
    i=1
    secondi=0
    while i==1:
        time.sleep(0.9)
        secondi += 1
        LED_READ()
        if secondi==3:
            print("STOP TIMER Durata :",secondi)
            i=0

def LED_READ():
      print("\033[31mLED ROSSO\033[0m")


def S1():
    M0_0 = 0
    M0_1 = 1
    I0_0 = 0
    if not I0_0  and not M0_0:
        TimerOf()
        LED_READ()
    elif  not M0_1   and   not M0_0:
        print("Led disattivato")





def start():
    S1()

start()
