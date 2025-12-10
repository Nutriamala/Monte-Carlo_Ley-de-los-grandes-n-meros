#include "MonedaMonteCarlo.h"
#include <iostream>

int main() {
    std::cout << "=== SIMULACION MONTE CARLO ===" << std::endl;
    std::cout << "Ingrese numero de lanzamientos (ej: 100000): ";
    
    int N;
    std::cin >> N;
    
    if (N <= 0) {
        std::cerr << "Error: N debe ser positivo" << std::endl;
        return 1;
    }
    
    MonedaMonteCarlo sim;
    sim.simular(N);
    sim.guardarDatos();
    
    std::cout << "\nGenerando graficas..." << std::endl;
    
    // Ejecutar Python para generar gráficas
    system("python scripts/graficas.py");
    
    std::cout << "\n=== PROCESO COMPLETADO ===" << std::endl;
    std::cout << "Revisa la carpeta 'results/' para ver:" << std::endl;
    std::cout << "  - datos.dat (datos brutos)" << std::endl;
    std::cout << "  - convergencia.png" << std::endl;
    std::cout << "  - desviacion.png" << std::endl;
    
    return 0;
}