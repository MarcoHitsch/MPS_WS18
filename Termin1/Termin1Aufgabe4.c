// Loesung zu Termin1
// Aufgabe 4
// Namen: ___________; ____________ 
// Matr.: ___________; ____________
// vom:   ___________

int globalOne = 1;
int globalTwo = 2;

#define LED1            (1<<8)         /* LED 1 (linke LED) */
#define LED2            (1<<9)         /* LED 2 */
#define LED3           (1<<10)         /* LED 3 */
#define LED4           (1<<11)         /* LED 4 */
#define LED5           (1<<12)         /* LED 5 */
#define LED6           (1<<13)         /* LED 6 */
#define LED7           (1<<14)         /* LED 7 */
#define LED8           (1<<15)         /* LED 8 */
#define ALL_LEDS       (LED1|LED2|LED3|LED4|LED5|LED6|LED7|LED8)

int addition(int a, int b, int c){
	return a+b+c;
}

int main (void)
{



	int localOne = 1;
	int localTwo = 2;

	globalOne = localTwo;
	localTwo = globalTwo;

	addition(localOne, localTwo, globalOne)
	
	return (0);
}
