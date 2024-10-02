/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Clase que representa una función primitiva recursiva.
 */

#ifndef FUNCION_PRIMITIVA_RECURSIVA_H_
#define FUNCION_PRIMITIVA_RECURSIVA_H_

#include <iostream>
#include <vector>

#include "../funciones_recursivas_basicas/funcion_recursiva_basica.h"
#include "../funciones_recursivas_basicas/cero/cero.h"
#include "../funciones_recursivas_basicas/sucesor/sucesor.h"
#include "../funciones_recursivas_basicas/proyeccion/proyeccion.h"

class FuncionPrimitivaRecursiva {
 public:
  virtual int Calcular(const int kOperando1, const int kOperando2) = 0;
  virtual int CasoBase(const int kOperando1, const int kOperando2) = 0;
  virtual int CasoRecursivo(const int kOperando1, const int kOperando2, const int kOperando3) = 0;
  void EsNatural(const std::vector<int>& kNumeros);
 protected:
  FuncionRecursivaBasica* funcion_recursiva_basica_ = nullptr;
};

#include "suma/suma.h"
#include "multiplicacion/multiplicacion.h"
#include "potencia/potencia.h"

#endif