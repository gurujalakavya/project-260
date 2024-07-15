#include <Keypad.h>

const int row_num = 4;
const int col_num = 4;

int score = 0;

char keys[row_num][col_num] = {
  {'1' , '2' , '3' , 'A'},
  {'4' , '5' , '6' , 'B'},
  {'7' , '8' , '9' , 'C'},
  {'*' , '0' , '#' , 'D'}
};

byte row_pins[] = {19,18,5,17};
byte col_pins[] = {16,4,2,15};

//  making keypad object
Keypad k = Keypad(makeKeymap(keys), row_pins, col_pins, row_num, col_num );

void setup(){
  Serial.begin(115200);
}

void loop(){

  //  picking a random element from 2D array
  byte random_row = random(1,5);
  byte random_column = random(1,5);
  char random_element = keys[random_row-1][random_column-1];

  //  picking up random hint
  String hint1 = "The element is in row : " + String(random_row);
  String hint2 = "The element is in column : " + String(random_column);
  byte random_hint = random(1,3);  //  possible values : 1 or 2
  if (random_hint  ==  1)Serial.println(hint1);
  else Serial.println(hint2);

  //  attempts left
  byte chances = 2;



  //  GAME LOOP
  while (chances){
    char key = k.getKey();

    //  key pressed
    if (key){
      if (key  ==  random_element){
        Serial.println("You WON!");
        break;
      }

      else{
        chances--;
        if (chances){
          Serial.println("Wrong guess, try again");
        }
        else{
          Serial.println("You lOSE!");
          break;
        }
      }
    }
  }

  
  Serial.println();
  Serial.println("Let's play again...");
  delay(5000);

}