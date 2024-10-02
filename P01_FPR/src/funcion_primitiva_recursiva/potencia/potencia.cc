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

#include "potencia.h"

/**
 * @brief Calcula el valor de la función primitiva recursiva de potencia.
 * @param kBase Base.
 * @param kExponente Exponente.
 */
int FPR_Potencia::Calcular(const int kBase, const int kExponente) {
  Contador::IncrementarContador();
  EsNatural({kBase, kExponente});
  if (kExponente == 0) {
    return CasoBase(kBase, kExponente);
  }
  return CasoRecursivo(kBase, kExponente, Calcular(kBase, kExponente - 1));
}

/**
 * @brief Calcula el valor de la función primitiva recursiva de potencia en el caso base.
 * @param kBase Primer parámetro, de carácter constante.
 * @param kExponente Segundo parámetro, de carácter variable.
 */
int FPR_Potencia::CasoBase(const int kBase, const int kExponente) {
  Contador::IncrementarContador();
  funcion_recursiva_basica_ = new FRB_Cero();
  int resultado_nulo = funcion_recursiva_basica_->Calcular({kBase}, 0);
  funcion_recursiva_basica_ = new FRB_Sucesor();
  return funcion_recursiva_basica_->Calcular({resultado_nulo}, 0);
}

/**
 * @brief Calcula el valor de la función primitiva recursiva de potencia en el caso recursivo.
 * @param kBase Primer parámetro, de carácter constante.
 * @param kExponente Segundo parámetro, de carácter variable.
 * @param kFuncionPotencia Valor de la función primitiva recursiva de potencia.
 */
int FPR_Potencia::CasoRecursivo(const int kBase, const int kExponente, const int kFuncionPotencia) {
  Contador::IncrementarContador();
  const std::vector<int> kParametros = {kBase, kExponente - 1, kFuncionPotencia};
  funcion_recursiva_basica_ = new FRB_Proyeccion();
  const int kPrimerParametro = funcion_recursiva_basica_->Calcular(kParametros, 2);
  const int kSegundoParametro = funcion_recursiva_basica_->Calcular(kParametros, 0);
  FuncionPrimitivaRecursiva* multiplicacion = new FPR_Multiplicacion();
  return multiplicacion->Calcular(kPrimerParametro, kSegundoParametro);
}