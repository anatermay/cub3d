# cub3d

> Proyecto de la escuela 42 inspirado en *Wolfenstein 3D* — implementación de un motor gráfico simple en C utilizando **raycasting**.

---

## 📖 Descripción
El objetivo de **cub3d** es crear un pequeño motor gráfico en 3D con **raycasting**.  
El programa renderiza un laberinto en perspectiva 3D a partir de un archivo de configuración `.cub` que contiene:

- Texturas para cada pared (Norte, Sur, Este, Oeste).
- Colores del suelo y techo.
- El mapa del mundo en 2D (convertido a vista 3D).

El jugador puede moverse por el mapa y girar la cámara como en *Wolfenstein 3D*.

---

## ⚙️ Compilación
Este proyecto utiliza **Makefile**.

```bash
# Compilar el proyecto
make

# Ejecutar el programa con un mapa de ejemplo
./cub3d maps/example.cub
````

---

## 🗂️ Estructura del proyecto

```
cub3d/
│── src/             # Código fuente del proyecto
│── includes/        # Archivos .h (definiciones y structs)
│── maps/            # Archivos .cub de prueba
│── Makefile         # Script de compilación
│── README.md        # Este archivo
```

---

## 🎮 Controles

* `W` / `A` / `S` / `D` → Moverse
* `←` / `→` → Girar cámara
* `ESC` → Salir del juego

---

## ✅ Normas de 42 cumplidas

* No se permiten *memory leaks*.
* Solo se usan funciones autorizadas.
* Gestión de errores rigurosa (archivos inválidos, parámetros incorrectos, etc.).

---

## 🌐 Recursos adicionales

* [Raycasting explained (Lode’s Computer Graphics Tutorial)](https://lodev.org/cgtutor/raycasting.html)
* [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)

---
