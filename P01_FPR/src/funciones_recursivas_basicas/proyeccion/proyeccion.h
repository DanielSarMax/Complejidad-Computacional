/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Clase que representa la función proyección.
 */

#ifndef FUNCIONES_RECURSIVAS_BASICAS_PROYECCION_H_
#define FUNCIONES_RECURSIVAS_BASICAS_PROYECCION_H_

#include <iostream>
#include <vector>

#include "../funcion_recursiva_basica.h"

class FRB_Proyeccion : public FuncionRecursivaBasica {
 public:
  FRB_Proyeccion() {}

  /**
   * @brief Calcula el valor de la función proyección.
   */
  int Calcular(const std::vector<int>& kParametros, const int kIndice) {
    Contador::IncrementarContador();
    ComprobarIndice(kParametros.size(), kIndice);
    return (kParametros[kIndice]);
  };
};

#endif