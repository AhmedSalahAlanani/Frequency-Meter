/*
 * Frequency Meter.c
 *
 * Created: 29-Jun-20 5:55:26 PM
 * Author : Ahmed Salah
 */ 

//Only use with Simulation
//#define		F_CPU					15100000UL		//Otherwise, Comment this line

#include "Timer_1/Timer_1.h"
#include "LCD Driver/LCD_INIT.h"



//	Application defined Constants
#define		Entry_Message			(u8*)"Frequency Meter "
#define		First_Message			(u8*)"Frequency = "


//	Global Variables
static u16 Readings[2] ;


//	Function Prototypes
void Timer_Handler(void);
u32 Calculate_Frequency(void);
void Update_LCD(u32 Reading);
u8* Convert_Integer_To_String(u32 integer_value);


int main(void)
{
	//Initialize LCD
	LCD_Vid_4BitInit();
	
	//Send message to the User
	LCD_Vid4BitSendString(Entry_Message);
	
	_delay_ms(2000);
	LCD_VidClrLCD();
	_delay_ms(2000);
	
	LCD_Vid4BitSendString(First_Message);

	//Initialize Timer_1
	Timer1_InputCapture_Init();	
	
	
    while (1) 
    {	
		Timer_Handler();
		Update_LCD(Calculate_Frequency());
    }
}



void Timer_Handler(void)
{
	//Poll the Flag
	while (!GET_BIT(TIFR,ICF1));
	
	//Get the First reading
	Readings[0] = ICR1_Read();
	
	//Clear the Flag
	SET_BIT(TIFR,ICF1);
	
	//Poll the Flag again
	while (!GET_BIT(TIFR,ICF1));
	
	//Get the Second reading
	Readings[1] = ICR1_Read();
	
	//Clear the Flag
	SET_BIT(TIFR,ICF1);
}



u32 Calculate_Frequency(void)
{	
	//Initialize variable for First time only
	static u32 Frequency ;
	
	//Subtract the First reading from the Second and divide the CPU frequency by the difference
	Frequency = F_CPU/(float)(Readings[1]-Readings[0]);	
	return Frequency;
}




void Update_LCD(u32 Reading)
{
	LCD_Vid_GoToXY(1,2);
	LCD_Vid4BitSendString((Convert_Integer_To_String(Reading)));
	
	//To make the readings more Clear
	_delay_ms(100);
}


u8* Convert_Integer_To_String(u32 integer_value)
{
	static  u8 string_value[9] = {0};
	
	for(u8 i=0, div =10 ;i<8 ; i++ )
	{
		string_value[7-i] = ((integer_value % 10) + 48) ;
		integer_value /= div ;
	}
	
	return string_value;
}
