#include <stdio.h>

int main(void)
{
	int i;

	i = printf("1. Je suis une patapoulpinette						");
	printf("%d\n", i);
	i = printf("2. %d est un nombre décimal (base 10) avec d			", -1560000);
	printf("%d\n", i);
	i = printf("3. %i est un nombre entier avec i					", 012);
	printf("%d\n", i);
	i = printf("3. %i est un nombre entier (base 10) avec i				", 12);
	printf("%d\n", i);
	i = printf("4. La chaine de caractères retournée est : %s", "Je suis une patapoulpinette	");
	printf("%d\n", i);
	i = printf("5. J'affiche un seul caractère : %c					", 's');
	printf("%d\n", i);
	i = printf("6. J'ai mangé %u M&M's							", 5);
	printf("%d\n", i);
	i = printf("7. Voici un nombre hexadécimal en minuscule : %x			", 45);
	printf("%d\n", i);
	i = printf("8. Voici un nombre hexadécimal en majuscule : %X			", 45);
	printf("%d\n", i);
	i = printf("9. Ma capacité à réfléchir est actuellement de 1%%			");
	printf("%d\n", i);
}