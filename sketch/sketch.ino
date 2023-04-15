#include <SPI.h>
#include <SD.h>
String tolog = " ";
String toedit = "datalog1.csv";
int logoptions = 2;

void setup() {
  // put your setup code here, to run once:
  SD.begin();
  Serial.begin(9600);
  if (!SD.begin(10)) {
    Serial.println("Le stockage ne peut être initialisé");
    while (1);
  }
  Serial.println("Le stockage est initialisé");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    tolog = Serial.readString();
    Serial.print(tolog);
    File datalog = SD.open(toedit, FILE_WRITE);
    datalog.print(tolog);
    datalog.close();
  }

}
