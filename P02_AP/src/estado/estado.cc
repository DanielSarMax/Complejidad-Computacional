/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Definición de la clase Estado.
 */

#include "estado.h"

Estado::Estado(const std::string& kNombre, const bool kEsFinal) {
  nombre_ = kNombre;
  es_final_ = kEsFinal;
}

/**
 * @brief Devuelve si el estado es final.
 * @return Si el estado es final.
 */
bool Estado::EsFinal() const { return es_final_; }

/**
 * @brief Establece si el estado es final.
 * @param kEsFinal Si el estado es final.
 */
void Estado::SetFinal(const bool kEsFinal) { es_final_ = kEsFinal; }

/**
 * @brief Devuelve el nombre del estado.
 * @return Nombre del estado.
 */
std::string Estado::GetNombre() const { return nombre_; }

/**
 * @brief Establece el nombre del estado.
 * @param kNombre Nombre del estado.
 */
void Estado::SetNombre(const std::string& kNombre) { nombre_ = kNombre; }

/**
 * @brief Devuelve las transiciones del estado.
 * @return Transiciones del estado
 */
std::vector<Transicion> Estado::GetTransiciones() const { return transiciones_; }

/**
 * @brief Establece las transiciones del estado.
 * @param kTransiciones Transiciones del estado.
 */
void Estado::SetTransiciones(const std::vector<Transicion>& kTransiciones) {
  transiciones_ = kTransiciones;
}

/**
 * @brief Agrega una transición al estado.
 * @param kTransicion Transición a agregar.
 */
void Estado::AgregarTransicion(const Transicion& kTransicion) {
  transiciones_.push_back(kTransicion);
}

/**
 * @brief Imprime la información del estado.
 */
void Estado::Imprimir() const {
  std::cout << "Estado: " << nombre_ << std::endl;
  std::cout << "Es final: " << es_final_ << std::endl;
  std::cout << "Transiciones: " << std::endl;
  for (const Transicion& transicion : transiciones_) {
    transicion.Imprimir();
  }
}