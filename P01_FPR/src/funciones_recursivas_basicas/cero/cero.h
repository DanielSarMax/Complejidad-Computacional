/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Clase que representa la función nula o cero.
 */

#ifndef FUNCIONES_RECURSIVAS_BASICAS_CERO_H_
#define FUNCIONES_RECURSIVAS_BASICAS_CERO_H_

#include <iostream>

#include "../funcion_recursiva_basica.h"

class FRB_Cero : public FuncionRecursivaBasica {
 public:
  FRB_Cero() {}
  /**
   * @brief Calcula el valor de la función nula o cero.
   */
  int Calcular(const std::vector<int>& kParametros, const int kIndice) {
    Contador::IncrementarContador();
    return 0;
  }
};

#endif