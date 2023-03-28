// Vyankatesh Ashtekar 
// Blink LED with required frequency and duty cycle
// One can blink multiple LEDs together. Make new functions by renaming the variable "lastRisingEdgeTime2" to "lastRisingEdgeTimeN" for N LEDs
// Non-blocking code

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  blinkLED1wFreq(1, 50, LED_BUILTIN);
}


void blinkLED1wFreq(float freq, float dutyCyclePercent, int pinNo) {

  if (freq < 1e-6)
    freq = 0.1;

  float timePeriod = (1 / freq) * 1000;  // convert to milliseconds
  float onPeriod = dutyCyclePercent * timePeriod / 100;

  static unsigned long lastRisingEdgeTime;

  if (millis() - lastRisingEdgeTime >= onPeriod) {
    digitalWrite(pinNo, 0);
  }

  if (millis() - lastRisingEdgeTime >= timePeriod) {
    digitalWrite(pinNo, 1);
    lastRisingEdgeTime += timePeriod;
  }
}

void blinkLED2wFreq(float freq, float dutyCyclePercent, int pinNo) {

  if (freq < 1e-6)
    freq = 0.1;

  float timePeriod = (1 / freq) * 1000;  // convert to milliseconds
  float onPeriod = dutyCyclePercent * timePeriod / 100;

  static unsigned long lastRisingEdgeTime2;

  if (millis() - lastRisingEdgeTime2 >= onPeriod) {
    digitalWrite(pinNo, 0);
  }

  if (millis() - lastRisingEdgeTime2 >= timePeriod) {
    digitalWrite(pinNo, 1);
    lastRisingEdgeTime2 += timePeriod;
  }
}
