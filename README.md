# Monte Carlo: Ley de los Grandes Números - Lanzamiento de Monedas

## 📋 Descripción
Simulación del método de Monte Carlo aplicado a la ley de los grandes números mediante el lanzamiento repetido de una moneda justa. El programa demuestra cómo la frecuencia relativa de caras converge al valor teórico 0.5 y analiza el comportamiento de la desviación estadística.

## 🎯 Objetivos
- Verificar experimentalmente la ley de los grandes números
- Visualizar la convergencia de frecuencias relativas
- Analizar el decaimiento de la desviación estadística vs número de lanzamientos
- Ilustrar el método de Monte Carlo en un problema simple pero representativo

## 🏗️ Estructura del Proyecto
MonteCarlo-Monedas/
├── src/
│ ├── main.cpp # Programa principal
│ ├── MonedaMonteCarlo.h # Definición de la clase
│ └── MonedaMonteCarlo.cpp # Implementación de la simulación
├── scripts/
│ └── graficas.py # Generación de gráficas
├── results/ # Datos y gráficas generados
└── README.md # Este archivo

text

## 🔧 Requisitos
### Compilación (C++):
- Compilador C++11 o superior (g++, clang++, MSVC)
- No requiere bibliotecas externas

### Gráficas (Python):
- Python 3.6+
- matplotlib
- numpy

## 🚀 Compilación y Ejecución

### 1. Compilar el programa C++:
```bash
# En Linux/Mac:
g++ -std=c++11 -o montecarlo src/*.cpp

# En Windows (MinGW):
g++ -std=c++11 -o montecarlo.exe src/*.cpp
2. Ejecutar la simulación:
bash
./montecarlo  # o montecarlo.exe en Windows
3. Ingresar parámetros:


📊 Gráficas Generadas
El programa crea tres gráficas en la carpeta results/:

convergencia.png: Muestra cómo la frecuencia de caras converge a 0.5

desviacion.png: Gráfica log-log de la desviación vs número de lanzamientos

histograma.png: Distribución de frecuencias en los últimos 1000 puntos
