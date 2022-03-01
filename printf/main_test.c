#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

/* ************************************************************************** */
/*                     TEST DE LA "VRAIE" FONCTION PRINTF                     */
/* ************************************************************************** */

/* int main(void)
{
	int		i;
	void	*p = NULL;

	i = printf("1. Je suis une patapoulpinette\n");
	printf("printf return : %d\n", i);
	i = printf("2. %d est un nombre décimal (base 10) avec d\n", -1560000);
	printf("printf return : %d\n", i);
	i = printf("3. %i est un nombre entier avec i\n", 012);
	printf("printf return : %d\n", i);
	i = printf("3. %i est un nombre entier (base 10) avec i\n", 12);
	printf("printf return : %d\n", i);
	i = printf("4. La chaine de caractères retournée est : %s\n", "Je suis une patapoulpinette");
	printf("printf return : %d\n", i);
	i = printf("5. J'affiche un seul caractère : %c\n", 's');
	printf("printf return : %d\n", i);
	i = printf("6. J'ai mangé %u M&M's\n", 5);
	printf("printf return : %d\n", i);
	i = printf("6. J'ai mangé %u M&M's\n", -5);
	printf("printf return : %d\n", i);
	i = printf("7. Voici un nombre hexadécimal en minuscule : %x\n", -45868955);
	printf("printf return : %d\n", i);
	i = printf("8. Voici un nombre hexadécimal en majuscule : %X\n", 45);
	printf("printf return : %d\n", i);
	i = printf("9. Ma capacité à réfléchir est actuellement de 1%%\n");
	printf("printf return : %d\n", i);
	i = printf("10. Ma capacité à réfléchir est actuellement de %bonjour\n");
	printf("printf return : %d\n", i);
	i = printf("10. Ma capacité à réfléchir est actuellement de 1%\n");
	printf("printf return : %d\n", i);
	i = printf("11. Voici le retour d'un pointeur : %p\n", p);
	printf("printf return : %d\n", i);
	i = printf("");
	printf("printf return : %d\n", i);
} */

/* ************************************************************************** */
/*                             TEST DE MON PRINTF                             */
/* ************************************************************************** */

int main(void)
{
	ft_printf("");
	ft_printf("1. Je suis une patapoulpinette\n");
	ft_printf("2. Je suis une patapoulpinett%c", 'e');
	ft_printf("\n3. Je suis une patapoulpin%ctte\n", 'e');
	ft_printf("4. Je suis un%c patapoulpin%ctte\n", 'e', 'e');
	ft_printf("%s", "5. Je suis une patapoulpinette\n");
	ft_printf("%d. Je suis une patapoulpinette\n", 6);
	return (0);
}

/* ************************************************************************** */
/*        EXEMPLE D'UTILISATION DE VA_START, VA_ARG, VA_COPY ET VA_END        */
/* ************************************************************************** */

// ------------------------------- Exemple 1 -------------------------------- //

/* // Variadic function to add numbers
int AddNumbers(int n, ...)
{
	int Sum = 0;
	int i = 0;
	va_list ptr;// Declaring pointer to the argument list

	va_start(ptr, n);// Initializing argument to the list pointer
	while(i < n)
	{
		Sum += va_arg(ptr, int);// Accessing current variable and pointing to next one
		i++;
	}
	va_end(ptr);// Ending argument list traversal
	return Sum;
}

int main()
{
	printf("\n Variadic functions: \n");
	// Variable number of arguments
	printf("\n 1 + 2 = %d ", AddNumbers(2, 1, 2));
	printf("\n 3 + 4 + 5 = %d ", AddNumbers(3, 3, 4, 5));
	printf("\n 6 + 7 + 8 + 9 = %d ", AddNumbers(4, 6, 7, 8, 9));
	printf("\n\n");
	return 0;
} */

// ------------------------------- Exemple 2 -------------------------------- //

/* // Variadic function to add numbers
int LargestNumber(int n, ...)
{
	int min = 0;
	int i = 0;
	int temp;
	va_list ptr;// Declaring pointer to the argument list

	va_start(ptr, n);// Initializing argument to the list pointer

	while (i < n)
	{
		temp = va_arg(ptr, int);// Accessing current variable and pointing to next
		min = temp > min ? temp : min;
		i++;
	}
	va_end(ptr);// End of argument list traversal
	return min;
}

int main()
{
	printf("\n\n Variadic functions: \n");
	// Variable number of arguments
	printf("\n %d ", LargestNumber(2, 1, 2));
	printf("\n %d ", LargestNumber(3, 8, 4, 1));
	printf("\n %d ", LargestNumber(4, 5, 2, 12, 9));
	printf("\n");
	return 0;
} */

// ------------------------------- Exemple 3 -------------------------------- //

/* void courses(char* arg0, ...) 
{
	va_list ap;

	int i, nb_args;
	char* cur_arg = arg0;

	// On n'est jamais trop prudent
	if (arg0 == NULL) {
		printf("Je n'ai rien à acheter\n");
		return;
	}

	// Commencer à parcourir la liste des paramètres.  La liste s'appelle ap
	// et le dernier argument fixe est arg0. 
	va_start(ap, arg0);

	// Ajouter 1 à nb_args jusqu'à ce qu'on lise un argument de type char*
	// égal à NULL.
	// Cette boucle compte le nombre d'arguments y compris le NULL, mais comme
	// on "oublie" de compter arg0, pas besoin de soustraire 1 du résultat 
	// final.
	for (
		nb_args = 0; 
		cur_arg != NULL;
		nb_args++, cur_arg = va_arg(ap, char*)
	); 

	// On a fini (pour cette fois)
	va_end(ap);

	printf("J'ai %d %s à acheter :\n", nb_args, 
			(nb_args > 1) ? "choses" : "chose");

	// Reparcourir à nouveau la liste de paramètres et les afficher un à un.
	// Remarquez que la boucle commence à 1 car le premier argument lu avec va_arg()
	// est en réalité le *deuxième* ingrédient de notre liste de courses.
	printf("- %s\n", arg0);
	va_start(ap, arg0);
	for (i = 1; i < nb_args; i++) {
		printf("- %s\n", va_arg(ap, char*));
	}
	printf("\n");

	va_end(ap);
}

int main(int argc, char* argv[])
{
	courses(NULL);
	courses("oeufs", NULL);
	courses("oeufs", "chocolat", NULL);
	courses("oeufs", "chocolat", "sucre", "farine", NULL);
	return 0;
} */