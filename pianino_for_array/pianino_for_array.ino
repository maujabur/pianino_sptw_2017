/*
   "pianino_for_array"  por MauMaker

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

// coleção de teclas e notas (array)
int quantidade = 11;
int tecla[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int nota[] = {
  NOTE_C5,
  NOTE_D5,
  NOTE_E5,
  NOTE_F5,
  NOTE_G5,
  NOTE_A5,
  NOTE_B5,
  NOTE_C6,
  NOTE_D6,
  NOTE_E6,
  NOTE_F6,
};

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
  
  for (int i = 0; i < quantidade; i = i + 1) {
    le_tecla(tecla[i], nota[i]); // chama a função que le a tecla
  } // fim do for
  
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

