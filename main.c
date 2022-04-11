#include "ft_printf.h"

int	main()
{
	char	cosa[5] = "holis";
	char	*ptr = cosa;
	ft_printf("El char a: %c\n", 'a');
	ft_printf("La string holis: %s\n", cosa);
	ft_printf("El puntero: %p\n", ptr);
	printf("Puntero oficial: %p\n", ptr);
	ft_printf("El numero decimal 12: %d\n", 12);
	ft_printf("El entero 156: %i\n", 156);
	ft_printf("El decimal sin signo 89: %u\n", 89);
	ft_printf("El decimal sin signo -56: %u\n", -56);
	printf("El hexadecimal oficial: %x\n", 125654);
	ft_printf("El hexadecimal en minus: %x\n", 125654);
	ft_printf("El hexadecimal en mayus: %X\n", 125654);
	ft_printf("El porcentaje: %%\n");
	ft_printf("\nPrueba variada del tiron:\n");

	ft_printf(" Un char a: %c\n La string holis: %s\n El puntero: %p\n El numero decimal 12: %d\n El entero 156: %i\n El decimal sin signo 89: %u\n El hexadecimal en minus y en mayus:\n - %x\n - %X\n El porcentaje: %%\n", 'a', cosa, ptr, 12, 156, 89, 125654, 125654);

	ft_printf("\nLos return:\n");
	ft_printf("El return del anterior char con un salto de linea es: %d\n", ft_printf("%c\n", 'a'));
	ft_printf("El return de la anterior string con un salto de linea es: %d\n", ft_printf("%s\n", cosa));
	ft_printf("El return del anterior puntero con un salto de linea es: %d\n", ft_printf("%p\n", ptr));
	ft_printf("El return del anterior numero decimal con un salto de linea es: %d\n", ft_printf("%d\n", -12));
	ft_printf("El return del anterior entero con un salto de linea es: %d\n", ft_printf("%i\n", 156));
	ft_printf("El return del anterior decimal sin signo con un salto de linea es: %d\n", ft_printf("%u\n", 89));
	ft_printf("El return del anterior hexadecimal minus con un salto de linea es: %d\n", ft_printf("%x\n", 125654));
	ft_printf("El return del anterior porcentaje con un salto de linea es: %d\n", ft_printf("%%\n"));

	ft_printf("Return de mezcla de cosas: %d", ft_printf("%c%%%s%%%%%c\n", 'a', cosa, 'a'));
	return (0);
}
