/* ADC Interfacing example for 10-bit ADC*/ /* The following example shows the procedure of setting up and using the PIC ADC */ /*
PIC ADC Ch 0 is used as the Analogue i/p. All 10 bits are shown on Ports D (0-8) and Port B (bits 9 and 10) */
#pragma config OSC = HS      /* set osc mode to HS */
#pragma config WDT = OFF     /* set watchdog timer off */
#pragma config LVP = OFF     /* Low Voltage Programming Off */
#pragma config DEBUG = OFF   /* Compile without extra Debug compile Code */

#include <p18f4520.h>        /* Device used is the PICF4520 */
#include <adc.h>
#include <stdlib.h>
#include <delays.h>

void main (void)
{
    TRISA = 0xFF; /* Configure Port A as I/Ps for ADC */
    /*Set PORT B as Digital Outputs to display only the 8 LSB ADC values*/
    TRISB = 0x00; /* Configure Port B as O/P */
    TRISD = 0X00; /* Configure Port D as all O/P */
	while(1)
	{
		OpenADC(ADC_FOSC_32 & ADC_LEFT_JUST & ADC_20_TAD,ADC_CH0 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 0b1011);
		ConvertADC( ); /* start A/D conversion */
		while(BusyADC( )); /* wait for completion */
		/* Get results and store at Ports D & B */
		LATD = ADRESH; /* Results Register High displayed, least sign on Port D */
		LATB = ADRESL; /* Results Register Low displayed on Port B */
		Delay10KTCYx(255); // Short delay here 	

		SetChanADC(ADC_CH1);
		ConvertADC( ); /* start A/D conversion */
		while(BusyADC( )); /* wait for completion */
		/* Get results and store at Ports D & B */
		LATD = ADRESH; /* Results Register High displayed, least sign on Port D */
		LATB = ADRESL; /* Results Register Low displayed on Port B */
		Delay10KTCYx(255); // Short delay here 	

		SetChanADC(ADC_CH2);
		ConvertADC( ); /* start A/D conversion */
		while(BusyADC( )); /* wait for completion */
		/* Get results and store at Ports D & B */
		LATD = ADRESH; /* Results Register High displayed, least sign on Port D */
		LATB = ADRESL; /* Results Register Low displayed on Port B */
		Delay10KTCYx(255); // Short delay here 	

		SetChanADC(ADC_CH3);
		ConvertADC( ); /* start A/D conversion */
		while(BusyADC( )); /* wait for completion */
		/* Get results and store at Ports D & B */
		LATD = ADRESH; /* Results Register High displayed, least sign on Port D */
		LATB = ADRESL; /* Results Register Low displayed on Port B */
		Delay10KTCYx(255); // Short delay here 	
		CloseADC( );
	}
}
