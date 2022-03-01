int count,i,j,k,l,cnt=9999,val=0,Action1=0;

int  arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
//const int arr[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x98};

unsigned int Pressed=0,Holded=0,released=0;
const int SW=12;

void setup()
{
    for( count= 0; count <12;count ++ )
    {
        pinMode(count, OUTPUT);
    }
    pinMode(SW,INPUT);  
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
}
void loop()
{
    val=digitalRead(SW);
    if(val==HIGH)
    {
        Pressed++;
        if(Pressed>20)
        {
            if(Action1==0)
            {
                cnt--;
                Action1=1;
            }
            Pressed=0;
            Holded++;
            if(Holded>10)
            {
                cnt--;
                Holded=0;
            }
        }      
    }
    else
    {
        released++;
        if(released>20)
        {
            released=0;
            Action1=0;
        }
    }
    Seven_Segment_Runner();
} 
 
void Seven_Segment_Runner(void)
{
   unsigned char Disp1_Data,Disp2_Data,Disp3_Data,Disp4_Data;
   unsigned int Temp_DATA;

  Temp_DATA  = cnt;
  Disp1_Data = Temp_DATA % 10;    
  Temp_DATA  = Temp_DATA / 10;    
  Disp2_Data = Temp_DATA % 10;
  Temp_DATA  = Temp_DATA / 10;
  Disp3_Data = Temp_DATA % 10;    
  Temp_DATA  = Temp_DATA / 10;    
  Disp4_Data = Temp_DATA % 10;            
  
  
  PORTD = arr[Disp1_Data]; 
    digitalWrite(11, HIGH);
  delay(1); 
  digitalWrite(11, LOW);
  
  PORTD = arr[Disp2_Data]; 
  digitalWrite(10, HIGH);
  delay(1); 
  digitalWrite(10, LOW);

  PORTD = arr[Disp3_Data]; 
  digitalWrite(9, HIGH);
  delay(1); 
  digitalWrite(9, LOW);
  
  PORTD = arr[Disp4_Data]; 
  digitalWrite(8, HIGH);
  delay(1); 
  digitalWrite(8, LOW);
}
