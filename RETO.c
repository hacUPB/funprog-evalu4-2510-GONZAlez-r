#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PALABRA 50
#define MAX_NOMBRE_ARCHIVO 100

// Declaración de funciones
char* cargarArchivo(const char* nombreArchivo);
void mostrarEstadisticas(const char* texto);
void contarVocales(const char* texto);
char* reemplazarPalabra(char* textoActual);
void guardarResultados(const char* nombreArchivoSalida, const char* textoParaGuardar); // Simplificado

int main() {
    char nombreArchivoEntrada[MAX_NOMBRE_ARCHIVO];
    char nombreArchivoSalida[MAX_NOMBRE_ARCHIVO];
    char* textoCargado = NULL;
    int opcion; // Variable simplificada

    printf("--- Analizador y Editor de Texto ---\n");

    printf("Archivo a cargar: ");
    scanf("%s", nombreArchivoEntrada);
    while (getchar() != '\n'); // Limpiar buffer

    textoCargado = cargarArchivo(nombreArchivoEntrada);
    if (textoCargado == NULL) {
        printf("Error al cargar.\n");
        return 1;
    }

    do {
        printf("\n--- Menu ---\n");
        printf(" 1. Estadisticas\n");
        printf(" 2. Vocales\n");
        printf(" 3. Reemplazar\n");
        printf(" 4. Guardar\n");
        printf(" 5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n'); // Limpiar buffer

        switch (opcion) {
            case 1: mostrarEstadisticas(textoCargado); break;
            case 2: contarVocales(textoCargado); break;
            case 3:
                textoCargado = reemplazarPalabra(textoCargado);
                printf("Reemplazo listo.\n");
                break;
            case 4:
                printf("Nombre para guardar: ");
                scanf("%s", nombreArchivoSalida);
                while (getchar() != '\n'); // Limpiar buffer
                guardarResultados(nombreArchivoSalida, textoCargado); // Simplificado
                printf("Guardado en '%s'.\n", nombreArchivoSalida);
                break;
            case 5: printf("Adios.\n"); break;
            default: printf("Opcion invalida.\n"); break;
        }
    } while (opcion != 5);

    if (textoCargado != NULL) {
        free(textoCargado);
    }
    return 0;
}

// Implementación de funciones simplificadas

char* cargarArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) return NULL;

    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    rewind(archivo);

    char* buffer = (char*)malloc((tamano + 1) * sizeof(char));
    if (buffer == NULL) { fclose(archivo); return NULL; }

    fread(buffer, sizeof(char), tamano, archivo);
    buffer[tamano] = '\0';
    fclose(archivo);
    return buffer;
}

void mostrarEstadisticas(const char* texto) {
    int caracteres = 0, palabras = 0, espacios = 0, lineas = 0;
    int enPalabra = 0;

    if (texto == NULL || *texto == '\0') {
        printf("Texto vacio.\n");
        return;
    }

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (c != '\n') caracteres++;
        if (c == ' ') espacios++;
        if (c == '\n') lineas++;

        if (!isspace(c) && enPalabra == 0) {
            palabras++;
            enPalabra = 1;
        } else if (isspace(c)) {
            enPalabra = 0;
        }
    }
    if (*texto != '\0' && texto[strlen(texto) - 1] != '\n') lineas++; // Ajuste final de línea

    printf("\n--- Estadisticas ---\n");
    printf("Caracteres: %d\n", caracteres);
    printf("Palabras: %d\n", palabras);
    printf("Espacios: %d\n", espacios);
    printf("Lineas: %d\n", lineas);
}

void contarVocales(const char* texto) {
    int vocales[5] = {0}; // a, e, i, o, u

    if (texto == NULL || *texto == '\0') {
        printf("Texto sin vocales.\n");
        return;
    }

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        if (c == 'a') vocales[0]++;
        else if (c == 'e') vocales[1]++;
        else if (c == 'i') vocales[2]++;
        else if (c == 'o') vocales[3]++;
        else if (c == 'u') vocales[4]++;
    }

    printf("\n--- Vocales ---\n");
    printf("a: %d, e: %d, i: %d, o: %d, u: %d\n", vocales[0], vocales[1], vocales[2], vocales[3], vocales[4]);
}

char* reemplazarPalabra(char* textoActual) {
    char buscar[MAX_PALABRA], reemplazar[MAX_PALABRA];

    if (textoActual == NULL) return NULL;

    printf("Palabra a buscar: ");
    scanf("%s", buscar);
    while (getchar() != '\n');
    printf("Reemplazar con: ");
    scanf("%s", reemplazar);
    while (getchar() != '\n');

    char* temp = textoActual;
    int lenB = strlen(buscar);
    int lenR = strlen(reemplazar);
    int ocurrencias = 0;

    while ((temp = strstr(temp, buscar)) != NULL) {
        ocurrencias++;
        temp += lenB;
    }

    if (ocurrencias == 0) {
        printf("No se encontro '%s'.\n", buscar);
        return textoActual;
    }

    long nuevoTamano = strlen(textoActual) + ocurrencias * (lenR - lenB) + 1;
    char* nuevoTexto = (char*)malloc(nuevoTamano * sizeof(char));
    if (nuevoTexto == NULL) {
        printf("Error de memoria.\n");
        return textoActual;
    }

    char* pLectura = textoActual;
    char* pEscritura = nuevoTexto;

    while (*pLectura != '\0') {
        if (strstr(pLectura, buscar) == pLectura) {
            strcpy(pEscritura, reemplazar);
            pEscritura += lenR;
            pLectura += lenB;
        } else {
            *pEscritura++ = *pLectura++;
        }
    }
    *pEscritura = '\0';

    free(textoActual);
    return nuevoTexto;
}

void guardarResultados(const char* nombreArchivoSalida, const char* textoParaGuardar) { // Parámetros simplificados
    FILE* archivoSalida = fopen(nombreArchivoSalida, "w");
    if (archivoSalida == NULL) {
        printf("Error al abrir archivo de salida.\n");
        return;
    }

    // Simplificación: Solo se guarda el texto si es un puntero válido
    if (textoParaGuardar != NULL && *textoParaGuardar != '\0') {
        fprintf(archivoSalida, "%s\n", textoParaGuardar);
    } else {
        fprintf(archivoSalida, "Texto vacio o no modificado.\n");
    }

    fclose(archivoSalida);
}