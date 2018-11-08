// Lösung zu Termin2
// Aufgabe 4
// Namen: Marcel Romagnuolo, Michael Gerster
// Matr.: 729698,726688
// vom :  22.10.13
// 

#include "../h/pmc.h"
#include "../h/pio.h"
#include "../h/aic.h"
#include "../h/tc.h"

void irq_handler(void)__attribute__((interrupt)); //Definition des Interrupts

void irq_handler(void)
{
	StructPIO* piobaseB = PIOB_BASE; // Deklarieren von piobase mit der Basisadresse
	StructAIC* aicbase = AIC_BASE;	// Deklarieren von Interrupt controller mit der Basisadresse

	piobaseB->PIO_PER = LED1; //es wird auf alle led's zugegriffen + schalter
	piobaseB->PIO_OER = LED1;


	if(!(piobaseB->PIO_PDSR&KEY1)) //wenn taste 1 gedrückt, wird eingeschaltet
	{
		piobaseB->PIO_CODR = LED1;	 
	}
	
	if(!(piobaseB->PIO_PDSR&KEY2))
	{
		piobaseB->PIO_SODR = LED1;
	}

	aicbase->AIC_EOICR = piobaseB->PIO_ISR;	// 
}


int main(void)
{
	int zaehler;
	
	StructPMC* pmcbase = PMC_BASE; 		//basisadresse des pmc
	pmcbase->PMC_PCER = 0x4000; 		//peripheral clocks aktiv für piob; 15. register
	
	StructPIO* piobaseB = PIOB_BASE; 	//es wird auf header datei zugegriffen über pointer
						//ersatz für die defines	
	PIOB_BASE->PIO_PER = LED1 | LED2 | LED3 | LED4 | LED5 | LED6 | LED7 | LED8 | KEY1 | KEY2;	//oder 0xfe18; 		//es wird auf alle led's zugegriffen + schalter
	piobaseB->PIO_OER = 0xfe00;
	
	piobaseB->PIO_SODR = 0xff00; 		//alle led's werden zunächst als default ausgeschaltet
	
	StructAIC* aicbase = AIC_BASE;		// Deklarieren von Interrupt controller mit der Basisadresse
	aicbase->AIC_IDCR = 1 << 14;		// 1 << 14 = 0x4000, Interrupt PIOB ausschalten
	aicbase->AIC_ICCR = 1 << 14;		// Interrupt piob löschen falls was drin ist.
	aicbase->AIC_SMR[14] = AIC_PRIOR;	// Bestimmung der Prioritiät. 0x7 ist die höchste Priorität.
	aicbase->AIC_SVR[14] = (unsigned int)irq_handler; //trage Einsprungadresse für den Interrupt in den irq_handler
	aicbase->AIC_IECR = 0x4000;		// Interruptregister wird aktiviert auf PIOB.
		
	piobaseB->PIO_IER = KEY1 | KEY2;	 // Bestimmung der Auslösefälle.
	
	while(1)
	{
	
		

		
		piobaseB->PIO_CODR = 0x200; //led 2 wird eingeschaltet
	//	piobaseB->PIO_CODR = 0x100;
		for(zaehler = 200000; zaehler > 0; zaehler--) //schindet zeit
		{
		}
		
		piobaseB->PIO_SODR = 0x200; //led 2 wird ausgeschaltet
	//	piobaseB->PIO_SODR = 0x100;
		for(zaehler = 200000; zaehler > 0; zaehler--) //schindet zeit
		{
		}	
	}
	
	//aicbase->AIC_IDCR = 1 << 14;	// 1 << 14 = 0x4000, Interrupt PIOB ausschalten
	//aicbase->AIC_ICCR = 1 << 14;	// Interrupt piob löschen falls was drin ist.	
	
	return 0;
}
