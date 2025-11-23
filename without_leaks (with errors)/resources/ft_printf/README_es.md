# ft_printf

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Lenguaje](https://img.shields.io/badge/Lenguaje-C-brightgreen)
![Rango](https://img.shields.io/badge/Rango-01-orange)
![Puntuación](https://img.shields.io/badge/Puntuación-100%2F100-success)

## 📋 Descripción del Proyecto

`ft_printf` es una reimplementación de la función `printf()` de la biblioteca estándar de C. Este proyecto forma parte del currículo del Common Core de 42 (Rango 01) y se enfoca en comprender las funciones variádicas, el formateo de cadenas y conceptos de programación de bajo nivel.

## 🎯 Objetivos

- Implementar una función `printf` personalizada que imite el comportamiento de la original
- Manejar múltiples especificadores de formato y conversiones
- Gestionar argumentos variádicos usando `stdarg.h`
- Devolver el número de caracteres impresos
- Seguir los estándares de codificación de 42 School (Norminette)

## 🔧 Especificadores de Formato Soportados

La función `ft_printf` soporta las siguientes conversiones:

| Especificador | Descripción | Función |
|---------------|-------------|---------|
| `%c` | Carácter | `ft_printchar()` |
| `%s` | Cadena de texto | `ft_printstr()` |
| `%p` | Dirección de puntero | `ft_printptr()` |
| `%d` | Entero decimal | `ft_printnbr()` |
| `%i` | Entero | `ft_printnbr()` |
| `%u` | Decimal sin signo | `ft_printunsigned()` |
| `%x` | Hexadecimal (minúsculas) | `ft_printhexl()` |
| `%X` | Hexadecimal (mayúsculas) | `ft_printhexu()` |
| `%%` | Signo de porcentaje literal | Manejo integrado |

## 📁 Estructura del Proyecto

```
1_ft_printf/
├── ft_printf.c         # Implementación principal de printf
├── ft_printf.h         # Archivo de cabecera con prototipos
├── ft_printchar.c      # Impresión de caracteres
├── ft_printstr.c       # Impresión de cadenas
├── ft_printptr.c       # Impresión de punteros
├── ft_printnbr.c       # Impresión de enteros
├── ft_printunsigned.c  # Impresión de enteros sin signo
├── ft_printhexl.c      # Hexadecimal en minúsculas
├── ft_printhexu.c      # Hexadecimal en mayúsculas
├── Makefile           # Configuración de compilación
└── README_es.md       # Este archivo
```

## 🚀 Uso

### Compilación

```bash
# Compilar la biblioteca
make

# Limpiar archivos objeto
make clean

# Limpiar todo
make fclean

# Recompilar todo
make re
```

### Integración

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    count = ft_printf("¡Hola %s! Tienes %d años.\n", "Mundo", 42);
    ft_printf("Caracteres impresos: %d\n", count);
    
    return (0);
}
```

### Compilación con tu proyecto

```bash
gcc -Wall -Wextra -Werror tu_archivo.c libftprintf.a -o tu_programa
```

## 💡 Características Principales

- **Funciones Variádicas**: Maneja un número variable de argumentos usando `va_list`
- **Seguridad de Tipos**: Manejo adecuado de diferentes tipos de datos
- **Manejo de Errores**: Gestión robusta de errores para casos extremos
- **Eficiencia de Memoria**: Sin asignación innecesaria de memoria
- **Cumplimiento de Norminette**: Sigue los estándares de codificación de 42 School

## 🧪 Pruebas

El proyecto maneja varios casos extremos incluyendo:
- Punteros de cadena NULL
- Valores cero
- Números negativos
- Valores máximos y mínimos de enteros
- Puntero a NULL
- Múltiples especificadores de formato consecutivos

## 📈 Rendimiento

- **Complejidad Temporal**: O(n) donde n es la longitud de la cadena de formato
- **Complejidad Espacial**: O(1) - uso constante de espacio
- **Valor de Retorno**: Número de caracteres impresos (igual que el printf original)

## 🔗 Enlaces

- **Autora**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **Perfil 42**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repositorio**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 🏆 Logro

**Puntuación Final**: 100/100 ✨

---

*Este proyecto fue completado como parte del currículo de 42 School en 42 Málaga.*
