#include <stdio.h>
#include <string.h>
#include "productos.h"

int menu() {
    int opc;
    printf("1. Ingrese el nombre y precio del producto\n");
    printf("2. Ver precio total del inventario\n");
    printf("3. Ver promedio precios de todos los productos\n");
    printf("4. Ver producto más caro\n");
    printf("5. Ver producto más barato\n");
    printf("6. Buscar información del producto\n");
    printf("7. Salir del programa\n");
    printf(">> ");
    scanf("%d", &opc);
    return opc;
}

void Ingreso(char productos[10][30], float precios[10], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        int valido = 0;

        // Validar nombre
        do {
            int tieneNumero = 0;
            int soloEspacios = 1;

            printf("Ingrese el nombre del producto %d: ", i + 1);
            fflush(stdin);
            fgets(productos[i], 30, stdin);

            // Quitar salto de línea
            int len = 0;
            while (productos[i][len] != '\0') {
                if (productos[i][len] == '\n') {
                    productos[i][len] = '\0';
                    break;
                }
                len++;
            }

            // Verificar si hay números o solo espacios
            for (int j = 0; productos[i][j] != '\0'; j++) {
                if (productos[i][j] >= '0' && productos[i][j] <= '9') {
                    tieneNumero = 1;
                }
                if (productos[i][j] != ' ') {
                    soloEspacios = 0;
                }
            }

            if (tieneNumero || soloEspacios || len == 0) {
                printf("Error: No se permiten números ni nombres vacíos. Intente de nuevo.\n");
            } else {
                valido = 1;
            }
        } while (!valido);

        // Validar precio
        int validacion;
        do {
            printf("Ingrese el precio del producto %d: ", i + 1);
            validacion = scanf("%f", &precios[i]);
            if (validacion != 1) {
                printf("Error: Debe ingresar un número.\n");
                while (getchar() != '\n');
                validacion = 0;
            } else if (precios[i] <= 0 || precios[i] > 1000) {
                printf("El precio debe ser mayor a 0 y menor a 1000.\n");
                validacion = 0;
            }
        } while (!validacion);
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
    float total = InventarioPT(precios, cantidad);   
    return total / cantidad;
}

void ProductoCaro(float precios[10], char productos[10][30], int cantidad) {
    float max = 0;
    for (int i = 0; i < cantidad; i++) {
        if (precios[i] > max) {
            max = precios[i];
        }
    }
    printf("El/Los productos más caros son:\n");
    for (int i = 0; i < cantidad; i++) {
        if (precios[i] == max) {
            printf(">> %s con precio: %.2f\n", productos[i], precios[i]);
        }
    }
}

void ProductoBarato(float precios[10], char productos[10][30], int cantidad) {
    float min = 1000;
    for (int i = 0; i < cantidad; i++) {
        if (precios[i] < min) {
            min = precios[i];
        }
    }
    printf("El/Los productos más baratos son:\n");
    for (int i = 0; i < cantidad; i++) {
        if (precios[i] == min) {
            printf(">> %s con precio: %.2f\n", productos[i], precios[i]);
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
            printf("El precio del producto %s es: %.2f\n", productos[i], precios[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

