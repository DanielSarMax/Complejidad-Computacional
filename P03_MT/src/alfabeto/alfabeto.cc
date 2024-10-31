/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición de los métodos de la clase Alfabeto.
 */

#include "alfabeto.h"

/**
 * @brief Constructor por defecto de la clase Alfabeto.
 */
Alfabeto::Alfabeto() {
  alfabeto_ = {};
}

/**
 * @brief Constructor de la clase Alfabeto.
 * @param kAlfabeto Conjunto de símbolos que forman el alfabeto.
 */
Alfabeto::Alfabeto(const std::set<Simbolo>& kAlfabeto) {
  alfabeto_ = kAlfabeto;
}

/**
 * @brief Sobrecarga del operador de inserción.
 * @param os Flujo de salida.
 * @param alfabeto Alfabeto a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
  os << "{";
  for (const auto& symbol : alfabeto.alfabeto_) {
    os << symbol << " ";
  }
  os << "}";
  return os;
}