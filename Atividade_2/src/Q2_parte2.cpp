
void pisca(int port)
{
  digitalWrite(port, HIGH);
  delay(200);
  digitalWrite(port, LOW);
  delay(200);
}

void do_nothing()
{
  // Nada
}

void Ascender_Vermelho()
{
  digitalWrite(8, HIGH);
}

void alterna_A_B(int vermelho, int verde)
{
  if (digitalRead(vermelho))
  {
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);
  }
  else if(digitalRead(verde))
  {
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, HIGH);
  }
  else
  {
    do_nothing();
  }
}

void QualTaAceso()
{

  if(digitalRead(4))
  {
    digitalWrite(8, HIGH);
    digitalWrite(12, LOW);
  }
  else if(digitalRead(2))//Apertando pino 2
  {
    alterna_A_B(8,12);  // 
  }
  else
    do_nothing();
}




void setup() {
  // put your setup code here, to run once:



  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);

}

void doNothing()
{

}



void loop() {

  bool verde = false;
  bool vermelho = false;

  if(digitalRead(4))
  {
    digitalWrite(8, HIGH);
    digitalWrite(12, LOW);
    delay(200);
  }

  if(digitalRead(2) && digitalRead(8) && !digitalRead(12))//Apertando pino 2
  {
    digitalWrite(12, HIGH);
    digitalWrite(8, LOW);
    delay(200);
  }

  if(digitalRead(2) && !digitalRead(8) && digitalRead(12))//Apertando pino 2
  {
    digitalWrite(8, HIGH);
    digitalWrite(12, LOW);
    delay(200);
  }

  else
  {
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
    delay(200);
  }
}


// 1º
// 2º