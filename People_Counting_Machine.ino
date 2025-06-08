#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int ir_Sensor_entry = 8;
const int ir_Sensor_exit = 9;
bool ir_status_entry = LOW;
bool ir_status_exit = LOW;
unsigned int count =0u;
bool add_count_status = LOW;
bool remove_count_status = LOW;
void setup() {
  pinMode(ir_Sensor_entry, INPUT);
  pinMode(ir_Sensor_exit, INPUT);
  lcd.begin(16, 2);
  lcd.print("People Counting");
  lcd.setCursor(3,2);
  lcd.print("Machine");
  delay(1000);

}
void loop() {
  ir_status_entry = digitalRead(ir_Sensor_entry);
  //delay(1000);
  ir_status_exit = digitalRead(ir_Sensor_exit);
  //delay(1000);

  if(ir_status_entry == HIGH)
  {
    if(add_count_status == LOW)
    {
      add_count_status = HIGH;
      count =  count + 1u;
     lcd.clear();
     lcd.print("One Person");
      lcd.setCursor(3,2);
     lcd.print("Added");
      delay(200);
    }
   
  } 
  else
  {
    add_count_status = LOW;
    lcd.clear();
    lcd.print("waiting for");
    lcd.setCursor(3,2);
    lcd.print("next entry");
    delay(500);
  }
  if(ir_status_exit == HIGH)
  {
    if((remove_count_status == LOW )and (count > 0))
    {
      remove_count_status = HIGH;
      count =  count - 1u;
      lcd.clear();
     lcd.print("One Person");
     lcd.setCursor(3,2);
     lcd.print("removed");
     delay(200);
    }
  } 
  else
  {
    remove_count_status = LOW;
    lcd.clear();
    lcd.print("waiting for");
    lcd.setCursor(3,2);
    lcd.print("next exit");
    delay(100);

  }

  lcd.clear();
  lcd.print("Total People");
  lcd.setCursor(3,2);
  lcd.print(count);
  delay(500);
 
  
  
}
