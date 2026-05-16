# Parcial-tercer-corte-
Creación de un videojuego
#  Dungeon Crawler

> Videojuego dungeon-crawler en C++ inspirado en Adventure (Atari 2600, 1980).  
> Desarrollado como proyecto final del curso.

Integrantes

Edgar Daniel Parra Palencia

Descripción del Juego
Un dungeon-crawler de consola con mapas en ASCII donde el jugador explora habitaciones, recoge objetos, evade enemigos y debe encontrar la salida para ganar.

## Compilación

### Requisitos previos

| Herramienta | Versión mínima |
|-------------|---------------|
| CMake       | 3.10          |
| g++ / MSVC / clang++ | C++17 |


### Linux

```bash
git clone https://github.com/TU_USUARIO/dungeon-crawler.git
cd dungeon-crawler
mkdir build && cd build
cmake ..
make
./dungeon




### macOS

bash
git clone https://github.com/TU_USUARIO/dungeon-crawler.git
cd dungeon-crawler
mkdir build && cd build
cmake ..
make
./dungeon



###  Windows

```powershell
git clone https://github.com/TU_USUARIO/dungeon-crawler.git
cd dungeon-crawler
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
dungeon.exe
```
## Estructura del Proyecto

dungeon-crawler/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── game.h
│   ├── player.h
│   ├── enemy.h
│   ├── room.h
│   └── item.h
└── src/
    ├── main.cpp
    ├── game.cpp
    ├── player.cpp
    ├── enemy.cpp
    ├── room.cpp
    └── item.cpp




##  Controles

| Tecla | Acción |
|-------|--------|
| `W` / `↑` | Mover arriba |
| `S` / `↓` | Mover abajo |
| `A` / `←` | Mover izquierda |
| `D` / `→` | Mover derecha |
| `E`       | Recoger / soltar objeto |
| `Q`       | Salir del juego |

---

##  Requisitos Cumplidos

- [x] Lenguaje: C++17
- [x] Mínimo 6 habitaciones conectadas con colisiones
- [x] 2 tipos de enemigos con comportamiento de persecución
- [x] Mapa visual en ASCII del entorno, jugador y enemigos
- [x] Inventario de un solo espacio (recoger/soltar)
- [x] Condiciones claras de victoria y derrota
- [x] Código modular en archivos `.h` y `.cpp` con uso de punteros
- [x] Compilación mediante CMake
- [x] Arreglos estáticos de entidades (sin `new`/`delete` en el game-loop)
