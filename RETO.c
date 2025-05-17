#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* cargar_archivo(const char* nombre) {
    FILE* f = fopen(nombre, "r");
    if (!f) { perror("Error al abrir"); return NULL; }
    fseek(f, 0, SEEK_END);
    long tam = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* cont = malloc(tam + 1);
    if (!cont) { perror("Error de memoria"); fclose(f); return NULL; }
    fread(cont, 1, tam, f);
    cont[tam] = '\0';
    fclose(f);
    return cont;
}

void calcular_estadisticas(const char* texto, int* tc, int* tp, int* te, int* tl, int fv[]) {
    *tc = *tp = *te = *tl = 0;
    int en_palabra = 0;
    for (int i = 0; texto[i]; i++) {
        if (texto[i] != '\n') (*tc)++;
        if (isspace(texto[i])) { if (texto[i] == ' ') (*te)++; en_palabra = 0; if (texto[i] == '\n') (*tl)++; }
        else if (!en_palabra) { (*tp)++; en_palabra = 1; }
        char c = tolower(texto[i]);
        if (c == 'a') fv[0]++; else if (c == 'e') fv[1]++; else if (c == 'i') fv[2]++; else if (c == 'o') fv[3]++; else if (c == 'u') fv[4]++;
    }
}

char* reemplazar_palabra(const char* texto, const char* buscar, const char* reemplazar) {
    char* res = NULL;
    int i, cont = 0, lb = strlen(buscar), lr = strlen(reemplazar);
    for (i = 0; texto[i]; i++) if (strstr(&texto[i], buscar) == &texto[i]) { cont++; i += lb - 1; }
    res = malloc(i + cont * (lr - lb) + 1);
    if (!res) return NULL;
    i = 0;
    while (*texto) {
        if (strstr(texto, buscar) == texto) { strcpy(&res[i], reemplazar); i += lr; texto += lb; }
        else res[i++] = *texto++;
    }
    res[i] = '\0';
    return res;
}

void guardar_resultados(const char* nombre, int tc, int tp, int te, int tl, int fv[], const char* texto_mod) {
    FILE* f = fopen(nombre, "w");
    if (f) {
        fprintf(f, "Estadísticas:\nTotal caracteres (sin \\n): %d\nTotal palabras: %d\nTotal espacios: %d\nTotal líneas: %d\n\nFrecuencia vocales (a,e,i,o,u): %d %d %d %d %d\n", tc, tp, te, tl, fv[0], fv[1], fv[2], fv[3], fv[4]);
        if (texto_mod) fprintf(f, "\nTexto modificado:\n%s\n", texto_mod);
        fclose(f);
        printf("Resultados guardados en '%s'\n", nombre);
    } else perror("Error al guardar");
}

int main() {
    char nom_arch[100], buscar[100], reemplazar[100], nom_salida[100], opcion;
    char *contenido = NULL, *texto_modificado = NULL;
    int tc, tp, te, tl, fv[5] = {0};

    printf("Analizador de texto simplificado.\n");
    printf("Nombre del archivo .txt: ");
    scanf("%99s", nom_arch); getchar();

    contenido = cargar_archivo(nom_arch);
    if (!contenido) return 1;

    do {
        printf("\nOpciones:\n1. Mostrar estadísticas\n2. Reemplazar palabra\n3. Guardar resultados\n4. Salir\nSeleccione: ");
        scanf("%c", &opcion); getchar();

        switch (opcion) {
            case '1':
                calcular_estadisticas(contenido, &tc, &tp, &te, &tl, fv);
                printf("\nEstadísticas:\nCaracteres: %d, Palabras: %d, Espacios: %d, Líneas: %d\nFrecuencia vocales (a,e,i,o,u): %d %d %d %d %d\n", tc, tp, te, tl, fv[0], fv[1], fv[2], fv[3], fv[4]);
                break;
            case '2':
                printf("Palabra a buscar: "); scanf("%99s", buscar); getchar();
                printf("Palabra para reemplazar: "); scanf("%99s", reemplazar); getchar();
                char* nuevo_texto = reemplazar_palabra(contenido, buscar, reemplazar);
                if (nuevo_texto) { if (texto_modificado) free(texto_modificado); texto_modificado = nuevo_texto; printf("Reemplazo hecho.\n"); }
                else printf("Error al reemplazar.\n");
                break;
            case '3':
                printf("Nombre para guardar el archivo: "); scanf("%99s", nom_salida); getchar();
                calcular_estadisticas(contenido, &tc, &tp, &te, &tl, fv);
                guardar_resultados(nom_salida, tc, tp, te, tl, fv, texto_modificado);
                break;
            case '4':
                printf("Saliendo.\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != '4');

    free(contenido);
    if (texto_modificado) free(texto_modificado);

    return 0;
}