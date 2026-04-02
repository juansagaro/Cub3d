<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="https://raw.githubusercontent.com/NanoHtz/Assets/main/cub3d/banner.svg" alt="Cub3D Banner">
</p>

<h1 align="center">Cub3D</h1>

<p align="center">
  <b>Mi primer motor de raycasting</b><br>
  <i>Inspirado en Wolfenstein 3D (1992)</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Nota-125%2F100-success?style=for-the-badge" alt="Score"/>
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/Bonus-Completado-blueviolet?style=for-the-badge" alt="Bonus"/>
</p>

<br>

<!-- ===================== DEMO ===================== -->
<h2 align="center">Vista del juego</h2>

<p align="center">
  <img src="https://camo.githubusercontent.com/e09de441549900a090025f2e8ba7665a706ba81bb39dd21de3dea4c870bcb236/68747470733a2f2f692e696d6775722e636f6d2f304f37646a57702e676966" alt="Demo" width="700">
</p>

<br>

<!-- ===================== ABOUT ===================== -->
## Sobre el proyecto

**Cub3D** renderiza un laberinto 3D a partir de un mapa 2D usando la técnica de **raycasting**. El jugador puede moverse libremente por el escenario, con paredes texturizadas y colisiones.

Proyecto del **Common Core de 42 Madrid**, desarrollado en **C** con la biblioteca gráfica **MiniLibX**.

<br>

<!-- ===================== FEATURES ===================== -->
## Características

<table align="center">
  <tr>
    <td align="center" width="200">
      <h3>Mandatory</h3>
      <p>
        Renderizado 3D<br>
        Texturas por orientación<br>
        Movimiento fluido<br>
        Sistema de colisiones<br>
        Parser de mapas .cub
      </p>
    </td>
    <td align="center" width="200">
      <h3>Bonus</h3>
      <p>
        Minimapa circular<br>
        Puertas interactivas<br>
        Arma animada<br>
        Control con ratón<br>
        Texturas suelo/techo
      </p>
    </td>
  </tr>
</table>

<br>

<!-- ===================== INSTALL ===================== -->
## Instalación

```bash
# Clonar
git clone https://github.com/juansagaro/Cub3d.git
cd Cub3d

# Compilar
make              # versión base
make bonus        # versión completa

# Ejecutar
./cub3d assets/maps/good/subject_map.cub
./cub3d_bonus assets/maps/bonus/dungeon.cub
```

<br>

<!-- ===================== CONTROLS ===================== -->
## Controles

<table align="center">
  <tr>
    <th>Tecla</th>
    <th>Acción</th>
  </tr>
  <tr>
    <td align="center"><kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd></td>
    <td>Movimiento</td>
  </tr>
  <tr>
    <td align="center"><kbd>←</kbd> <kbd>→</kbd></td>
    <td>Rotar cámara</td>
  </tr>
  <tr>
    <td align="center"><kbd>Mouse</kbd></td>
    <td>Rotar cámara (bonus)</td>
  </tr>
  <tr>
    <td align="center"><kbd>E</kbd></td>
    <td>Abrir puerta (bonus)</td>
  </tr>
  <tr>
    <td align="center"><kbd>M</kbd></td>
    <td>Toggle minimapa (bonus)</td>
  </tr>
  <tr>
    <td align="center"><kbd>Click</kbd></td>
    <td>Disparar (bonus)</td>
  </tr>
  <tr>
    <td align="center"><kbd>ESC</kbd></td>
    <td>Salir</td>
  </tr>
</table>

<br>

<!-- ===================== MAPS ===================== -->
## Formato de mapas

Los mapas usan la extensión `.cub` y definen texturas, colores y el laberinto:

```
NO assets/textures/north.xpm
SO assets/textures/south.xpm
WE assets/textures/west.xpm
EA assets/textures/east.xpm

F 220,100,0
C 50,50,80

111111111
100000001
100N00001
100000001
111111111
```

<table align="center">
  <tr>
    <td align="center"><code>0</code></td>
    <td>Suelo</td>
    <td align="center"><code>1</code></td>
    <td>Pared</td>
  </tr>
  <tr>
    <td align="center"><code>N S E W</code></td>
    <td>Spawn del jugador</td>
    <td align="center"><code>D</code></td>
    <td>Puerta (bonus)</td>
  </tr>
</table>

<br>

<!-- ===================== STRUCTURE ===================== -->
## Estructura

```
Cub3d/
├── assets/
│   ├── maps/          # Mapas .cub
│   └── textures/      # Texturas .xpm
├── mandatory/
│   ├── inc/           # Headers
│   └── src/           # Código fuente
└── bonus/
    ├── inc/
    └── src/
```

<br>

<!-- ===================== FOOTER ===================== -->
<p align="center">
  <b>42 Madrid</b>
</p>

<p align="center">
  <a href="https://github.com/juansagaro">
    <img src="https://img.shields.io/badge/GitHub-juansagaro-181717?style=flat-square&logo=github" alt="GitHub">
  </a>
</p>
