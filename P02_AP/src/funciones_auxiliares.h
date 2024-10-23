/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Declaración de funciones auxiliares.
 */

#include "automatapila/automatapila.h"

void InstruccionesDeUso(int argc, char* argv[]);
AutomataPila ExtraerInformacionAutomataPiLa(
    const std::string& kNombreFichero, bool kEsFinalPorEstadoFinal = false);
std::vector<Estado> ExtraeInformacionEstados(std::vector<Estado>& kEstados,
                                             const std::string& kLinea);
std::vector<Simbolo> ExtraeInformacionAlfabeto(const std::string& kLinea);
std::vector<Transicion> ExtraeInformacionTransiciones(
    std::vector<Transicion>& kTransiciones, const std::string& kNombreFichero);
void ConfigurarEstados(Estado& kEstadoInicial,
                       std::vector<Estado>& kEstados,
                       std::vector<Estado>& kEstadosFinales,
                       const std::vector<Transicion>& kTransiciones);

const std::string kTextoDeAyuda = 
  "Este programa determina si una cadena pertenece al lenguaje "
  "de un autómata con pila.\n"
  "El programa recibe como argumento un fichero de texto con"
  " la definición del autómata.\n"
  "El fichero de texto debe tener el siguiente formato:\n"
  "# Comentarios\n"
  "Línea 1: Nombre de los estados separados por espacios\n"
  "Línea 2: Alfabeto de entrada separado por espacios\n"
  "Línea 3: Alfabeto de la pila separado por espacios\n"
  "Línea 4: Estado inicial\n"
  "Línea 5: Símbolo inicial de la pila\n"
  "Línea 6 (solamente en el caso de APf (finalización por "
  "estado final)):"
  " Estados finales separados por espacios\n"
  "Líneas 7 en adelante: Transiciones en el formato "
  "'estado_origen símbolo_entrada símbolo_pila estado_destino "
  "simbolo_pila_resultante'\n";

