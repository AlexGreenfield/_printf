
#include <stdio.h>
#include <limits.h>
#include "printf.h"

/*
int	main(void)
{
	char *str;

	str = "Esta es mi string";
	ft_printf("\nMy numero de caracteres es %d", ft_printf("This is a char: %c\nan string: %s\na int: %d\na unsigned int: %u\na %% symbol\na hex lower %x\na hex upper %X\na pointer %p\nand a break%", 'a', "testing string", 3891281, 2147483647, 590, 590, str));
	write(1, "\n\n", 2);
	printf("\nMy numero de caracteres es %d", printf("This is a char: %c\nan string: %s\na int: %d\na unsigned int: %u\na %% symbol\na hex lower %x\na hex upper %X\na pointer %p\nand a break", 'a', "testing string", 3891281, 2147483647, 590, 590, str));
	return (0);
}
*/

int main()
{
	int n_ft;
	int n;
	char str[5] = "hola";
	//! CARÁCTERES
	printf("---------------------------\n");
	printf("TEXTO SIN FORMATO\n");
	n_ft = ft_printf("esto es una prueba"); printf(" |FT: %d\n",n_ft);
	n = printf("esto es una prueba"); printf(" | : %d\n",n);
	printf("---------------------------\n");
	printf("CARÁCTERES\n");
	n_ft = ft_printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres: %d\n",n);

	n_ft = ft_printf("%c", 126); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%c", 126); printf(" | Carácteres: %d\n",n);

	n_ft = ft_printf("%c %c %c", '0',0,'1'); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%c %c %c", '0',0,'1'); printf(" | Carácteres: %d\n",n);

	//! STRINGS
	printf("---------------------------\n");
	printf("STRINGS\n");
	char *ptr = str;
	n_ft = ft_printf("%s",ptr); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%s",ptr); printf(" | Carácteres: %d\n",n);

	ptr = NULL;
	n_ft = ft_printf("%s",ptr); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%s",ptr); printf(" | Carácteres: %d\n",n);
	//! PUNTEROS
	printf("---------------------------\n");
	printf("PUNTEROS\n");
	char *my_ptr = NULL;
    n_ft = ft_printf("%p",my_ptr); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%p",my_ptr); printf(" | Carácteres: %d\n",n);
	my_ptr = str;
	n_ft = ft_printf("%p",my_ptr); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%p",my_ptr); printf(" | Carácteres: %d\n",n);

	//! DECIMALES CON SIGNO
	printf("---------------------------\n");
	printf("DECIMALES CON SIGNO\n");
	n_ft = ft_printf("%d",2147483647); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%d",2147483647); printf(" | Carácteres: %d\n",n);

	//! DECIMALES SIN SIGNO
	printf("---------------------------\n");
	printf("DECIMALES SIN SIGNO\n");
	n_ft = ft_printf("%u",-2147483647); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%u",-2147483647); printf(" | Carácteres: %d\n",n);
	//! ENTEROS
	printf("---------------------------\n");
	printf("ENTEROS\n");
	n_ft = ft_printf("%i",-2147483647); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("%i",-2147483647); printf(" | Carácteres: %d\n",n);
	//! HEXADECIMALES
	printf("---------------------------\n");
	printf("HEXADECIMALES\n");
	unsigned int hex = 0;
	n_ft = ft_printf("x: %x | X: %X",hex,hex); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("x: %x | X: %X",hex,hex); printf(" | Carácteres: %d\n",n);
	hex = 4294967295;
	n_ft = ft_printf("x: %x | X: %X",hex,hex); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("x: %x | X: %X",hex,hex); printf(" | Carácteres: %d\n",n);
	//! PORCENTAJES
	printf("---------------------------\n");
	printf("PORCENTAJES\n");
 	n_ft = ft_printf(" %% "); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf(" %% ");  printf(" | Carácteres: %d\n",n);

//! Diferenciador erroneo
	printf("---------------------------\n");
	printf("DIFERENCIADOR\n");
 	n_ft = ft_printf("Especificador invalido: %z", 42); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("Especificador invalido: %z", 42); printf(" | Carácteres: %d\n",n);

//! % solo al final de string
	printf("---------------------------\n");
	printf("%% al final de la string\n");
 	n_ft = ft_printf("Al final hay un %"); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("Al final hay un %"); printf(" | Carácteres: %d\n",n);

//! % en medio de una string de string
	printf("---------------------------\n");
	printf("%% en medio de una string\n");
 	n_ft = ft_printf("Al final habia un % , pero ahora una string: %s", "String aqui"); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("Al final habia un % , pero ahora una string: %s", "String aqui"); printf(" | Carácteres: %d\n",n);

//! No hay string
	printf("---------------------------\n");
	printf("String vacia\n");
 	n_ft = ft_printf(""); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf(""); printf(" | Carácteres: %d\n",n);

//! Mas argumentos que especificadores
	printf("---------------------------\n");
	printf("Especificadores de mas\n");
 	n_ft = ft_printf("Hay especificadores de mas: %s, %s", str); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("Hay especificadores de mas: %s, %s", str); printf(" | Carácteres: %d\n",n);

//! Menos argumentos que especificadores
	printf("---------------------------\n");
	printf("Especificadores de menos\n");
 	n_ft = ft_printf("Hay especificadores de menos: %s", str, "Argumento de mas"); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("Hay especificadores de menos: %s", str, "Argumento de mas"); printf(" | Carácteres: %d\n",n);

//! Espeficicador erroneo
	printf("---------------------------\n");
	printf("Especificador erroneo\n");
 	n_ft = ft_printf("Especificador erroneo: %s", 0); printf(" | Carácteres FT: %d\n",n_ft);
	n = printf("Especificador erroneo: %s", 0); printf(" | Carácteres: %d\n",n);

//! Extra test


write(1, "My ft\n", 7);

ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
write(1, "\n", 1);

ft_printf(" %x ", LONG_MAX);
write(1, "\n", 1);

ft_printf(" %x ", ULONG_MAX);
write(1, "\n", 1);

ft_printf(" %x ", 9223372036854775807LL);
write(1, "\n", 1);

ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
write(1, "\n", 1);

ft_printf(" %X ", LONG_MAX);
write(1, "\n", 1);

ft_printf(" %X ", ULONG_MAX);
write(1, "\n", 1);

ft_printf(" %X ", 9223372036854775807LL);
write(1, "\n", 1);

ft_printf(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
write(1, "\n", 1);


printf("Original printf\n");

printf(" %p %p\n", LONG_MIN, LONG_MAX);

printf(" %x\n", LONG_MAX);

printf(" %x\n", ULONG_MAX);

printf(" %x\n", 9223372036854775807LL);

printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

printf(" %X\n", LONG_MAX);

printf(" %X\n", ULONG_MAX);

printf(" %X\n", 9223372036854775807LL);

printf(" %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);




system("leaks -q a.out");
	return (0);
}
