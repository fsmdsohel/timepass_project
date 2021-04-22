#define extend_monitor 44 //e/r-101/114

#define table_light 52 //5/6-53/54
#define rm_light 40    //t/y-116/121
#define blue_light 48  //q/w-113/119
#define table_fan 38   //3/4-51/52
#define back_light 50  //7/8-55/56
#define sound_box 46   //u/i-117/105

void setup()
{
  pinMode(extend_monitor, OUTPUT);

  pinMode(table_light, OUTPUT);
  pinMode(rm_light, OUTPUT);
  pinMode(blue_light, OUTPUT);
  pinMode(table_fan, OUTPUT);
  pinMode(back_light, OUTPUT);
  pinMode(sound_box, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  if (Serial.available() > 0)
  {

    String val = "";

    while (Serial.available() > 0)
    {
      val += String(Serial.read());
    }

    if (val == "49")
    {
      digitalWrite(rm_light, HIGH);   // off
      digitalWrite(blue_light, HIGH); // on
      digitalWrite(back_light, HIGH); // on
      Serial.println("Night mode on");
    }
    else if (val == "50")
    {
      digitalWrite(rm_light, LOW);   // on
      digitalWrite(blue_light, LOW); // off
      digitalWrite(back_light, LOW); // off
      Serial.println("Night mode off");
    }
    else if (val == "53")
    {
      digitalWrite(table_light, HIGH);
      Serial.println("Table light on");
    }
    else if (val == "54")
    {
      digitalWrite(table_light, LOW);
      Serial.println("Table light off");
    }
    else if (val == "121")
    {
      digitalWrite(rm_light, HIGH);
      Serial.println("Room light off");
    }
    else if (val == "116")
    {
      digitalWrite(rm_light, LOW);
      digitalWrite(blue_light, LOW);
      Serial.println("Room light on");
    }
    else if (val == "113")
    {
      digitalWrite(blue_light, HIGH);
      digitalWrite(rm_light, HIGH);
      Serial.println("Blue light on");
    }
    else if (val == "119")
    {
      digitalWrite(blue_light, LOW);
      Serial.println("Blue light off");
    }
    else if (val == "51")
    {
      digitalWrite(table_fan, HIGH);
      Serial.println("Table fan on");
    }
    else if (val == "52")
    {
      digitalWrite(table_fan, LOW);
      Serial.println("Table fan off");
    }
    else if (val == "55")
    {
      digitalWrite(back_light, HIGH);
      Serial.println("Back light on");
    }
    else if (val == "56")
    {
      digitalWrite(back_light, LOW);
      Serial.println("Back light off");
    }
    else if (val == "117")
    {
      digitalWrite(sound_box, HIGH);
      Serial.println("Sound box on");
    }
    else if (val == "105")
    {
      digitalWrite(sound_box, LOW);
      Serial.println("Sound box off");
    }
    else if (val == "101")
    {
      digitalWrite(extend_monitor, LOW);
      Serial.println("Extend monitor on");
    }
    else if (val == "114")
    {
      digitalWrite(extend_monitor, HIGH);
      Serial.println("Extend monitor off");
    }
  }
}
