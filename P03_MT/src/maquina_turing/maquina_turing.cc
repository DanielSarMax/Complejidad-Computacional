/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since Noviembre 2024
 * @description: Definición de los métodos de la clase MaquinaTuring.
 */

#include "maquina_turing.h"

/**
 * @brief Constructor por defecto de la clase MaquinaTuring.
 */
MaquinaTuring::MaquinaTuring() {
  estado_inicial_ = Estado();
  alfabeto_entrada_ = Alfabeto();
  alfabeto_cinta_ = Alfabeto();
  estados_ = {};
  cintas_ = {};
  blanco_ = Simbolo("_");
  numero_cintas_ = 0;
}

/**
 * @brief Constructor de la clase MaquinaTuring.
 * @param kEstadoInicial Estado inicial de la máquina.
 * @param kAlfabetoEntrada Alfabeto de entrada.
 * @param kAlfabetoCinta Alfabeto de la cinta.
 * @param kEstados Estados de la máquina.
 * @param kBlanco Símbolo blanco.
 * @param kNumeroCintas Número de cintas.
 */
MaquinaTuring::MaquinaTuring(const Estado& kEstadoInicial,
                             const Alfabeto& kAlfabetoEntrada,
                             const Alfabeto& kAlfabetoCinta,
                             const std::vector<Estado>& kEstados,
                             const Simbolo& kBlanco,
                             const int kNumeroCintas)
    : estado_inicial_{kEstadoInicial},
      alfabeto_entrada_{kAlfabetoEntrada},
      alfabeto_cinta_{kAlfabetoCinta},
      estados_{kEstados},
      blanco_{kBlanco},
      numero_cintas_{kNumeroCintas} {
  for (int i = 0; i < kNumeroCintas; i++) {
    cintas_.push_back(Cinta({}, kBlanco));
  }
}

/**
 * @brief Devuelve el estado inicial de la máquina.
 * @return Estado inicial.
 */
Estado MaquinaTuring::getEstadoInicial() const {
  return estado_inicial_;
}

/**
 * @brief Devuelve el alfabeto de entrada de la máquina.
 * @return Alfabeto de entrada.
 */
Alfabeto MaquinaTuring::getAlfabetoEntrada() const {
  return alfabeto_entrada_;
}

/**
 * @brief Devuelve el alfabeto de la cinta de la máquina.
 * @return Alfabeto de la cinta.
 */
Alfabeto MaquinaTuring::getAlfabetoCinta() const {
  return alfabeto_cinta_;
}

/**
 * @brief Devuelve los estados de la máquina.
 * @return Estados.
 */
std::vector<Estado> MaquinaTuring::getEstados() const {
  return estados_;
}

/**
 * @brief Devuelve el símbolo blanco de la máquina.
 * @return Símbolo blanco.
 */
Simbolo MaquinaTuring::getBlanco() const {
  return blanco_;
}

/**
 * @brief Devuelve el número de cintas de la máquina.
 * @return Número de cintas.
 */
int MaquinaTuring::getNumeroCintas() const {
  return numero_cintas_;
}

/**
 * @brief Devuelve las cintas de la máquina.
 * @return Cintas.
 */
std::vector<Cinta> MaquinaTuring::getCintas() const {
  return cintas_;
}

/**
 * @brief Inserta una cadena en la/as cinta/as de la máquina.
 * @param kCadena Cadena a insertar.
 */
void MaquinaTuring::InsertarCadena(const std::string& kCadena) {
  for (int i = 0; i < numero_cintas_; i++) {
    std::vector<Simbolo> cinta;
    for (const char& caracter : kCadena) {
      cinta.push_back(Simbolo{std::string(1, caracter)});
    }
    cinta.push_back(blanco_);
    cintas_[i] = Cinta{cinta, blanco_};
  }
}

/**
 * @brief Busca un estado en la máquina.
 * @param kNombreEstado Nombre del estado a buscar.
 * @return Estado.
 */
Estado MaquinaTuring::BuscarEstado(const std::string& kNombreEstado) const {
  for (const auto& estado : estados_) {
    if (estado.getNombre() == kNombreEstado) {
      return estado;
    }
  }
  std::cerr << "Error: No se ha encontrado el estado " << kNombreEstado << std::endl;
  exit(EXIT_FAILURE);
}

/**
 * @brief Ejecuta la máquina de Turing.
 * @param kCadena Cadena a procesar.
 * @return True si la ejecución ha finalizado en un estado final, false en caso contrario.
 */
bool MaquinaTuring::Ejecutar(const std::string& kCadena) {
  InsertarCadena(kCadena);
  Estado estado_actual = estado_inicial_;
  while (true) {
    if (estado_actual.esFinal()) {
      return true;
    }
    std::vector<Simbolo> simbolos_leidos;
    std::vector<Cinta> cintas = getCintas();
    for (int i = 0; i < numero_cintas_; i++) {
      Cinta cinta_actual = cintas[i];
      int posicion_cabeza = cinta_actual.getPosicionCabeza();
      simbolos_leidos.push_back(cinta_actual.getCinta()[posicion_cabeza]);
    }
    std::vector<Transicion> transiciones = estado_actual.getTransiciones();
    Transicion transicion_actual;
    bool transicion_encontrada = false;
    for (const auto transicion : transiciones) {
      if (estado_actual.getNombre() == transicion.getEstadoOrigen() &&
          transicion.getSimboloActualCintas() == simbolos_leidos &&
          !transicion_encontrada) {
        transicion_actual = transicion;
        transicion_encontrada = true;
      }    
    }
    if (!transicion_encontrada) { return false; }
    for (int i = 0; i < numero_cintas_; i++) {
      Cinta cinta_actual = cintas[i];
      cinta_actual.Escribir(transicion_actual.getSimboloNuevoCintas()[i]);
      cinta_actual.MoverCabeza(transicion_actual.getMovimientoCintas()[i]);
      cintas_[i] = cinta_actual;
    }
    estado_actual = BuscarEstado(transicion_actual.getEstadoDestino());
  }
}

/**
 * @brief Imprime las cintas de la máquina.
 */
void MaquinaTuring::ImprimirCintas() const {
  for (int iterador = 0; iterador < numero_cintas_; iterador++) {
    std::cout << "Cinta " << iterador + 1 << ": " << std::endl;
    std::cout << cintas_[iterador] << std::endl;
  }
}

/**
 * @brief Sobrecarga del operador de inserción.
 * @param os Flujo de salida.
 * @param kMaquinaTuring Máquina de Turing a imprimir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const MaquinaTuring& kMaquinaTuring) {
  os << "Estado inicial: " << std::endl << kMaquinaTuring.estado_inicial_ << std::endl;
  os << "Alfabeto de entrada: " << kMaquinaTuring.alfabeto_entrada_ << std::endl;
  os << "Alfabeto de la cinta: " << kMaquinaTuring.alfabeto_cinta_ << std::endl;
  os << "Estados: " << std::endl;
  for (const auto& estado : kMaquinaTuring.estados_) {
    os << estado << std::endl;
  }
  os << "Símbolo blanco: " << kMaquinaTuring.blanco_ << std::endl;
  os << "Número de cintas: " << kMaquinaTuring.numero_cintas_ << std::endl;
  return os;
}