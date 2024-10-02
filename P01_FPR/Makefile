# Variables
CXX = g++
CXXFLAGS = -std=c++11
SRC_DIR = src
SRC = $(SRC_DIR)/main.cc \
      $(SRC_DIR)/funcion_primitiva_recursiva/funcion_primitiva_recursiva.cc \
      $(SRC_DIR)/funcion_primitiva_recursiva/suma/suma.cc \
      $(SRC_DIR)/funcion_primitiva_recursiva/multiplicacion/multiplicacion.cc \
      $(SRC_DIR)/funcion_primitiva_recursiva/potencia/potencia.cc \
      $(SRC_DIR)/funciones_auxiliares/funciones.cc
HEADERS = $(SRC_DIR)/funcion_primitiva_recursiva/funcion_primitiva_recursiva.h \
          $(SRC_DIR)/funcion_primitiva_recursiva/suma/suma.h \
          $(SRC_DIR)/funcion_primitiva_recursiva/multiplicacion/multiplicacion.h \
          $(SRC_DIR)/funcion_primitiva_recursiva/potencia/potencia.h \
          $(SRC_DIR)/funciones_auxiliares/funciones.h \
          $(SRC_DIR)/contador_llamadas.h
OBJ = $(SRC:.cc=.o)
TARGET = potencia

# Reglas
all: $(TARGET)

$(TARGET): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(TARGET)

.PHONY: all clean