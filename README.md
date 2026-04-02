<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/cub3d/banner.svg" alt="Cub3D Banner">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Nota-125%2F100-success?style=flat-square" alt="Score"/>
  <img src="https://img.shields.io/badge/Lenguaje-C-00599C?style=flat-square&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/Norminette-OK-success?style=flat-square" alt="Norminette"/>
  <img src="https://img.shields.io/badge/Bonus-100%25-blueviolet?style=flat-square" alt="Bonus"/>
</p>

---

## Sobre el proyecto

**Cub3D** es un motor gráfico que renderiza un entorno 3D a partir de un mapa 2D utilizando la técnica de **raycasting**, la misma que popularizó [Wolfenstein 3D](https://es.wikipedia.org/wiki/Wolfenstein_3D) en 1992.

El jugador puede explorar el laberinto en primera persona, con paredes texturizadas, colisiones y movimiento fluido.

> Proyecto del **Common Core de 42 Madrid**, desarrollado en C puro con **MiniLibX**.

---

## Características

<table>
<tr>
<td width="50%" valign="top">

### Base
- Renderizado 3D con raycasting
- Paredes texturizadas (N/S/E/W)
- Colores de suelo y techo
- Movimiento y rotación fluidos
- Sistema de colisiones
- Parser robusto de archivos `.cub`

</td>
<td width="50%" valign="top">

### Bonus
- Minimapa circular tipo radar
- Puertas que se abren con `E`
- Arma animada (7 frames)
- Rotación con ratón
- Disparo con click izquierdo
- Texturas en suelo y techo

</td>
</tr>
</table>

---

## Instalación

### Requisitos
- Linux con X11
- GCC
- Dependencias: `libx11-dev` `libxext-dev` `zlib1g-dev`

### Compilar y ejecutar

```bash
# Clonar el repositorio
git clone https://github.com/juansagaro/Cub3d.git && cd Cub3d

# Compilar
make                # Versión mandatory
make bonus          # Versión con bonus

# Ejecutar
./cub3d assets/maps/good/subject_map.cub
./cub3d_bonus assets/maps/bonus/dungeon.cub
```

| Comando | Descripción |
|---------|-------------|
| `make` | Compila versión base |
| `make bonus` | Compila versión completa |
| `make clean` | Elimina objetos |
| `make fclean` | Elimina objetos y ejecutables |
| `make re` | Recompila todo |

---

## Controles

| Tecla | Acción |
|:-----:|--------|
| <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> | Movimiento |
| <kbd>←</kbd> <kbd>→</kbd> | Rotar cámara |
| <kbd>ESC</kbd> | Salir |

### Solo en bonus

| Tecla | Acción |
|:-----:|--------|
| <kbd>Ratón</kbd> | Rotar cámara |
| <kbd>Click izq.</kbd> | Disparar |
| <kbd>E</kbd> | Abrir puerta |
| <kbd>M</kbd> | Mostrar/ocultar minimapa |

---

## Mapas

Los mapas utilizan la extensión `.cub` y contienen la configuración de texturas, colores y el laberinto.

### Ejemplo

```
NO assets/textures/wolfenstein/greystone.xpm
SO assets/textures/wolfenstein/bluestone.xpm
WE assets/textures/wolfenstein/mossy.xpm
EA assets/textures/wolfenstein/redbrick.xpm

F 220,100,0
C 50,50,80

D assets/textures/wolfenstein/door.xpm

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
10000000N0000000110000D010001
111111111111111111111111111111
```

### Caracteres

| Símbolo | Significado |
|:-------:|-------------|
| `0` | Suelo transitable |
| `1` | Pared |
| `N` `S` `E` `W` | Posición inicial del jugador |
| `D` | Puerta *(bonus)* |
| ` ` | Espacio vacío |

### Mapas incluidos

```
assets/maps/
├── good/      → Mapas válidos para jugar
├── bad/       → Mapas inválidos (para testing del parser)
└── bonus/     → Mapas con puertas y features extra
```

---

## Texturas

El proyecto incluye dos packs de texturas:

| Pack | Estilo |
|------|--------|
| `wolfenstein/` | Clásico Wolfenstein 3D |
| `simonkraft/` | Estilo Minecraft |

Además, el directorio `gun/` contiene los 7 frames de animación del arma.

---

## Estructura del proyecto

```
Cub3d/
│
├── mandatory/
│   ├── inc/            # Headers (cub3d.h, libft, gnl, minilibx)
│   └── src/
│       ├── parser/     # Lectura y validación de .cub
│       ├── render/     # Raycasting y dibujado
│       ├── inputs/     # Manejo de teclado
│       ├── logic/      # Movimiento y colisiones
│       └── cleanup/    # Liberación de memoria
│
├── bonus/              # Misma estructura + minimap, arma, ratón
│
└── assets/
    ├── maps/           # Archivos .cub
    └── textures/       # Archivos .xpm
```

---

## Autor

<p align="center">
  <a href="https://github.com/juansagaro">
    <img src="https://img.shields.io/badge/juansagaro-181717?style=for-the-badge&logo=github&logoColor=white" alt="GitHub"/>
  </a>
</p>

<p align="center">
  <sub>Desarrollado en <b>42 Madrid</b></sub>
</p>
