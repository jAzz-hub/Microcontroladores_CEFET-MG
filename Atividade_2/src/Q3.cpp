
void ascender_digito_9()
{ 
  digitalWrite(0, LOW);    // Ativa a;
  digitalWrite(1, LOW);    // Ativa b;
  digitalWrite(2, LOW);    // Ativa c;
  digitalWrite(3, LOW);    // Ativa d;
  digitalWrite(5, LOW);    // Ativa f;
  digitalWrite(6, LOW);    // Ativa g;
}


// int pino_decremental = 7;
// int pino_incremental = 8;

void setup()
{

  // Configurando pinos para conseguir realizar entradas e saídas de sinais

    // Pinos de entrada
  // pinMode(pino_decremental,INPUT);
  // pinMode(pino_incremental,INPUT);
    // Pinos de saída
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

    // Apagando todos os segmentos do display
  digitalWrite(0, HIGH);    // Ativa a;
  digitalWrite(1, HIGH);    // Ativa b;
  digitalWrite(2, HIGH);    // Ativa c;
  digitalWrite(3, HIGH);    // Ativa d;
  digitalWrite(4, HIGH);    // Ativa d;
  digitalWrite(5, HIGH);    // Ativa f;
  digitalWrite(6, HIGH);    // Ativa g;
}

void loop() {
  // put your main code here, to run repeatedly:

  // bool estado_incrementar = digitalRead(pino_incremental);
  // bool estado_decrementar = digitalRead(pino_decremental);


  ascender_digito_9();
}
