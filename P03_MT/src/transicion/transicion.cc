/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición de los métodos de la clase Transición.
 */

#include "transicion.h"

/**
 * @brief Constructor por defecto de la clase Transición
 */
Transicion::Transicion() {
  estado_origen_ = "";
  estado_destino_ = "";
  transicion_ = {};
}

/**
 * @brief Constructor de la clase Transición.
 * @param kEstadoOrigen Estado
 * @param kEstadoDestino Estado
 * @param kTransiciones Transiciones
 */
Transicion::Transicion(const std::string& kEstadoOrigen,
                       const std::string& kEstadoDestino,
                       const std::vector<TuplaTransicion>& kTransicion)
    : estado_origen_(kEstadoOrigen),
      estado_destino_(kEstadoDestino),
      transicion_(kTransicion) {}

/**
 * @brief Devuelve el estado origen de la transición.
 * @return Estado origen.
 */
std::string Transicion::getEstadoOrigen() const {
  return estado_origen_;
}

/**
 * @brief Devuelve el estado destino de la transición.
 * @return Estado destino
 */
std::string Transicion::getEstadoDestino() const {
  return estado_destino_;
}

/**
 * @brief Devuelve las transiciones de la transición.
 * @return Transiciones.
 */
std::vector<TuplaTransicion> Transicion::getTransicion() const {
  return transicion_;
}

/**
 * @brief Devuelve los símbolos actuales de las cintas.
 * @return Símbolos actuales.
 */
std::vector<Simbolo> Transicion::getSimboloActualCintas() const {
  std::vector<Simbolo> simbolos_actuales;
  for (int iterador{0}; iterador < int(transicion_.size()); ++iterador) {
    TuplaTransicion tupla_actual = transicion_[iterador];
    simbolos_actuales.push_back(std::get<0>(tupla_actual));
  }
  return simbolos_actuales;
}

/**
 * @brief Devuelve los símbolos nuevos de las cintas.
 * @return Símbolos nuevos.
 */
std::vector<Simbolo> Transicion::getSimboloNuevoCintas() const {
  std::vector<Simbolo> simbolos_nuevos;
  for (int iterador{0}; iterador < int(transicion_.size()); ++iterador) {
    TuplaTransicion tupla_actual = transicion_[iterador];
    simbolos_nuevos.push_back(std::get<1>(tupla_actual));
  }
  return simbolos_nuevos;
}

/**
 * @brief Devuelve los movimientos de las cintas.
 * @return Movimientos.
 */
std::vector<Simbolo> Transicion::getMovimientoCintas() const {
  std::vector<Simbolo> movimientos;
  for (int iterador{0}; iterador < int(transicion_.size()); ++iterador) {
    TuplaTransicion tupla_actual = transicion_[iterador];
    movimientos.push_back(std::get<2>(tupla_actual));
  }
  return movimientos;
}

/**
 * @brief Sobrecarga del operador de inserción.
 * @param os Flujo de salida.
 * @param transicion Transición a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Transicion& kTransicion) {
  os << "(" << kTransicion.estado_origen_;
  for (int iterador{0}; iterador < int(kTransicion.transicion_.size()); ++iterador) {
    TuplaTransicion tupla_actual = kTransicion.transicion_[iterador];
    os << " " << std::get<0>(tupla_actual);
  }
  os << " " << kTransicion.estado_destino_;
  for (int iterador{0}; iterador < int(kTransicion.transicion_.size()); ++iterador) {
    TuplaTransicion tupla_actual = kTransicion.transicion_[iterador];
    os << " " << std::get<1>(tupla_actual) << " " << std::get<2>(tupla_actual);
  }
  os << ")";
  return os;
}