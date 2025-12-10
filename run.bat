@echo off
echo =================================
echo   SIMULACION COMPLETA
echo =================================
echo.

echo 1. Compilando programa C++...
g++ -std=c++11 -Iinclude src\main.cpp src\MonedaMonteCarlo.cpp -o moneda.exe

if errorlevel 1 (
    echo ERROR al compilar
    pause
    exit /b 1
)

echo ✓ Compilado: moneda.exe
echo.

echo 2. Ejecutando simulacion...
echo [Ingresa un numero y presiona Enter]
moneda.exe

echo.
echo 3. Verificando resultados...
if exist results\datos.dat (
    echo ✓ Datos generados
) else (
    echo ERROR: No se generaron datos
    pause
    exit /b 1
)

echo.
echo 4. Mostrando contenido de results/...
dir results\

echo.
pause