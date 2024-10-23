/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Definición de la clase Transición.
 */

#include "transicion.h"

Transicion::Transicion(const std::string& kEstadoOrigen, const Simbolo& kSimboloEntrada,
             const Simbolo& kSimboloPila, const std::string& kEstadoDestino,
             const Simbolo& kSimboloPilaResultante) {
  estado_origen_ = kEstadoOrigen;
  simbolo_entrada_ = kSimboloEntrada;
  simbolo_pila_ = kSimboloPila;
  estado_destino_ = kEstadoDestino;
  simbolo_pila_resultante_ = kSimboloPilaResultante;
}

/**
 * @brief Devuelve el estado de origen.
 * @return Estado de origen.
 */
std::string Transicion::GetNombreEstadoOrigen() const { return estado_origen_; }

/**
 * @brief Devuelve el símbolo de entrada.
 * @return Símbolo de entrada.
 */
Simbolo Transicion::GetSimboloEntrada() const { return simbolo_entrada_; }

/**
 * @brief Devuelve el símbolo de la pila.
 * @return Símbolo de la pila.
 */
Simbolo Transicion::GetSimboloPila() const { return simbolo_pila_; }

/**
 * @brief Devuelve el estado destino.
 * @return Estado destino.
 */
std::string Transicion::GetNombreEstadoDestino() const { return estado_destino_; }

/**
 * @brief Devuelve el símbolo de la pila resultante.
 * @return Símbolo de la pila resultante.
 */
Simbolo Transicion::GetSimboloPilaResultante() const { return simbolo_pila_resultante_; }

/**
 * @brief Imprime la información de la transición.
 */
void Transicion::Imprimir() const {
  std::cout << estado_origen_ << " " << simbolo_entrada_.GetSimbolo() << " "
            << simbolo_pila_.GetSimbolo() << " " << estado_destino_ << " "
            << simbolo_pila_resultante_.GetSimbolo() << std::endl;
}