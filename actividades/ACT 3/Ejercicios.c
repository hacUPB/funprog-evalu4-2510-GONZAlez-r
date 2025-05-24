// Ejercicio 1

#include <stdio.h>
#include <ctype.h>

int contarVocales(const char *cadena) {
    int contador = 0;
    while (*cadena) {
        char c = tolower(*cadena);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
        cadena++;
    }
    return contador;
}

int main() {
    char texto[] = "Hola mundo";
    printf("Vocales: %d\n", contarVocales(texto));
    return 0;
}


// Ejercicio 2

#include <stdio.h>
#include <string.h>

void invertirCadena(const char *entrada, char *salida) {
    int len = strlen(entrada);
    for (int i = 0; i < len; i++) {
        salida[i] = entrada[len - 1 - i];
    }
    salida[len] = '\0';
}

int main() {
    char original[] = "programa";
    char invertida[100];
    invertirCadena(original, invertida);
    printf("La cadena invertida es: %s\n", invertida);
    return 0;
}

// Ejercicio 3

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int esPalindromo(const char *cadena) {
    char limpio[100], inverso[100];
    int j = 0;

    for (int i = 0; cadena[i]; i++) {
        if (isalnum(cadena[i])) {
            limpio[j++] = tolower(cadena[i]);
        }
    }
    limpio[j] = '\0';

    // Invertir
    int len = strlen(limpio);
    for (int i = 0; i < len; i++) {
        inverso[i] = limpio[len - 1 - i];
    }
    inverso[len] = '\0';

    return strcmp(limpio, inverso) == 0;
}

int main() {
    char texto[] = "Anita lava la tina";
    if (esPalindromo(texto)) {
        printf("Es palíndromo\n");
    } else {
        printf("No es palíndromo\n");
    }
    return 0;
}

// Ejercicio 4

#include <stdio.h>

void aMayusculas(char *cadena) {
    while (*cadena) {
        if (*cadena >= 'a' && *cadena <= 'z') {
            *cadena -= 32;
        }
        cadena++;
    }
}

int main() {
    char texto[] = "cadena de prueba";
    aMayusculas(texto);
    printf("Mayúsculas: %s\n", texto);
    return 0;
}


// Ejercicio 5

#include <stdio.h>

void tokenizar(const char *cadena) {
    char token[100];
    int j = 0;

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == ',' || cadena[i] == ';' || cadena[i] == ' ') {
            if (j > 0) {
                token[j] = '\0';
                printf("Token: %s\n", token);
                j = 0;
            }
        } else {
            token[j++] = cadena[i];
        }
    }
    if (j > 0) {
        token[j] = '\0';
        printf("Token: %s\n", token);
    }
}

int main() {
    char texto[] = "Hola,mundo;esto es una prueba";
    tokenizar(texto);
    return 0;
}
