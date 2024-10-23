/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Declaración de la clase Cadena.
 */

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <vector>

#include "../simbolo/simbolo.h"

class Cadena {
 public:
  Cadena(const std::string& kCadena) : cadena_{kCadena} {
    for (char simbolo : cadena_) {
      simbolos_.push_back(Simbolo{std::string(1, simbolo)});
    }
  }

  std::string GetCadena() const { return cadena_; }
  std::vector<Simbolo> GetSimbolos() const { return simbolos_; }

 private:
  std::string cadena_;
  std::vector<Simbolo> simbolos_;
};

#endif