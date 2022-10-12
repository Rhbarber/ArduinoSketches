#include <SoftwareSerial.h> // Librería SoftwareSerial
SoftwareSerial BT(2,3);     // Definir pines RX y TX del modulo Bluetooth

void setup() {
  BT.begin(9600);           // Inicializar puerto de serie para Bluetooth (Modo AT 2)
  Serial.begin(9600);       // Inicializar puerto de serie
}

void loop() {
  if(BT.available())        // Condicional de si llega dato por el puerto BT se envia al monitor serial
  {
    Serial.write(BT.read());
  }

  if(Serial.available())    // Condicional de si llega dato por el monitor serial se envia al puerto BT
  {
    BT.write(Serial.read());
  }
}
