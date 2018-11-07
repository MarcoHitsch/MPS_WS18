// Loesung zu Termin2
// Aufgabe 1
// von:
// vom: 
// 

#include "../h/pmc.h"
#include "../h/pio.h"

int main(void)
{
  StructPMC* pmcbase = PMC_BASE;	// Basisadresse des PMC
  StructPIO* piobaseB = PIOB_BASE;	// Basisadresse PIOB
  
  piobaseB->PIO_PER = ALL_LEDS; /* PIO Enable Register */
  piobaseB->PIO_OER = ALL_LEDS; /* Output Enable Register */
  
  unsigned int i;

  while(1)
  {
    // Alle LEDs
    // piobaseB->PIO_CODR = ALL_LEDS;
    // piobaseB->PIO_SODR = ALL_LEDS;

    
    // // Taste 1 -> LED1 an
    // if(piobaseB->PIO_PDSR&KEY1) 
		// {
    //     piobaseB->PIO_SODR = LED1; 
		// }
    
    // // Taste 1 -> LED1 aus
		// if(piobaseB->PIO_PDSR&KEY2)
		// {
		// 	  piobaseB->PIO_CODR = LED1;
    // }
    
    // Blinken
    piobaseB->PIO_CODR = LED2; // LED2 aus
		for(i = 0; i < 3; i++); // i müsste ~500000 sein bei 12 MHz
		piobaseB->PIO_SODR = LED2; // LED2 an
		for(i = 0; i < 3; i++); // i müsste ~500000 sein bei 12 MHz
  }
    
  return 0;
}
