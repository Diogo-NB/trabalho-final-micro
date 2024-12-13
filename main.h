#include <16F874A.h>
#device ADC=10

#FUSES PUT                      //Power Up Timer
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOPROTECT                //Code not protected from reading

#use delay(crystal=4MHz)

#use FIXED_IO(D_outputs=PIN_D7,PIN_D6,PIN_D5,PIN_D4,PIN_D3,PIN_D2,PIN_D1,PIN_D0)
#use FIXED_IO(B_outputs=PIN_B7,PIN_B6,PIN_B5,PIN_B4)

#define S1   PIN_B0
#define S2   PIN_B1
#define S3   PIN_B2
#define S4   PIN_B3

#define DU   PIN_B7
#define DD   PIN_B6
#define DC   PIN_B5
#define DM   PIN_B4

