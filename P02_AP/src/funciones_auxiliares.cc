/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Definición de funciones auxiliares.
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "automatapila/automatapila.h"
#include "funciones_auxiliares.h"

/**
 * @brief Muestra las instrucciones de uso del programa.
 * @param argc Número de argumentos.
 * @param argv Argumentos.
 */
void InstruccionesDeUso(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << ": Falta el fichero de entrada" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información"
              << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kTextoDeAyuda << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief Extrae los estados de un fichero.
 * @param kFichero Fichero de entrada.
 * @return Vector de estados.
 */
std::vector<Estado> ExtraerEstadosDeFichero(std::ifstream& kFichero) {
  std::string linea;
  std::getline(kFichero, linea);
  std::istringstream stream{linea};
  std::vector<Estado> estados;
  std::string nombre_estado;
  while (stream >> nombre_estado) {
    estados.push_back(Estado{nombre_estado});
  }
  return estados;
}

/**
 * @brief Extrae los símbolos de un fichero.
 * @param kFichero Fichero de entrada.
 * @return Vector de símbolos.
 */
std::vector<Simbolo> ExtraerSimbolosDeFichero(std::ifstream& kFichero) {
  std::string linea;
  std::getline(kFichero, linea);
  std::istringstream stream{linea};
  std::vector<Simbolo> simbolos;
  std::string simbolo;
  while (stream >> simbolo) {
    simbolos.push_back(Simbolo{simbolo});
  }
  return simbolos;
}

/**
 * @brief Extrae las transiciones de un fichero.
 * @param kFichero Fichero de entrada.
 * @param kNombreFichero Nombre del fichero.
 * @return Vector de transiciones.
 */
std::vector<Transicion> ExtraerInformacionTransiciones(
    std::ifstream& kFichero, const std::string& kNombreFichero) {
  std::vector<Transicion> transiciones;
  std::string linea;
  while (std::getline(kFichero, linea)) {
    std::istringstream stream{linea};
    std::string estado_origen;
    std::string simbolo_entrada;
    std::string simbolo_pila;
    std::string estado_destino;
    std::string simbolo_pila_resultante;
    stream >> estado_origen >> simbolo_entrada >> simbolo_pila >>
        estado_destino >> simbolo_pila_resultante;
    transiciones.push_back(Transicion{estado_origen, Simbolo{simbolo_entrada},
                                      Simbolo{simbolo_pila}, estado_destino,
                                      Simbolo{simbolo_pila_resultante}});
  }
  return transiciones;
}

/**
 * @brief Configura los estados de un autómata con pila.
 * @param kEstados Estados.
 * @param kEstadosFinales Estados finales.
 * @param kTransiciones Transiciones.
 */
void ConfigurarEstados(Estado& kEstadoInicial,
                       std::vector<Estado>& kEstados,
                       std::vector<Estado>& kEstadosFinales,
                       const std::vector<Transicion>& kTransiciones) {
  // Establecer las transiciones de los estados
  for (Estado& estado : kEstados) {
    for (const Transicion& transicion : kTransiciones) {
      if (estado.GetNombre() == transicion.GetNombreEstadoOrigen()) {
        estado.AgregarTransicion(transicion);
        if (estado.GetNombre() == kEstadoInicial.GetNombre()) {
          kEstadoInicial.AgregarTransicion(transicion);
        }
      }
    }
  }
  // Establecer si los estados son finales
  for (Estado& estado : kEstados) {
    for (Estado& estado_final : kEstadosFinales) {
      if (estado.GetNombre() == estado_final.GetNombre()) {
        estado.SetFinal(true);
      }
    }
  }
  // Establecer las transiciones de los estados finales
  for (Estado& estado : kEstadosFinales) {
    for (const Transicion& transicion : kTransiciones) {
      if (estado.GetNombre() == transicion.GetNombreEstadoOrigen()) {
        estado.AgregarTransicion(transicion);
      }
    }
  }
}

/**
 * @brief Extrae la información de un autómata con pila de un fichero.
 * @param kNombreFichero Nombre del fichero.
 * @param kEsFinalPorEstadoFinal Indica si el autómata es final por estado
 * final.
 * @return Autómata con pila.
 */
AutomataPila ExtraerInformacionAutomataPiLa(const std::string& kNombreFichero,
                                            bool kEsFinalPorEstadoFinal) {
  std::ifstream fichero{kNombreFichero};
  if (!fichero) {
    std::cerr << "Error al abrir el fichero " << kNombreFichero << std::endl;
    exit(EXIT_SUCCESS);
  }
  // Si la línea empieza por # es un comentario
  std::string linea;
  while (std::getline(fichero, linea)) {
    if (linea[0] != '#') {
      // Retroceder el puntero del fichero a la posición anterior
      fichero.seekg(-linea.size() - 1, std::ios_base::cur);
      break;
    }
  }
  std::vector<Estado> estados = ExtraerEstadosDeFichero(fichero);
  std::vector<Simbolo> alfabeto_entrada = ExtraerSimbolosDeFichero(fichero);
  std::vector<Simbolo> alfabeto_pila = ExtraerSimbolosDeFichero(fichero);
  // Línea 4: Estado inicial
  std::string estado_inicial;
  std::getline(fichero, estado_inicial);
  // Línea 5: Símbolo inicial de la pila
  std::string simbolo_inicial_pila;
  std::getline(fichero, simbolo_inicial_pila);
  // Línea 6 (solamente en el caso de APf (finalización por estado final)):
  // Estados finales
  std::vector<Estado> estados_finales;
  if (kEsFinalPorEstadoFinal) {
    estados_finales = ExtraerEstadosDeFichero(fichero);
    for (Estado& estado : estados_finales) {
      estado.SetFinal(true);
    }
  }
  // Líneas 7 en adelante: Transiciones
  std::vector<Transicion> transiciones =
      ExtraerInformacionTransiciones(fichero, kNombreFichero);
  fichero.close();
  Estado estado_inicial_obj{estado_inicial};
  ConfigurarEstados(estado_inicial_obj, estados, estados_finales, transiciones);
  return AutomataPila{estados,
                      Alfabeto{alfabeto_entrada},
                      Alfabeto{alfabeto_pila},
                      estado_inicial_obj,
                      Simbolo{simbolo_inicial_pila},
                      transiciones,
                      estados_finales};
}