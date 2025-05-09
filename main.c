#include <stdio.h>
#include <string.h>
#include "productos.h"

int main() {
    char productos[10][30];
    char nombre[30];
    float precios[10];
    int opc, cantidad, ingresov = 0;

    do {
        printf("¿Cuántos productos quieres ingresar? (1 a 10): ");
        int validacion = scanf("%d", &cantidad);
        if (validacion != 1 || cantidad < 1 || cantidad > 10) {
            printf("Error: Solo puedes ingresar un número entero entre 1 y 10. Intenta de nuevo.\n");
            while (getchar() != '\n');
        }
    } while (cantidad < 1 || cantidad > 10);

    do {
        opc = menu();

        switch (opc) {
            case 1:
                Ingreso(productos, precios, cantidad);
                ingresov = 1;
                break;

            case 2:
                if (ingresov) {
                    printf("Total del inventario: %.2f\n", InventarioPT(precios, cantidad));
                } else {
                    printf("Primero ingrese los productos.\n");
                }
                break;

            case 3:
                if (ingresov) {
                    printf("Precio promedio: %.2f\n", PPromedio(precios, cantidad));
                } else {
                    printf("Primero ingrese los productos.\n");
                }
                break;

            case 4:
                if (ingresov) {
                    ProductoCaro(precios, productos, cantidad);
                } else {
                    printf("Primero ingrese los productos.\n");
                }
                break;

            case 5:
                if (ingresov) {
                    ProductoBarato(precios, productos, cantidad);
                } else {
                    printf("Primero ingrese los productos.\n");
                }
                break;

            case 6:
                if (ingresov) {
                    Mostrar(productos, precios, cantidad, nombre);
                } else {
                    printf("Primero ingrese los productos.\n");
                }
                break;

            case 7:
                printf("Saliendo del programa...\n");
                return 0;

            default:
                printf("Opción no válida. Intente otra vez.\n");
        }

    } while (opc != 7);

    return 0;
}
