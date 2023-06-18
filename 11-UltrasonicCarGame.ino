int trigPin = 11;
int echoPin = 13;
float initial_distance, initial_distance_2,  final_distance, duration, delta_distance;
int latencyInMicroSeconds = 500;

int minimumDistance = 10;
int maximumDistance = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  initial_distance = (duration * 0.0343) / 2;

  delay(50);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  initial_distance_2 = (duration * 0.0343) / 2;

  if(initial_distance <= maximumDistance){
    
    if(abs(initial_distance - initial_distance_2) > 3 && abs(initial_distance - initial_distance_2) < 50){
      delay(latencyInMicroSeconds);
      
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);
      final_distance = (duration * 0.0343) / 2;

      if(abs(initial_distance - final_distance) < 60 && abs(initial_distance - final_distance) > 10){
        delta_distance = initial_distance - final_distance;

        if(delta_distance > 1){
          Serial.println("RIGHT");
          delay(200);
          }else {
            Serial.println("LEFT");
          delay(200);
            }
        }
    }
    }
  delay(20);
  
}
