#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProductos(char productos[10][50], float precios[10], int cantidad) {
	int i = 0;
    for (i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        getchar(); 
        fgets(productos[i], 50, stdin);
        productos[i][strcspn(productos[i], "\n")] = '\0'; 

        
        int validacion;
        do {
            printf("Ingrese el precio del producto %d (valor mayor que 0 y menor o igual a 1000): ", i + 1);
            validacion = scanf("%f", &precios[i]);

            if (validacion != 1) {
                printf("Error: Debe ingresar un número válido. Intente de nuevo.\n");
                while (getchar() != '\n');  
                precios[i] = 0; 
            } else if (precios[i] <= 0 || precios[i] > 1000) {
                printf("Advertencia: El precio debe ser mayor a 0 y menor a 1000\n");
            }
        } while (validacion != 1 || precios[i] <= 0 || precios[i] > 1000);
    }
}

float calcularPrecioTotal(float precios[10], int cantidad) {
    float total = 0;
    int i = 0;
    for (i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

void encontrarProductoMasCaro(float precios[10], char productos[10][50], int cantidad) {

    float max = 0;
    int i = 0;
    for (i = 0; i < cantidad; i++)
    {
        if (precios[i]>max) {
            max=precios[i];
        }
    }
    printf("El o los productos mas caros son:\n");

    for (i = 0; i < cantidad; i++)
    {
        if (precios[i]==max) {
            printf("+%s precio:\t%.2f\n", productos[i], precios[i]);
        }
    }
}

void encontrarProductoMasBarato(float precios[10], char productos[10][50], int cantidad) {

    float min=1000;
	int i = 0;
    for (i = 0; i < cantidad; i++)
    {
        if (precios[i]<min) {
            min=precios[i];
        }
    }
    printf("El o los productos mas baratos son:\n");

    for (i = 0; i < cantidad; i++)
    {
        if (precios[i]==min) {
            printf("-%s precio:\t%.2f\n", productos[i], precios[i]);
        }
    }
}

float calcularPrecioPromedio(float precios[10], int cantidad) {
    float total = calcularPrecioTotal(precios, cantidad);
    return total / cantidad;
}

void buscarProducto(char productos[10][50], float precios[10], int cantidad, char nombre[50]) {
	int i = 0;
    for (i = 0; i < cantidad; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            printf("El precio del producto %s es: %.2f\n", productos[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado\n");
}
