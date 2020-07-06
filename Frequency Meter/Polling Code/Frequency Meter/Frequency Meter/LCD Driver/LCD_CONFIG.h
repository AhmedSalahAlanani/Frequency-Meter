//****************************************************************************
#ifndef	LCD_CONFIG_H_
#define	LCD_CONFIG_H_


#include "DIO_INIT.h"


//	Clock	Frequency
#ifndef F_CPU
#define F_CPU 16000000UL						 // 16 MHz clock speed
#endif


//	Control Pins
#define		RS						0
#define		RW						1
#define		EN						2


//	Control and Data Ports
#define		CONTROL_PORT			portB		//	It only takes the Selected Bits above
#define		DATA_PORT				portB		//	In case of 4_Bits , it takes the 4 Most Significant Bits


//	Selected Mode 
#define		MODE					4		//	Choose from  ( 4 or 8 )

#endif
//****************************************************************************
