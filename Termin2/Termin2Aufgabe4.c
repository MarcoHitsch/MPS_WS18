// Loesung zu Termin2
// Aufgabe 4
// Namen: __________; ___________
// Matr.: __________; ___________
// vom :  __________
// 

#include "../h/pmc.h"
#include "../h/pio.h"
#include "../h/aic.h"

StructPIO* piobaseB = PIOB_BASE;
StructAIC* aicbase = AIC_BASE;

void taste_irq_handler (void) __attribute__ ((interrupt));

void taste_irq_handler (void)
{
	//aufgabe 2
	// Taste 1 -> LED1 an
    if(piobaseB->PIO_PDSR&KEY1) 
	{
		piobaseB->PIO_SODR = LED1; 
	}
    
    // Taste 1 -> LED1 aus
	if(piobaseB->PIO_PDSR&KEY2)
	{
		piobaseB->PIO_CODR = LED1;
	}
	aicbase->AIC_EOICR = piobaseB->PIO_ISR;
}

int main(void)
{
	unsigned int i;

	aicbase->AIC_IDCR = 1 << 14; // Interrupt PIOB ausschalten
	aicbase->AIC_ICCR = 1 << 14; // Interrupt PIOB löschen
	aicbase->AIC_SVR[14] = (unsigned int)irq_handler;
	aicbase->AIC_SMR[14] = 0x7; // Priorität
	aicbase->AIC_IECR = 1 << 14;// Interrupt PIOB einschalten

	piobaseB->PIO_IER = KEY1 | KEY2; // Interrupt innerhalb PIOB erlauben für Key1 & 2

	while( 1 )
	{
		//aufgabe 3
		piobaseB->PIO_CODR = LED2; // LED2 aus
		for(i = 0; i < 3; i++); // i müsste ~500000 sein bei 12 MHz
		piobaseB->PIO_SODR = LED2; // LED2 an
		for(i = 0; i < 3; i++); // i müsste ~500000 sein bei 12 MHz
	} 
	aicbase->AIC_IDCR = 1 << 14; // Interrupt PIOB ausschalten
	aicbase->AIC_ICCR = 1 << 14; // Interrupt PIOB löschen
	
	return 0;
}
