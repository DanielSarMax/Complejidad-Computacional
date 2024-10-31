/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición de las funciones auxiliares.
 */

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