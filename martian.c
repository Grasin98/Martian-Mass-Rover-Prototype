/*******************************************************
This program was created by the CodeWizardAVR V3.29 
Automatic Program Generator
© Copyright 1998-2016 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 26-01-2018
Author  : 
Company : 
Comments: 


Chip type               : ATmega16L
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <io.h>

// Declare your global variables here

void forward()
{
 PORTA.2=1;
 PORTA.3=1;
 PORTA.4=0;
 
 PORTA.5=1;
 PORTA.6=1;
 PORTA.7=0;
}


void back()
{
 PORTA.2=0;
 PORTA.3=1;
 PORTA.4=1;
 
 PORTA.5=0;
 PORTA.6=1;
 PORTA.7=1;
}


void left()
{
 PORTA.2=1;
 PORTA.3=1;
 PORTA.4=0;
 
 PORTA.5=0;
 PORTA.6=1;
 PORTA.7=1;
}


void right()
{
 PORTA.2=0;
 PORTA.3=1;
 PORTA.4=1;
 
 PORTA.5=1;
 PORTA.6=1;
 PORTA.7=0;
}

void Stop()
{
 PORTA.3=0;
 PORTA.6=0;
}


void hand_forward()
{
PORTC.7=1;
PORTC.6=1;
PORTC.5=0;
}

void hand_back()
{
PORTC.7=0;
PORTC.6=1;
PORTC.5=1;
}



// Standard Input/Output functions
#include <stdio.h>

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
    TCNT0=100;
    PORTD.4=1;

}

// Timer 0 output compare interrupt service routine
interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
    TCNT0=100;
    PORTD.4=0;
}

// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Place your code here
    TCNT1=100;
    PORTD.5=1;

}

// Timer1 output compare A interrupt service routine
interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
// Place your code here
    TCNT1=100;
    PORTD.5=0;

}

// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
    TCNT2=100;
    PORTD.6=1;
}

// Timer2 output compare interrupt service routine
interrupt [TIM2_COMP] void timer2_comp_isr(void)
{
    TCNT2=100;
    PORTD.6=0;
}

void main(void)
{
// Declare your local variables here
char value;

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=In Bit0=In 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=Out Bit5=Out Bit4=Out Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=0 Bit5=0 Bit4=0 Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: Fast PWM top=0xFF
// OC0 output: Disconnected
// Timer Period: 32.768 ms
TCCR0=(1<<WGM00) | (0<<COM01) | (0<<COM00) | (1<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x00;
OCR0=0x6C;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: Fast PWM top=0x00FF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 32.768 ms
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: On
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (1<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (1<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x6C;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 7.813 kHz
// Mode: Fast PWM top=0xFF
// OC2 output: Disconnected
// Timer Period: 32.768 ms
ASSR=0<<AS2;
TCCR2=(1<<PWM2) | (0<<COM21) | (0<<COM20) | (1<<CTC2) | (1<<CS22) | (1<<CS21) | (1<<CS20);
TCNT2=0x00;
OCR2=0X6C;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(1<<OCIE2) | (1<<TOIE2) | (0<<TICIE1) | (1<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (1<<OCIE0) | (1<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: Off
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Globally enable interrupts
#asm("sei")

while (1)
      {    
      
      
       scanf("%c",&value);
       
       if (value=="a")
       {
        forward();
       }          
       
       else if (value==" b")
       {
        Stop();
       }       
       
       else if (value=="c")
       {
        back();
       }   
       
       
       else if (value=="d")
       {
        left();
       } 
       
       
       else if (value=="e")
       {
        right();
       }
       
       else if(value=="f" && PIND.2==0)
       {
         hand_back();
       }                
       
       
       else if (value=="g" && PIND.1==0)
       {
        hand_forward();
       }
       
       
       else if (value=="h")      //Gripper_Open
       {   
       
       if (OCR2<0X75)
       {
        continue;
       }
       OCR2=OCR2++;
       
       }
        
       else if (value=="i")      //Gripper_Close
       {   
       
       if (OCR2<0X6C)
       {
        continue;
       } 
       
       OCR2=OCR2--;
       
       }
       
       else if (value=="j")      //Camera_Up
       {   
       
       if (OCR1AL<0X75)
       {
        continue;
       }    
       
       OCR1AL=OCR1AL++;
       
       }
       
       else if (value=="k")      //Camera_Close
       {   
       
       if (OCR1AL<0X75)
       {
        continue;
       } 
       
       OCR1AL=OCR1AL--;
       
       }
       
       else if (value=="l")      //Camera_Left
       {   
       
       if (OCR1AL<0X6C)
       {
        continue;
       }
         
       OCR1AL=OCR1AL--;
       }
        
        else if (value=="m")      //Camera_Right
       {   
       
       if (OCR1AL<0X75)
       {
        continue;
       }
       OCR1AL=OCR1AL++;
       
       
      }
      } 
      
}
