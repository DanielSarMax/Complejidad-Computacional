# Variables
CXX = g++
CXXFLAGS = -std=c++17
SRC_DIR = src
SRC = $(SRC_DIR)/main.cc \
      $(SRC_DIR)/automatapila/automatapila.cc \
      $(SRC_DIR)/estado/estado.cc \
      $(SRC_DIR)/pila/pila.cc \
      $(SRC_DIR)/transicion/transicion.cc \
      $(SRC_DIR)/funciones_auxiliares.cc
HEADERS = $(SRC_DIR)/alfabeto/alfabeto.h \
          $(SRC_DIR)/automatapila/automatapila.h \
          $(SRC_DIR)/cadena/cadena.h \
          $(SRC_DIR)/estado/estado.h \
          $(SRC_DIR)/pila/pila.h \
          $(SRC_DIR)/simbolo/simbolo.h \
          $(SRC_DIR)/transicion/transicion.h \
          $(SRC_DIR)/funciones_auxiliares.h
OBJ = $(SRC:.cc=.o)
TARGET = automatapila

# Reglas
all: $(TARGET)

$(TARGET): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(TARGET)

.PHONY: all clean