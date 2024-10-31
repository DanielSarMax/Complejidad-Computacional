/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Declaración de la clase Cinta.
 */

#ifndef CINTA_H
#define CINTA_H

#include <iostream>
#include <vector>

#include "../simbolo/simbolo.h"

class Cinta {
 public:
  Cinta();
  Cinta(const std::vector<Simbolo>& kCinta,
        const Simbolo& kBlanco,
        const int kPosicionCabeza = 0);

  std::vector<Simbolo> getCinta() const;
  int getPosicionCabeza() const;

  void MoverCabeza(const Simbolo& kSimbolo);
  void Escribir(const Simbolo& kSimbolo);

  friend std::ostream& operator<<(std::ostream& os, const Cinta& kCinta);

 private:
  std::vector<Simbolo> cinta_;
  int posicion_cabeza_;
  Simbolo blanco_;
};

#endif