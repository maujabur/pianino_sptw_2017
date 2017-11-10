/*
   "pianino"  por MauMaker

   www.maumaker.com

   contém código do exemplo toneMelody que acompanha a IDE do Arduinos

   Atribuição-NãoComercial-CompartilhaIgual 4.0 Internacional (CC BY-NC-SA 4.0)

   https://creativecommons.org/licenses/by-nc-sa/4.0/deed.pt_BR

*/

#include "pitches.h" // nomes das notas

int FALANTE = 13;// Saída de som

int APERTADO = LOW;
// para clipes e botões, use LOW
// para pregador, use HIGH

void setup() {
  pinMode(2, INPUT_PULLUP); // define como entrada para tecla
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
} // fim do setup()

///////////////////////////////////////////////////////////////
void loop() {
le_tecla(2,NOTE_C5); // chama a função que le a tecla
le_tecla(3,NOTE_D5);
le_tecla(4,NOTE_E5);
le_tecla(5,NOTE_F5);
le_tecla(6,NOTE_G5);
le_tecla(7,NOTE_A5);
le_tecla(8,NOTE_B5);
le_tecla(9,NOTE_C6);
le_tecla(10,NOTE_D6);
le_tecla(11,NOTE_E6);
le_tecla(12,NOTE_F6);
} // fim do loop

///////////////////////////////////////////////////////////////
// fizemos uma função para ler qualquer tecla
// é quase igual ao loop do programa "uma tecla"
///////////////////////////////////////////////////////////////

void le_tecla(int tecla, int nota) { 
  
  if (digitalRead(tecla) == APERTADO) { // se a tecla estiver apertada
    
    tone(FALANTE, nota); // toca a nota correspondente
    
    while (digitalRead(tecla) == APERTADO) {
      delay(20); // faz um tempo pra ler de novo
      // (evita ruidos do contato)
    } // fim do while()

    noTone(FALANTE); // desliga o som depois que a tecla for solta
  
  } // fim do if
} // fim do le_tecla

