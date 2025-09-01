/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:32:31 by aternero          #+#    #+#             */
/*   Updated: 2025/08/28 13:24:39 by aternero         ###   ########.fr       */
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
# define ENOTEX  "Missing north texture (NO)."         // Falta la textura para el norte (NO)
# define ESOTEX  "Missing south texture (SO)."         // Falta la textura para el sur (SO)
# define EWETEX  "Missing west texture (WE)."          // Falta la textura para el oeste (WE)
# define EETEX   "Missing east texture (EA)."          // Falta la textura para el este (EA)
# define ETEXINV "Invalid texture path."               // La ruta a una textura no es válida
# define ETEXDUP "Duplicated texture definition."      // Se ha definido más de una vez la misma textura

// ---------- Colores ----------
# define EFCLR   "Invalid floor color (F)."            // Definición inválida del color del suelo (F)
# define ECCLR   "Invalid ceiling color (C)."          // Definición inválida del color del techo (C)
# define ECOLINV "Color values must be in range [0-255]." // Valores de color fuera de rango permitido (0-255)
# define ECOLDUP "Duplicated color definition."        // Se ha definido más de una vez el mismo color

// ---------- Mapa ----------
# define EMAPMISS   "Missing map definition."          // No se ha encontrado la definición del mapa
# define EMAPINV    "Invalid character in map. Allowed: 0, 1, N, S, E, W, space." // El mapa contiene un carácter no permitido
# define EMAPOPEN   "Map is not closed/surrounded by walls." // El mapa no está cerrado o rodeado de muros
# define EMAPSPAWN  "Player spawn point (N/S/E/W) missing or duplicated." // Falta el punto de spawn del jugador o está duplicado
# define EMAPSPACE  "Map contains invalid spaces."     // El mapa contiene espacios no válidos en su definición
# define EMAPORDER  "Map must be the last element in the file." // El mapa no está en la última posición dentro del archivo

// ---------- Formato / líneas ----------
# define EEMPTY "Unexpected empty line in file."       // Línea vacía en un lugar no permitido
# define EUNDEF "Undefined element identifier."        // Identificador de elemento no reconocido (ni textura, ni color, ni mapa)
# define ELINE  "Malformed line in .cub file."         // Línea con formato incorrecto en el archivo .cub

// ---------- Memoria ----------
# define EMALLOC "Memory allocation failed."           // Error al reservar memoria con malloc

#endif
