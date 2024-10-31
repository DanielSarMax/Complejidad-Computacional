/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Declaración de la clase LectorMaquinaTuring.
 */

#ifndef LECTOR_MAQUINA_TURING_H
#define LECTOR_MAQUINA_TURING_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <set>

#include "../maquina_turing/maquina_turing.h"
#include "../informacion_maquina_turing.h"

class LectorMaquinaTuring {
 public:
  LectorMaquinaTuring();
  LectorMaquinaTuring(const std::string& kNombreFichero);

  InformacionMaquinaTuring LeerMaquinaTuring();
  std::vector<Estado> ExtraerEstadosDeFichero(std::ifstream& kFichero) const;
  std::set<Simbolo> ExtraerSimbolosDeFichero(std::ifstream& kFichero) const;
  std::vector<Transicion> ExtraerInformacionTransiciones(std::ifstream& kFichero) const;
  void ConfigurarEstados(Estado& kEstadoInicial,
                         std::vector<Estado>& kEstados,
                         std::vector<Estado>& kEstadosFinales,
                         std::vector<Transicion>& kTransiciones) const;

 private:
  std::string nombre_fichero_;
  InformacionMaquinaTuring informacion_leida_;
};

#endif
  