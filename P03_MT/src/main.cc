/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Programa principal que ejecuta una máquina de Turing
 *               con una entrada dada por el usuario.
 */

#include <iostream>

#include "./lector_maquina_turing/lector_maquina_turing.h"
#include "./funciones_auxiliares.h"

int main(int argc, char* argv[]) {
  InstruccionesDeUso(argc, argv);
  InformacionMaquinaTuring informacion_maquina_turing =
      LectorMaquinaTuring{argv[1]}.LeerMaquinaTuring();
  MaquinaTuring maquina_turing{informacion_maquina_turing.estado_inicial_,
                               informacion_maquina_turing.alfabeto_entrada_,
                               informacion_maquina_turing.alfabeto_cinta_,
                               informacion_maquina_turing.estados_,
                               informacion_maquina_turing.blanco_,
                               informacion_maquina_turing.numero_cintas_};
  std::cout << maquina_turing << std::endl;
  std::string cadena_a_procesar;
  while (true) {
    std::cout << "Elija una opción: " << std::endl;
    std::cout << "1. Introducir cadena" << std::endl;
    std::cout << "2. Salir" << std::endl;
    std::cout << "-> ";
    int opcion;
    std::cin >> opcion;
    std::string cadena_a_procesar;
    switch (opcion) {
      case 1:
        std::cout << "Introduzca la cadena a procesar: ";
        std::cin >> cadena_a_procesar;
        if (maquina_turing.Ejecutar(cadena_a_procesar)) {
            std::cout << "La máquina de Turing ha parado en un estado de \033[1;32maceptación\033[0m."
                << std::endl;
        } else {
            std::cout << "La máquina de Turing ha parado en un estado de \033[1;31mrechazo\033[0m."
                << std::endl;
        }
        maquina_turing.ImprimirCintas();
        std::cout << std::endl;
        break;
      case 2:
        return 0;
      default:
        std::cerr << "Error: Opción no válida." << std::endl;
        return 0;
    }
  }
  return 0;
}