/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición de los métodos de la clase Cinta.
 */

#include "cinta.h"

/**
 * @brief Constructor por defecto de la clase Cinta.
 */
Cinta::Cinta() {
  cinta_ = {};
  posicion_cabeza_ = 0;
  blanco_ = Simbolo{"_"};
  cinta_.push_back(blanco_);
}

/**
 * @brief Constructor de la clase Cinta.
 * @param kCinta Cinta
 */
Cinta::Cinta(const std::vector<Simbolo>& kCinta,
             const Simbolo& kBlanco,
             const int kPosicionCabeza) {
  cinta_ = kCinta;
  blanco_ = kBlanco;
  posicion_cabeza_ = kPosicionCabeza;
  cinta_.push_back(blanco_);
}

/**
 * @brief Devuelve la cinta.
 * @return Cinta.
 */
std::vector<Simbolo> Cinta::getCinta() const {
  return cinta_;
}

/**
 * @brief Devuelve la posición de la cabeza.
 * @return Posición de la cabeza.
 */
int Cinta::getPosicionCabeza() const {
  return posicion_cabeza_;
}

/**
 * @brief Mueve la cabeza de la cinta.
 * @param kSimbolo Símbolo.
 */
void Cinta::MoverCabeza(const Simbolo& kSimbolo) {
  const char kDireccion = kSimbolo.getSimbolo()[0];
  switch (kDireccion) {
    case 'R':
      posicion_cabeza_++;
      break;
    case 'L':
      posicion_cabeza_--;
      break;
    case 'S':
      break;
    default:
      break;
  }
  if (posicion_cabeza_ < 0) {
    cinta_.insert(cinta_.begin(), blanco_);
    posicion_cabeza_ = 0;
  } else if (posicion_cabeza_ >= int(cinta_.size())) {
    cinta_.push_back(blanco_);
  }
}

/**
 * @brief Escribe un símbolo en la cinta.
 * @param kSimbolo Símbolo.
 */
void Cinta::Escribir(const Simbolo& kSimbolo) {
  cinta_[getPosicionCabeza()] = kSimbolo;
}

/**
 * @brief Sobrecarga del operador de inserción.
 * @param os Flujo de salida.
 * @param kCinta Cinta a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Cinta& kCinta) {
  os << "[";
  for (int iterador{0}; iterador < int(kCinta.getCinta().size()); iterador++) {
    std::string simbolo = kCinta.getCinta()[iterador].getSimbolo();
    if (iterador == kCinta.getPosicionCabeza()) {
      simbolo = "\033[1;31m" + simbolo + "\033[0m";
    }
    os << simbolo << " | ";
  }
  os << "]";
  return os;
}