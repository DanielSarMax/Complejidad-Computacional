/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Declaración de la clase MaquinaTuring.
 */

#ifndef MAQUINA_TURING_H
#define MAQUINA_TURING_H

#include <iostream>
#include <vector>

#include "../estado/estado.h"
#include "../alfabeto/alfabeto.h"
#include "../cinta/cinta.h"

class MaquinaTuring {
 public:
  MaquinaTuring();
  MaquinaTuring(const Estado& kEstadoInicial,
                const Alfabeto& kAlfabetoEntrada,
                const Alfabeto& kAlfabetoCinta,
                const std::vector<Estado>& kEstados,
                const Simbolo& kBlanco,
                const int kNumeroCintas);
  Estado getEstadoInicial() const;
  Alfabeto getAlfabetoEntrada() const;
  Alfabeto getAlfabetoCinta() const;
  std::vector<Estado> getEstados() const;
  Simbolo getBlanco() const;
  int getNumeroCintas() const;
  std::vector<Cinta> getCintas() const;
  bool Ejecutar(const std::string& kCadena);
  void InsertarCadena(const std::string& kCadena);
  Estado BuscarEstado(const std::string& kNombreEstado) const;
  void ImprimirCintas() const;
  friend std::ostream& operator<<(std::ostream& os, const MaquinaTuring& kMaquinaTuring);

 private:
  Estado estado_inicial_;
  Alfabeto alfabeto_entrada_;
  Alfabeto alfabeto_cinta_;
  std::vector<Estado> estados_;
  std::vector<Cinta> cintas_;
  Simbolo blanco_;
  int numero_cintas_;
};

#endif