/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Programa cliente que nos dice si una cadena pertenece
 *               al lenguaje de un autómata con pila.
 */

#include <iostream>

#include "funciones_auxiliares.h"

int main(int argc, char* argv[]) {
  InstruccionesDeUso(argc, argv);
  AutomataPila automata{ExtraerInformacionAutomataPiLa(argv[1], true)};
  // automata.Imprimir();
  // automata.ImprimirTransicionesPorEstado();
  std::string cadena;
  std::cout << "Modo traza (\033[32ms\033[0m/\033[31mn\033[0m): ";
  char modo_traza;
  std::cin >> modo_traza;
  if (modo_traza == 's') {
    automata.SetModoTraza(true);
  } 
  while (true) {
    std::cout << "Introduce una cadena ('exit' para salir): ";
    std::cin >> cadena;
    if (cadena == "exit") {
      break;
    }
    Cadena cadena_obj{cadena};
    if (automata.ProcesarCadena(cadena_obj)) {
      std::cout << "La cadena \033[32mpertenece\033[0m al lenguaje del autómata con pila."
            << std::endl;
    } else {
      std::cout << "La cadena \033[31mno pertenece\033[0m al lenguaje del autómata con pila."
            << std::endl;
    }
    cadena.clear();
  }
  return 0;
}
