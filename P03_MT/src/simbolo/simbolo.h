/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Declaración de la clase Simbolo.
 */

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <vector>

class Simbolo {
 public:
  Simbolo();
  Simbolo(const std::string& kSimbolo);

  std::string getSimbolo() const { return simbolo_; }

  friend std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo);
  friend bool operator==(const Simbolo& kSimbolo1, const Simbolo& kSimbolo2);

 private:
  std::string simbolo_;
};

bool operator<(const Simbolo& kSimbolo1, const Simbolo& kSimbolo2);

#endif