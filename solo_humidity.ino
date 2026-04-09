#define UMIDITY 34

// max sensor value: 4095
const int dry_val = 3500;
const int wet_val = 990;

typedef struct {
  int h;
  int p;
} soloState;

void setup() {
  Serial.begin(115200);
  Serial.println(wet_val);
  pinMode(UMIDITY, INPUT);
}

soloState getSoloHumidty() {
  int h = analogRead(UMIDITY);

  int p = map(h, dry_val, wet_val, 0, 100);
  // Constrain the value to given numbers
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
  delay(1000);
}
