/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición del struct InformacionMaquinaTuring.
 */

#ifndef INFORMACION_MAQUINA_TURING_H
#define INFORMACION_MAQUINA_TURING_H

#include "./maquina_turing/maquina_turing.h"

struct InformacionMaquinaTuring {
  Estado estado_inicial_;
  Alfabeto alfabeto_entrada_;
  Alfabeto alfabeto_cinta_;
  std::vector<Estado> estados_;
  Simbolo blanco_;
  int numero_cintas_;
  Alfabeto alfabeto_movimientos_ = Alfabeto({Simbolo{"L"}, Simbolo{"R"}, Simbolo{"S"}});
};

#endif