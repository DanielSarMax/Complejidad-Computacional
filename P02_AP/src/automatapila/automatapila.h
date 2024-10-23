/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Declaración de la clase AutomataPila.
 */

#ifndef AUTOMATA_PILA_H
#define AUTOMATA_PILA_H

#include <iostream>
#include <vector>

#include "../alfabeto/alfabeto.h"
#include "../cadena/cadena.h"
#include "../estado/estado.h"
#include "../pila/pila.h"
#include "../simbolo/simbolo.h"
#include "../transicion/transicion.h"

class AutomataPila {
 public:
  AutomataPila(const std::vector<Estado>& kEstados,
               const Alfabeto& kAlfabetoEntrada, const Alfabeto& kAlfabetoPila,
               const Estado& kEstadoInicial, const Simbolo& kSimboloInicialPila,
               const std::vector<Transicion>& kTransiciones,
               const std::vector<Estado>& kEstadosFinales = {});

  void Imprimir() const;
  void ImprimirTransicionesPorEstado() const;

  Estado GetEstado(const std::string& kNombre) const;
  Simbolo GetSimboloInicialPila() const;
  Alfabeto GetAlfabetoPila() const;
  Alfabeto GetAlfabetoEntrada() const;
  void SetModoTraza(const bool kModoTraza);

  bool ProcesarCadena(const Cadena& kCadena);

 private:
  Pila pila_;
  std::vector<Estado> estados_;
  Alfabeto alfabeto_entrada_;
  Alfabeto alfabeto_pila_;
  Estado estado_inicial_;
  Simbolo simbolo_inicial_pila_;
  std::vector<Transicion> transiciones_;
  std::vector<Estado> estados_finales_;
  bool modo_traza_;

  void ComprobarCadena(const Cadena& kCadena) const;
  bool EsTransicionValida(const Transicion& kTransicion,
                          const Simbolo& kSimboloCadena,
                          const Simbolo& kSimboloPila) const;
  void InsertaSimboloEnPila(const Simbolo& kSimbolo, Pila& kPila) const;
  bool EsFinalPorEstadoFinal(const Cadena& kCadena,
                             const std::vector<Estado>& kEstadosActuales,
                             const int kPosicion) const;

  bool EsEstadoValido(const Estado& kEstado) const;
  bool EsSimboloValido(const Simbolo& kSimbolo,
                       const Alfabeto& kAlfabeto) const;
  void CompruebaAutomata() const;
  void CompruebaEstadoInicial() const;
  void CompruebaEstadoFinal() const;
  void CompruebaTransicion(const Transicion& kTransicion) const;
  void CompruebaSimboloInicialPila() const;

  void ResetearPila();
  void ImprimirTraza(
      const Estado& kEstadoActual, const Cadena& kCadena,
      const int kPosicionPuntero, const Pila& kPilaActual,
      const std::vector<Transicion>& kPosiblesTransiciones) const;
};

#endif