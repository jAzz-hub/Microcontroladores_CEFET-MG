// Configurações dos segmentos (ânodo comum)
const int segmentPins[] = {0, 1, 2, 3, 4, 5, 6}; // a, b, c, d, e, f, g

int num = 0;
const int pino_decremental = 7;
const int pino_incremental = 8;
bool ultimo_estado_decremental = HIGH;
bool ultimo_estado_incremental = HIGH;

// Função para apagar todos os segmentos
void apagar_todos_os_segmentos() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], HIGH);
  }
}

// Funções para acender cada dígito (ajustadas para ânodo comum)
void ascender_digito_0() {
  apagar_todos_os_segmentos();
  digitalWrite(0, LOW); // a
  digitalWrite(1, LOW); // b
  digitalWrite(2, LOW); // c
  digitalWrite(3, LOW); // d
  digitalWrite(4, LOW); // e
  digitalWrite(5, LOW); // f
}

void ascender_digito_1() {
  apagar_todos_os_segmentos();
  digitalWrite(1, LOW); // b
  digitalWrite(2, LOW); // c
}

void ascender_digito_2() {
  apagar_todos_os_segmentos();
  digitalWrite(0, LOW); // a
  digitalWrite(1, LOW); // b
  digitalWrite(3, LOW); // d
  digitalWrite(4, LOW); // e
  digitalWrite(6, LOW); // g
}

void ascender_digito_3() {
  apagar_todos_os_segmentos();
  digitalWrite(0, LOW); // a
  digitalWrite(1, LOW); // b
  digitalWrite(2, LOW); // c
  digitalWrite(3, LOW); // d
  digitalWrite(6, LOW); // g
}

void ascender_digito_4() {
  apagar_todos_os_segmentos();
  digitalWrite(1, LOW); // b
  digitalWrite(2, LOW); // c
  digitalWrite(5, LOW); // f
  digitalWrite(6, LOW); // g
}

void ascender_digito_5() {
  apagar_todos_os_segmentos();
  digitalWrite(0, LOW); // a
  digitalWrite(2, LOW); // c
  digitalWrite(3, LOW); // d
  digitalWrite(5, LOW); // f
  digitalWrite(6, LOW); // g
}

void ascender_digito_6() {
  apagar_todos_os_segmentos();
  digitalWrite(0, LOW); // a
  digitalWrite(2, LOW); // c
  digitalWrite(3, LOW); // d
  digitalWrite(4, LOW); // e
  digitalWrite(5, LOW); // f
  digitalWrite(6, LOW); // g
}

void ascender_digito_7() {
  apagar_todos_os_segmentos();
  digitalWrite(0, LOW); // a
  digitalWrite(1, LOW); // b
  digitalWrite(2, LOW); // c
}

void ascender_digito_8() {
  apagar_todos_os_segmentos();
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
}

void ascender_digito_9() {
  apagar_todos_os_segmentos();
  digitalWrite(0, LOW); // a
  digitalWrite(1, LOW); // b
  digitalWrite(2, LOW); // c
  digitalWrite(3, LOW); // d
  digitalWrite(5, LOW); // f
  digitalWrite(6, LOW); // g
}

void ascender_digito(int num) {
  switch (num) {
    case 0: ascender_digito_0(); break;
    case 1: ascender_digito_1(); break;
    case 2: ascender_digito_2(); break;
    case 3: ascender_digito_3(); break;
    case 4: ascender_digito_4(); break;
    case 5: ascender_digito_5(); break;
    case 6: ascender_digito_6(); break;
    case 7: ascender_digito_7(); break;
    case 8: ascender_digito_8(); break;
    case 9: ascender_digito_9(); break;
    default: apagar_todos_os_segmentos(); // Número inválido
  }
}

// Verifica borda de subida para incremento
bool borda_de_subida_incremento(bool estado_atual, bool ultimo_estado) {
  return (estado_atual == LOW && ultimo_estado == HIGH); // Usando pull-up
}

// Verifica borda de subida para decremento
bool borda_de_subida_decremento(bool estado_atual, bool ultimo_estado) {
  return (estado_atual == LOW && ultimo_estado == HIGH); // Usando pull-up
}

void setup() {
  // Configura pinos do display como saída
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], HIGH); // Inicia apagado (ânodo comum)
  }

  // Configura switches com pull-up interno
  pinMode(pino_incremental, INPUT_PULLUP);
  pinMode(pino_decremental, INPUT_PULLUP);
}

void loop() {
  bool estado_incrementar = digitalRead(pino_incremental);
  bool estado_decrementar = digitalRead(pino_decremental);

  // Verifica borda de subida para incremento
  if (borda_de_subida_incremento(estado_incrementar, ultimo_estado_incremental)) {
    if (num < 9) num++;
    delay(50); // Debounce simples
  }

  // Verifica borda de subida para decremento
  if (borda_de_subida_decremento(estado_decrementar, ultimo_estado_decremental)) {
    if (num > 0) num--;
    delay(50); // Debounce simples
  }

  // Atualiza estados anteriores
  ultimo_estado_incremental = estado_incrementar;
  ultimo_estado_decremental = estado_decrementar;

  // Atualiza o display
  ascender_digito(num);
}
