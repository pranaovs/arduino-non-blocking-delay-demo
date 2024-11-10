// Demo program to demonstrate the usage of non-blocking delays for pseudo-async operations

/* Introduction:
 * Delays are extremely useful in microcontroller programming.
 * They allow you to pause the execution of your program for a certain amount of time.
 * However, they are blocking, meaning that the program will not do anything else while the delay is happening.
 * This can be a problem when you want to do multiple things at once.
 * For example, if you want to blink an LED while waiting for a button press, you can't use a delay because it will block the button press from being detected.
 */

/*
 * Instead of using delay() to block execution of code,
 * we can use the millis() function to allow a particular case to run when a certain time has passed,
 * ensuring that the code runs in a non-blocking manner.
 */

// Define two pin-sets for two buttons and LEDs
#define BUTTON1_PIN 2
#define LED1_PIN 9
int led1_interval = 1; // Time in seconds to keep LED1 on
unsigned long led1_off; // Variable to store millis to turn off LED1

#define BUTTON2_PIN 3
#define LED2_PIN 10
int led2_interval = 1; // Time in seconds to keep LED2 on
unsigned long led2_off; // Variable to store millis to turn off LED2


void setup() {

  Serial.begin(9600);

  pinMode(BUTTON1_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);

  pinMode(BUTTON2_PIN, INPUT);
  pinMode(LED2_PIN, OUTPUT);

}

void loop() {
  // Code block to save time to turn off LEDs when button is pressed
  if (digitalRead(BUTTON1_PIN) == HIGH){
    led1_off = millis() + (led1_interval * 1000);
    Serial.print("Button 1 pressed. millis() = ");
    Serial.print(millis(), DEC);
    Serial.print(". led1_off = ");
    Serial.print(led1_off, DEC);
    Serial.println();
  }

  if (digitalRead(BUTTON2_PIN) == HIGH){
    led2_off = millis() + (led2_interval * 1000);
    Serial.print("Button 2 pressed. millis() = ");
    Serial.print(millis(), DEC);
    Serial.print(". led2_off = ");
    Serial.print(led2_off, DEC);
    Serial.println();
  }

  // Code bock to turn on LEDs when time is less than the time to turn off (set by button press)
  if (millis() < led1_off){
    digitalWrite(LED1_PIN, HIGH);
  } else {
    digitalWrite(LED1_PIN, LOW);
  }
  if (millis() < led2_off){
    digitalWrite(LED2_PIN, HIGH);
  } else {
    digitalWrite(LED2_PIN, LOW);
  }

  delay(1);

}
