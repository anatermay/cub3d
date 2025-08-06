El **archivo de configuración .cub** describe la escena de un juego basado en *ray-casting*. Contiene dos partes principales según el enunciado:

- La **información de configuración** contiene los elementos separados por una o más líneas vacías. Todos ellos comienzan con su identificador. Pueden aparecer en caulquier orden y con los datos separados por uno o más espacios.
    - Las **texturas** son:
        - La ruta a la textura de la pared norte.
            
            <aside>
            
            **NO ./path_to_the_texture**
            
            </aside>
            
        - La ruta a la textura de la pared sur.
            
            <aside>
            
            **SO ./path_to_the_texture**
            
            </aside>
            
        - La ruta a la textura de la pared éste.
            
            <aside>
            
            **EA  ./path_to_the_texture**
            
            </aside>
            
        - La ruta a la textura de la pared oeste.
            
            <aside>
            
            **WE  ./path_to_the_texture**
            
            </aside>
            
    - Los **colores** en formato RGB, con valores entre 0 y 2500, de:
        - El suelo.
            
            <aside>
            
            **F R,G,B**
            
            </aside>
            
        - El cielo.
            
            <aside>
            
            **C R,G,B**
            
            </aside>
            
- El **mapa** está compuesto por espacios vacíos, paredes y la posición inicial del jugador conforme a su orientación (N, S, E, W). El mapa debe estar cerrado por paredes. Además, los espacios son válidos y deben manejarse como parte del mapa. Cualquier error en el formato del mapa también debe generar un error y salir del programa.

<aside>

Si hay una configuración incorrecta a lo largo del parseo del programa, éste debe salir con un mensaje de error explícito.

**Error\n[mensaje claro]**

</aside>

Para organizar todos los datos que nos da el archivo, es necesario definir estructuras en un archivo de cabecera. En este archivo de cabecera almacenaremos las texturas, los colores y el mapa. Las estructuras deben ser claras, modulares y fáciles de usar durante el parseo y el renderizado del juego.

- Estructura para los colores RGB.
    - Red
    - Green
    - Blue
- Estructura para up-down
    - Identificador
    - ColoresRGB
- Estructura para las texturas.
    - Identificador
    - Abreviatura
    - Textura
- Estructura de posición.
- Estructura del jugador
    - Posición inicial.
    - Orientación.
- Estructura del mapa.
    - Archivo.
    - Matriz de caracteres.
    - Dimensiones del mapa [x, y]
    - Norte
    - Sur
    - Este
    - Oeste
    - Suelo
    - Cielo
- Estructura del juego.
    - Mapa
    - Jugador