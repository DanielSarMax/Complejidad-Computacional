/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Declaración de la clase Transición.
 */

#ifndef TRANSICION_H
#define TRANSICION_H

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

#include "../simbolo/simbolo.h"

/** Tupla de transición: (simbolo_cinta_actual, simbolo_cinta_nuevo, movimiento) */
using TuplaTransicion = std::tuple<Simbolo, Simbolo, Simbolo>;

class Transicion {
 public:
  Transicion();
  Transicion(const std::string& kEstadoOrigen,
             const std::string& kEstadoDestino,
             const std::vector<TuplaTransicion>& kTransicion);

  std::string getEstadoOrigen() const;
  std::string getEstadoDestino() const;
  std::vector<TuplaTransicion> getTransicion() const;
  std::vector<Simbolo> getSimboloActualCintas() const;
  std::vector<Simbolo> getSimboloNuevoCintas() const;
  std::vector<Simbolo> getMovimientoCintas() const;

  friend std::ostream& operator<<(std::ostream& os, const Transicion& kTransicion);

 private:
  std::string estado_origen_;
  std::string estado_destino_;
  std::vector<TuplaTransicion> transicion_; /** Cada índice corresponde con la cinta sobre la que tiene efecto */
};

#endif