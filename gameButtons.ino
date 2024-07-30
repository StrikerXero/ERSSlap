//RENAME PIN NUMBERS TO SYMANTIC NAMES
#define ledReset 6
#define ledPlayer1 5
#define ledPlayer2 3
const int buttonReset = 2;
const int buttonPlayer1 = 4;
const int buttonPlayer2 = 7;
//SET INITIAL BUTTON STATES
int resetState = 0;
int player1State = 0;
int player2State = 0;


void setup() {
//SET PIN OPERATION
  pinMode (ledReset, OUTPUT);
  pinMode (ledPlayer1, OUTPUT);
  pinMode (ledPlayer2, OUTPUT);
  pinMode (buttonReset, INPUT);
  pinMode (buttonPlayer1, INPUT);
  pinMode (buttonPlayer2, INPUT);
}

void loop() {
//GET BUTTON STATES
  resetState = digitalRead(buttonReset);
  player1State = digitalRead(buttonPlayer1);
  player2State = digitalRead(buttonPlayer2);

//PLAYER 1 WINS
  while((player1State == 1) && (resetState == 0)) {
    digitalWrite (ledPlayer1, HIGH);
    resetState = digitalRead(buttonReset);
  }

  //PLAYER 2 WINS
  while((player2State == 1) && (resetState == 0)){
    digitalWrite (ledPlayer2, HIGH);
    resetState = digitalRead(buttonReset);
  }

//RESET IF PLAYER WINS
  if((player1State == 1) || (player2State == 1) && (resetState == HIGH)) {
    digitalWrite(ledReset, HIGH);
    int player1State = 0;
    int player2State = 0;
    int resetState = 0;
    delay(500);
    digitalWrite(ledPlayer1, LOW);
    digitalWrite(ledPlayer2, LOW);
    digitalWrite(ledReset, LOW);
  }
}