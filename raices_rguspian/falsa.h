/**
 * @file
 * @brief Regla Falsa
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef FALSA_H
#define FALSA_H

#include "expression.h"
#include "raices.h"

using std::string;
using raices::solucion;

namespace raices{
    class falsa{
        
    public:
        /**
         * @brief Crea una nueva instancia del método de la regla falsa
         * @param f_str Función como texto
         */
        falsa(string f_str):f(f_str){

        }

        /**
         * @brief Encuentra una solucón a la función usando TVI
         * @param xi Límite inferior de la función
         * @param xs Límite superior de la función
         * @param tol Tolerancia - del Error Relativo Porcentual
         * @param n Número máximo de repeticiones
         * @return Solucion
         * 
        */

        solucion encontrar(double xi, double xs, double tol, int n){
            using raices::es_cero;
            using raices::error_relativo;

            solucion sol(f.str(), {xi, xs});

            // Paso 0
            if ((f(xi) * f(xs))>= 0.0f){
                return sol;
            }

            // Paso 1
            int i = 1;

            // Paso 2 Calcular xr

            double numerador = f(xs)* (xi-xs);
            double denominador = f(xi) - f(xs);

            double xr_ant = xs - (numerador / denominador);

            sol.agregar(xr_ant);

            if (f(xi) * f(xr_ant) > 0){
                xi = xr_ant;
            } else {
                xs = xr_ant;
            }

            //Paso 3 hacemos un while para ir iterando
            while(i<=n){
                // Paso 4 repetimos el calculo de xr
                numerador = f(xs)* (xi-xs);
                denominador = f(xi) - f(xs);
                double xr_nueva = xs - (numerador / denominador);
                
                sol.agregar(xr_nueva);

                double er = error_relativo(xr_nueva, xr_ant);
                // Calcular el error relativo porcentual
                double erp = er * 100;

                // Paso 5
                if (es_cero(f(xr_nueva)) || erp < tol){
                    sol.raiz = xr_nueva;
                    return sol;
                }

                // Paso 6
                i++;


                // Paso 7
                if (f(xi) * f(xr_nueva) > 0){
                    xi = xr_nueva;
                } else {
                    xs = xr_nueva;
                }

                xr_ant = xr_nueva;
            }
            
            // Paso 8
            return sol;
        }

    private:
        expression f /* Evaluador de expresiones */;
    };
    
}
#endif