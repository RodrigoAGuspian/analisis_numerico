/**
 * @file
 * @brief Biseccion
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef BISECCION_H
#define BISECCION_H

#include <string>
#include "expression.h"
#include "raices.h"


using std::string;
using raices::solucion;

namespace raices{
    class biseccion{
        
    public:
        /**
         * @brief Crea una nueva instancia del metodo biseccion
         * @param f_str Función como texto
         */
        biseccion(string f_str):f(f_str){

        }

        /**
         * @brief Encuentra una solución a la función usando el método bisección
         * @param a Límite inferior de la función
         * @param b Límite superior de la función
         * @param tol Tolerancia - del Error Relativo Porcentual
         * @param n Número máximo de repeticiones
         * @return Solucion
         * 
        */

        solucion encontrar(double a, double b, double tol, int n){
            using raices::es_cero;
            using raices::error_relativo;

            solucion sol(f.str(), {a, b});

            // Paso 0
            if ((f(a) * f(b))>= 0.0f){
                return sol;
            }

            // Paso 1
            int i = 1;
            // Paso 2

            double x_ant = (a+b)/2.0f;
            sol.agregar(x_ant);

            if (f(a) * f(x_ant) > 0.0f){
                a = x_ant;
            } else {
                b = x_ant;
            }

            //Paso 3
            while(i<=n){
                // Paso 4
                double x_nueva = (a + b)/2.0f;
                
                sol.agregar(x_nueva);

                double er = error_relativo(x_nueva, x_ant);
                // Calcular el error relativo porcentual
                double erp = er * 100;

                // Paso 5
                if (es_cero(f(x_nueva)) || erp < tol){
                    sol.raiz = x_nueva;
                    return sol;
                }

                // Paso 6
                i++;

                // Paso 7
                if (f(a) * f(x_nueva) > 0.0f){
                    a = x_nueva;
                } else {
                    b = x_nueva;
                }

                x_ant = x_nueva;
            }
            
            // Paso 8
            return sol;
        }

    private:
        expression f /* Evaluador de expresiones */;
    };
    
}
#endif