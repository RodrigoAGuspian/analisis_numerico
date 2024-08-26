/**
 * @file
 * @brief Secante
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef SECANTE_H
#define SECANTE_H

#include "expression.h"
#include "raices.h"


using std::string;
using raices::solucion;

namespace raices{
    class secante{
        
    public:
        /**
         * @brief Crea una nueva instancia del método de la secante
         * @param f_str Función como texto
         */
        secante(string f_str):f(f_str){

        }

        /**
         * @brief Encuentra una solucón a la función usando TVI
         * @param x0 Valor x0 de la funcion
         * @param x1 Valor x0 de la funcion
         * @param tol Tolerancia - del Error Relativo Porcentual
         * @param n Número máximo de repeticiones
         * @return Solucion
         * 
        */

        solucion encontrar(double x0, double x1, double tol, int n){
            using raices::es_cero;
            using raices::error_relativo;

            solucion sol(f.str(), {x0, x1});

            // Paso 0 comprobar que x0 o x1 son raices
            sol.agregar(x0);
            sol.agregar(x1);

            if (es_cero(f(x0))){
                sol.raiz = x0;
                return sol;
                
            }

            if (es_cero(f(x1))){
                sol.raiz = x1;
                return sol;
                
            }
            // Paso 1
            int i = 1;


            //Paso 2 hacemos un while para ir iterando
            while(i<=n){
                // Paso 4 repetimos el calculo de xr
                double numerador = f(x1)* (x0-x1);
                double denominador = f(x0) - f(x1);
                
                double x2 = x1 - (numerador / denominador);

                sol.agregar(x2);

                double er = error_relativo(x2, x1);
                // Calcular el error relativo porcentual
                double erp = er * 100;

                // Paso 5
                if (es_cero(f(x2)) || erp < tol){
                    sol.raiz = x2;
                    return sol;
                }

                // Paso 6
                i++;


                // Paso 7
                x0 = x1;
                x1 = x2;
                

            }
            
            // Paso 8
            return sol;
        }

    private:
        expression f /* Evaluador de expresiones */;
    };
    
}
#endif