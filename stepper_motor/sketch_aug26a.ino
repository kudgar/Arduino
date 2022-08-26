// Контакты   Bl Pi Ye  Or
int pins[] = {8, 9, 10, 11}; //Задаем пины по порядку

int phases = 8; // для шагового режима установить 4

// Для шагового режима
//bool motorPhases[4][4] = { // [phase][pin]
//// -------- pins ----------
//// Winding    A  B  A  B
//// Motor Pin  1  2  3  4
//// Color      Bl Pi Ye Or
//  {           1, 1, 0, 0},
//  {           0, 1, 1, 0},
//  {           0, 0, 1, 1},
//  {           1, 0, 0, 1}
//};

// Для полушагового режима
bool motorPhases[8][4] = { // [phase][pin]
  // -------- pins ----------
  // Winding    A  B  A  B
  // Motor Pin  1  2  3  4
  // Color      Bl Pi Ye Or
  {             1, 1, 0, 0},
  {             0, 1, 0, 0},
  {             0, 1, 1, 0},
  {             0, 0, 1, 0},
  {             0, 0, 1, 1},
  {             0, 0, 0, 1},
  {             1, 0, 0, 1},
  {             1, 0, 0, 0}
};

void setup() {
  for (int i = 0; i < 4; i++) pinMode(pins[i], OUTPUT);
}

int phase = 0;
int _step = 1; // Если у шага поменять знак, на -1 - изменится направление вращения.

void loop() {
  phase += _step;
  if (phase > 7) phase = 0;
  if (phase < 0) phase = 7;

  for (int i = 0; i < 4; i++) {
    digitalWrite(pins[i], ((motorPhases[phase][i] == 1) ? HIGH : LOW));
  }
  // Пауза на вращение на один шаг/полушаг
  delay(2); // Для шагового режима установить в 3
}
