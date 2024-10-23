/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 * @author Daniel David Sarmiento Barrera
 * @since October 2024
 * @description: Definición de la clase AutomataPila.
 */

#include <tuple>
#include <set>

#include "automatapila.h"

/**
 * @brief Constructor de la clase AutomataPila.
 *        Inserta el símbolo inicial de la pila en la pila.
 */
AutomataPila::AutomataPila(const std::vector<Estado>& kEstados,
                           const Alfabeto& kAlfabetoEntrada,
                           const Alfabeto& kAlfabetoPila,
                           const Estado& kEstadoInicial,
                           const Simbolo& kSimboloInicialPila,
                           const std::vector<Transicion>& kTransiciones,
                           const std::vector<Estado>& kEstadosFinales)
    : estados_{kEstados},
      alfabeto_entrada_{kAlfabetoEntrada},
      alfabeto_pila_{kAlfabetoPila},
      estado_inicial_{kEstadoInicial},
      simbolo_inicial_pila_{kSimboloInicialPila},
      transiciones_{kTransiciones},
      estados_finales_{kEstadosFinales} {
  pila_.Push(kSimboloInicialPila);
  SetModoTraza(false);
  CompruebaAutomata();
}

/**
 * @brief Comprueba si un estado ya existe en el autómata.
 * @param kEstado Estado a comprobar.
 * @return Si el estado ya existe retornará true, en caso contrario retornará
 *         false.
 */
bool AutomataPila::EsEstadoValido(const Estado& kEstado) const {
  for (const Estado& estado : estados_) {
    if (estado.GetNombre() == kEstado.GetNombre()) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Comprueba si un símbolo es válido.
 * @param kSimbolo Símbolo a comprobar.
 * @param kAlfabeto Alfabeto en el que se comprobará el símbolo.
 * @return Si el símbolo es válido retornará true, en caso contrario retornará
 *         false.
 */
bool AutomataPila::EsSimboloValido(const Simbolo& kSimbolo, const Alfabeto& kAlfabeto) const {
  if (kSimbolo.GetSimbolo() == ".") {
    return true;
  }
  for (const std::string& kSimboloIndividual : kSimbolo.GetSimboloSeparado()) {
    bool simbolo_encontrado = false;
    for (const Simbolo& simbolo : kAlfabeto.GetSimbolos()) {
      if (simbolo.GetSimbolo() == kSimboloIndividual) {
        simbolo_encontrado = true;
      }
    }
    if (!simbolo_encontrado) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Comprueba si el estado inicial del autómata es válido.
 */
void AutomataPila::CompruebaEstadoInicial() const {
  if (!EsEstadoValido(estado_inicial_)) {
    std::cerr << "Error: El estado inicial " << estado_inicial_.GetNombre()
              << " no se encuentra en la lista de estados." << std::endl;
    exit(1);
  }
}

/**
 * @brief Comprueba si el estado final del autómata es válido.
 */
void AutomataPila::CompruebaEstadoFinal() const {
  for (const Estado& estado : estados_finales_) {
    if (!EsEstadoValido(estado)) {
      std::cerr << "Error: El estado final " << estado.GetNombre()
                << " no se encuentra en la lista de estados." << std::endl;
      exit(1);
    }
  }
}

/**
 * @brief Comprueba si el símbolo inicial de la pila es válido.
 */
void AutomataPila::CompruebaSimboloInicialPila() const {
  if (!EsSimboloValido(GetSimboloInicialPila(), GetAlfabetoPila())) {
    std::cerr << "Error: El símbolo inicial de la pila " << GetSimboloInicialPila().GetSimbolo()
              << " no se encuentra en el alfabeto de la pila." << std::endl;
    exit(1);
  }
}

/**
 * @brief Comprueba si una transición es válida.
 * @param kTransicion Transición a comprobar.
 */
void AutomataPila::CompruebaTransicion(const Transicion& kTransicion) const {
  if (!EsEstadoValido(GetEstado(kTransicion.GetNombreEstadoOrigen()))) {
    std::cerr << "Error: El estado origen " << kTransicion.GetNombreEstadoOrigen()
              << " no se encuentra en la lista de estados." << std::endl;
    exit(1);
  }
  if (!EsEstadoValido(GetEstado(kTransicion.GetNombreEstadoDestino()))) {
    std::cerr << "Error: El estado destino " << kTransicion.GetNombreEstadoDestino()
              << " no se encuentra en la lista de estados." << std::endl;
    exit(1);
  }
  if (!EsSimboloValido(kTransicion.GetSimboloEntrada(), alfabeto_entrada_)) {
    std::cerr << "Error: El símbolo de entrada " << kTransicion.GetSimboloEntrada().GetSimbolo()
              << " no se encuentra en el alfabeto de entrada." << std::endl;
    exit(1);
  }
  if (!EsSimboloValido(kTransicion.GetSimboloPila(), alfabeto_pila_)) {
    std::cerr << "Error: El símbolo de la pila " << kTransicion.GetSimboloPila().GetSimbolo()
              << " no se encuentra en el alfabeto de la pila." << std::endl;
    exit(1);
  }
  if (!EsSimboloValido(kTransicion.GetSimboloPilaResultante(), alfabeto_pila_)) {
    std::cerr << "Error: El símbolo de la pila resultante "
              << kTransicion.GetSimboloPilaResultante().GetSimbolo()
              << " no se encuentra en el alfabeto de la pila." << std::endl;
    exit(1);
  }
}


/**
 * @brief Comprueba si el autómata cumple con todas las restricciones.
 */
void AutomataPila::CompruebaAutomata() const {
  CompruebaEstadoInicial();
  CompruebaEstadoFinal();
  CompruebaSimboloInicialPila();
  for (const Transicion& transicion : transiciones_) {
    CompruebaTransicion(transicion);
  }
}

/**
 * @brief Imprime la información del autómata con pila.
 */
void AutomataPila::Imprimir() const {
  std::cout << "\033[0;31mAutómata con pila definido:\033[0m" << std::endl;
  std::cout << "Estados: ";
  for (const Estado& estado : estados_) {
    std::cout << estado.GetNombre() << " ";
  }
  std::cout << std::endl;
  std::cout << "Alfabeto de entrada: ";
  GetAlfabetoEntrada().Imprimir();
  std::cout << "Alfabeto de la pila: ";
  GetAlfabetoPila().Imprimir();
  std::cout << "Estado inicial: " << estado_inicial_.GetNombre() << std::endl;
  std::cout << "Símbolo inicial de la pila: "
            << simbolo_inicial_pila_.GetSimbolo() << std::endl;
  std::cout << "Estados finales: ";
  for (const Estado& estado : estados_finales_) {
    std::cout << estado.GetNombre() << " ";
  }
  std::cout << std::endl;
  std::cout << "Transiciones:" << std::endl;
  for (const Transicion& transicion : transiciones_) {
    transicion.Imprimir();
  }
}

/**
 * @brief Imprime las transiciones de un estado.
 * @param kEstado Estado del que se quieren imprimir las transiciones.
 */
void AutomataPila::ImprimirTransicionesPorEstado() const {
  for (const Estado& estado : estados_) {
    estado.Imprimir();
  }
}

/**
 * @brief Devuelve un estado a partir de su nombre.
 * @param kNombre Nombre del estado.
 * @return Estado.
 */
Estado AutomataPila::GetEstado(const std::string& kNombre) const {
  for (const Estado& estado : estados_) {
    if (estado.GetNombre() == kNombre) {
      return estado;
    }
  }
  std::cerr << "Error: No se ha encontrado el estado " << kNombre << std::endl;
  exit(1);
}

/**
 * @brief Devuelve el símbolo inicial de la pila.
 * @return Símbolo inicial de la pila.
 */
Simbolo AutomataPila::GetSimboloInicialPila() const {
  return simbolo_inicial_pila_;
}

/**
 * @brief Devuelve el alfabeto de la pila.
 * @return Alfabeto de la pila.
 */
Alfabeto AutomataPila::GetAlfabetoPila() const {
  return alfabeto_pila_;
}

/**
 * @brief Devuelve el alfabeto de entrada.
 * @return Alfabeto de entrada.
 */
Alfabeto AutomataPila::GetAlfabetoEntrada() const {
  return alfabeto_entrada_;
}

/**
 * @brief Establece el modo traza del autómata.
 * @param kModoTraza Modo traza.
 */
void AutomataPila::SetModoTraza(const bool kModoTraza) {
  modo_traza_ = kModoTraza;
}

/**
 * @brief Comprueba si una transición es válida para un símbolo de entrada y un
 *       símbolo de la pila.
 * @param kTransicion Transición a comprobar.
 * @param kSimboloCadena Símbolo de la cadena.
 * @param kSimboloPila Símbolo de la pila.
 * @return Si la transición es válida retornará true, en caso contrario retornará
 *        false.
 */
bool AutomataPila::EsTransicionValida(const Transicion& kTransicion,
                          const Simbolo& kSimboloCadena,
                          const Simbolo& kSimboloPila) const {
  return (kTransicion.GetSimboloEntrada().GetSimbolo() == kSimboloCadena.GetSimbolo() ||
          kTransicion.GetSimboloEntrada().GetSimbolo() == ".") &&
         (kTransicion.GetSimboloPila().GetSimbolo() == kSimboloPila.GetSimbolo() ||
          kTransicion.GetSimboloPila().GetSimbolo() == ".");
}

/**
 * @brief Inserta una serie de símbolos en la pila.
 * @param kSimbolos Símbolos a insertar.
 * @param kPila Pila en la que se insertarán los símbolos.
 */
void AutomataPila::InsertaSimboloEnPila(const Simbolo& kSimbolo, Pila& kPila) const {
  std::vector<std::string> simbolos = kSimbolo.GetSimboloSeparado();
  for (int iterador = static_cast<int>(simbolos.size()) - 1; iterador >= 0; --iterador) {
    if (simbolos[iterador] != ".") {
      kPila.Push(Simbolo{simbolos[iterador]});
    }
  }
}

/**
 * @brief Comprueba si el autómata es final por estado final.
 * @return Si el autómata es final por estado final retornará true, en caso
 *         contrario retornará false.
 */
bool AutomataPila::EsFinalPorEstadoFinal(const Cadena& kCadena, 
                                       const std::vector<Estado>& kEstadosActuales,
                                       const int kPosicion) const {
  if (kPosicion == kCadena.GetSimbolos().size() || kCadena.GetCadena() == ".") {
    for (const Estado& estado : kEstadosActuales) {
      if (estado.EsFinal()) {
        return true;
      }
    }
  }
  return false;
}

/**
 * @brief Comprueba si una cadena es válida para el autómata.
 * @param kCadena Cadena a comprobar.
 */
void AutomataPila::ComprobarCadena(const Cadena& kCadena) const {
  for (const Simbolo& simbolo : kCadena.GetSimbolos()) {
    if (!EsSimboloValido(simbolo, alfabeto_entrada_)) {
      std::cerr << "Error: El símbolo " << simbolo.GetSimbolo()
                << " de la cadena " << kCadena.GetCadena()
                << " no se encuentra en el alfabeto de entrada." << std::endl;
      exit(1);
    }
  }
}

/**
 * @brief Resetea la pila del autómata.
 */
void AutomataPila::ResetearPila() {
  while (!pila_.IsEmpty()) {
    pila_.Pop();
  }
  pila_.Push(simbolo_inicial_pila_);
}

/**
 * @brief Comparador de tuplas, para poder utilizarlas en un conjunto.
 */
struct ComparadorTuplas {
  bool operator()(const std::tuple<std::vector<Estado>, Pila, int>& kTupla1,
                  const std::tuple<std::vector<Estado>, Pila, int>& kTupla2) const {
    return !(kTupla1 == kTupla2);
  }
};

/**
 * @brief Procesa una cadena en el autómata con pila no determinista.
 * @param kCadena Cadena a procesar.
 * @return Si la cadena es aceptada por el autómata con pila retornará true,
 *         en caso contrario retornará false.
 */
bool AutomataPila::ProcesarCadena(const Cadena& kCadena) {
  ComprobarCadena(kCadena);
  ResetearPila();
  // Utilizamos una pila para manejar el backtracking.
  std::stack<std::tuple<std::vector<Estado>, Pila, int>> estados_pila;
  estados_pila.push(std::make_tuple(std::vector<Estado>{estado_inicial_}, pila_, 0));
  // Conjunto para guardar configuraciones visitadas.
  std::set<std::tuple<std::vector<Estado>, Pila, int>, ComparadorTuplas> configuraciones_visitadas;
  while (!estados_pila.empty()) {
    auto [estados_actuales, pila_actual, posicion] = estados_pila.top();
    estados_pila.pop();
    // Verificamos si esta configuración ya fue visitada.
    std::tuple<std::vector<Estado>, Pila, int> configuracion_actual = 
        std::make_tuple(estados_actuales, pila_actual, posicion);
    if (configuraciones_visitadas.count(configuracion_actual) > 0) {
      continue;
    }
    // Marcamos la configuración actual como visitada.
    configuraciones_visitadas.insert(configuracion_actual);
    if (EsFinalPorEstadoFinal(kCadena, estados_actuales, posicion)) {
      return true;
    }
    // Obtenemos el símbolo actual de la cadena en la posición correspondiente.
    const std::vector<Simbolo> simbolos = kCadena.GetSimbolos();
    Simbolo simbolo{"."};
    if (posicion < simbolos.size()) {
      simbolo.SetSimbolo(simbolos[posicion].GetSimbolo());
    }
    std::vector<Estado> nuevos_estados_actuales;
    for (const Estado& estado : estados_actuales) {
      std::vector<Transicion> transiciones_posibles;
      for (const Transicion& transicion : estado.GetTransiciones()) {
        if (EsTransicionValida(transicion, simbolo, pila_actual.Top())) {
          transiciones_posibles.push_back(transicion);
          // Creamos una copia del estado de la pila para este camino.
          Pila nueva_pila = pila_actual;
          if (transicion.GetSimboloPila().GetSimbolo() != ".") {
            nueva_pila.Pop();
          }
          // Añadimos los símbolos resultantes de la transición a la pila.
          Simbolo simbolo_auxiliar = transicion.GetSimboloPilaResultante();
          InsertaSimboloEnPila(simbolo_auxiliar, nueva_pila);
          Estado nuevo_estado = GetEstado(transicion.GetNombreEstadoDestino());
          nuevos_estados_actuales.push_back(nuevo_estado);
          // Agregamos el nuevo estado y la nueva pila a la pila de backtracking.
          estados_pila.push({{nuevo_estado}, nueva_pila, posicion + 
                            (transicion.GetSimboloEntrada().GetSimbolo() == "." ? 0 : 1)});
        }
      }
      if (modo_traza_) {
        ImprimirTraza(estado, kCadena, posicion, pila_actual, transiciones_posibles);
      }
    }
  }
  return false;
}


/**
 * @brief Imprime la traza de la ejecución del autómata con pila.
 */
void AutomataPila::ImprimirTraza(const Estado& kEstadoActual, 
                                const Cadena& kCadena, 
                                const int kPosicionPuntero, 
                                const Pila& kPilaActual, 
                                const std::vector<Transicion>& 
                                kPosiblesTransiciones) const {
  std::cout << "Estado actual: " << kEstadoActual.GetNombre() << std::endl;
  std::cout << "Cadena: ";
  for (int iterador = 0; iterador < kCadena.GetSimbolos().size(); ++iterador) {
    if (iterador == kPosicionPuntero) {
      std::cout << "\033[0;31m|\033[0m";
    }
    std::cout << kCadena.GetSimbolos()[iterador].GetSimbolo();
  }
  if (kPosicionPuntero == kCadena.GetSimbolos().size()) {
    std::cout << "\033[0;31m|\033[0m";
  }
  std::cout << std::endl;
  std::cout << "Pila: ";
  kPilaActual.Imprimir();
  std::cout << "Posibles transiciones: " << std::endl;
  for (const Transicion& transicion : kPosiblesTransiciones) {
    transicion.Imprimir();
  }
  std::cout << "----------------------" << std::endl;
}


/**
 * @brief Procesa una cadena en el autómata con pila no determinista.
 * @param kCadena Cadena a procesar.
 * @return Si la cadena es aceptada por el autómata con pila retornará true,
 *         en caso contrario retornará false.
 */
/*bool AutomataPila::ProcesarCadena(const Cadena& kCadena) {
  ComprobarCadena(kCadena);
  ResetearPila();
  // Utilizamos una pila para manejar el backtracking.
  std::stack<std::tuple<std::vector<Estado>, Pila, int>> estados_pila;
  estados_pila.push(std::make_tuple(std::vector<Estado>{estado_inicial_}, pila_, 0));
  while (!estados_pila.empty()) {
    auto [estados_actuales, pila_actual, posicion] = estados_pila.top();
    estados_pila.pop();
    if (EsFinalPorEstadoFinal(kCadena, estados_actuales, posicion)) {
      return true;
    }
    // Obtenemos el símbolo actual de la cadena en la posición correspondiente.
    const std::vector<Simbolo> simbolos = kCadena.GetSimbolos();
    Simbolo simbolo{"."};
    if (posicion < simbolos.size()) {
      simbolo.SetSimbolo(simbolos[posicion].GetSimbolo());
    }
    std::vector<Estado> nuevos_estados_actuales;
    for (const Estado& estado : estados_actuales) {
      for (const Transicion& transicion : estado.GetTransiciones()) {
        if (EsTransicionValida(transicion, simbolo, pila_actual.Top())) {
          if (modo_traza_) {
            ImprimirTraza(estado, kCadena, posicion, pila_actual, 
                          estado.GetTransiciones());
          }
          // Creamos una copia del estado de la pila para este camino.
          Pila nueva_pila = pila_actual;
          if (transicion.GetSimboloPila().GetSimbolo() != ".") {
            nueva_pila.Pop();
          }
          // Añadimos los símbolos resultantes de la transición a la pila.
          Simbolo simbolo_auxiliar = transicion.GetSimboloPilaResultante();
          InsertaSimboloEnPila(simbolo_auxiliar, nueva_pila);
          Estado nuevo_estado = GetEstado(transicion.GetNombreEstadoDestino());
          nuevos_estados_actuales.push_back(nuevo_estado);
          // Agregamos el nuevo estado y la nueva pila a la pila de backtracking.
          estados_pila.push({{nuevo_estado}, nueva_pila, posicion + 
                            (transicion.GetSimboloEntrada().GetSimbolo() == "." ? 0 : 1)});
        }
      }
    }
  }
  return false;
}*/