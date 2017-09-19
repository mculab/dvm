

/* 
 * File: adc.h  

 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __ADC_H
#define	__ADC_H

#define _XTAL_FREQ 4000000
//Define Channels
#define AN0  0
#define AN1  1
#define AN2  2
#define AN3  3
#define AN4  4
#define AN5  5
#define AN6  6
#define AN7  7

//Function Declarations
void InitADC(void);
unsigned int GetADCValue(unsigned char);


#endif	/* XC_HEADER_TEMPLATE_H */

