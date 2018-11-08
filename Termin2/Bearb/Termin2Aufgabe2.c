// Lösung zu Termin2
// Aufgabe 2 +3
// Namen: Marcel Romagnuolo, Michael Gerster
// Matr.: 729698,726688
// vom :  22.10.13
// 

#include "../h/pmc.h"
#include "../h/pio.h"

int main(void)
{
	int zaehler;
	
	StructPMC* pmcbase = PMC_BASE; //basisadresse des pmc
	pmcbase->PMC_PCER = 0x4200; //peripheral clocks aktiv für piob; 15. register
	
	StructPIO* piobaseB = PIOB_BASE; //es wird auf header datei zugegriffen über pointer
					 //ersatz für die defines
	
	PIOB_BASE->PIO_PER = 0x318; //folgende ports werden enabled: schalter 1,2, led 1, led 2	
	piobaseB->PIO_OER = 0x300; // Output Register wird aktiviert für led 1 und 2	
	
	while(1)
	{
	
		//aufgabe 2
		if(!(piobaseB->PIO_PDSR&KEY1)) //wenn taste 1 gedrückt, wird eingeschaltet
		{
			piobaseB->PIO_CODR = 0x100;	 
		}
		
		if(!(piobaseB->PIO_PDSR&KEY2))
		{
			piobaseB->PIO_SODR = 0x100;
		}
		
		
		//aufgabe 3
		piobaseB->PIO_CODR = 0x200; //led 2 wird eingeschaltet
		for(zaehler = 200000; zaehler > 0; zaehler--); //schindet zeit
		piobaseB->PIO_SODR = 0x200; //led 2 wird ausgeschaltet
		for(zaehler = 200000; zaehler > 0; zaehler--); //schindet zeit
	}
	
	return 0;
}

