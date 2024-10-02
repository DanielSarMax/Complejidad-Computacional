/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Declaración de la función primitiva recursiva de potencia.
 */

#ifndef FUNCION_PRIMITIVA_RECURSIVA_POTENCIA_H_
#define FUNCION_PRIMITIVA_RECURSIVA_POTENCIA_H_

#include <iostream>

#include "../funcion_primitiva_recursiva.h"

class FPR_Potencia : public FuncionPrimitivaRecursiva {
 public:
  FPR_Potencia() {}
  int Calcular(const int kBase, const int kExponente);
  int CasoBase(const int kBase, const int kExponente);
  int CasoRecursivo(const int kBase, const int kExponente, const int kFuncionPotencia);
};

#endif