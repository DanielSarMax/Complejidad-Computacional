/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Programa cliente que calcula el valor de la función primitiva recursiva de suma.
 */

#include <iostream>

#include "funcion_primitiva_recursiva/funcion_primitiva_recursiva.h"

int Contador::contador_ = 0;

int main(int argc, char* argv[]) {
  while (true) {
    std::cout << "Introduce la base de la potencia: ";
    int base = 0;
    std::cin >> base;
    std::cout << "Introduce el exponente de la potencia: ";
    int exponente = 0;
    std::cin >> exponente;

    FPR_Potencia potencia;
    std::cout << "El resultado de la función primitiva recursiva de potencia es: " << potencia.Calcular(base, exponente) << std::endl;
    std::cout << "Número de operaciones realizadas: " << Contador::ObtenerContador() << std::endl;
    Contador::ResetearContador();

    std::cout << "[1] Realizar otra operación" << std::endl;
    std::cout << "[2] Salir" << std::endl;
    std::cout << "Introduce una opción: ";
    int opcion = 0;
    std::cin >> opcion;
    if (opcion == 2 || opcion != 1) {
      break;
    }
  }
  return 0;
}
