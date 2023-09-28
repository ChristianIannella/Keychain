# Keychain


Portachiavi elettronico con generatore di numeri casuali da 1 a 6.

![Dice keychain by Iannella Christian](https://github.com/ChristianIannella/Keychain/blob/main/Dice/Docs/IMG_2136.JPG)


Questo dado elettronico è basato su un Attiny85 (SOIC 8), a bordo c'è un pulsante collegato a IO2 (pin 7), uno slot per batteria CR2032.

Il dispositivo viene attivato alla pressione del pulsante e genererà dei numeri casuali visualizzti su sette led disposti come su un dado, dopo
un certo tempo si spegneranno per tornare in modalità **Deep Sleep** questo permette alla batteria di durare per un lunghissimo periodo.

E' in oltre possibile programmare il dispositivo a propio piacimento, puoi utilizzare il programmatore [ICSP Uploader](https://www.tindie.com/products/30806/)
