//****************************************************************************
 #ifndef	TIMER_1_H_
 #define	TIMER_1_H_

 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "avr/interrupt.h"
 #include "Timer_1_Config.h"
 #include "Timer_1_REG.h"
 
   
 //	Functions Prototypes
 void Timer1_CTC_Init(void);
 void Timer1_InputCapture_Init(void);
 void Timer_1_Interrupt_Enable(void);
 void OCR1A_Write(u16 value);
 u16 ICR1_Read(void);
 void TIMER1_COMPA_Callback(void(*function_ptr) (void));
 void TIMER1_CAPT_Callback(void(*function_ptr) (void));

#endif
//****************************************************************************