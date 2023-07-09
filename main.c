#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define N 3 // Tamaño de la matriz (3x3)

void generarMatrizMagica(int matriz[N][N]) {
    int i, j;
    int contador = 1;

    // Inicializar la matriz con ceros
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matriz[i][j] = 0;
        }
    }

    // Colocar los números en la matriz
    i = 0;
    j = N / 2;
    while (contador <= N * N) {
        matriz[i][j] = contador;
        contador++;

        i--;
        j++;
        if (i < 0 && j == N) {
            i = 1;
            j = N - 1;
        }
        else if (i < 0) {
            i = N - 1;
        }
        else if (j == N) {
            j = 0;
        }
        else if (matriz[i][j] != 0) {
            i = i + 2;
            j = j - 1;
        }
    }
}

void imprimirMatriz(int matriz[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Agregar un salto de línea adicional al final
}


//Factores Primos
void factoresPrimos(int numero) {
    int i;
    int potencia;
    int factores[100];  // Array para almacenar los factores primos
    int exponentes[100];  // Array para almacenar los exponentes de los factores primos
    int num_factors = 0;  // Número de factores primos encontrados hasta ahora

    // For para buscar el numero de factores primos del numero ingresado
    for (i = 2; i <= sqrt(numero); i++) {
        potencia = 0;
        while (numero % i == 0) {
            potencia++;
            numero /= i;
        }
        if (potencia > 0) {
            factores[num_factors] = i;
            exponentes[num_factors] = potencia;
            num_factors++;
        }
    }

    // If n is a prime number greater than 2
    if (numero > 2) {
        factores[num_factors] = numero;
        exponentes[num_factors] = 1;
        num_factors++;
    }

    // Ordena los factores primos de mayor a menor
    for (i = 0; i < num_factors - 1; i++) {
        for (int j = i + 1; j < num_factors; j++) {
            if (factores[i] < factores[j]) {
                int temp = factores[i];
                factores[i] = factores[j];
                factores[j] = temp;
                temp = exponentes[i];
                exponentes[i] = exponentes[j];
                exponentes[j] = temp;
            }
        }
    }

    // Imprime la factorización de primos en formato potencia
    for (i = 0; i < num_factors; i++) {
        printf("%d^%d ", factores[i], exponentes[i]);
    }
    printf("\n");
}

int aux_factoresPrimos() {

    int n;
    //Le pedimos al usuario que ingrese un numero
    printf("Ingrese un numero... : ");
    //capturamos el numero ingresado
    scanf("%d", &n);
    printf("la descomposicion del numero en potencias de sus factores primos %d es: ", n);
    factoresPrimos(n);

    return 0;

}




int NumeroMagico(int number){
    int ac, c, r, aux;
    while (c <= 9) {
        aux = number;
        while (aux > 0) {
            r = aux % 10;
            if (r == c) {
                ac = (ac * 10) + r;
            }
            aux = (aux - r) / 10;
        }
        c = c + 1;
    }
    int menor=ac;
    int invert=0;
    while(ac>0){
        invert=(invert *10)+ (ac%10);
        ac = ac/10;

    }
    int mayor=invert;

    int resta=mayor-menor;
    if(resta==number){
        return 1;
    }else{
        return 0;
    }

}



//Numeros Romanos
int romanToInt(char *s) {
    int result = 0;
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                result -= 1;
            } else {
                result += 1;
            }
        } else if (s[i] == 'V') {
            result += 5;
        } else if (s[i] == 'X') {
            if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                result -= 10;
            } else {
                result += 10;
            }
        } else if (s[i] == 'L') {
            result += 50;
        } else if (s[i] == 'C') {
            if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                result -= 100;
            } else {
                result += 100;
            }
        } else if (s[i] == 'D') {
            result += 500;
        } else if (s[i] == 'M') {
            result += 1000;
        } else {
            return -1;  // dato invalido
        }
    }
    return result;
}

void aux_romanToInt() {
    char roman[16];
    printf("Ingrese el numero romano que desee convertir... : ");
    scanf("%s", roman); //se captura el dato ingresado
    int result = romanToInt(roman); //se envia el resultado al metodo de conversion
    if (result == -1) {
        printf("Null\n");
    } else {
        printf("%d\n", result);
    }
}






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

void Date (char date[10]) {


    if (date[2] == '/' && date[5] == '/'&& date[9] !=
                                           '\0'&& date[8] !=
                                                  '\0'&&date[7] !=
                                                        '\0'&&date[6] !=
                                                              '\0') {
        char mes;
        char dia1=date[0];
        char dia2=date[1];
        char mes1=date[3];
        char mes2=date[4];
        char año1=date[6];
        char año2=date[7];
        char año3=date[8];
        char año4=date[9];


        if ( dia1=='0' || dia1=='1' ||dia1=='2'  ) {

            if(mes1=='0' && mes2=='1'){
                printf("%c%c de Enero de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }else if(mes1=='0' && mes2=='2'){
                printf("%c%c de Febrero de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='3'){
                printf("%c%c de Marzo de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='4'){
                printf("%c%c de Abril de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='5'){
                printf("%c%c de Mayo de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='6'){
                printf("%c%c de Junio de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='7'){
                printf("%c%c de Julio de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='7'){
                printf("%c%c de Julio de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='7'){
                printf("%c%c de Julio de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='8'){
                printf("%c%c de Agosto de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='0' && mes2=='9'){
                printf("%c%c de Septiembre de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='1' && mes2=='0'){
                printf("%c%c de Octubre de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            } else if(mes1=='1' && mes2=='1'){
                printf("%c%c de Noviembre de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }
            else if(mes1=='1' && mes2=='2'){
                printf("%c%c de Diciembre de %c%c%c%c",dia1,dia2,año1,año2,año3,año4);
            }

            else {
                printf("El mes no es valido");
            }


        } else {
            printf("El dia no es valido");
        }
    }
    else{
        printf("La fecha  no es correcta por favor ingresera con el formato=01/12/2022");
    }



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
                aux_romanToInt();
                break;
            case 2:
                printf(".......Factores Primos.......\n");
                aux_factoresPrimos();
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
                printf("-------Numeros Magico-----");
                printf("Ingrese el numero \n ");
                scanf("%d",&num);
                printf("El numero %d %s",num,  NumeroMagico(num)?"es magico":"No es magico\n");
                break;
            case 6:
                printf(".......Fechas.......\n");
                printf("Ingrese la fecha de la siguiente forma 02/12/2022 \n ");
                char date[10];
                scanf("%s", &date);
                Date(date);
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
                int matriz[N][N];
                int i, j;

                printf("Ingrese los numeros para la matriz magica:\n");

                // Solicitar al usuario los numeros para la matriz
                for (i = 0; i < N; i++) {
                    for (j = 0; j < N; j++) {
                        printf("Ingrese el numero en la posicion [%d][%d]: ", i, j);
                        scanf("%d", &matriz[i][j]);
                    }
                }

                printf("\nMatriz ingresada:\n");
                imprimirMatriz(matriz);

                printf("\nGenerando matriz magica...\n\n");

                generarMatrizMagica(matriz);

                printf("Matriz magica generada:\n");
                imprimirMatriz(matriz);




                break;
            default:
                printf("\n\n Opcion digitada incorrecta\n\n\n");
        }
    } while (option != 10);

    return 0;
}
