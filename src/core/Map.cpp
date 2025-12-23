#include "../../include/core/Map.h"

Map::Map() {
  // 1. Inicializar todo el grid a 0 (Césped)
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = 0;
    }
  }

  // 2. Crear un camino manual (Esto es temporal, luego cargaremos mapas)
  // Vamos a hacer una "L" simple:
  // Empieza en (0, 2) -> va a la derecha -> baja -> fin

  // Parte A: Recta horizontal (Fila 2, Columnas 0 a 10)
  for (int x = 0; x <= 10; x++)
    grid[2][x] = 1;

  // Parte B: Bajada vertical (Columna 10, Filas 2 a 12)
  for (int y = 2; y <= 12; y++)
    grid[y][10] = 1;

  // Parte C: Recta final (Fila 12, Columnas 10 a 18)
  for (int x = 10; x < COLS; x++)
    grid[12][x] = 1;

  // 3. Rellenar los Waypoints (Puntos clave para la IA de los enemigos)
  // Los enemigos irán de punto a punto en línea recta
  camino.push_back(
      Vector2{0, 2 * TILE_SIZE + TILE_SIZE / 2}); // Inicio (Centrado en altura)
  camino.push_back(Vector2{10 * TILE_SIZE + TILE_SIZE / 2,
                           2 * TILE_SIZE + TILE_SIZE / 2}); // Primera curva
  camino.push_back(Vector2{10 * TILE_SIZE + TILE_SIZE / 2,
                           12 * TILE_SIZE + TILE_SIZE / 2}); // Segunda curva
  camino.push_back(
      Vector2{SCREEN_WIDTH,
              12 * TILE_SIZE + TILE_SIZE / 2}); // Final (Sale de pantalla)

  // Nota: Sumo "+ TILE_SIZE/2" para que el punto esté EN EL CENTRO del
  // cuadrado, no en la esquina.
}

void Map::Draw() {
  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLS; x++) {
      // Calcular la posición en píxeles
      int posX = x * TILE_SIZE;
      int posY = y * TILE_SIZE;

      // Decidir el color
      Color colorDelCuadrado;

      if (grid[y][x] == 0) {
        colorDelCuadrado = DARKGREEN; // Césped
      } else {
        colorDelCuadrado = DARKBROWN; // Camino
      }

      // PINTAR
      DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, colorDelCuadrado);

      // Opcional: Pintar una línea finita gris para ver la cuadrícula
      DrawRectangleLines(posX, posY, TILE_SIZE, TILE_SIZE, Fade(BLACK, 0.1f));
    }
  }

  // Debug: Pintar los waypoints para ver si están bien colocados (pequeños
  // puntos rojos)
  for (Vector2 punto : camino) {
    DrawCircleV(punto, 5, RED);
  }
}

Map::~Map() {};
