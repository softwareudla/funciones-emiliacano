#include <stdio.h>
#include <string.h>
#include "productos.h"

int main() {
    char productos[10][30];
    float precios[10];
    char nombre[30];
    int cantidad, opc;
    int ingresado = 0;

    do {
        printf("¿Cuántos productos quieres ingresar? (1 a 10): ");
        int val = scanf("%d", &cantidad);
        if (val != 1 || cantidad < 1 || cantidad > 10) {
            printf("Error: Ingresa un número entre 1 y 10.\n");
            while (getchar() != '\n');
        }
    } while (cantidad < 1 || cantidad > 10);

    do {
        opc = menu();

        switch (opc) {
            case 1:
                Ingreso(productos, precios, cantidad);
                ingresado = 1;
                break;
            case 2:
                if (ingresado)
                    printf("Total del inventario: %.2f\n", InventarioPT(precios, cantidad));
                else
                    printf("Primero debes ingresar productos.\n");
                break;
            case 3:
                if (ingresado)
                    printf("Precio promedio: %.2f\n", PPromedio(precios, cantidad));
                else
                    printf("Primero debes ingresar productos.\n");
                break;
            case 4:
                if (ingresado)
                    ProductoCaro(precios, productos, cantidad);
                else
                    printf("Primero debes ingresar productos.\n");
                break;
            case 5:
                if (ingresado)
                    ProductoBarato(precios, productos, cantidad);
                else
                    printf("Primero debes ingresar productos.\n");
                break;
            case 6:
                if (ingresado)
                    Mostrar(productos, precios, cantidad, nombre);
                else
                    printf("Primero debes ingresar productos.\n");
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }

    } while (opc != 7);

    return 0;
}
