/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Declaración de la clase Alfabeto.
 */

#ifndef ALFABETO_H
#define ALFABETO_H

#include <iostream>
#include <set>

#include "../simbolo/simbolo.h"

class Alfabeto {
 public:
  Alfabeto();
  Alfabeto(const std::set<Simbolo>& kAlfabeto);

  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto);

  std::set<Simbolo> getAlfabeto() const;
  
 private:
  std::set<Simbolo> alfabeto_;
};

#endif