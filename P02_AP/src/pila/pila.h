/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Declaración de la clase Pila.
 */

#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stack>

#include "../simbolo/simbolo.h"

class Pila {
 public:
  Pila() = default;
  Pila(const std::stack<Simbolo>& kPila) : pila_{kPila} {}

  void Push(const Simbolo& kSimbolo) { pila_.push(kSimbolo); }
  void Pop() { pila_.pop(); }
  bool IsEmpty() const { return pila_.empty(); }
  Simbolo Top() const { return pila_.top(); }

  void Imprimir() const;

  bool operator==(const Pila& kPila) const { return pila_ == kPila.pila_; }

 private:
  std::stack<Simbolo> pila_;
};

#endif