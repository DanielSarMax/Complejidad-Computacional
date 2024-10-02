# Práctica 1: Implementación de Funciones Primitivas Recursivas

## Descripción

Este proyecto implementa la función potencia \(potencia(x, y)\) como una función primitiva recursiva. La función calcula la potencia de una base \(x\) elevada a un exponente \(y\). 

Se utiliza programación orientada a objetos en C++ para el desarrollo de la solución.

## Función Primitiva Recursiva

Las funciones primitivas recursivas son un conjunto de funciones que se definen utilizando la recursión primitiva. Este tipo de funciones se construyen a partir de funciones básicas.

Para representar las funciones recursivas básicas se codificó una clase abstracta `FuncionRecursivaBasica` con un método virtual `Calcular()`. A partir de ella, se crearon las clases `FRB_Cero`, `FRB_Proyeccion`, `FRB_Sucesor`.

Asimismo, se creó la clase abstracta `FuncionPrimitivaRecursiva` con un método virtual `Calcular()`. A partir de ella, se crearon las clases `FPR_Suma`, `FPR_Multiplicacion`, `FPR_Potencia`. Para cada una de estas funciones se planteó el caso base y recursivo, los cuales se ven englobados dentro de la función virtual `Calcular()`, que recibirá inicialmente dos parámetros como entrada.

## Contador

Además, se implementó una clase `Contador` con los métodos estáticos `IncrementarContador()`, `ObtenerContador()` y `ResetearContador()`. La finalidad de dicha clase es contar el número de llamadas totales a funciones en la ejecución del programa.

## Requisitos

- Un compilador de C++ (por ejemplo, g++)
- Make (para la compilación automática)

## Ejecución

### Paso 1: Compilación

Para compilar el proyecto, asegúrate de que tienes instalado `make` y un compilador de C++.

1. Abre una terminal en la carpeta del proyecto.
2. Ejecuta el siguiente comando en la raíz del proyecto para compilar el programa:

   ```bash
   make
   ```
3. Una vez compilado, ejecuta el programa con el siguiente comando:

   ```bash
   ./potencia
   ```

4. Introduce los datos solicitados por el programa (base y potencia).