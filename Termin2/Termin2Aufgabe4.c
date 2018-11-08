// Loesung zu Termin2
// Aufgabe 4
// Namen: __________; ___________
// Matr.: __________; ___________
// vom :  __________
// 

#include "../h/pmc.h"
#include "../h/pio.h"
#include "../h/aic.h"

void taste_irq_handler (void) __attribute__ ((interrupt));

void taste_irq_handler (void)
{

}

int main(void)
{
	StructAIC* aicbase = AIC_BASE; // Basisadresse AIC
	aicbase->AIC_IDCR = 1; // Interrupt PIOB ausschalten
	aicbase->AIC_ICCR = 1; // Interrupt PIOB löschen
	aicbase->AIC_SVR[1] = (unsigned int)irq_handler;
	aicbase->AIC_SMR[1] = 0x7; // Priorität
	aicbase->AIC_IECR = 1;// Interrupt PIOB einschalten
	piobaseB->PIO_IER = ...; // Interrupt innerhalb PIOB erlauben
	while( 1 ); // Endlosschleife
	aicbase->AIC_IDCR = 1 << 14; // Interrupt PIOB ausschalten
	aicbase->AIC_ICCR = 1 << 14; // Interrupt PIOB löschen
	
	return 0;
}
