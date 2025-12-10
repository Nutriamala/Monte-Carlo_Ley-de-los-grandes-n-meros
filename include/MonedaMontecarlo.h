#ifndef MONEDA_MONTE_CARLO_H
#define MONEDA_MONTE_CARLO_H

#include <vector>

class MonedaMonteCarlo {
private:
    std::vector<int> N;
    std::vector<double> frecuencias;
    std::vector<double> desviaciones;
    
public:
    void simular(int N_max);
    void guardarDatos();
    
    // Para análisis
    const std::vector<int>& getN() const { return N; }
    const std::vector<double>& getFrecuencias() const { return frecuencias; }
    const std::vector<double>& getDesviaciones() const { return desviaciones; }
};

#endif