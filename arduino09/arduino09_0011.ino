// Codigo Ejemplo
int lectura = 0;
int anterior = 0;
int distancia = 0;
int sendorPin = 7;

void setup()
{
  Serial.begin(9600);
  // Enviar Texto a la Consola Serial
  Serial.println("Iniciando");
}

void loop()
{
  // Tomar Lectura
  lectura = readUltrasonicDistance(sendorPin, sendorPin);
  // Calcular Distancia
  distancia = 0.01723 * lectura;
  if ( distancia != anterior ) {
    anterior = distancia;
 	// Enviar Lectura a la Consola Serial
 	Serial.print(distancia);
 	Serial.println("cm");
  }
  delay(1000); // Demora de 100ms
}

// Función para Recolectar Lectura
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  // Inicializar Sensor
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // Iniciar Sensor en Modo Lectura
  pinMode(echoPin, INPUT);
  // Retornar Lectura
  return pulseIn(echoPin, HIGH);
}
