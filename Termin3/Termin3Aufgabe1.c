// Loesung zu Termin3
// Aufgabe 1
// von:
// vom: 
// 

#include "../h/pmc.h"
#include "../h/tc.h"
#include "../h/pio.h"
#include "../h/aic.h"

StructPIO* piobaseA   = PIOA_BASE; // Basisadresse PIO A
StructPIO* piobaseB   = PIOB_BASE;		// Basisadresse PIO B
StructAIC* aicbase  = AIC_BASE;		// Basisadresse Interuptconstroller
StructTC* timerbase3  = TCB3_BASE; // Basisadressse TC Block 1
StructPMC* pmcbase	= PMC_BASE;		// Basisadresse des PMC

void taste_irq_handler (void) __attribute__ ((interrupt));

// Interruptserviceroutine f�r die Tasten SW1 und SW2
void taste_irq_handler (void)
{
// ab hier entsprechend der Aufgabestellung erg�nzen
// *************************************************
  
  if(!(piobaseB->PIO_PDSR&KEY1)) // Taste 1 gedrückt
	{
      piobaseA->PIO_PER  = (1<<PIOTIOA3); // Pumpe aus (low active)
  }

  if(!(piobaseB->PIO_PDSR&KEY2)) // Taste 2 gedrückt
	{
      piobaseA->PIO_PDR  = (1<<PIOTIOA3); // Pumpe an (low active)
  }

	aicbase->AIC_EOICR = piobaseB->PIO_ISR;	// interupt beendet
}

// Timer3 initialisieren
void Timer3_init( void )
{
	timerbase3->TC_CCR = TC_CLKDIS;	// Disable Clock
 
  // Initialize the mode of the timer 3
  timerbase3->TC_CMR =
    TC_ACPC_CLEAR_OUTPUT  |    //ACPC    : Register C clear TIOA
    TC_ACPA_SET_OUTPUT    |    //ACPA    : Register A set TIOA
    TC_WAVE               |    //WAVE    : Waveform mode
    TC_CPCTRG             |    //CPCTRG  : Register C compare trigger enable
    TC_CLKS_MCK8;           //TCCLKS  : MCKI / 8

  // Initialize the counter:
  timerbase3->TC_RA = 31250;	
  timerbase3->TC_RC = 62500;	

  // Start the timer :
  timerbase3->TC_CCR = TC_CLKEN ;	// Clock Enable
  timerbase3->TC_CCR = TC_SWTRG ;	// Software Trigger
  piobaseA->PIO_PER  = (1<<PIOTIOA3) ;	// PIO Disable (Pumpe aus)
  piobaseA->PIO_OER  = (1<<PIOTIOA3) ;	// Output enabled
  piobaseA->PIO_CODR = (1<<PIOTIOA3) ;	// Output cleared
}

int main(void)
{
  pmcbase->PMC_PCER	= 0x6200;	// Peripheral Clocks einschalten für PIOB, PIOA, TC3
  piobaseB->PIO_PER = KEY1 | KEY2; // Tasten aktivieren
  piobaseB->PIO_IER = KEY1 | KEY2; // Interupts für Tasten aktivieren
	
// ab hier entsprechend der Aufgabestellung erg�nzen
//**************************************************

  // Interupt für Tasten einstellen
  aicbase->AIC_IDCR = 1 << 14;		// Disable PIOB
  aicbase->AIC_ICCR = 1 << 14;		// Clear PIOB
  aicbase->AIC_SMR[14] = AIC_PRIOR;	// Prio für PIOB
  aicbase->AIC_SVR[14] = (unsigned int)irq_handler; // Handler eintragen
  aicbase->AIC_IECR = 0x4000;		// Enable für PIOB

  Timer3_init();

	while(1)
	{

	}
	
	return 0;
}
