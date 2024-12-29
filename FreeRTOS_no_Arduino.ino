#include <Arduino_FreeRTOS.h>

int intervalo1Pisca = 1000;
int intervalo2Pisca = 1000;

void setup() {
  // put your setup code here, to run once:
  xTaskCreate(tarefaLedVerm, "tarefaLedVerm", 128, NULL, 1, NULL);
  xTaskCreate(tarefaLedAmar, "tarefaLedAmar", 128, NULL, 1, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void tarefaLedVerm(void *pvParametros) {
  pinMode(11, OUTPUT);

  while(true) {
    digitalWrite(11, HIGH);
    delay(intervalo1Pisca);
    digitalWrite(11, LOW);
    delay(intervalo1Pisca);
  }
}

void tarefaLedAmar(void *pvParametros) {
  pinMode(12, OUTPUT);

  while(true) {
    digitalWrite(12, HIGH);
    delay(intervalo2Pisca);
    digitalWrite(12, LOW);
    delay(intervalo2Pisca);
  }
}
