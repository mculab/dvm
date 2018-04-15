/*
 * File:   main.c
 * Author: Fozlea Rabbi
 * Blog Address: www.microcontroller-lab.blogspot.com
 * Compiler: Hi-Tech PICC v9.83
 * Created on March 4, 2017, 10:52 AM
 */


#include <htc.h>
#include "adc.h"
#include "lcd.h"

#define _XTAL_FREQ 4000000
// CONFIG
__CONFIG(0x3F71);

// Oscillator Selection bits (XT oscillator)
// Watchdog Timer Enable bit (WDT disabled)
// Power-up Timer Enable bit (PWRT enabled)
// Brown-out Reset Enable bit (BOR enabled)
// Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
// Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
// Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
// Flash Program Memory Code Protection bit (Code protection off)



void main(void) {
    unsigned int ADC_Value, V_Actual;
    unsigned int BCD_Value[4];
	__delay_ms(500);   //power up delay for LCD
    InitADC();
    lcd_init();
	lcd_clear();
	lcd_puts("DVM 1.0");
    __delay_ms(500);

    for(;;){
        lcd_clear();
        ADC_Value = GetADCValue(AN0);
        V_Actual = ADC_Value*4.88*6;			//(Vin/V22) = 6	
        V_Actual /=10;							//maximum value of V_Actual is 5 digit, so make it 4 digit just divide V_Actual by 10

        if(V_Actual>3000){
        lcd_puts("V Out of Range!");			//if iput voltage >30 volt
        }

        else{
        	BCD_Value[0] = V_Actual%10;
        	BCD_Value[1]=(V_Actual/10)%10;
        	BCD_Value[2]=(V_Actual/100)%10;
        	BCD_Value[3]=(V_Actual/1000)%10;
        
        	lcd_putch(BCD_Value[3]+0x30);		// Display digit1 of ADC_value on LCD
			lcd_putch(BCD_Value[2]+0x30);		// Display digit2 of ADC_value on LCD
        	lcd_putch('.');                     // Display (.) on LCD
			lcd_putch(BCD_Value[1]+0x30);		// Display digit3 of ADC_value on LCD
			lcd_putch(BCD_Value[0]+0x30);		// Display digit4 of ADC_value on LCD
        	lcd_puts("VDC");
			__delay_ms(500);					// Half second delay before next reading
        
        }
        
    }

}
