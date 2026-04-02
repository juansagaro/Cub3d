<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/cub3d/banner.svg" alt="Cub3d banner">
</p>

<h3 align="center">
  Motor de raycasting al estilo Wolfenstein 3D
</h3>

<p align="center">
  <img src="https://img.shields.io/badge/Nota-125%2F100-brightgreen?style=for-the-badge" alt="Score"/>
  <img src="https://img.shields.io/badge/Lenguaje-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Norminette-OK-success?style=for-the-badge" alt="Norminette"/>
  <img src="https://img.shields.io/badge/Bonus-Completado-blueviolet?style=for-the-badge" alt="Bonus"/>
</p>

<p align="center">
  <a href="#-sobre-el-proyecto">Sobre</a> •
  <a href="#-características">Características</a> •
  <a href="#-demostración">Demo</a> •
  <a href="#-instalación">Instalación</a> •
  <a href="#-controles">Controles</a> •
  <a href="#-formato-de-mapas">Mapas</a> •
  <a href="#-arquitectura">Arquitectura</a>
</p>

---

## Sobre el proyecto

**Cub3D** es un motor gráfico que implementa **raycasting** para renderizar un entorno 3D a partir de un mapa 2D, inspirado en el legendario [Wolfenstein 3D](https://es.wikipedia.org/wiki/Wolfenstein_3D) (1992).

El proyecto forma parte del **Common Core de 42 Madrid** y está desarrollado íntegramente en **C** siguiendo la estricta [Norma de 42](https://github.com/42School/norminette), utilizando únicamente la biblioteca gráfica **MiniLibX**.

```
                    ┌─────────────────────────────────────────┐
                    │              RAYCASTING                 │
                    │                                         │
     Mapa 2D        │     ══════════════════════════         │      Vista 3D
   ┌─────────┐      │    ║░░░░░░░░░░░░░░░░░░░░░░░░║         │    ┌─────────┐
   │ 1111111 │      │    ║▓▓▓▓▓▓░░░░░░░░░░░░▓▓▓▓▓▓║         │    │ ▓▓░░░▓▓ │
   │ 1000001 │  ──► │    ║▓▓▓▓▓▓▓▓▓░░░░░▓▓▓▓▓▓▓▓▓▓║    ──►  │    │ ▓▓▓░▓▓▓ │
   │ 100N001 │      │    ║▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓║         │    │ ▓▓▓▓▓▓▓ │
   │ 1111111 │      │    ══════════════════════════         │    └─────────┘
   └─────────┘      │                                         │
                    └─────────────────────────────────────────┘
```

---

## Características

### Mandatory

| Característica | Descripción |
|----------------|-------------|
| **Raycasting DDA** | Algoritmo Digital Differential Analyzer para detección de paredes |
| **Texturas XPM** | Paredes texturizadas según orientación (N/S/E/W) |
| **Suelo y Techo** | Colores RGB o texturas personalizadas |
| **Colisiones** | Sistema de detección con radio de colisión |
| **Parser robusto** | Validación completa de archivos `.cub` con flood-fill |
| **Movimiento fluido** | Desplazamiento, strafe y rotación de cámara |

### Bonus

| Característica | Descripción |
|----------------|-------------|
| **Minimapa** | Radar circular con vista aérea del entorno |
| **Puertas** | Elementos interactivos que se abren con `E` |
| **Arma animada** | Sprite de 7 frames con animación al disparar |
| **Control con ratón** | Rotación de cámara y disparo con mouse |

---

## Demostración

### Vista del juego

```
┌────────────────────────────────────────────────────────────────────┐
│  ┌──────┐                                                          │
│  │MINIMAP│   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓   │
│  │  ●→   │   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓   │
│  │ ████  │   ▓▓▓▓▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▓▓▓▓▓▓▓   │
│  └──────┘   ▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓▓▓   │
│             ▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓▓▓▓   │
│             ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   │
│             ████████████████████████████████████████████████████   │
│             ████████████████████████████████████████████████████   │
│                                                                    │
│                              ╔═══╗                                 │
│                              ║ █ ║  ← Arma                         │
│                              ╚═══╝                                 │
└────────────────────────────────────────────────────────────────────┘
```

### Texturas incluidas

El proyecto incluye dos packs de texturas:

| Pack | Estilo | Archivos |
|------|--------|----------|
| `wolfenstein/` | Clásico Wolfenstein 3D | 8 texturas |
| `simonkraft/` | Estilo Minecraft | ~25 texturas |

---

## Instalación

### Requisitos previos

- **Sistema operativo**: Linux (X11)
- **Compilador**: GCC con soporte C99
- **Dependencias**: `libx11-dev`, `libxext-dev`, `zlib1g-dev`

```bash
# Debian/Ubuntu
sudo apt-get install libx11-dev libxext-dev zlib1g-dev
```

### Compilación

```bash
# Clonar repositorio
git clone git@github.com:NanoHtz/Cub3d.git
cd Cub3d

# Compilar versión mandatory
make

# Compilar versión bonus
make bonus
```

### Ejecución

```bash
# Mandatory
./cub3d assets/maps/good/subject_map.cub

# Bonus
./cub3d_bonus assets/maps/bonus/dungeon.cub
```

### Comandos del Makefile

| Comando | Descripción |
|---------|-------------|
| `make` | Compila la versión mandatory |
| `make bonus` | Compila la versión con bonus |
| `make clean` | Elimina archivos objeto |
| `make fclean` | Elimina objetos y ejecutables |
| `make re` | Recompila desde cero |

---

## Controles

### Movimiento

```
                    ┌───┐
                    │ W │  Adelante
                    └───┘
              ┌───┐ ┌───┐ ┌───┐
   Izquierda  │ A │ │ S │ │ D │  Derecha
              └───┘ └───┘ └───┘
                    Atrás
```

### Controles completos

| Tecla | Acción | Versión |
|-------|--------|---------|
| `W` | Mover adelante | Ambas |
| `S` | Mover atrás | Ambas |
| `A` | Strafe izquierda | Ambas |
| `D` | Strafe derecha | Ambas |
| `←` | Rotar cámara izquierda | Ambas |
| `→` | Rotar cámara derecha | Ambas |
| `ESC` | Salir del juego | Ambas |
| `M` | Toggle minimapa | Bonus |
| `E` | Abrir puerta | Bonus |
| `Mouse` | Rotar cámara | Bonus |
| `Click` | Disparar (animación) | Bonus |

---

## Formato de mapas

### Estructura del archivo `.cub`

```bash
# Texturas de paredes (obligatorias)
NO assets/textures/wolfenstein/greystone.xpm    # Norte
SO assets/textures/wolfenstein/bluestone.xpm    # Sur
WE assets/textures/wolfenstein/mossy.xpm        # Oeste
EA assets/textures/wolfenstein/redbrick.xpm     # Este

# Colores de suelo y techo (RGB 0-255)
F 220,100,0     # Floor (suelo)
C 50,50,80      # Ceiling (techo)

# Puerta (solo bonus)
D assets/textures/wolfenstein/door.xpm

# Mapa (debe estar al final y cerrado por paredes)
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
10000000N00000001100000010001
110000011101010111110111100111
11111111 1111111 111111111111
```

### Caracteres del mapa

| Char | Significado |
|------|-------------|
| `0` | Suelo (transitable) |
| `1` | Pared |
| `N` | Spawn mirando Norte |
| `S` | Spawn mirando Sur |
| `E` | Spawn mirando Este |
| `W` | Spawn mirando Oeste |
| `D` | Puerta (bonus) |
| ` ` | Espacio vacío |

### Mapas incluidos

```
assets/maps/
├── good/           # Mapas válidos
│   ├── subject_map.cub
│   ├── works.cub
│   └── ...
├── bad/            # Mapas inválidos (testing)
│   └── 43 archivos de prueba
└── bonus/          # Mapas con puertas
    ├── dungeon.cub
    ├── library.cub
    └── ...
```

---

## Arquitectura

### Estructura del proyecto

```
Cub3d/
├── Makefile
├── README.md
│
├── assets/
│   ├── maps/                    # Mapas .cub
│   └── textures/                # Texturas .xpm
│       ├── wolfenstein/
│       ├── simonkraft/
│       └── gun/                 # Frames del arma
│
├── mandatory/
│   ├── inc/
│   │   ├── cub3d/cub3d.h        # Header principal
│   │   ├── libft/               # Biblioteca de 42
│   │   ├── gnl/                 # Get Next Line
│   │   └── minilibx-linux/      # MiniLibX
│   └── src/
│       ├── main.c
│       ├── parser/              # Parsing de .cub
│       ├── inits/               # Inicializaciones
│       ├── inputs/              # Manejo de teclas
│       ├── logic/               # Movimiento y colisiones
│       ├── render/              # Raycasting y dibujado
│       ├── core/                # Game loop
│       ├── cleanup/             # Liberación de memoria
│       └── utils/               # Funciones auxiliares
│
└── bonus/                       # Misma estructura + extras
    └── src/
        ├── render/
        │   ├── draw_minimap.c
        │   └── draw_weapon.c
        ├── inputs/
        │   └── input_mouse.c
        └── logic/
            └── player_actions.c
```

### Flujo del programa

```
main()
 │
 ├── Validación de argumentos (.cub)
 │
 ├── parser()
 │    ├── Lectura del archivo
 │    ├── Parsing de texturas y colores
 │    ├── Parsing del mapa
 │    └── Validación (flood-fill)
 │
 └── start_mlx()
      ├── Inicialización de ventana
      ├── Carga de texturas
      ├── Setup de hooks (eventos)
      │
      └── mlx_loop() ─────────────────┐
           │                          │
           └── draw_loop() ◄──────────┘
                ├── move_player()
                ├── render_floor_ceiling()
                ├── render_3d_view()    ← Raycasting DDA
                ├── render_minimap()    ← (bonus)
                ├── render_weapon()     ← (bonus)
                └── mlx_put_image_to_window()
```

### Algoritmo DDA (Raycasting)

```
Para cada columna X de la pantalla (0 → 1800):

    1. Calcular dirección del rayo
       ray_dir = player_dir + plane * (2*x/width - 1)

    2. Inicializar DDA
       - delta_dist: distancia entre intersecciones
       - side_dist: distancia a primera intersección
       - step: dirección del paso (+1 o -1)

    3. Ejecutar DDA (buscar pared)
       while (!hit)
           if (side_dist_x < side_dist_y)
               avanzar en X
           else
               avanzar en Y
           if (mapa[y][x] == '1')
               hit = true

    4. Calcular distancia perpendicular
       (evita efecto fish-eye)

    5. Dibujar columna texturizada
       - Altura proporcional a la distancia
       - Textura según orientación (N/S/E/W)
```

---

## Especificaciones técnicas

| Parámetro | Valor |
|-----------|-------|
| Resolución | 1800 x 1000 px |
| Tamaño de celda | 64 px |
| Velocidad de movimiento | 0.12 |
| Velocidad de rotación | 0.1 |
| Radio de colisión | 0.2 |
| Sensibilidad del ratón | 0.0015 |
| FOV | ~66° (plane = 0.66) |

---

## Norma de 42

Este proyecto cumple con la **Norminette** de 42:

- Funciones de máximo **25 líneas**
- Máximo **4 parámetros** por función
- Máximo **4 variables** por función
- Nombres en **snake_case** y en inglés
- **Una responsabilidad** por función
- Variables declaradas al **inicio del bloque**
- Sin uso de bibliotecas externas (excepto MiniLibX)

---

## Recursos

- [Tutorial de Raycasting - Lode](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Wolfenstein 3D - Wikipedia](https://es.wikipedia.org/wiki/Wolfenstein_3D)

---

<p align="center">
  Desarrollado con <b>C</b> en <b>42 Madrid</b>
</p>

<p align="center">
  <a href="https://github.com/NanoHtz">NanoHtz</a>
</p>
