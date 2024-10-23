/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Declaración de la clase Transición.
 */

#ifndef TRANSICION_H
#define TRANSICION_H

#include <iostream>

#include "../simbolo/simbolo.h"

class Transicion {
 public:
  Transicion();
  Transicion(const std::string& kEstadoOrigen, const Simbolo& kSimboloEntrada,
             const Simbolo& kSimboloPila, const std::string& kEstadoDestino,
             const Simbolo& kSimboloPilaResultante);

  std::string GetNombreEstadoOrigen() const;
  Simbolo GetSimboloEntrada() const;
  Simbolo GetSimboloPila() const;
  std::string GetNombreEstadoDestino() const;
  Simbolo GetSimboloPilaResultante() const;

  void Imprimir() const;

 private:
  std::string estado_origen_;
  Simbolo simbolo_entrada_;
  Simbolo simbolo_pila_;
  std::string estado_destino_;
  Simbolo simbolo_pila_resultante_;
};

#endif