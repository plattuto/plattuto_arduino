int sensor = 2;
int led = 12;
double tiempo = 0, val=0;
int valPul = 0;
double cont=0, pasos=0;

int pulsador = 7;

bool estado = false;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(pulsador, INPUT);
}

void loop() {

  val = digitalRead(sensor);
  valPul = digitalRead(pulsador);

  if(val==0){
    estado = true;
    pasos = pasos + 1;
  }

  if(pasos>1){
    estado = false;
  }

  while(estado){
    digitalWrite(led, HIGH);
    cont = cont+15.3;
    tiempo = cont/100;
    Serial.println(tiempo);
    break;
  }
  if(!estado){
    digitalWrite(led, LOW);
  }

  if(valPul == 0){
    cont=0;
    tiempo=0;
    estado=false;
    pasos=0;
  }

  delay(100);

}

