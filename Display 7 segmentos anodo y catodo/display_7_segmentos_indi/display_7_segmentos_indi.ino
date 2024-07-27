const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {

  /*Número 0*/
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 1);
  /*Fin 0*/

  delay(2000);

  /*Número 1*/
  digitalWrite(A, 1);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
  /*Fin1*/

  delay(2000);

  /*Número 2*/
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 1);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 1);
  digitalWrite(G, 0);
  /*Fin2*/

  delay(2000);

  /*Número 3*/
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 0);
  /*Fin3*/

  delay(2000);

  /*Número 4*/
  digitalWrite(A, 1);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
  /*Fin4*/

  delay(2000);

  /*Número 5*/
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
  /*Fin5*/

  delay(2000);

  /*Número 6*/
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
  /*Fin6*/

  delay(2000);

  /*Número 7*/
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 0);
  /*Fin7*/

  delay(2000);

  /*Número 8*/
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
  /*Fin8*/

  delay(2000);

  /*Número 9*/
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
  /*Fin9*/

  delay(2000);

}
