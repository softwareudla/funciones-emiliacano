
#include "funciones.h"
#include <stdio.h>
#include <string.h>

int main() {
    char productos[10][50];
    float precios[10];
    int cantidad;
    float productosCaros[10];
    float max=0;
    float min=1000;

    
    do {
        printf("¿Cuántos productos quieres ingresar? (1 a 10): ");
        int validacion = scanf("%d", &cantidad);
        if (validacion != 1 || cantidad < 1 || cantidad > 10) {
            printf("Error: Solo puedes ingresar un número entero entre 1 y 10. Intenta de nuevo.\n");
            while (getchar() != '\n'); 
        }
    } while (cantidad < 1 || cantidad > 10);

    ingresarProductos(productos, precios, cantidad);

    float total = calcularPrecioTotal(precios, cantidad);
    printf("Precio total del inventario: %.2f\n", total);

    encontrarProductoMasCaro(precios,productos,cantidad);
    encontrarProductoMasBarato(precios,productos,cantidad);

    float promedio = calcularPrecioPromedio(precios, cantidad);
    printf("El precio promedio es: %.2f\n", promedio);

    char nombreProducto[50];
    printf("Ingrese el nombre del producto a buscar: ");
    getchar(); 
    fgets(nombreProducto, 50, stdin);
    nombreProducto[strcspn(nombreProducto, "\n")] = '\0'; 
    buscarProducto(productos, precios, cantidad, nombreProducto);

    printf("Presione Enter para salir...\n");
    getchar();  
  
    return 0;
}