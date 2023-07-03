#include <Arduino.h>
#include <avr/sleep.h>
#include <avr/power.h>

int randNumber;
 
const byte LED_1 = 0;
const byte LED_2_7 = 1;
const byte LED_3_6 = 4;
const byte LED_4_5 = 3;

const byte SWITCH = 2; 

volatile byte last_sw_state = true;
volatile byte state = false;

ISR(PCINT0_vect){
  byte sw_state;
  sw_state = digitalRead(SWITCH); 
  if (sw_state==LOW) { 
    state = true;
  }
  last_sw_state = sw_state;
}

void enter_sleep (){
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  ADCSRA = 0; 
  power_all_disable (); 
  sleep_enable();
  sleep_cpu();
  sleep_disable();
  power_all_enable();
}

void generate_number(){

  state = false;
  int delay_time = 75;

  for(int x = 0; x < 6; x++) {

    delay_time += 75;
    randomSeed(millis());        
    randNumber = random(1,7); 

    if (randNumber==1){
      digitalWrite(LED_1,HIGH);
      digitalWrite(LED_2_7,LOW);
      digitalWrite(LED_3_6,LOW);
      digitalWrite(LED_4_5,LOW);
    }
    else if(randNumber==2){
      digitalWrite(LED_1,LOW);
      digitalWrite(LED_2_7,HIGH);
      digitalWrite(LED_3_6,LOW);
      digitalWrite(LED_4_5,LOW);
    }
    else if(randNumber==3){
      digitalWrite(LED_1,HIGH);
      digitalWrite(LED_2_7,HIGH);
      digitalWrite(LED_3_6,LOW);
      digitalWrite(LED_4_5,LOW);
    }
    else if(randNumber==4){
      digitalWrite(LED_1,LOW);
      digitalWrite(LED_2_7,HIGH);
      digitalWrite(LED_3_6,HIGH);
      digitalWrite(LED_4_5,LOW);
    }
    else if(randNumber==5){
      digitalWrite(LED_1,HIGH);
      digitalWrite(LED_2_7,HIGH);
      digitalWrite(LED_3_6,HIGH);
      digitalWrite(LED_4_5,LOW);
    }
    else if(randNumber==6){
      digitalWrite(LED_1,LOW);
      digitalWrite(LED_2_7,HIGH);
      digitalWrite(LED_3_6,HIGH);
      digitalWrite(LED_4_5,HIGH);
    }
    delay(delay_time);
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2_7,LOW);
    digitalWrite(LED_3_6,LOW);
    digitalWrite(LED_4_5,LOW);

  }

  randomSeed(millis());        
  randNumber = random(1,7); 

  if (randNumber==1){
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2_7,LOW);
    digitalWrite(LED_3_6,LOW);
    digitalWrite(LED_4_5,LOW);
  }
  else if(randNumber==2){
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2_7,HIGH);
    digitalWrite(LED_3_6,LOW);
    digitalWrite(LED_4_5,LOW);
  }
  else if(randNumber==3){
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2_7,HIGH);
    digitalWrite(LED_3_6,LOW);
    digitalWrite(LED_4_5,LOW);
  }
  else if(randNumber==4){
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2_7,HIGH);
    digitalWrite(LED_3_6,HIGH);
    digitalWrite(LED_4_5,LOW);
  }
  else if(randNumber==5){
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2_7,HIGH);
    digitalWrite(LED_3_6,HIGH);
    digitalWrite(LED_4_5,LOW);
  }
  else if(randNumber==6){
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2_7,HIGH);
    digitalWrite(LED_3_6,HIGH);
    digitalWrite(LED_4_5,HIGH);
  }
  delay(2000);
  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2_7,LOW);
  digitalWrite(LED_3_6,LOW);
  digitalWrite(LED_4_5,LOW);
}

void setup(){

  pinMode (LED_1, OUTPUT);
  pinMode (LED_2_7, OUTPUT);
  pinMode (LED_3_6, OUTPUT);
  pinMode (LED_4_5, OUTPUT);

  digitalWrite(LED_1,LOW);
  digitalWrite(LED_2_7,LOW);
  digitalWrite(LED_3_6,LOW);
  digitalWrite(LED_4_5,LOW);

  pinMode (SWITCH, INPUT_PULLUP);

  cli(); // Disable interrupt
  PCMSK  |= bit (PCINT2);  // D2 / pin 7
  GIFR   |= bit (PCIF);    // Clear any outstanding interrupts
  GIMSK  |= bit (PCIE);    // Enable pin change interrupts
  sei(); // Enable interrupt
}

void loop(){
  if(state==true){
    generate_number();
  }
  state= false;
  enter_sleep ();

}