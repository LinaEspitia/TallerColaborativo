#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



void deleteSpace(char *text) {
    int i = 0, j = 0;
    int len = strlen(text);
    int inSpace=0;

    while (isspace(text[i]) && i < len) i++;

    while (isspace(text[len - 1]) && len > 0) len--;

    while (i < len) {
        if (!isspace(text[i]) || (isspace(text[i]) && !isspace(text[j - 1]))) {
            text[j++] = text[i];
        }
        i++;
    }

    text[j] = '\0';
}

void enterText(){
#define MAX_LEN 100
    char text[MAX_LEN];

    printf("Ingresar un texto al que desea quitar los espacios extras: \n");
    fflush(stdin);
    fgets(text, MAX_LEN, stdin);

    deleteSpace(text);
    printf("Texto ingresado con los espacios extra borrados: %s \n", text);
}

int productPoint() {

    int vectorOne[5], vectorTwo[5];
    int aux[5];
    int result = 0;
    int lenOne, lenTwo;

    printf("\nIngrese la longitud del vector 1\n");
    scanf("%d", &lenOne);

    printf("\nIngrese la longitud del vector 2-----\n");
    scanf("%d", &lenTwo);


    if (lenOne == lenTwo) {
        printf("Agregue valores al primer vector \n");
        for (int i = 0; i < lenOne; i++)
            scanf("%d", &vectorOne[i]);
        printf("Agregue valores al segundo vector \n");
        for (int i = 0; i < lenTwo; i++)
            scanf("%d", &vectorTwo[i]);


    } else {

        printf("Null\n");
        return 0;
    }

    for (int i = 0; i < lenTwo; i++) {
        aux[i] = vectorOne[i] * vectorTwo[i];
        result += aux[i];
    }

    printf("El producto punto de los vectores es: %d \n ", result);

    return result;

}

int multiplicacionMatriz() {
    int a[15][15], b[15][15], c[15][15];
    int f1, f2, c1, c2;

    int cont, aux;
    printf("\n El numero de filas de la primera matriz debe coincidir con el numero de columnas de la segunda matriz \n");
    printf("\nPor favor agregue el numero de filas de la matriz 1 \n");
    scanf("%d", &f1);

    printf("Por favor agregue el numero de columnas de la matriz 1 \n");
    scanf("%d", &c1);

    printf("Por favor agregue el numero de filas de la matriz 2 \n ");
    scanf("%d", &f2);

    printf("Por favor agregue el numero de columnas de la matriz 2 \n");
    scanf("%d", &c2);


    if (f1 == c2) {

        for (int i = 0; i < f1; ++i) {
            for (int j = 0; j < c1; ++j) {
                a[i][j] = rand() % 9 + 1;
            }
        }

        for (int i = 0; i < f2; ++i) {
            for (int j = 0; j < c2; ++j) {
                b[i][j] = rand() % 9 + 1;
            }
        }

        for (int i = 0; i < f1; ++i) {
            for (int j = 0; j < c1; ++j) {
                for (cont = 0, aux = 0; cont < c1; ++cont) {
                    aux = aux + a[i][cont] * b[cont][j];
                }
                c[i][j] = aux;
            }
        }

        printf("\nPrimer matriz:");
        for (int i = 0; i < f1; ++i) {
            printf("\n");
            for (int j = 0; j < c1; ++j) {
                printf("\t%d", a[i][j]);
            }
        }

        printf("\n Segunda matriz:");
        for (int i = 0; i < f2; ++i) {
            printf("\n");
            for (int j = 0; j < c2; ++j) {
                printf("\t%d", b[i][j]);
            }
        }

        printf("\n Multiplicacion de matriz:\n");
        for (int i = 0; i < f1; ++i) {
            printf("\n");
            for (int j = 0; j < c2; ++j) {
                printf("\t%d", c[i][j]);
            }
        }
    } else {
        printf("Null \n");

    }
}




int numerosEgolatras(int n){
    int numeroDigitos = floor(log10(n)+1);
    char cadena [numeroDigitos + 1];

    sprintf (cadena,"%d",n);

    int suma=0;
    for(int i=0;i<numeroDigitos; i++){
        int cont = cadena[i] - '0';

        int elevado = pow(cont, numeroDigitos);
        suma=suma +elevado;
    }
    if(suma==n){
        return 1;
    }else{
        return 0;
    }


}

int option;
void *menu (){
    printf("\t.........MENU........ \n\n"
           "1. Numeros Romanos\n"
           "2. Factores Primos\n"
           "3. Borrar Espacios\n"
           "4. Numeros Egolatras \n"
           "5. Numero Magico \n"
           "6. Fechas\n"
           "7. Producto Punto\n"
           "8. Multiplicacion de Matrices\n"
           "9. Matriz Magica\n"
           "10. Salir\n\n"
           "Dijite una opcion del menu: \n");
            scanf("%i", &option);
            fflush(stdin);
}

int main() {
    do {
        menu();
        switch (option) {

            case 0:
                printf("Se esta saliendo del programa...\n");
                break;
            case 1:
                printf(".......Numeros Romanos.......\n");
                break;
            case 2:
                printf(".......Factores Primos.......\n");
                break;
            case 3:
                printf(".......Borrar Espacios.......\n");
                enterText();
                break;
            case 4:

                printf(".......Numeros Egolatras.......\n");
                printf("Por favor ingrese el numero \n ");
                int num ;
                scanf("%d", &num);
                printf("El numero %d %s",num, numerosEgolatras( num)?"es egolatra\n":"No es egolatra\n");
                break;
            case 5:
                printf(".......Numero Magico.......\n");
                break;
            case 6:
                printf(".......Fechas.......\n");
                break;
            case 7:
                printf(".......Producto Punto.......\n");
                productPoint();
                break;
            case 8:
                printf(".......Multiplicacion de Matrices.......\n");
                multiplicacionMatriz();
                printf("\n");
                break;
            case 9:
                printf(".......Matriz Magica.......\n");
                break;
            default:
                printf("\n\n Opcion digitada incorrecta\n\n\n");
        }
    } while (option != 10);

    return 0;
}
