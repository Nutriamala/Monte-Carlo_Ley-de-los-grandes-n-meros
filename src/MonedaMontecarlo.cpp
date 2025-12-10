#include "MonedaMonteCarlo.h"
#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <cstdlib>

void MonedaMonteCarlo::simular(int N_max) {
    N.clear();
    frecuencias.clear();
    desviaciones.clear();
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    int caras = 0;
    
    // Definir puntos fijos ANTES de simular
    // Esto garantiza distribución consistente
    
    for (int i = 1; i <= N_max; i++) {
        if (dis(gen) < 0.5) caras++;
        
        // REGLA ÚNICA Y CONSISTENTE:
        bool guardar = false;
        
        // Para TODOS los N, misma lógica:
        if (i <= 100) {
            // N pequeños: más puntos
            guardar = (i <= 10 || i % 10 == 0);
        } 
        else {
            // N grandes: puntos logarítmicos
            if (i <= 1000 && i % 100 == 0) guardar = true;
            else if (i <= 10000 && i % 500 == 0) guardar = true;
            else if (i <= 100000 && i % 5000 == 0) guardar = true;
            else if (i % 10000 == 0) guardar = true;
        }
        
        // Siempre guardar algunos puntos clave
        if (i == 1 || i == 10 || i == 100 || i == 1000 || 
            i == 10000 || i == 100000 || i == 1000000 ||
            i == N_max) {
            guardar = true;
        }
        
        if (guardar) {
            double f = (double)caras / i;
            double d = std::abs(f - 0.5);
            
            N.push_back(i);
            frecuencias.push_back(f);
            desviaciones.push_back(d);
        }
    }
}

void MonedaMonteCarlo::guardarDatos() {
    // Crear carpeta results si no existe
    #ifdef _WIN32
        system("mkdir results 2>nul");
    #else
        system("mkdir -p results");
    #endif
    
    // Guardar datos en results/datos.dat
    std::ofstream file("results/datos.dat");
    file << "# N\tfrecuencia\tdesviacion\n";
    
    for (size_t i = 0; i < N.size(); i++) {
        file << N[i] << "\t" << frecuencias[i] << "\t" << desviaciones[i] << "\n";
    }
    file.close();
    
    std::cout << "✓ Datos guardados en: results/datos.dat" << std::endl;
    std::cout << "✓ Puntos guardados: " << N.size() << std::endl;
}