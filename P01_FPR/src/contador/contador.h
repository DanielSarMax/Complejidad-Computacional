/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Declaración de la clase contador.
 */

#ifndef CONTADOR_H_
#define CONTADOR_H_

#include <iostream>

class Contador {
 public:
  Contador() {}
  static void IncrementarContador() { contador_++; }
  static int ObtenerContador() { return contador_; }
  static void ResetearContador() { contador_ = 0; }
 private:
  static int contador_;
};

#endif