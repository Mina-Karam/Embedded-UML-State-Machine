typedef enum{
  Off,
  On,
  Total_Events
}Event_t;

typedef enum{
  Light_Off,
  Light_Dim,
  Light_Med,
  Light_Full,
  Total_Light_States
}Light_State_t;

Light_State_t current_state = Light_Off;

#define PIN_LED 9

#define LIGHT_BRIGHT_DIM   25
#define LIGHT_BRIGHT_MED   85
#define LIGHT_BRIGHT_FULL  255
#define LIGHT_BRIGHT_OFF   0

void setup() 
{
  Serial.begin(115200);
  Serial.println("Light control application");
  Serial.println("-------------------------");
  Serial.println("Send 'x' or 'o'");
}

void loop() 
{
  uint8_t event;

  if(Serial.available() > 0)
  {
    event = Serial.read();
    if(event == 'x')
    {
      light_state_machine(Off);
    }
    else if(event == 'o')
    {
      light_state_machine(On);
    }
  }
}

void light_state_machine(uint8_t event)
{
  switch (current_state)
  {
    case Light_Off:
      {
        switch (event)
        {
          case Off:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_OFF); /* --Ignore-- */
            current_state = Light_Off;
            Serial.println("Light OFF");
            break;
          }

          case On:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_DIM);
            current_state = Light_Dim;
            Serial.println("Light Dim");
            break;
          }

          default:
          {
            /* Do Nothing */
            break;
          }
        }
        break;
      }
      
    case Light_Dim:
      {
        switch (event)
        {
          case Off:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_OFF);
            Serial.println("Light Off");
            current_state = Light_Off;
            break;
          }
          
          case On:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_MED);
            Serial.println("Light Med");
            current_state = Light_Med;
            break;
          }

          default:
          {
            /* Do Nothing */
            break;
          }
        }
        break;
      }
    case Light_Med:
      {
        switch (event)
        {
          case Off:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_OFF);
            Serial.println("Light Off");
            current_state = Light_Off;
            break;
          }
          
          case On:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_FULL);
            Serial.println("Light Full");
            current_state = Light_Full;
            break;
          }

          default:
          {
            /* Do Nothing */
            break;
          }
        }
        break;
      }
    case Light_Full:
      {
        switch (event)
        {
          case Off:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_OFF);
            Serial.println("Light Off");
            current_state = Light_Off;
            break;
          }
          
          case On:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_DIM);
            Serial.println("Light Dim");
            current_state = Light_Dim;
            break;
          }

          default:
          {
            /* Do Nothing */
            break;
          }
        }
        break;
      }

    default:
    {
      /* Do Nothing */
      break;
    }
  }
}

void light_change_intensity(uint8_t pin, uint8_t intensity)
{
  analogWrite(pin,intensity);
}