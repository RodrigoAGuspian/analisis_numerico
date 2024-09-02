/**
 * @file
 * @brief Teorema de Valor Inicial
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef TVI_H
#define TVI_H

#include <string>
#include "expression.h"
#include "raices.h"

using std::string;
using raices::solucion;

namespace raices{
    class tvi{
    public:
        /**
         * @brief Crea una nueva instancia del método tvi
         * @param f_str Función como texto
         * 
        */
        tvi(string f_str):f(f_str){

        }

        /**
         * @brief Encuentra una solución a la función usando TVI
         * @param a Límite inferior de la función
         * @param b Límite superior de la función
         * @param h distancía del paso para buscar la raiz de la función 
         * @return Solucion
         * 
        */
        solucion encontrar(double a, double b, double h){
            solucion sol(f.str(), {a, b});
            // 1. Verificar que el valor de entrada es válido.

            // si f(a) * f(b) > 0 retornar solucion NAN
            
            if (f(a) * f(b) >= 0.0f){
                return sol;
            }

            // x = a
            double x = a;

            // mientras x < b
            // Repetir
            while (x < b){
                // si f(x) * f(x+h) < 0 retornar solucion x + (h/2)
                sol.agregar(x);
                if (f(x) * f(x+h) < 0.0f){
                    sol.raiz = x + (h/2.0f);
                    return sol;
                }
                // sino x = x+h
                x += h;
            }
            // fin mientras
            return sol;
            

        }

    private:
        expression f /* Evaluador de expresiones */;
    };
    
}
#endif