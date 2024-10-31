/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
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
  Estado(const std::string& kNombre, 
         const std::vector<Transicion>& kTransiciones = {}, 
         bool kEsFinal = false);

  std::string getNombre() const;
  bool esFinal() const;
  std::vector<Transicion> getTransiciones() const;

  void setEsFinal(bool kEsFinal);

  void AgregarTransicion(const Transicion& kTransicion);

  friend std::ostream& operator<<(std::ostream& os, const Estado& estado);

 private:
  std::string nombre_;
  bool es_final_;
  std::vector<Transicion> transiciones_;
};

#endif