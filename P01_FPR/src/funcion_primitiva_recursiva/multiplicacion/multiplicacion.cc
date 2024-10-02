/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since September 2024
 * @description: Definición de la función primitiva recursiva de multiplicación.
 */

#include "multiplicacion.h"

/**
 * @brief Calcula el valor de la función primitiva recursiva de multiplicación.
 * @param kMultiplicando Primer factor.
 * @param kMultiplicador Segundo factor.
 */
int FPR_Multiplicacion::Calcular(const int kMultiplicando, const int kMultiplicador) {
  Contador::IncrementarContador();
  EsNatural({kMultiplicando, kMultiplicador});
  if (kMultiplicador == 0) {
    return CasoBase(kMultiplicando, kMultiplicador);
  }
  return CasoRecursivo(kMultiplicando, kMultiplicador, Calcular(kMultiplicando, kMultiplicador - 1));
}

/**
 * @brief Calcula el valor de la función primitiva recursiva de multiplicación en el caso base.
 * @param kMultiplicando Primer parámetro, de carácter constante.
 * @param kMultiplicador Segundo parámetro, de carácter variable.
 */
int FPR_Multiplicacion::CasoBase(const int kMultiplicando, const int kMultiplicador) {
  Contador::IncrementarContador();
  funcion_recursiva_basica_ = new FRB_Cero();
  return funcion_recursiva_basica_->Calcular({}, 0);
}

/**
 * @brief Calcula el valor de la función primitiva recursiva de multiplicación en el caso recursivo.
 * @param kMultiplicando Primer parámetro, de carácter constante.
 * @param kMultiplicador Segundo parámetro, de carácter variable.
 * @param kFuncionMultiplicacion Valor de la función primitiva recursiva de multiplicación.
 */
int FPR_Multiplicacion::CasoRecursivo(const int kMultiplicando, const int kMultiplicador, const int kFuncionMultiplicacion) {
  Contador::IncrementarContador();
  const std::vector<int> kParametros = {kMultiplicando, kMultiplicador - 1, kFuncionMultiplicacion};
  funcion_recursiva_basica_ = new FRB_Proyeccion();
  const int kPrimerParametro = funcion_recursiva_basica_->Calcular(kParametros, 2);
  const int kSegundoParametro = funcion_recursiva_basica_->Calcular(kParametros, 0);
  FuncionPrimitivaRecursiva* suma = new FPR_Suma();
  return suma->Calcular(kPrimerParametro, kSegundoParametro);
}