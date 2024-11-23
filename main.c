#include <main.h>

// Trabalho final da disciplina Microcontroladores e Microprocessadores
// - Diogo Nunes
// - Rafael �vora
// - Pedro Franco
// - Vinicius Barbosa

int16 intervalo_inc = 1000;  // Intervalo de incremento em 1 segundo (inicialmente 1000ms)
int16 contador = 0;  // Contador come�a em 9999, agora um int16 para suportar at� 9999
int16 unidade;
int16 dezena;
int16 centena;
int16 milhar;

int16 fase = 0;
int16 inicio;

int16 duracao_da_fase = 50;

int1 unidade_ativo = 0, dezena_ativo = 0, centena_ativo = 0, milhar_ativo = 0;
int1 unidade_ativode = 0, dezena_ativode = 0, centena_ativode = 0, milhar_ativode = 0;
int16 contde = 200;
int1 comeca=0;
int1 espera=0;

int16 unidade_ativodecont = contde, dezena_ativodecont = contde, centena_ativodecont = contde, milhar_ativodecont = contde;

int16 contador_tela_inicial = 0;

int16 vez_contador_tela_inicial = 0;

const int8 listadisplay4[] = {0x08,0x00,0x00,0x01,0x02,0x04};
const int8 listadisplay3[] = {0x00,0x08,0x01,0x00,0x00,0x00};
const int8 listadisplay2[] = {0x00,0x01,0x08,0x00,0x00,0x00};
const int8 listadisplay1[] = {0x01,0x00,0x00,0x08,0x10,0x20};

const int8 u1 [] = {4,3,2,1,0};
const int8 d1 [] = {3,2,1,0,0};
const int8 c1 [] = {3,2,1,0,0};
const int8 m1 [] = {2,1,0,1,0};

const int8 display_numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

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

#INT_TIMER0
void TIMER0_isr(void) 
{
   set_timer0(get_timer0() + 131);  // Ajuste do temporizador para 1ms
   
   contador_ms++;  // Incrementa o contador de milissegundos
   
   if (contador_ms >= intervalo_inc) {  // Se atingir o intervalo de 1 segundo
      contador_ms = 0;  // Reseta o contador de milissegundos
      
      contador_tela_inicial++;
      
      if (contador_tela_inicial >3)
         espera = 1;
         
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
      if (!unidade_ativodecont) {
         unidade_ativodecont= contde;
         unidade_ativode=0;
      }
   }
   
   if (dezena_ativode){
      dezena_ativodecont--;
      if (!dezena_ativodecont) {
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
   if (unidade_ativo && unidade) {
      fase = 0;     
   }

   // Se a dezena est� ativa e seu valor � diferente de zero, reseta o contador
   if (dezena_ativo && dezena) {
      fase = 0;
   }

   // Se a centena est� ativa e seu valor � diferente de zero, reseta o contador
   if (centena_ativo && centena) {
    fase = 0;
   }

   // Se o milhar est� ativo e seu valor � diferente de zero, reseta o contador
   if (milhar_ativo && milhar) {
      fase = 0;
   }
      
}

void verificaerro0 (){
   // Se a unidade est� ativa e seu valor � diferente de zero, reseta o contador
   if (!unidade_ativo && !unidade) {
      fase = 0;
   }
   
   // Se a dezena est� ativa e seu valor � diferente de zero, reseta o contador
   if (!dezena_ativo && !dezena) {
      fase = 0;
   }
   
   // Se a centena est� ativa e seu valor � diferente de zero, reseta o contador
   if (!centena_ativo && !centena) {
      fase = 0;
   }
   
   // Se o milhar est� ativo e seu valor � diferente de zero, reseta o contador
   if (!milhar_ativo && !milhar) {
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
         tela_iniciu();
         escolha_de_fase();

      if (fase==1)
      {
        contador =0;
        comeca=1;
         while (fase) {
        fase1();
        }
        comeca=0;
        falha();
      }
      if (fase==2)
      {
        contador =0;
        comeca=1;
        while (fase) {
         fase2();  
        }
        comeca=0;
        falha();
      }
      if (fase==3)
      {
        contador =0;
        comeca=1;
        while (fase) {
         fase3();
        }
        comeca=0;
        falha();
      }
      if (fase==4)
      {
        contador =0;
        comeca=1;
        while (fase) {
         fase4();
        }
        comeca=0;
        falha ();
      }
      }

   }
}


void fase1 (){
   unidade = u1 [contador] ;    // Unidades
   dezena = d1 [contador];     // Dezenas
   centena = c1 [contador];   // Centenas
   milhar = m1 [contador];   // Milhares
       
   update_display();  // Atualiza o display
   
   verificabotao();
}

void fase2 (){
   unidade = u1 [contador] ;    // Unidades
   dezena = d1 [contador];     // Dezenas
   centena = c1 [contador];   // Centenas
   milhar = m1 [contador];   // Milhares
       
   update_display();  // Atualiza o display
   
   verificabotao();
}

void fase3 (){
   unidade = u1 [contador] ;    // Unidades
   dezena = d1 [contador];     // Dezenas
   centena = c1 [contador];   // Centenas
   milhar = m1 [contador];   // Milhares
       
   update_display();  // Atualiza o display
   
   verificabotao(); 
}

void fase4 (){
   unidade = u1 [contador] ;    // Unidades
   dezena = d1 [contador];     // Dezenas
   centena = c1 [contador];   // Centenas
   milhar = m1 [contador];   // Milhares
       
   
   
   update_display();  // Atualiza o display
   
   verificabotao();  
}


void escolha_de_fase (){
      if (espera){
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
      }
      if (fase){
      output_low(DM);
      output_low(DD);
      output_low(DC);
      output_low(DU);
      inicio=4;
      intervalo_inc =intervalo_inc * 2 ;
      output_high(DU);
      
      while (inicio){
          output_high(DU);
          output_d(display_numbers[inicio-1]);
          output_low(DU);
      }
      intervalo_inc = intervalo_inc / 2 ;
      }
}

void falha (){
   output_low(DM);
   output_low(DD);
   output_low(DC);
   output_low(DU);
   inicio=7;
   output_high(DU);
   
   while (inicio){
    output_high(DU);
    if (inicio % 3 == 0){
         output_d(0b111111001);
    }else if((inicio % 3 == 1)) {
         output_d(0b111110110);
    }else{
         output_d(0x3F);   
    }
    output_low(DU);         
   }
}


void tela_iniciu(){
   
   if (contador_tela_inicial== 1 || contador_tela_inicial==2 ) {
      
      output_low(DM);
      output_low(DU);
   
      if (vez_contador_tela_inicial){
      output_low(DC);
      output_high(DD);
      output_d(listadisplay3[contador_tela_inicial]);
   
      vez_contador_tela_inicial=0;
      }  else {
      output_low(DD);
      output_high(DC);
      output_d(listadisplay2[contador_tela_inicial]);
   
      vez_contador_tela_inicial=1;
        }    
   
   } else   {
      output_low(DD);
      output_low(DC);
   
      if (vez_contador_tela_inicial){
         output_low(DM);
         output_high(DU);
         output_d(listadisplay4[contador_tela_inicial]);
      
         vez_contador_tela_inicial=0;
      }  else  {
         output_low(DU);
         output_high(DM);
         output_d(listadisplay1[contador_tela_inicial]);
      
         vez_contador_tela_inicial=1;
      }
   }
}



void update_display() {

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
