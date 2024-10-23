/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Declaración de la clase Alfabeto.
 */

#ifndef ALFABETO_H
#define ALFABETO_H

#include <iostream>
#include <vector>

#include "../simbolo/simbolo.h"

class Alfabeto {
 public:
  Alfabeto(const std::vector<Simbolo>& kSimbolos) : simbolos_{kSimbolos} {}
  std::vector<Simbolo> GetSimbolos() const { return simbolos_; }
  void Imprimir() const {
    std::cout << "[ ";
    for (const Simbolo& simbolo : simbolos_) {
      std::cout << simbolo.GetSimbolo() << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
  }
  
 private:
  std::vector<Simbolo> simbolos_;
};

#endif