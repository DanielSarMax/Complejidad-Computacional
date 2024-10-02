/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Definición de funciones auxiliares.	
 */

#include <iostream>
#include <vector>

#include "../contador/contador.h"

/**
 * @brief Comprueba si el índice es válido.
 * @param kVectorSize Tamaño del vector.
 * @param kIndice Índice a comprobar.
 */
void ComprobarIndice(const int kVectorSize, const int kIndice) {
  Contador::IncrementarContador();
  if (kIndice < 0 || kIndice >= kVectorSize) {
    std::cerr << "Error: El índice no es válido." << std::endl;
    exit(1);
  }
}