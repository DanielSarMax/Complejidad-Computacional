/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Clase que representa una función primitiva recursiva de suma.
 */

#ifndef FUNCION_PRIMITIVA_RECURSIVA_SUMA_H_
#define FUNCION_PRIMITIVA_RECURSIVA_SUMA_H_

#include <iostream>
#include <vector>

#include "../funcion_primitiva_recursiva.h"

class FPR_Suma : public FuncionPrimitivaRecursiva {
 public:
  FPR_Suma() {}
  int Calcular(const int kOperando1, const int kOperando2);
  int CasoBase(const int kOperando1, const int kOperando2);
  int CasoRecursivo(const int kOperando1, const int kOperando2, const int kFuncionSuma);
};

#endif