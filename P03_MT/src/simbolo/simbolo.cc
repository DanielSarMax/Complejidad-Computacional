/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición de los métodos de la clase Simbolo.
 */

#include "simbolo.h"

/**
 * @brief Constructor por defecto de la clase Simbolo.
 */
Simbolo::Simbolo() {
  simbolo_ = "";
}

/**
 * @brief Constructor de la clase Simbolo.
 * @param kSimbolo Cadena de caracteres que representa el símbolo.
 */
Simbolo::Simbolo(const std::string& kSimbolo) {
  simbolo_ = kSimbolo;
}

/**
 * @brief Sobrecarga del operador de inserción.
 * @param os Flujo de salida.
 * @param simbolo Símbolo a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo) {
  os << simbolo.simbolo_;
  return os;
}

/**
 * @brief Sobrecarga del operador de comparación.
 * @param kSimbolo1 Símbolo a comparar.
 * @param kSimbolo2 Símbolo a comparar.
 * @return true si el primer símbolo es menor que el segundo, false en caso contrario.
 */
bool operator<(const Simbolo& kSimbolo1, const Simbolo& kSimbolo2) {
  return kSimbolo1.getSimbolo() < kSimbolo2.getSimbolo();
}

/**
 * @brief Sobrecarga del operador de comparación.
 * @param kSimbolo1 Símbolo a comparar.
 * @param kSimbolo2 Símbolo a comparar.
 * @return true si los símbolos son iguales, false en caso contrario.
 */
bool operator==(const Simbolo& kSimbolo1, const Simbolo& kSimbolo2) {
  return kSimbolo1.getSimbolo() == kSimbolo2.getSimbolo();
}