#define BuscarLed 1
#define BuscarNumero 2
int Led = 0;
int Dato = 0;
int EstadoBusqueda = 0;
void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  Serial.println("Hola");
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char Letra = Serial.read();
    if (Letra == 'L') {
      EstadoBusqueda = BuscarLed;
    }
    else if (Letra == 'D') {
      EstadoBusqueda = BuscarNumero;
    }
    else if (Letra == '.') {
      analogWrite(Led, Dato);
      Serial.println("El led es: ");
      Serial.println(Led);
      Serial.println("Dato: ");
      Serial.println(Dato);
      Led = 0;
      Dato = 0;
    }
    else if (Letra >= '0' && Letra <= '9') {
      int NumeroActual = int(Letra - '0');
      if (EstadoBusqueda == BuscarLed) {
        Led = Led * 10 + NumeroActual;
      }
      else if (EstadoBusqueda == BuscarNumero) {
        Dato = Dato * 10 + NumeroActual;
      }
    }
  }
}
