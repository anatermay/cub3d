/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:32:31 by aternero          #+#    #+#             */
/*   Updated: 2025/11/13 18:19:33 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

// ==========================
//       PARSE ERRORS
// ==========================

// ---------- ARGUMENTS ----------
# define EARGC "Invalid number of arguments."
# define ECUB  "Invalid file extension. Expected .cub"

// ---------- FILE ----------
# define EOPEN "Failed to open .cub file."
# define EREAD "Failed to read .cub file."
# define EEMPTYFILE "The .cub file is empty."

// ---------- TEXTURES ----------
# define EID	 "Missing or duplicated element identifier."
# define EINVALIDID "Invalid element identifier. Expected: NO, SO, WE, EA, F, C"
# define ETEX    "Missing texture."
# define ETEXINV "Invalid texture path."

// ---------- COLORS ----------
# define ECLR   "Invalid color."
# define ECOLINV "Color values must be in range [0-255]."
# define ECOLDUP "Duplicated color definition."
# define ECOLFORMAT "Invalid color format. Expected: F R,G,B or C R,G,B"
# define ECOLMISSING "Missing color values. Expected 3 RGB values."

// ---------- MAP ----------
# define EMAPORDER  "Map must be the last element in the file."
# define EMISSINGELEM "Missing required element. Expected: NO, SO, WE, EA, F, C"
# define ENOMAP     "No map found after required elements."
# define EPP	"More than one starting position has been detected."
# define EMCHR	"Invalid character in the map"
# define EMPPOS	"Invalid place for player position"
# define EWALLS "The map must be surrounded by walls."
# define EPPO "No starting position detected."

// ---------- FORMAT / LINES ----------
# define ELINE  "Malformed line in .cub file."

// ---------- MEMORY ----------
# define EMALLOC "Memory allocation failed."

#endif
