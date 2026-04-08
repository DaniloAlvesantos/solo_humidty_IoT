#define UMIDITY 34
const int dry_val = 4095;
const int wet_val = 1200;

typedef struct {
  int h;
  int p;
} soloState;

void setup() {
  Serial.begin(115200);
  pinMode(UMIDITY, INPUT);
}

soloState getSoloHumidty() {
  int h = analogRead(UMIDITY);

  int p = map(h, dry_val, wet_val, 0, 100);
  // Garantir que o valor não ultrapasse 0 ou 100
  p = constrain(p, 0, 100);
  
  soloState res;
  res.h = h;
  res.p = p;

  return res;
}

void loop() {
  soloState soil = getSoloHumidty();
  
  Serial.print("Raw: ");
  Serial.print(soil.h);
  Serial.print("| Percent: ");
  Serial.print(soil.p);
  Serial.println("%");
  delay(2000);
}
