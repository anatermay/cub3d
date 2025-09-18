/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:32:31 by aternero          #+#    #+#             */
/*   Updated: 2025/09/18 19:11:22 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

// ==========================
//       ERRORES PARSEO
// ==========================

// ---------- Argumentos ----------
# define EARGC "Invalid number of arguments."          // Número incorrecto de argumentos al ejecutar el programa
# define ECUB  "Invalid file extension. Expected .cub" // El archivo no tiene extensión .cub

// ---------- Archivo ----------
# define EOPEN "Failed to open .cub file."             // No se pudo abrir el archivo .cub
# define EREAD "Failed to read .cub file."             // Error al leer el archivo .cub
# define EEMPTYFILE "The .cub file is empty."          // El archivo .cub no contiene ninguna información

// ---------- Texturas ----------
# define EID	 "Missing or duplicated element identifier." // Falta o está duplicado un identificador de elemento (textura, color)
# define EINVALIDID "Invalid element identifier. Expected: NO, SO, WE, EA, F, C" // Identificador de elemento inválido
# define ETEX    "Missing texture."         // Falta la textura para el norte (NO)
# define ETEXINV "Invalid texture path."               // La ruta a una textura no es válida

// ---------- Colores ----------
# define ECLR   "Invalid color."            // Definición inválida del color del suelo (F)
# define ECOLINV "Color values must be in range [0-255]." // Valores de color fuera de rango permitido (0-255)
# define ECOLDUP "Duplicated color definition."        // Se ha definido más de una vez el mismo color
# define ECOLFORMAT "Invalid color format. Expected: F R,G,B or C R,G,B" // Formato de color incorrecto
# define ECOLMISSING "Missing color values. Expected 3 RGB values." // Faltan valores de color

// ---------- Mapa ----------
# define EMAPORDER  "Map must be the last element in the file." // El mapa no está en la última posición dentro del archivo
# define EMISSINGELEM "Missing required element. Expected: NO, SO, WE, EA, F, C" // Falta un elemento requerido
# define ENOMAP     "No map found after required elements." // No se encontró mapa después de los elementos requeridos
# define EPP	"More than one starting position has been detected."
# define EMCHR	"Invalid character in the map"
# define EMPPOS	"Invalid place for player position"
# define EWALLS "The map must be surrounded by walls."
# define EPPO "No starting position detected."

// ---------- Formato / líneas ----------
# define ELINE  "Malformed line in .cub file."         // Línea con formato incorrecto en el archivo .cub

// ---------- Memoria ----------
# define EMALLOC "Memory allocation failed."           // Error al reservar memoria con malloc

#endif
