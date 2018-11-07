// Loesung zu Termin1
// Aufgabe 3
// Namen: ___________; ____________ 
// Matr.: ___________; ____________
// vom:   ___________

int globalOne = 1;
int globalTwo = 2;

int main (void)
{
	int localOne = 1;
	int localTwo = 2;

	globalOne = localTwo;
	localTwo = globalTwo;
	return (0);
}
