
const int buttonPin = 2;  
const int led[] = {3, 4, 5, 6, 7, 8, 9};  

int contador = 0;  
bool buttonState = false;  
bool lastButtonState = false; 

void setup() {
  // Configura os LEDs como saída
  for (int i = 0; i < 7; i++) {
    pinMode(led[i], OUTPUT);
  }
  // Configura o pino do botão como entrada
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Lê o estado atual do botão
  buttonState = digitalRead(buttonPin);

  // Verifica se houve uma transição de pressionado para não pressionado
  if (buttonState == LOW && lastButtonState == HIGH) {
    contador++;  // Incrementa o contador
    if (contador > 9) {
      contador = 0;  // Volta para zero após 9
    }
    atualizarDisplay();  // Atualiza os LEDs com o novo valor do contador
  }

  // Atualiza o estado anterior do botão
  lastButtonState = buttonState;
}

void atualizarDisplay() {
  // Define os padrões de cada LED para os números de 0 a 9
  const bool digitos[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
  };

  // Atualiza cada LED de acordo com o valor do contador
  for (int i = 0; i < 7; i++) {
    digitalWrite(led[i], digitos[contador][i]);
  }
}
