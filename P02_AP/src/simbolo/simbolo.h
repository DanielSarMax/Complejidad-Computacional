/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Declaración de la clase Simbolo.
 */

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <vector>

class Simbolo {
 public:
  Simbolo(const std::string& kSimbolo = "") : simbolo_{kSimbolo} {
    for (char caracter : simbolo_) {
      simbolo_separado_.push_back(std::string{caracter});
    }
  };
  std::string GetSimbolo() const { return simbolo_; }
  void SetSimbolo(const std::string& kSimbolo) { 
    simbolo_ = kSimbolo;
    simbolo_separado_.clear();
    for (char caracter : simbolo_) {
      simbolo_separado_.push_back(std::string{caracter});
    }
  }
  std::vector<std::string> GetSimboloSeparado() const { return simbolo_separado_; }

  bool operator==(const Simbolo& kSimbolo) const { return simbolo_ == kSimbolo.simbolo_; }

 private:
  std::string simbolo_;
  std::vector<std::string> simbolo_separado_;
};

#endif