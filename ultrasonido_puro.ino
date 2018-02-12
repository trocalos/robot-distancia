const int EchoPin = 11;
const int TriggerPin = 12;
const int LedPin = 3;

// Motores ***************************************
// Motor A
int ENA = 10;
int IN1 = 9;
int IN2 = 8;

// Motor B
int ENB = 5;
int IN3 = 7;
int IN4 = 6;
// ***************************************************
 
void setup() {
   Serial.begin(9600);
   pinMode(LedPin, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   digitalWrite(LedPin, LOW);

// Motores ***************************************
     // Declaramos todos los pines como salidas
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
   // *************************************************** 
}
 
void loop() {
   int cm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(cm);
 //  delay(1000);
// Lo que hace el robot ************************************

if (cm>=81){    //Más de 80 cm apagado
    
    digitalWrite(LedPin, LOW);
   Parar ();
      } 
   
    if (cm>=60&&cm<=80){    //Entre 60 y 80 cm
    Parar ();
    digitalWrite(LedPin, HIGH);
    delay(100);
    digitalWrite(LedPin, LOW);
    delay(100);             // Parpadea
      } 
    
    if (cm<=60&&cm>20){    //Entre 60 y 20 cm
    digitalWrite(LedPin, HIGH);
     Adelante ();
    } 
   if (cm<=19&&cm>15){    //Entre 19 y 15 cm esperamos a ver que pasa y lanzamos aviso
    
    digitalWrite(LedPin, LOW);
    Parar ();
 }
     if (cm<=14){    //Menos de 14 cm hay que huir
    digitalWrite(LedPin, HIGH);
     Atras ();
     delay (3000);
     Derecha ();
     delay (2000);
      Adelante ();
      delay (2000);
      Izquierda ();
      delay (4000);
      
    } 

    
 
}
 // Lo que hace el robot FIN **********************************************************

 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;

   
}


//  Definición de Motores ***************************************
void Adelante ()
{
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 255); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 255); //Velocidad motor B
}

void Atras ()
{
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 128);  //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 128); //Velocidad motor B
}

void Derecha ()
{
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 200); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 100); //Velocidad motor A
}

void Izquierda ()
{
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 50); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 150); //Velocidad motor A
}

void Parar ()
{
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 0); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 0); //Velocidad motor A
}

