// ----- DECLARATION DES VARIABLES ------

// Pour les LED
int LED1=6;
int LED2=5;
int LED3=7;
int LED4=2;

// on indique la pin du capteur d'inclinaison
int buttonPin = 3; 
// On vérifie l'état du capteur d'inclinaison
int buttonState;
// Variable pour le random de l'animation 
long ranim;
// Variable pour le random du résultat final
long ran;
// Il n'y a pas encore eu de lancement de dé
int last = 0;
// Temps que le dé reste affiché 1000 ms = 1 seconde
int time = 6000; 

// ----- DECLARATION ENTREES ET SORTIES ------
void setup ()
{
  //On indique que les LED sont des sorties
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  // On indique que le detecteur d'inclinaison est une entrée.
  pinMode (buttonPin, INPUT);

  randomSeed(analogRead(0)); // on initialise le fait de pouvoir lancer des randoms
}

// ----- ACTIONS A EFFECTUER ------
void loop()
{  
      
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW){ // Si on bouge le dé
    
   for (int i=0; i <= 7; i++){ // Animation pour 8 affichages de dé avec 200 ms entre chaque
     
  ranim = random(1, 7); // on effectue un random pour chaque affichage
  
  while (ranim == last){ // On verifie que deux affichages consécutifs ne sont pas les mêmes 
    ranim = random(1, 7); // Sinon on random un autre chiffre
  }
  last = ranim; // On stock le chiffre pour éviter d'afficher les 2 mêmes valeurs de dé pendant l'animation
    if (ranim == 1){
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,HIGH);
    }
    if (ranim == 2){
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
    }
    if (ranim == 3){
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,HIGH);
    }
    if (ranim == 4){
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
    }
    if (ranim == 5){
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,HIGH);
   }
   if (ranim == 6){
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
      digitalWrite(LED4,LOW);
   }
      delay(200);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
      delay(50);
   } 
    
    
// RANDOM DU RESULTAT FINAL
    ran = random(1,7); 
    if (ran == 1){
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,HIGH);
        delay (time);
      }
    
    if (ran == 2){
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      delay (time);
    }
    if (ran == 3){
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,HIGH);
      delay (time);
    }
    if (ran == 4){
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      delay (time);
    }
    if (ran == 5){
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,HIGH);
      delay (time);
   }
   if (ran == 6){
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
      digitalWrite(LED4,LOW);
      delay (time);
   }
  }
  // On éteint tout pour pouvoir relancer le dé
digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
}
