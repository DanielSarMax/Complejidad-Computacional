# Variables
CXX = g++
CXXFLAGS = -std=c++17
SRC_DIR = src
SRC = $(SRC_DIR)/main.cc \
      $(SRC_DIR)/alfabeto/alfabeto.cc \
      $(SRC_DIR)/estado/estado.cc \
      $(SRC_DIR)/cinta/cinta.cc \
      $(SRC_DIR)/transicion/transicion.cc \
      $(SRC_DIR)/funciones_auxiliares.cc \
      $(SRC_DIR)/lector_maquina_turing/lector_maquina_turing.cc \
      $(SRC_DIR)/maquina_turing/maquina_turing.cc \
      $(SRC_DIR)/simbolo/simbolo.cc
HEADERS = $(SRC_DIR)/alfabeto/alfabeto.h \
          $(SRC_DIR)/maquina_turing/maquina_turing.h \
          $(SRC_DIR)/cinta/cinta.h \
          $(SRC_DIR)/estado/estado.h \
          $(SRC_DIR)/pila/pila.h \
          $(SRC_DIR)/simbolo/simbolo.h \
          $(SRC_DIR)/transicion/transicion.h \
          $(SRC_DIR)/funciones_auxiliares.h \
          $(SRC_DIR)/lector_maquina_turing/lector_maquina_turing.h
OBJ = $(SRC:.cc=.o)
TARGET = maquina_turing

# Reglas
all: $(TARGET)

$(TARGET): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(TARGET)

.PHONY: all clean