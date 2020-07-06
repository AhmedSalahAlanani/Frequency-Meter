//****************************************************************************
 #ifndef	TIMER_1_CONFIG_H_
 #define	TIMER_1_CONFIG_H_
 

/* Select Timer_1 Mode */
#define			TIMER_1_MODE								1					  // Choose from (0) to (4)

//	For Non PWM Mode only
#define			Compare_OutputMode							0					  // From (0) to (7)

//	For CTC Mode only
#define			CTC_TopValue								0					  // (0) for OCR1A, (1) for ICR1 


//	For Input Capture Mode only
#define			Input_Capture_Enable						1					  // (1) To Enable, (0) To Disable
#define			Input_Capture_EdgeSelect					1					  // (0) for Falling Edge, (1) for Rising Edge

#define			Noise_Canceler_Enable						1					  // (1) To Enable, (0) To Disable


/* Select the Clock for Timer_1 */
#define			Clock_Select								1					  // From (0) to (7)


/* Select Timer_1 Interrupt Enable */						
#define			Timer_1_Interrupt_select					0					  // From (0) to (3)




#endif
//****************************************************************************