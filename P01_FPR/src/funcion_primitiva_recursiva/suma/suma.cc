/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Definición de la función primitiva recursiva de suma.
 */

#include "suma.h"

/**
 * @brief Calcula el valor de la función primitiva recursiva de suma.
 * @param kOperando1 Primer sumando.
 * @param kOperando2 Segundo sumando.
 */
int FPR_Suma::Calcular(const int kOperando1, const int kOperando2) {
  Contador::IncrementarContador();
  EsNatural({kOperando1, kOperando2});
  if (kOperando2 == 0) {
    return CasoBase(kOperando1, kOperando2);
  }
  return CasoRecursivo(kOperando1, kOperando2, Calcular(kOperando1, kOperando2 - 1));
}

/**
 * @brief Calcula el valor de la función primitiva recursiva de suma en el caso base.
 * @param kOperando1 Primer parámetro, de carácter constante.
 * @param kOperando2 Segundo parámetro, de carácter variable.
 */
int FPR_Suma::CasoBase(const int kOperando1, const int kOperando2) {
  Contador::IncrementarContador();
  funcion_recursiva_basica_ = new FRB_Proyeccion();
  return funcion_recursiva_basica_->Calcular({kOperando1}, 0);
}

/**
 * @brief Calcula el valor de la función primitiva recursiva de suma en el caso recursivo.
 * @param kOperando1 Primer parámetro, de carácter constante.
 * @param kOperando2 Segundo parámetro, de carácter variable.
 * @param kFuncionSuma Valor de la función primitiva recursiva de suma.
 */
int FPR_Suma::CasoRecursivo(const int kOperando1, const int kOperando2, const int kFuncionSuma) {
  Contador::IncrementarContador();
  funcion_recursiva_basica_ = new FRB_Proyeccion();
  int primera_proyeccion = funcion_recursiva_basica_->Calcular({kOperando1, kOperando2 - 1, kFuncionSuma}, 2);
  funcion_recursiva_basica_ = new FRB_Sucesor();
  return funcion_recursiva_basica_->Calcular({primera_proyeccion}, 0);
}
  