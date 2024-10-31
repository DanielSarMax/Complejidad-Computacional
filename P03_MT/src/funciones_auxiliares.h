/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Declaración de funciones auxiliares.
 */

#ifndef FUNCIONES_AUXILIARES_H_
#define FUNCIONES_AUXILIARES_H_

#include <iostream>

void InstruccionesDeUso(int argc, char* argv[]);
const std::string kTextoDeAyuda = R"(
- Este programa determina si una cadena pertenece al lenguaje de una Máquina de Turing.
- Recibe como argumento un fichero de texto con la definición de la Máquina de Turing.
- El formato del fichero de entrada para la configuración de la Máquina de Turing debe ser el siguiente:

# Comentarios pueden comenzar con '#'

q1 q2 q3 ...     # conjunto de estados Q
a b ...          # alfabeto de entrada Σ
A B ...          # alfabeto de cinta Γ
q1               # estado inicial
_                # símbolo blanco (espacio en blanco)
q2 q3 ...        # conjunto de estados finales F
q1 a q2 A R      # transiciones en el formato (estado_actual, símbolo_leído, nuevo_estado, símbolo_escrito, movimiento)
                 # donde 'R' es movimiento a la derecha, 'L' es movimiento a la izquierda, y 'S' es sin movimiento
)";

#endif  // FUNCIONES_AUXILIARES_H_