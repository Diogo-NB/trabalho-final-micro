#include <16F877A.h>

#FUSES PUT                      //Power Up Timer
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES WRT_1000                 //Program Memory Write Protected from 0 to 0x0FFF
#FUSES NOPROTECT                //Code not protected from reading

#use FIXED_IO(D_outputs=PIN_D7,PIN_D6,PIN_D5,PIN_D4,PIN_D3,PIN_D2,PIN_D1,PIN_D0)
#use FIXED_IO(A_outputs=PIN_A5)

#use delay(crystal=8MHz)

#define S1   PIN_B0
#define S2   PIN_B1
#define S3   PIN_B2
#define S4   PIN_B3

#define DU   PIN_B4
#define DD   PIN_B5
#define DC   PIN_B6
#define DM   PIN_B7

#define BUZZER   PIN_A5
