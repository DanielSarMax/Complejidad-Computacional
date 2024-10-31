/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición de los métodos de la clase LectorMaquinaTuring.
 */

#include "lector_maquina_turing.h"

/**
 * @brief Constructor por defecto de la clase LectorMaquinaTuring.
 */
LectorMaquinaTuring::LectorMaquinaTuring() {
  nombre_fichero_ = "";
  informacion_leida_ = InformacionMaquinaTuring();
}

/**
 * @brief Constructor de la clase LectorMaquinaTuring.
 * @param kNombreFichero Nombre del fichero a leer.
 */
LectorMaquinaTuring::LectorMaquinaTuring(const std::string& kNombreFichero) {
  nombre_fichero_ = kNombreFichero;
  informacion_leida_ = InformacionMaquinaTuring();
}

/**
 * @brief Extrae los estados de un fichero.
 * @param kFichero Fichero de entrada.
 * @return Vector de estados.
 */
std::vector<Estado> LectorMaquinaTuring::ExtraerEstadosDeFichero(
    std::ifstream& kFichero) const {
  std::string linea;
  std::getline(kFichero, linea);
  std::istringstream stream{linea};
  std::vector<Estado> estados;
  std::string nombre_estado;
  while (stream >> nombre_estado) {
    estados.push_back(Estado{nombre_estado});
  }
  return estados;
}

/**
 * @brief Extrae los símbolos de un fichero.
 * @param kFichero Fichero de entrada.
 * @return Set de símbolos.
 */
std::set<Simbolo> LectorMaquinaTuring::ExtraerSimbolosDeFichero(
    std::ifstream& kFichero) const {
  std::string linea;
  std::getline(kFichero, linea);
  std::istringstream stream{linea};
  std::set<Simbolo> simbolos;
  std::string simbolo;
  while (stream >> simbolo) {
    simbolos.insert(Simbolo{simbolo});
  }
  return simbolos;
}

/**
 * @brief Extrae la información de las transiciones de un fichero.
 * @param kFichero Fichero de entrada.
 * @return Vector de transiciones
 * @details Las transiciones se encuentran en el fichero en el formato:
 * 'estado_origen, numero_cintas * (simbolo_cinta_actual), estado_destino,
 * numero_cintas * (simbolo_cinta_nuevo movimiento)'
 */
std::vector<Transicion> LectorMaquinaTuring::ExtraerInformacionTransiciones(
    std::ifstream& kFichero) const {
  std::vector<Transicion> transiciones;
  std::string linea;
  while (std::getline(kFichero, linea)) {
    std::istringstream stream{linea};
    std::string estado_origen;
    std::string estado_destino;
    stream >> estado_origen;
    std::vector<TuplaTransicion> tuplas_transicion;
    std::vector<Simbolo> simbolo_actual_cintas;
    std::vector<Simbolo> simbolo_nuevo_cintas;
    std::vector<Simbolo> movimientos;
    for (int i = 0; i < informacion_leida_.numero_cintas_; i++) {
      std::string simbolo_actual;
      stream >> simbolo_actual;
      simbolo_actual_cintas.push_back(Simbolo{simbolo_actual});
    }
    stream >> estado_destino;
    for (int i = 0; i < informacion_leida_.numero_cintas_; i++) {
      std::string simbolo_nuevo;
      std::string movimiento;
      stream >> simbolo_nuevo >> movimiento;
      simbolo_nuevo_cintas.push_back(Simbolo{simbolo_nuevo});
      movimientos.push_back(Simbolo{movimiento});
    }
    for (int i = 0; i < informacion_leida_.numero_cintas_; i++) {
      tuplas_transicion.push_back(std::make_tuple(
          simbolo_actual_cintas[i], simbolo_nuevo_cintas[i], movimientos[i]));
    }
    transiciones.push_back(
        Transicion{estado_origen, estado_destino, tuplas_transicion});
  }
  return transiciones;
}

/**
 * @brief Configura los estados de la máquina de Turing.
 * @param kEstadoInicial Estado inicial de la máquina de Turing.
 * @param kEstados Estados de la máquina de Turing.
 * @param kEstadosFinales Estados finales de la máquina de Turing.
 * @param kTransiciones Transiciones de la máquina de Turing.
 */
void LectorMaquinaTuring::ConfigurarEstados(
    Estado& kEstadoInicial, std::vector<Estado>& kEstados,
    std::vector<Estado>& kEstadosFinales,
    std::vector<Transicion>& kTransiciones) const {
  // Establecer las transiciones de los estados
  for (Estado& estado : kEstados) {
    for (const Transicion& transicion : kTransiciones) {
      if (estado.getNombre() == transicion.getEstadoOrigen()) {
        estado.AgregarTransicion(transicion);
        if (estado.getNombre() == kEstadoInicial.getNombre()) {
          kEstadoInicial.AgregarTransicion(transicion);
        }
      }
    }
  }
  // Establecer si los estados son finales
  for (Estado& estado : kEstados) {
    for (Estado& estado_final : kEstadosFinales) {
      if (estado.getNombre() == estado_final.getNombre()) {
        estado.setEsFinal(true);
      }
    }
  }
  // Establecer las transiciones de los estados finales
  for (Estado& estado : kEstadosFinales) {
    for (const Transicion& transicion : kTransiciones) {
      if (estado.getNombre() == transicion.getEstadoOrigen()) {
        estado.AgregarTransicion(transicion);
      }
    }
  }
}

/**
 * @brief Lee la máquina de Turing del fichero.
 * @return Información de la máquina de Turing.
 */
InformacionMaquinaTuring LectorMaquinaTuring::LeerMaquinaTuring() {
  std::ifstream fichero{nombre_fichero_};
  if (!fichero) {
    std::cerr << "Error al abrir el fichero " << nombre_fichero_ << std::endl;
    exit(EXIT_SUCCESS);
  }
  // Si la línea empieza por # es un comentario
  std::string linea;
  while (std::getline(fichero, linea)) {
    if (linea[0] != '#') {
      // Retroceder el puntero del fichero a la posición anterior
      fichero.seekg(-linea.size() - 1, std::ios_base::cur);
      break;
    }
  }
  std::vector<Estado> estados = ExtraerEstadosDeFichero(fichero);
  informacion_leida_.alfabeto_entrada_ = ExtraerSimbolosDeFichero(fichero);
  informacion_leida_.alfabeto_cinta_ = ExtraerSimbolosDeFichero(fichero);
  std::string estado_inicial;
  std::getline(fichero, estado_inicial);
  informacion_leida_.estado_inicial_ = Estado{estado_inicial};
  std::string simbolo_blanco;
  std::getline(fichero, simbolo_blanco);
  informacion_leida_.blanco_ = Simbolo{simbolo_blanco};
  std::vector<Estado> estados_finales = ExtraerEstadosDeFichero(fichero);
  std::string numero_cintas;
  std::getline(fichero, numero_cintas);
  informacion_leida_.numero_cintas_ = std::stoi(numero_cintas);
  std::vector<Transicion> transiciones =
      ExtraerInformacionTransiciones(fichero);
  fichero.close();
  ConfigurarEstados(informacion_leida_.estado_inicial_, estados, estados_finales,
                    transiciones);
  informacion_leida_.estados_ = estados;
  return informacion_leida_;
}