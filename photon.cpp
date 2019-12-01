int temp = A0; 
int led = D7;
int relay = D1;
int state = 0; // 0 Low
int currenttemp = 0;
int templo = 56;
int temphi = 64;

void setup() {

  pinMode(temp, INPUT);
  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);

}

void loop() {

    // Low
    if(state == 0){
        digitalWrite(led, HIGH);
        digitalWrite(relay, HIGH);
	}

    // Normal
	else if(state == 1){
        digitalWrite(led, LOW);
        digitalWrite(relay, HIGH);
	}

    // High
	else if(state == 2){
        digitalWrite(relay, LOW);
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(100);
    }

    // Set state
    int oldState = state;
    currentTemp = analogRead(temp);
    if (currentTemp < templo) {
        state = 0;
    } else if (currentTemp < temphi) {
        state = 1;
    } else {
        state = 2;
    }
    if (oldState != state) {
        Particle.publish("temp_state_change", state, PUBLIC); 
    }
}