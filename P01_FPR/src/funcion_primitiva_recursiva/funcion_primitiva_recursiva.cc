/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Definición de los métodos de la clase FuncionPrimitivaRecursiva.
 */

#include "funcion_primitiva_recursiva.h"

/**
 * @brief Comprueba si los números son naturales.
 * @param kNumeros Vector de números.
 */
void FuncionPrimitivaRecursiva::EsNatural(const std::vector<int>& kNumeros) {
  Contador::IncrementarContador();
  for (int i = 0; i < kNumeros.size(); i++) {
    if (kNumeros[i] < 0) {
      std::cerr << "Error: El número " << kNumeros[i] << " no es natural." << std::endl;
      exit(1);
    }
  }
}