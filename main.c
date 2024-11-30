#include <main.h>

int16 V_INTERVALO_INCREMENTO = 1000;  
int16 contador = 0;  
int16 unidade;
int16 dezena;
int16 centena;
int16 milhar;

int16 fase = 0;
int16 inicio;
int16 velocidade;
int1 unidade_ativo = 0, dezena_ativo = 0, centena_ativo = 0, milhar_ativo = 0;
int1 unidade_ativode = 0, dezena_ativode = 0, centena_ativode = 0, 
milhar_ativode = 0;
int16 contde = 200;
int1 comeca=0;

int1 para_1=0,para_2=0,para_3=0;

int16 unidade_ativodecont = contde, dezena_ativodecont = contde, 
centena_ativodecont = contde, milhar_ativodecont = contde;

int16 contador_tela_inicial = 0;
int16 finalfase = 100;
int16 vez_contador_tela_inicial = 0;

const int8 listadisplay4[] = {0x08,0x00,0x00,0x01,0x02,0x04,0b01001000,
0b01000000,0b01000000,0b01000001,0b01000010,0b01000100};
const int8 listadisplay3[] = {0x00,0x08,0x01,0x00,0x00,0x00,0x00,0b01001000,
0b01000001,0x00,0x00,0x00};
const int8 listadisplay2[] = {0x00,0x01,0x08,0x00,0x00,0x00,0x00,0b01000001,
0b01001000,0x00,0x00,0x00};
const int8 listadisplay1[] = {0x01,0x00,0x00,0x08,0x10,0x20,0b01000001,
0b01000000,0b01000000,0b01001000,0b01010000,0b01100000};

const int8 u1 [] = {4,3,2,1,0,3,2,1,0,3,2,1,0,3,2,1,0,5,4,3,2,1,0,5,4,3,2,1,0,8,
7,6,5,4,3,2,1,0,8,7,6,5,4,3,2,1,0,5,4,3 ,2 ,1 ,0 ,10,11,11,12,12};
const int8 d1 [] = {3,2,1,0,0,2,1,0,6,5,4,3,2,1,0,4,3,2,1,0,2,1,0,2,1,0,3,2,1,0,
2,1,0,1,0,1,0,4,3,2,1,0,2,1,0,5,4,3,2,1 ,0 ,10,10,10,11,11,12,12};
const int8 c1 [] = {3,2,1,0,0,2,1,0,6,5,4,3,2,1,0,2,1,0,5,4,3,2,1,0,2,1,0,2,1,0,
7,6,5,4,3,2,1,0,5,4,3,2,1,0,2,1,0,1,0,10,10,10,10,10,11,11,12,12};
const int8 m1 [] = {2,1,0,1,0,1,0,1,0,9,8,7,6,5,4,3,2,1,0,5,4,3,2,1,0,3,2,1,0,3,
2,1,0,2,1,0,4,3,2,1,0,8,7,6,5,4,3,2,1,0 ,10,10,10,10,11,11,12,12};


const int8 u2 [] = {1,0,5,4,3,2,1,0,2,1,0,1,0,5,4,3,2,1,0,2,1,0,1,0,2,1,0,1,0,1,
0,1,0,1,0,8,7,6,5,4,3,2,1,0,7,6,5,4,3,2,1,0,10,10,10,10,11,11,11,12,12};
const int8 d2 [] = {2,1,0,3,2,1,0,2,1,0,1,0,1,0,3,2,1,0,2,1,0,1,0,2,1,0,1,0,1,0,
1,0,3,2,1,0,8,7,6,5,4,2,1,0,6,5,4,3,2,1,0,1,0 ,10,10,10,11,11,11,12,12};
const int8 c2 [] = {3,2,1,0,1,0,3,2,1,0,1,0,2,1,0,1,0,3,2,1,0,1,0,3,2,1,0,1,0,7,
6,5,4,3,2,1,0,1,0,1,0,2,1,0,5,4,3,2,1,0,3,2,1 ,0 ,10,10,11,11,11,12,12};
const int8 m2 [] = {4,3,2,1,0,5,4,3,2,1,0,4,3,2,1,0,5,4,3,2,1,0,3,2,1,0,1,0,1,0,
7,6,5,4,3,2,1,0,1,0,1,0,1,0,4,3,2,1,0,5,4,3,2 ,1 ,0 ,10,11,11,11,12,12};

const int8 u3 [] = {2,1,0,2,1,0,2,1,0,2,1,0,3,2,1,0,3,2,1,0,2,1,0,1,0,1,0,1,0,1,
0,3,2,1,0,1,0,4,3,2,1,0,6,5,4,3,2,1,0,2,1,0,2,1,0,5,4,3,2,1,0,2,1,0,2,1,0,2,1,0,
2,1,0,4,3,2,1,0,2,1,0,5,4,3,2,1,0,2,1,0,1,0,1,0,1 ,0 ,1 ,0 ,1 ,0 ,11,11,11,12,12};
const int8 d3 [] = {2,1,0,2,1,0,2,1,0,2,1,0,3,2,1,0,3,2,1,0,4,3,2,1,0,3,2,1,0,3,
2,1,0,1,0,1,0,2,1,0,1,0,1,0,4,3,2,1,0,2,1,0,5,4,3,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,
2,1,0,3,2,1,0,1,0,2,1,0,3,2,1,0,2,1,0,2,1,0,1,0,10,10,10,10,10,10,11,11,11,12,12};
const int8 c3 [] = {2,1,0,2,1,0,2,1,0,2,1,0,3,2,1,0,6,5,4,3,2,1,0,3,2,1,0,1,0,1,
0,1,0,2,1,0,1,0,1,0,3,2,1,0,1,0,2,1,0,5,4,3,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,
2,1,0,2,1,0,3,2,1,0,2,1,0,1,0,2,1,0,3,2,1,0,1,0,1 ,0 ,10,10,10,10,11,11,11,12,12};
const int8 m3 [] = {2,1,0,2,1,0,2,1,0,2,1,0,3,2,1,0,3,2,1,0,2,1,0,1,0,1,0,3,2,1,
0,1,0,2,1,0,1,0,7,6,5,4,3,2,1,0,5,4,3,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,
2,1,0,1,0,5,4,3,2,1,0,2,1,0,2,1,0,4,3,2,1,0,1,0,1 ,0 ,1 ,0 ,10,10,11,11,11,12,12};

const int8 u4 [] = {6,5,4,3,2,1,0,1,0,7,6,5,4,3,2,1,0,3,2,1,0,2,1,0,3,2,1,0,7,6,
5,4,3,2,1,0,7,6,5,4,3,2,1,0,5,4,3,2,1,0,10,10,11,11,12,12};
const int8 d4 [] = {5,4,3,2,1,0,1,0,1,0,5,4,3,2,1,0,3,2,1,0,4,3,2,1,0,3,2,1,0,3,
2,1,0,1,0,1,0,1,0,3,2,1,0,6,5,4,3,2,1,0,10,10,11,11,12,12};
const int8 c4 [] = {4,3,2,1,0,5,4,3,2,1,0,1,0,1,0,3,2,1,0,6,5,4,3,2,1,0,3,2,1,0,
1,0,1,0,3,2,1,0,1,0,1,0,7,6,5,4,3,2,1,0,10,10,11,11,12,12};
const int8 m4 [] = {3,2,1,0,7,6,5,4,3,2,1,0,1,0,3,2,1,0,8,7,6,5,4,3,2,1,0,3,2,1,
0,9,8,7,6,5,4,3,2,1,0,8,7,6,5,4,3,2,1,0,10,10,11,11,12,12};

const int8 display_numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0b00001000,0b01001000,0b01001001};

int1 pasou_fase_1=0;
int1 pasou_fase_2=0;
int1 pasou_fase_3=0;
int1 pasou_fase_4=0;

int16 contador_ms = 0;  // Contador de milissegundos para controle de intervalo
void verificaerro0 ();
void verificaerro9 ();
void jogo ();
void tela_iniciu();
void escolha_de_fase ();
void fase1 ();
void fase4 ();
void fase3 ();
void fase2 ();
void falha ();
void delay();
#INT_TIMER0
void TIMER0_isr(void) 
{
   set_timer0(get_timer0() + 131);  // Ajuste do temporizador para 1ms
   
   contador_ms++;  // Incrementa o contador de milissegundos
   
   if (contador_ms >= V_INTERVALO_INCREMENTO) {  // Se atingir o intervalo de 1 segundo
      contador_ms = 0;  // Reseta o contador de milissegundos
      
      para_3=0;
      
      contador_tela_inicial++;
      
      if (inicio){
          inicio--;
      }

      if (fase && comeca){
         contador++;
         verificaerro9 ();
         verificaerro0 ();
         unidade_ativo = 0;
         dezena_ativo = 0;
         centena_ativo = 0;
         milhar_ativo = 0;
         
      }
      
      if (contador_tela_inicial > 5) {  // Se o contador atingir 0, reseta para 9999
         contador_tela_inicial = 0;
      }
   }
}
void delay(int milliseconds) {
    volatile int i;
    // O n�mero de itera��es neste loop define a dura��o do delay
    for(i = 0; i < milliseconds; i++) {
        
    }
}
void update_display();

void verificabotao(){
      if (!input(S4) && !unidade_ativode) {
         unidade_ativo = 1;
         unidade_ativode = 1;
      }

      if (!input(S3) && !dezena_ativode) {
         dezena_ativo = 1;
         dezena_ativode = 1;
      } 
      if (!input(S2) && !centena_ativode) {
         centena_ativo = 1;
         centena_ativode = 1;
      } 
      if (!input(S1) && !milhar_ativode) {
         milhar_ativo = 1;
         milhar_ativode = 1;
      }
      
      if (unidade_ativode){
         unidade_ativodecont--;
         if (!unidade_ativodecont){
         unidade_ativodecont= contde;
         unidade_ativode=0;
         }
      }
      if (dezena_ativode){
         dezena_ativodecont--;
         if (!dezena_ativodecont){
         dezena_ativodecont= contde;
         dezena_ativode=0;
         }
      }
      if (centena_ativode){
         centena_ativodecont--;
         if (!centena_ativodecont){
         centena_ativodecont= contde;
         centena_ativode=0;
         }
      }
      if (milhar_ativode){
         milhar_ativodecont--;
         if (!milhar_ativodecont){
         milhar_ativodecont= contde;
         milhar_ativode=0;
         }
      }

}

void verificaerro9 (){
 // Se a unidade est� ativa e seu valor � diferente de zero, reseta o contador
         if (unidade_ativo && unidade != 0) {
         fase = 0;     
         }

         // Se a dezena est� ativa e seu valor � diferente de zero, reseta o contador
         if (dezena_ativo && dezena != 0) {
         fase = 0;
         }

         // Se a centena est� ativa e seu valor � diferente de zero, reseta o contador
         if (centena_ativo && centena != 0) {
         fase = 0;
         }

         // Se o milhar est� ativo e seu valor � diferente de zero, reseta o contador
         if (milhar_ativo && milhar != 0) {
         fase = 0;
         }
      
}

void verificaerro0 (){
 // Se a unidade est� ativa e seu valor � diferente de zero, reseta o contador
         if (!unidade_ativo && unidade == 0) {
         fase = 0;
         }

         // Se a dezena est� ativa e seu valor � diferente de zero, reseta o contador
         if (!dezena_ativo && dezena == 0) {
         fase = 0;
         }

         // Se a centena est� ativa e seu valor � diferente de zero, reseta o contador
         if (!centena_ativo && centena == 0) {
         fase = 0;
         }

         // Se o milhar est� ativo e seu valor � diferente de zero, reseta o contador
         if (!milhar_ativo && milhar == 0) {
         fase = 0;
         }
      

}

void main()
{
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8 | RTCC_8_BIT); // Configura��o do timer para interrup��o a cada 1ms
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);  // Habilita interrup��es globais
   
   output_d(0);  // Limpa os displays

   fase = 0;
   while (TRUE)
   {
      
      if (fase==0)
      {
      V_INTERVALO_INCREMENTO=V_INTERVALO_INCREMENTO/( 3 * (pasou_fase_1+pasou_fase_2+pasou_fase_3+pasou_fase_4)+5) ;
      tela_iniciu();
      V_INTERVALO_INCREMENTO=V_INTERVALO_INCREMENTO*( 3 * (pasou_fase_1+pasou_fase_2+pasou_fase_3+pasou_fase_4)+5);
      escolha_de_fase();

      if (fase==1)
      {
        contador =0;
        comeca=1;
        velocidade = V_INTERVALO_INCREMENTO;
        para_1=0;
        para_2=0;
        while (fase){
        fase1();
        }
        comeca=0;
        
        if (contador < finalfase){
        falha ();
        contador=0;
        }
        
        if (contador >= finalfase+4)
        pasou_fase_1=1;

        V_INTERVALO_INCREMENTO = velocidade;
        fase=0;
        
      }
      if (fase==2)
      {
        contador =0;
        comeca=1;
        velocidade = V_INTERVALO_INCREMENTO;
        para_1=0;
        para_2=0;
        while (fase){
        fase2();
        }
        comeca=0;
        
        if (contador < finalfase){
        falha ();
        contador=0;
        }
        if (contador >= finalfase+4)
        pasou_fase_2=1;
        
        V_INTERVALO_INCREMENTO = velocidade;
        fase=0;
      }
      if (fase==3)
      {
        contador =0;
        comeca=1;
        velocidade = V_INTERVALO_INCREMENTO;
        para_1=0;
        para_2=0;
        while (fase){
        fase3();
        }
        comeca=0;
        
        if (contador < finalfase){
        falha ();
        contador=0;
        }
        if (contador >= finalfase+4)
        pasou_fase_3=1;
        
        V_INTERVALO_INCREMENTO = velocidade;
        fase=0;
      
      }
      if (fase==4)
      {
        contador =0;
        comeca=1;
        velocidade = V_INTERVALO_INCREMENTO;
        para_1=0;
        para_2=0;
        V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*0.60 ;
        while (fase){
        fase4();
        }
        comeca=0;
        
        if (contador < finalfase){
        falha ();
        contador=0;
        }
        if (contador >= finalfase+4)
        pasou_fase_4=1;
        
        V_INTERVALO_INCREMENTO = velocidade;
        fase=0;
      }
      }
      contador=0;
      //jogo();
     
      
   }
}


void fase1 (){
      
      if (contador <47){
      unidade = u1 [contador] ;    // Unidades
      dezena = d1 [contador];     // Dezenas
      centena = c1 [contador];   // Centenas
      milhar = m1 [contador]; 
      }else{
      unidade = u1 [contador-47] ;    // Unidades
      dezena = d1 [contador-47];     // Dezenas
      centena = c1 [contador-47];   // Centenas
      milhar = m1 [contador-47];    
      }  
      
      update_display();  // Atualiza o display
      verificabotao();
      
      if (contador==50 && !para_1){
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*0.85 ;
      para_1=1;
      }
      
      
      if (contador==75 &&  !para_2){
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*0.85 ;
      para_2=1;
      }
      
      if (contador == finalfase+5)
      fase=0;
      
}

void fase2 (){
      if (contador <33){
      unidade = u2 [contador] ;    // Unidades
      dezena = d2 [contador];     // Dezenas
      centena = c2 [contador];   // Centenas
      milhar = m2 [contador]; 
      }else{
      unidade = u2 [contador-33] ;    // Unidades
      dezena = d2 [contador-33];     // Dezenas
      centena = c2 [contador-33];   // Centenas
      milhar = m2 [contador-33];    
      }  
      
          
      
      
      update_display();  // Atualiza o display
      verificabotao();
      
      if (contador==12 && !para_1){
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*0.90 ;
      para_1=1;
      }
      
      
      if (contador==24 &&  !para_2){
      V_INTERVALO_INCREMENTO = velocidade ;
      para_2=1;
      para_1=0;
      }
      
      if (contador==48 &&  !para_1){
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*0.80 ;
      para_2=0;
      para_1=1;
      }
      
      if (contador==72 &&  !para_2){
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*0.90 ;
      para_2=1;
      para_1=0;
      }
      
      if (contador==96 &&  !para_1){
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*0.90 ;
      para_1=1;
      }

      if (contador == finalfase+5)
      fase=0;
}

void fase3 (){
    
      unidade = u3 [contador] ;    // Unidades
      dezena = d3 [contador];     // Dezenas
      centena = c3 [contador];   // Centenas
      milhar = m3 [contador];   // Milhares             
      
      update_display();  // Atualiza o display
      verificabotao();
      
      if ((contador+1) % 3 == 0 && !para_1 && contador <30 ){
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*0.94 ;
      para_1=1;
      para_2=0;
      } 
      
      if ((contador+1)%4 == 0 && !para_2 && (contador+1)%12 ){
      para_1=0;
      para_2=1;
      }
      
      if (contador == finalfase+5)
      fase=0;
}

void fase4 (){
      
      if (contador <50){
      unidade = u4 [contador] ;    // Unidades
      dezena = d4 [contador];     // Dezenas
      centena = c4 [contador];   // Centenas
      milhar = m4 [contador]; 
      }else{
      unidade = u4 [contador-50] ;    // Unidades
      dezena = d4 [contador-50];     // Dezenas
      centena = c4 [contador-50];   // Centenas
      milhar = m4 [contador-50];    
      }
            
      update_display();  // Atualiza o display
      verificabotao();  
      
      if (contador == finalfase+5)
      fase=0;
      
}


void escolha_de_fase (){
      
       if (!input(S4)) {
            fase = 4;
       }

       if (!input(S3)) {
            fase = 3;
       } 
       if (!input(S2)) {
            fase = 2;
       } 
       if (!input(S1)) {
            fase = 1;
      
      }
      if (fase){
         
      output_low(DM);
      output_low(DD);
      output_low(DC);
      output_low(DU);
      inicio=3;
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO*2 ;
      output_high(DU);
      
      while (inicio > 0){
           unidade = inicio;
           dezena = 12;
           centena = 12;           // Unidades
           milhar = inicio ;
           update_display();
           delay(30);
          
      }
      V_INTERVALO_INCREMENTO = V_INTERVALO_INCREMENTO/2 ;
      }
}

void falha (){


      inicio=7;

      unidade = 12 ;
      if ((contador % 10 )){
      dezena = -(contador % 10 )+10;
      centena = -((contador / 10) % 10)+9;
      }else{
      dezena=0;
      centena = -((contador / 10) % 10)+10;
      }
                // Unidades
      milhar =12 ;
      
      while (inicio){
         update_display();
         
         delay(15);
      }
}




void tela_iniciu(){
   
   if (contador_tela_inicial== 1 || contador_tela_inicial==2 ) {
      
         output_low(DM);
         output_low(DU);
      
         if (vez_contador_tela_inicial){
         output_low(DC);
         output_high(DD);
         if (!pasou_fase_3){
         output_d(listadisplay3[contador_tela_inicial]);   
         }else {
         output_d(listadisplay3[contador_tela_inicial+6]);
         }

         vez_contador_tela_inicial=0;
         }  else {
         output_low(DD);
         output_high(DC);
         
         if (!pasou_fase_2){
         output_d(listadisplay2[contador_tela_inicial]);   
         }else {
         output_d(listadisplay2[contador_tela_inicial+6]);
         }
      
         vez_contador_tela_inicial=1;
           }    
  
      } else   {
         output_low(DD);
         output_low(DC);
      
         if (vez_contador_tela_inicial){
         output_low(DM);
         output_high(DU);
         
         if (!pasou_fase_4){
         output_d(listadisplay4[contador_tela_inicial]);   
         }else {
         output_d(listadisplay4[contador_tela_inicial+6]);
         }
      
         vez_contador_tela_inicial=0;
         }  else  {
         output_low(DU);
         output_high(DM);
         
         if (!pasou_fase_1){
         output_d(listadisplay1[contador_tela_inicial]);   
         }else {
         output_d(listadisplay1[contador_tela_inicial+6]);
         }
         
      
         vez_contador_tela_inicial=1;
         }
      }
      delay(35);
    
      
}

void update_display() {
   delay(25);
   if (input_state(DU)) {
      output_low(DU);
      output_high(DD);
      output_d(display_numbers[dezena]);
   } else if (input_state(DD)) {
      output_low(DD);
      output_high(DC);
      output_d(display_numbers[centena]);
   } else if (input_state(DC)) {
      output_low(DC);
      output_high(DM);
      output_d(display_numbers[milhar]);
   } else {
      output_low(DM);
      output_high(DU);
      output_d(display_numbers[unidade]);
   }
}

