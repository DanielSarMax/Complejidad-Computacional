/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Definición de la clase Pila.
 */

#include "pila.h"

/**
 * @brief Imprime la pila.
 */
void Pila::Imprimir() const {
  std::stack<Simbolo> pila_auxiliar = pila_;
  std::cout << "[ ";
  while (!pila_auxiliar.empty()) {
    std::cout << pila_auxiliar.top().GetSimbolo() << " ";
    pila_auxiliar.pop();
  }
  std::cout << "]";
  std::cout << std::endl;
}