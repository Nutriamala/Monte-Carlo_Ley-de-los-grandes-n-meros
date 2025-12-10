import matplotlib.pyplot as plt
import numpy as np
import os
import sys

print("=== GENERANDO GRAFICAS ===")

# Verificar datos
archivo_datos = "results/datos.dat"
if not os.path.exists(archivo_datos):
    print(f"ERROR: No existe {archivo_datos}")
    sys.exit(1)

# Leer datos
N, f, d = [], [], []
with open(archivo_datos, 'r') as file:
    for line in file:
        if line.startswith('#'):
            continue
        partes = line.strip().split()
        if len(partes) >= 3:
            try:
                N.append(int(float(partes[0])))
                f.append(float(partes[1]))
                d.append(float(partes[2]))
            except:
                continue

if not N:
    print("ERROR: No hay datos")
    sys.exit(1)

N = np.array(N)
f = np.array(f)
d = np.array(d)

print(f"Datos: {len(N)} puntos")

# ============================================
# 1. GRÁFICA DE CONVERGENCIA (Convergencia a 0.5)
# ============================================
plt.figure(figsize=(10, 6))
plt.plot(N, f, 'b-', linewidth=1.5, label='Frecuencia simulada')
plt.axhline(y=0.5, color='r', linestyle='--', linewidth=2, label='Valor teórico (0.5)')
plt.xlabel('Número de lanzamientos')
plt.ylabel('Frecuencia de caras')
plt.title('Convergencia a 0.5 (Ley de los Grandes Números)')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig('results/convergencia.png', dpi=150)

# ============================================
# 2. GRÁFICA DE DESVIACIÓN (CON SUAVIZADO)
# ============================================
plt.figure(figsize=(10, 6))

# Implementar suavizado (Rolling Mean) para eliminar picos extremos
window_size = 2 # Media de 5 puntos para suavizar. Puedes aumentar si los picos persisten.
d_smoothed = np.convolve(d, np.ones(window_size)/window_size, mode='valid')
N_smoothed = N[window_size - 1:] # Ajustar el eje N para que coincida

# Trazar la línea simulada suavizada (manteniendo el estilo de línea continua 'g-')
plt.loglog(N_smoothed, d_smoothed, 'g-', linewidth=1.5, label='Desviación simulada (suavizada)') 

# Trazar la tendencia teórica (la fórmula 1/(2*sqrt(N)) es CORRECTA)
plt.loglog(N, 1/(2*np.sqrt(N)), 'r--', linewidth=2, label=r'Tendencia Teórica $\sigma_F = 1/(2\sqrt{N})$')

plt.xlabel('N (log)')
plt.ylabel('Desviación $|F - 0.5|$ (log)')
plt.title('Desviación vs N (Escala Log-Log)')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig('results/desviacion.png', dpi=150)

# ============================================
# 3. HISTOGRAMA DE DISTRIBUCIÓN
# ============================================
plt.figure(figsize=(10, 6))

# Tomar los últimos valores para el histograma
ultimos_valores = f[-1000:] if len(f) > 1000 else f

# Crear histograma
plt.hist(ultimos_valores, bins=30, alpha=0.7, color='blue', edgecolor='black')

# Línea en el valor teórico
plt.axvline(x=0.5, color='red', linestyle='--', linewidth=2)

plt.xlabel('Frecuencia')
plt.ylabel('Frecuencia absoluta')
plt.title('Histograma de distribución')
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig('results/histograma.png', dpi=150)

print("✓ 3 gráficas guardadas en results/")
print("  1. convergencia.png")
print("  2. desviacion.png")
print("  3. histograma.png")

# Mostrar solo la última gráfica
plt.show()