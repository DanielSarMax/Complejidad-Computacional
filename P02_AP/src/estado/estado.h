/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Declaración de la clase Estado.
 */

#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <vector>

#include "../transicion/transicion.h"

class Estado {
 public:
  Estado();
  Estado(const std::string& kNombre, const bool kEsFinal = false);

  bool EsFinal() const;
  void SetFinal(const bool kEsFinal);
  std::string GetNombre() const;
  void SetNombre(const std::string& kNombre);
  std::vector<Transicion> GetTransiciones() const;
  void SetTransiciones(const std::vector<Transicion>& kTransiciones);
  void AgregarTransicion(const Transicion& kTransicion);
  
  void Imprimir() const;

  bool operator==(const Estado& kEstado) const { return nombre_ == kEstado.nombre_; }

 private:
  std::string nombre_;
  bool es_final_;
  std::vector<Transicion> transiciones_;
};

#endif