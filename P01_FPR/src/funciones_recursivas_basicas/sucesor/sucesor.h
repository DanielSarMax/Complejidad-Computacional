/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Clase que representa la función sucesor.
 */

#ifndef FUNCIONES_RECURSIVAS_BASICAS_SUCESOR_H_
#define FUNCIONES_RECURSIVAS_BASICAS_SUCESOR_H_

#include <iostream>

#include "../funcion_recursiva_basica.h"

class FRB_Sucesor : public FuncionRecursivaBasica {
 public:
  FRB_Sucesor() {}
  /**
   * @brief Calcula el valor de la función sucesor.
   */
  int Calcular(const std::vector<int>& kParametros, const int kIndice) {
    Contador::IncrementarContador();
    if (kParametros.size() != 1) {
      std::cerr << "Error: Número de parámetros incorrecto." << std::endl;
      exit(1);
    }
    return (kParametros[0] + 1);
  }
};

#endif