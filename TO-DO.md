# TO-DO para el Proyecto mmsound

## Fase 1: Configuración y Estructura Básica

- [X] Define la estructura del proyecto:
    Crea un repositorio en GitHub para el proyecto.
    Configura un entorno de desarrollo en C++ (p. ej., Visual Studio Code, CLion).
    Crea los archivos fuente iniciales (main.cpp, parser.cpp, csound_generator.cpp, etc.).

- [X] Implementa la lectura básica de archivos:
    Crea una función para leer el archivo .mm línea por línea.
        `std::ifstream`
    Almacena el contenido del archivo en una estructura de datos adecuada (p. ej., un vector de strings).

- [] Establece la comunicación con Csound:
    Investiga cómo interactuar con Csound desde C++.
    Configura la conexión básica para enviar comandos a Csound.
    Crea un archivo .orc de csound de prueba.

- [] Define la estructura de datos para la música:
    Crea estructuras para representar notas, acordes, frases y la partitura completa.
    Considera el uso de clases para organizar mejor la información.
    
        - [X] Clase `Nota`: 
            Atributos (nombre, octava, duración, alteración)
            Métodos (calcular valor MIDI o Hz, calcular duración en ms)
        - [] Clase `Secuencia`:
            Atributos (vector de notas, repeticiones)
            Métodos (parsear cadena str, expandir repeticiones o stacks)
        - [] Calse `Repoductor`:
            Atributos (instancia con CSound, tempo)
            Métodos (inicializar, reproducir secuencia)   

## Fase 2: Análisis del Archivo .mm (Parser)

- [] Implementa el análisis de los parámetros iniciales:
    Extrae el tempo (T), la duración predeterminada (L) y el compás.
    Almacena estos valores en variables.

- [] Desarrolla el analizador de notas y acordes:
    Crea funciones para identificar y extraer notas individuales, acordes y duraciones.
    Implementa la lógica para manejar las alteraciones de octava (<, >).
    Implementa la logica para manejar repeticiones [].

- [] Implementa la lógica para las duraciones de las notas:
    Crea funciones para transformar los tiempos a valores que entienda csound.
    Implementa la lógica para manejar los tiempos por defecto y los especificados en las notas.

- [] Construye la estructura de datos de la partitura:
    Almacena las notas, acordes y duraciones en la estructura de datos definida en la Fase 1.

## Fase 3: Generación de Comandos para Csound

- [] Convierte la estructura de datos de la partitura en comandos de Csound:
    Crea funciones para generar comandos "i" de Csound a partir de las notas, acordes y duraciones.
    Considera el uso de plantillas de strings para facilitar la generación de comandos.

- [] Implementa la lógica para el tempo y las duraciones:
    Asegúrate de que los comandos de Csound reflejen correctamente el tempo y las duraciones de las notas.

- [] Envía los comandos a Csound:
    Utiliza la conexión establecida en la Fase 1 para enviar los comandos generados a Csound.

## Fase 4: Pruebas y Depuración

- [] Crea archivos .mm de prueba:
    Diseña archivos de prueba que cubran todos los aspectos del formato .mm.

- [] Realiza pruebas exhaustivas:
    Ejecuta el programa con los archivos de prueba y verifica que la música generada sea correcta.
    Utiliza herramientas de depuración para identificar y corregir errores.

- [] Optimiza el rendimiento:
    Identifica y corrige cuellos de botella en el rendimiento.
    Considera el uso de técnicas de optimización para mejorar la velocidad de ejecución.

## Fase 5: Documentación y Mejora

- [] Documenta el código:
    Agrega comentarios al código para explicar su funcionamiento.
    Crea un archivo README.md con instrucciones de uso y documentación del formato .mm.

- [] Considera la posibilidad de agregar funciones adicionales:
    Implementa soporte para otros elementos musicales (p. ej., dinámicas, articulaciones).
    Agrega una interfaz gráfica de usuario para facilitar la creación y edición de archivos .mm.
