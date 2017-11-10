/*
   "uma tecla"  por MauMaker

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

int tecla = 2; // pino onde está ligada a tecla
int nota = NOTE_C5; // nota musical da tecla

void setup() {
  pinMode(tecla, INPUT_PULLUP); // define como entrada para tecla
} // fim do setup()

void loop() {

  if (digitalRead(tecla) == APETADO) { // se a tecla estiver apertada

    tone(FALANTE, nota); // toca a nota correspondente

    while (digitalRead(tecla) == APERTADO) {
      ; // não faz nada, espera até que a tecla seja solta
    } // fim do while()

    noTone(FALANTE); // desliga o som depois que a tecla for solta

  } // fim do if
} // fim do loop
