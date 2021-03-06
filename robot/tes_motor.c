/*****************************************************
This program was produced by the
CodeWizardAVR V2.03.9 Standard
Automatic Program Generator
� Copyright 1998-2008 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 7/28/2012
Author  : Yahya
Company : 
Comments: 


Chip type               : AT90USB1286
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 2048
*****************************************************/

#include <90usb1286.h>
// Standard Input/Output functions
#include <stdio.h>
#include <delay.h>
#include <string.h>
#include <stdlib.h>


// Declare your global variables here
  int i = 0, k=0,l=0;
  int j = 0;
  int lpwm, rpwm;
  char data, speed[15];
  

int konversi (char p)
{
    int k=0;
    if(p=='0')
        k=0;
    if(p=='1')
        k=1;
    if(p=='2')
        k=2;                    
    if(p=='3')
        k=3;
    if(p=='4')
        k=4;
    if(p=='5')
        k=5;
    if(p=='6')
        k=6;
    if(p=='7')
        k=7;
    if(p=='8')
        k=8;
    if(p=='9')
        k=9;
                                  
    return k;    
}


void gerak_robot(char kanan, char kiri, int RPWM, int LPWM)
{
 if (kanan == '+')
 {
    if (kiri == '+')  //maju
    {
        PORTB.4 = 1;
        PORTB.5 = 0;
        PORTB.6 = 0;
        PORTB.7 = 1; 
        OCR3AH=0x00;//data1;
        OCR3AL=LPWM;//data1    motor kiri
        OCR3BH=0x00;//data1;
        OCR3BL=RPWM;//data1;     motor kanan
        delay_ms(30); 
            
        /*PORTB.4 = 0;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 0; 
        OCR3AH=0x00;//data1;
        OCR3AL=100;//data1; 
        OCR3AH=0x00;//data1;
        OCR3AL=100;//data1;
        delay_ms(5); 
        */    
        PORTB.4 = 1;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 1;
    }
    
    if (kiri == '-')  //putar kiri
    {
        PORTB.4 = 1;
        PORTB.5 = 0;
        PORTB.6 = 1;
        PORTB.7 = 0; 
        OCR3AH=0x00;//data1;
        OCR3AL=LPWM;//data1    motor kiri
        OCR3BH=0x00;//data1;
        OCR3BL=RPWM;//data1;     motor kanan
        delay_ms(30); 
            
        /*PORTB.4 = 0;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 0; 
        OCR3AH=0x00;//data1;
        OCR3AL=100;//data1; 
        OCR3AH=0x00;//data1;
        OCR3AL=100;//data1;
        delay_ms(5); 
        */    
        PORTB.4 = 1;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 1;
    }
 }
 else
 {
    if (kiri == '+')  //putar kanan
    {
        PORTB.4 = 0;
        PORTB.5 = 1;
        PORTB.6 = 0;
        PORTB.7 = 1; 
        OCR3AH=0x00;//data1;
        OCR3AL=LPWM;//data1    motor kiri
        OCR3BH=0x00;//data1;
        OCR3BL=RPWM;//data1;     motor kanan
        delay_ms(30); 
            
        /*PORTB.4 = 0;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 0; 
        OCR3AH=0x00;//data1;
        OCR3AL=100;//data1; 
        OCR3AH=0x00;//data1;
        OCR3AL=100;//data1;
        delay_ms(5); 
        */    
        PORTB.4 = 1;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 1;
    }
    
    if (kiri == '-')  //mundur
    {
        PORTB.4 = 0;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 0; 
        OCR3AH=0x00;//data1;
        OCR3AL=LPWM;//data1    motor kiri
        OCR3BH=0x00;//data1;
        OCR3BL=RPWM;//data1;     motor kanan
        delay_ms(30); 
            
        /*PORTB.4 = 0;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 0; 
        OCR3AH=0x00;//data1;
        OCR3AL=100;//data1; 
        OCR3AH=0x00;//data1;
        OCR3AL=100;//data1;
        delay_ms(5); 
        */    
        PORTB.4 = 1;
        PORTB.5 = 1;
        PORTB.6 = 1;
        PORTB.7 = 1;    
    }
 }
}  

  
void main(void)
{
// Declare your local variables here

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=In Func2=In Func1=In Func0=In 
// State7=0 State6=0 State5=0 State4=0 State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0xF0;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=In Func2=In Func1=In Func0=In 
// State7=0 State6=0 State5=0 State4=0 State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0xF0;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

// Port E initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTE=0x00;
DDRE=0x00;

// Port F initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTF=0x00;
DDRF=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=FFh
// OC0A output: Disconnected
// OC0B output: Disconnected
TCCR0A=0x00;
TCCR0B=0x00;
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// OC1C output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
OCR1CH=0x00;
OCR1CL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer 2 Stopped
// Mode: Normal top=FFh
// OC2A output: Disconnected
// OC2B output: Disconnected
ASSR=0x00;
TCCR2A=0x00;
TCCR2B=0x00;
TCNT2=0x00;
OCR2A=0x00;
OCR2B=0x00;

// Timer/Counter 3 initialization
// Clock source: System Clock
// Clock value: 62.500 kHz
// Mode: Fast PWM top=03FFh
// OC3A output: Non-Inv.
// OC3B output: Discon.
// OC3C output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 3 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR3A=0xA3;
TCCR3B=0x0C;
TCNT3H=0x00;
TCNT3L=0x00;
ICR3H=0x00;
ICR3L=0x00;
OCR3AH=0x00;
OCR3AL=0x00;
OCR3BH=0x00;
OCR3BL=0x00;
OCR3CH=0x00;
OCR3CL=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
// INT3: Off
// INT4: Off
// INT5: Off
// INT6: Off
// INT7: Off
EICRA=0x00;
EICRB=0x00;
EIMSK=0x00;
// PCINT0 interrupt: Off
// PCINT1 interrupt: Off
// PCINT2 interrupt: Off
// PCINT3 interrupt: Off
// PCINT4 interrupt: Off
// PCINT5 interrupt: Off
// PCINT6 interrupt: Off
// PCINT7 interrupt: Off
PCMSK0=0x00;
PCICR=0x00;

// Timer/Counter 0 Interrupt(s) initialization
TIMSK0=0x00;
// Timer/Counter 1 Interrupt(s) initialization
TIMSK1=0x00;
// Timer/Counter 2 Interrupt(s) initialization
TIMSK2=0x00;
// Timer/Counter 3 Interrupt(s) initialization
TIMSK3=0x00;

// USART1 initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART1 Receiver: On
// USART1 Transmitter: On
// USART1 Mode: Asynchronous
// USART1 Baud Rate: 9600
UCSR1A=0x00;
UCSR1B=0x18;
UCSR1C=0x06;
UBRR1H=0x00;
UBRR1L=0x67;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
ADCSRB=0x00;

// USB Controller initialization
// USB Mode: Disabled
// UID Pin: Off
// UVCON Pin: Off
// USB Pad Regulator: Off
// OTG Pad: Off
// VBUS Transition interrupt: Off
// ID Transition interrupt: Off
UHWCON=0x00;
USBCON=0x00;
USBINT=0; // Clear the interrupt flags
// SRP interrupt: Off
// VBUS Error interrupt: Off
// B-Connection Error interrupt: Off
// Role Exchange interrupt: Off
// HNP Error interrupt: Off
// Suspend Time-out Error interrupt: Off
OTGIEN=0x00;
OTGINT=0; // Clear the interrupt flags
// SRP Method: Data line pulsing
OTGCON=0x00;

for(i=0;i<20;i++)
{
delay_ms(500);
}

printf("Robot 1, ready..");

while (1)
      {                        
         //k += PIND.0; 
         //l += PINE.5;       
         data = getchar();
         //printf("%x\n",UCSR1A); 
         //baca data encoder
         //j = PIND.0;
         
         //if(PIND.0!=j)
         //{
             
             
             //printf("%d\n",i);
         //}  //baca data encoder
         
         
            if (data == '#')
            {
                while (data == '#')
                {
                    data = getchar();
                    if (data == 'C')
                    {
                        while (data == 'C')  
                        {   
                            data = getchar();
                            
                            if (data == 'C')
                            {
                                data = getchar();
                            }
                            else
                            {
                                for(i=0;i<15;i++)
                                {
                                    speed[i] = data;                                      
                                    while (data==speed[i])//(UCSR1A == 64 )
                                    {
                                        data = getchar();
                                    } 
                                }     
                                 rpwm=konversi(speed[2])*100+konversi(speed[4])*10+konversi(speed[6]);
                                 lpwm=konversi(speed[10])*100+konversi(speed[12])*10+konversi(speed[14]);
                               printf("\nPWM kanan: ");
                                 printf("%d\n",rpwm);
                                 printf("PWM kiri: ");
                                 printf("%d\n",lpwm);
                                 gerak_robot(speed[0],speed[8],rpwm,lpwm);
                            }
                            
                        }   
                    }
                    else
                    {
                        for(i=0;i<15;i++)
                        {
                            speed[i] = '0';
                        }   
                    }
                }
            }    
            rpwm=konversi(speed[2])*100+konversi(speed[4])*10+konversi(speed[6]);
            lpwm=konversi(speed[10])*100+konversi(speed[12])*10+konversi(speed[14]);
                         
          
         if(data == '8')    //maju tekan w
         {              
            PORTB.4 = 1;
            PORTB.5 = 0;
            PORTB.6 = 0;
            PORTB.7 = 1; 
            OCR3AH=0x00;//data1;
            OCR3AL=70;//data1    motor kiri
            OCR3BH=0x00;//data1;
            OCR3BL=100;//data1;     motor kanan
            delay_ms(50); 
            
             PORTB.4 = 0;
            PORTB.5 = 1;
            PORTB.6 = 1;
            PORTB.7 = 0; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1;
            delay_ms(5); 
            
            PORTB.4 = 1;
            PORTB.5 = 1;
            PORTB.6 = 1;
            PORTB.7 = 1;
      
            data=']'; 
            k += PIND.0; 
            l += PINE.5;
         }   
                      
         if(data == '2')    //mundur tekan s
         {
            PORTB.4 = 0;
            PORTB.5 = 1;
            PORTB.6 = 1;
            PORTB.7 = 0; 
            OCR3AH=0x00;//data1;
            OCR3AL=70;//data1  
            OCR3BH=0x00;//data1;
            OCR3BL=98;//data1;
            delay_ms(50); 
            
            
             PORTB.4 = 1;
            PORTB.5 = 0;
            PORTB.6 = 0;
            PORTB.7 = 1; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1;
            delay_ms(5); 
            
            PORTB.4 = 1;
            PORTB.5 = 1;
            PORTB.6 = 1;
            PORTB.7 = 1;

            data=']';
         }
                        
         if(data == 'p')
         {
           printf("k = %d ",k);
            printf("l = %d ",l);
         }
         
         if(data == '6')    //kanan
         {
            PORTB.4 = 0;
            PORTB.5 = 1;
            PORTB.6 = 0;
            PORTB.7 = 1; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1  
            OCR3BH=0x00;//data1;
            OCR3BL=98;//data1;
            delay_ms(50); 
            
            PORTB.4 = 1;
            PORTB.5 = 0;
            PORTB.6 = 1;
            PORTB.7 = 0; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1;
            delay_ms(5); 
            
            PORTB.4 = 1;
            PORTB.5 = 1;
            PORTB.6 = 1;
            PORTB.7 = 1;
            
            data=']';
         } 
         
         if(data == '4')    //kiri
         {
            PORTB.4 = 1;
            PORTB.5 = 0;
            PORTB.6 = 1;
            PORTB.7 = 0; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1  
            OCR3BH=0x00;//data1;
            OCR3BL=96;//data1;
            delay_ms(50); 
            
            PORTB.4 = 0;
            PORTB.5 = 1;
            PORTB.6 = 0;
            PORTB.7 = 1; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1; 
            OCR3AH=0x00;//data1;
            OCR3AL=100;//data1;
            delay_ms(5); 
            
            PORTB.4 = 1;
            PORTB.5 = 1;
            PORTB.6 = 1;
            PORTB.7 = 1;
            
            
            data=']';
         }  
      };
      
}



