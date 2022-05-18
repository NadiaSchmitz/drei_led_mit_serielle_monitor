int led_red = 5;
int led_green = 10;
int led_white = 3;
int leds[3] = {led_white, led_red, led_green};
String gelesen = "";

void setup() {
  pinMode(led_red,OUTPUT);
  pinMode(led_green,OUTPUT);
  pinMode(led_white, OUTPUT);
  Serial.begin(9600);
  delay(2000);
  Serial.print("Bitte gewünschte Effekt eingeben");
  Serial.println();
}

void loop() {
  if (Serial.available() > 0) {
    gelesen = "";
    while (Serial.available() > 0) {
      gelesen = Serial.readStringUntil('\n');
      delay(2);
      }
      Serial.print(gelesen);
      Serial.println();
    }
    // Rotes Led einschalten
  if (gelesen == "rot") {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_white, LOW);
    // Grünes Led einschalten
  } else if (gelesen == "grün") {
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_white, LOW);
    // Whites Led einschalten
  } else if (gelesen == "white") {
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_white, HIGH);
    // Alle Led einschalten
  } else if (gelesen == "alle") {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_white, HIGH);
    // Alle Led außer weisen einschalten
  } else if (gelesen == "nicht weiß") {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_white, LOW);
    // Welle
  } else if (gelesen == "welle") {
      for (int i = 0; i < 3; i++) {
        digitalWrite(leds[i], HIGH);
        delay(100);
        digitalWrite(leds[i], LOW);
      }
     // Stufeweise alle Led einschalten
  } else if (gelesen == "pulse") {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_white, HIGH);
    delay(30);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_white, LOW);
    delay(30);
    // Jedes Led nacheinander drei Mal blinken
  } else if (gelesen == "drei") {
    digitalWrite(led_white, HIGH);
    delay(100);
    digitalWrite(led_white, LOW);
    delay(100);
    digitalWrite(led_white, HIGH);
    delay(100);
    digitalWrite(led_white, LOW);
    delay(100);
    digitalWrite(led_red, HIGH);
    delay(100);
    digitalWrite(led_red, LOW);
    delay(100);
    digitalWrite(led_red, HIGH);
    delay(100);
    digitalWrite(led_red, LOW);
    delay(100);
    digitalWrite(led_green, HIGH);
    delay(100);
    digitalWrite(led_green, LOW);
    delay(100);
    digitalWrite(led_green, HIGH);
    delay(100);
    digitalWrite(led_green, LOW);
    // Zufälliges Led einschalten
  } else if (gelesen == "zufall") {
    int gewinn = random(0,3);
    digitalWrite(leds[gewinn], HIGH);
    delay(1000);
    digitalWrite(led_white, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    }
  }
