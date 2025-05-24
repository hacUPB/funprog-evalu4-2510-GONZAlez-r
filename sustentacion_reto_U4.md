1. Análisis del Problema:

El objetivo principal  era desarrollar un codigo en lenguaje C para manejar un archivos de texto, para este reto se pidieron algunos objetivos entre estos estan 


  leer el archivo. 
 
 analizar la estadísticas de palabras y vocales.
 
  transformar y reemplazar texto.
  
  guardar resultados.
  

2. Estrategia de Solución:

El código es coordinado por medio de la rama main la cual controla el el programa por medio de un menú interactivo. Cada tarea se delega a una función específica:

main(): Dirige la ejecución yel programa para el  usuario.

cargarArchivo(): Carga el texto desde un archivo a memoria.

mostrarEstadisticas(): Calcula y muestra datos como caracteres y palabras.

contarVocales(): Cuenta la cantidad de vocales.

reemplazarPalabra(): Busca y sustituye texto, manejando la memoria.

guardarResultados(): Guarda el texto actual en un archivo.



3. Tabla de Variables  (main):

Variable	***** ****************Tipo	***** ********************************Rol
nombreArchivoEntrada******	****char[MAX_NOMBRE_ARCHIVO]	************Entrada: Nombre del archivo a cargar.
textoCargado	******************char**********	**********************Intermedia: Puntero al texto en memoria.
opcion	************************int*****************	********************Entrada: Opción del menú elegida.



mostrarEstadisticas(const char* texto)

Variable*****************	Tipo	*************************Rol
texto	const *************char*	*************************Entrada: Texto a analizar.
caracteres	*************int	***************************Salida: Conteo de caracteres (sin \n).
palabras	***************int	***************************Salida: Conteo de palabras.
espacios	***************int	***************************Salida: Conteo de espacios en blanco.
lineas	*****************int	***************************salida: Conteo de líneas.
enPalabra	***************int	***************************Intermedia: Bandera para conteo de palabras.
i	***********************int	***************************Intermedia: Índice del bucle.
c	***********************char	***************************Intermedia: Carácter actual.

Función: contarVocales(const char* texto)

Variable	***********Tipo	*********Rol
texto	const *********char*	*******Entrada: Texto a analizar.
vocales	*************int[5]	*******Salida: Arreglo con conteo de a, e, i, o, u.
i	*******************int***********	Intermedia: Índice del bucle.
c	*******************char	*********Intermedia: Carácter actual (minúscula).



4. Pseudocódigo (Ejemplo main):

INICIO main
  SOLICITAR Y CARGAR ARCHIVO
  SI ERROR, SALIR

  HACER:
    MOSTRAR MENU (Estadísticas, Vocales, Reemplazar, Guardar, Salir)
    SOLICITAR OPCION
    SEGUN OPCION:
      CASO 1: LLAMAR mostrarEstadisticas()
      CASO 2: LLAMAR contarVocales()
      CASO 3: textoCargado = LLAMAR reemplazarPalabra(textoCargado)
      CASO 4: SOLICITAR NOMBRE SALIDA; LLAMAR guardarResultados()
      CASO 5: SALIR
  MIENTRAS OPCION NO SEA 5

  LIBERAR MEMORIA DE textoCargado
FIN main


5. Lenguaje:
Para este codigo se utilizo un  lengua mas tecnico para evitar ambiguedades:
 memoria dinámica, punteros, algoritmos de manipulación de cadena de textos, etc.