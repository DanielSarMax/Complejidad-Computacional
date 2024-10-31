/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición de los métodos de la clase Estado.
 */

#include "estado.h"

/**
 * @brief Constructor por defecto de la clase Estado.
 */
Estado::Estado() {
  nombre_ = "";
  es_final_ = false;
  transiciones_ = {};
}

/**
 * @brief Constructor de la clase Estado.
 * @param kNombre Nombre del estado.
 * @param kTransiciones Transiciones del estado.
 * @param kEsFinal Indica si el estado es final.
 */
Estado::Estado(const std::string& kNombre,
               const std::vector<Transicion>& kTransiciones,
                bool kEsFinal) 
    : nombre_{kNombre},
      transiciones_{kTransiciones},
      es_final_{kEsFinal} {}

/**
 * @brief Devuelve el nombre del estado.
 * @return Nombre del estado.
 */
std::string Estado::getNombre() const {
  return nombre_;
}

/**
 * @brief Indica si el estado es final.
 * @return true si el estado es final, false en caso contrario.
 */
bool Estado::esFinal() const {
  return es_final_;
}

/**
 * @brief Devuelve las transiciones del estado.
 * @return Transiciones del estado
 */
std::vector<Transicion> Estado::getTransiciones() const {
  return transiciones_;
}

/**
 * @brief Establece si el estado es final.
 * @param kEsFinal Indica si el estado es final.
 */
void Estado::setEsFinal(bool kEsFinal) {
  es_final_ = kEsFinal;
}

/**
 * @brief Agrega una transición al estado.
 * @param kTransicion Transición a agregar.
 */
void Estado::AgregarTransicion(const Transicion& kTransicion) {
  transiciones_.push_back(kTransicion);
}

/**
 * @brief Sobrecarga del operador de inserción.
 * @param os Flujo de salida.
 * @param estado Estado a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Estado& estado) {
  os << estado.nombre_ << "(" << (estado.es_final_ ? "final" : "no final") << "):";
  for (const auto& transition : estado.transiciones_) {
    os << "\n\t" << transition;
  }
  return os;
}
