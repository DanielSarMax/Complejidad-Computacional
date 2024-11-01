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
  std::cout << "Introduzca la cadena a procesar: ";
  std::cin >> cadena_a_procesar;
  if (maquina_turing.Ejecutar(cadena_a_procesar)) {
    std::cout << "La máquina de Turing ha parado en un estado de aceptación."
              << std::endl;
  } else {
    std::cout << "La máquina de Turing ha parado en un estado de rechazo."
              << std::endl;
  }
  maquina_turing.ImprimirCintas();
  return 0;
}