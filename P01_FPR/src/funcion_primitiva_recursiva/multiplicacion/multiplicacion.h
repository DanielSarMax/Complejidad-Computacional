/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Declaración de la función primitiva recursiva de multiplicación.
 */

#ifndef FUNCION_PRIMITIVA_RECURSIVA_MULTIPLICACION_H_
#define FUNCION_PRIMITIVA_RECURSIVA_MULTIPLICACION_H_

#include <iostream>
#include <vector>

#include "../funcion_primitiva_recursiva.h"

class FPR_Multiplicacion : public FuncionPrimitivaRecursiva {
 public:
  FPR_Multiplicacion() {}
  int Calcular(const int kMultiplicando, const int kMultiplicador);
  int CasoBase(const int kMultiplicando, const int kMultiplicador);
  int CasoRecursivo(const int kMultiplicando, const int kMultiplicador, const int kFuncionMultiplicacion);
};

#endif
