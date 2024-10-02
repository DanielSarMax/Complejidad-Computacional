/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Clase que representa una función recursiva básica.
 */

#ifndef FUNCION_RECURSIVA_BASICA_H_
#define FUNCION_RECURSIVA_BASICA_H_

#include <iostream>
#include <vector>
#include <string>

#include "../funciones_auxiliares/funciones.h"
#include "../contador/contador.h"

class FuncionRecursivaBasica {
 public:
  virtual int Calcular(const std::vector<int>& kParametros, const int kIndice = 0) = 0;
};

#endif