#include <stdio.h>
#include <string.h>
#include "productos.h"

int menu() {
    int opc;
    printf("\n--- MENU ---\n");
    printf("1. Ingresar productos\n");
    printf("2. Ver total del inventario\n");
    printf("3. Ver precio promedio\n");
    printf("4. Ver producto más caro\n");
    printf("5. Ver producto más barato\n");
    printf("6. Buscar producto\n");
    printf("7. Salir\n");
    printf(">> ");
    scanf("%d", &opc);
    return opc;
}

void Ingreso(char productos[10][30], float precios[10], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        int nombreValido = 0;

        while (!nombreValido) {
            int tieneNumero = 0;

            printf("Ingrese el nombre del producto %d: ", i + 1);
            fflush(stdin);
            fgets(productos[i], 30, stdin);

          
            int j = 0;
            while (productos[i][j] != '\0') {
                if (productos[i][j] == '\n') {
                    productos[i][j] = '\0';
                }
                j++;
            }

     
            for (j = 0; productos[i][j] != '\0'; j++) {
                if (productos[i][j] >= '0' && productos[i][j] <= '9') {
                    tieneNumero = 1;
                }
            }

            if (productos[i][0] == '\0' || tieneNumero) {
                printf("Error: No se permiten números ni dejar vacío. Intente de nuevo.\n");
            } else {
                nombreValido = 1;
            }
        }

        int valido = 0;
        while (!valido) {
            printf("Ingrese el precio del producto %d: ", i + 1);
            if (scanf("%f", &precios[i]) != 1) {
                printf("Error: Debe ingresar un número.\n");
                while (getchar() != '\n');
            } else if (precios[i] <= 0 || precios[i] > 1000) {
                printf("Error: El precio debe ser mayor a 0 y menor o igual a 1000.\n");
            } else {
                valido = 1;
            }
        }
    }
}

float InventarioPT(float precios[10], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

float PPromedio(float precios[10], int cantidad) {
    return InventarioPT(precios, cantidad) / cantidad;
}

void ProductoCaro(float precios[10], char productos[10][30], int cantidad) {
    float max = precios[0];
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > max) {
            max = precios[i];
        }
    }
    printf("Producto(s) más caro(s):\n");
    for (int i = 0; i < cantidad; i++) {
        if (precios[i] == max) {
            printf(">> %s - %.2f\n", productos[i], precios[i]);
        }
    }
}

void ProductoBarato(float precios[10], char productos[10][30], int cantidad) {
    float min = precios[0];
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < min) {
            min = precios[i];
        }
    }
    printf("Producto(s) más barato(s):\n");
    for (int i = 0; i < cantidad; i++) {
        if (precios[i] == min) {
            printf(">> %s - %.2f\n", productos[i], precios[i]);
        }
    }
}

void Mostrar(char productos[10][30], float precios[10], int cantidad, char nombre[30]) {
    printf("Ingrese el nombre del producto a buscar: ");
    fflush(stdin);
    fgets(nombre, 30, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            printf("El precio de %s es: %.2f\n", productos[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}
