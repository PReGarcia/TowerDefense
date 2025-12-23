#include "../../include/entities/Entity.h"

Vector2 Entity::calcularMovimiento(Vector2 posicion, Vector2 destino,
                                   float velocidad) {
  float delta = GetFrameTime();
  float paso = velocidad * delta;

  float distancia = Vector2Distance(destino, posicion);
  if (distancia <= paso) {
    return {destino.x, destino.y};
  } else {
    Vector2 direccion = Vector2Normalize(Vector2Subtract(destino, posicion));
    return {posicion.x + (direccion.x * paso),
            posicion.y + (direccion.y * paso)};
  }
}

void Entity::Dibujar() {
  // 1. ORIGEN: ¿Qué parte de la imagen original queremos? (Toda la imagen)
  Rectangle fuente = {0.0f, 0.0f, (float)textura.width, (float)textura.height};

  // 2. DESTINO: ¿Dónde y de qué tamaño la queremos en pantalla?
  // Ajusta '40.0f' al tamaño de tus casillas o al que desees
  float anchoDeseado = 40.0f;
  float altoDeseado = 40.0f;
  Rectangle destino = {x, y, anchoDeseado, altoDeseado};

  // 3. PIVOTE: ¿Desde dónde se dibuja? (0,0 es la esquina superior izquierda)
  Vector2 origen = {0.0f, 0.0f};

  // 4. DIBUJAR CON ESCALADO
  DrawTexturePro(textura, fuente, destino, origen, 0.0f, WHITE);

  // Para debug (ver el cuadrado rojo del tamaño exacto)
  // DrawRectangleLines((int)x, (int)y, (int)anchoDeseado, (int)altoDeseado,
  // RED);
}

Entity::~Entity() {}
