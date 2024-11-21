/*
 * Portas LCD
rs  8
en  9
D4  4
D5  5
D6  6
D7  7


Botoes LCD
AnalogRead(0)
Select 638
Up     100
Down   258
Left   411
Right  0
Reset  Do not touch that one...

*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);


int btn = 1;
int menu = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

}



void loop() {

  delay(50);
  btn = analogRead(0);

  /*APERTO DE BOTÃO*/
  switch (btn) {
    case 638: select();  break;
    case 100: up();      break;    
    case 258: down();    break;
    case 411: left();    break;
    case 0  : right();   break;
    };

  /*ORQUESTRADOR DE MENU*/
  Serial.print("Menu: ");
  Serial.println(menu);
  
  switch (menu){
     case -4: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("> Opcao 4      ^");
      lcd.setCursor(0,1); lcd.print("Opcao 5        v"); 
     break;
    
     case -3: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("> Opcao 3      ^");
      lcd.setCursor(0,1); lcd.print("Opcao 4        v"); 
    break;
    
    case -2: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("> Opcao 2      ^");
      lcd.setCursor(0,1); lcd.print("Opcao 3        v"); 
    break;
    
    case -1: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("> Opcao 1      ^");
      lcd.setCursor(0,1); lcd.print("Opcao 2        v"); 
    break;*
    
    case 0: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("Welcome:       |"); 
      lcd.setCursor(0,1); lcd.print("> Opcao 1      v");  
    break;
     
    case 1: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("Opcao 1        ^");
      lcd.setCursor(0,1); lcd.print("> Opcao 2      v"); 
    break;
     
    case 2: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("Opcao 2        ^");
      lcd.setCursor(0,1); lcd.print("> Opcao 3      v"); 
    break;
     
    case 3: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("Opcao 3        ^");
      lcd.setCursor(0,1); lcd.print("> Opcao 4      v"); 
    break;
     
    case 4: 
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("Opcao 4        ^");
      lcd.setCursor(0,1); lcd.print("> Opcao 5"); 
    break;
    
  }
    
}


 /* */
/* SELECT */
void select() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Select");  
 
}

/*UP*/
void up() {
  delay(300);

  if (menu > 0){
    menu = menu*(-1);
    }
  else if (menu < 0){
    menu = menu + 1;   
    };
  
  
}

/*DOWN*/
void down(){
  delay(300);

  if (menu < 0){
    menu = menu*(-1);
    }
  else if (menu >= 4){
      return; 
    }
    else if (menu >= 0){
        menu = menu + 1;
      };  
  
}

/*LEFT*/
void left(){

}

/*RIGHT*/
void right(){

}
