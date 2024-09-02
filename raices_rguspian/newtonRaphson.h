/**
 * @file
 * @brief Newton Raphson
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef NEWTOW_RAPHSON
#define NEWTOW_RAPHSON

#include "expression.h"
#include "raices.h"

using std::string;
using raices::solucion;

namespace raices{
    class newton_raphson{
        
    public:
        /**
         * @brief Crea una nueva instancia del método de Newton Raphson
         * @param f_str Función como texto
         * @param df_str Derivada como texto
         */
        newton_raphson(string f_str, string df_str):f(f_str),df(df_str){

        }

        /**
         * @brief Encuentra una solución a la función usando Newton Rapshon
         * @param p0 Valor Inicial (primera aproximación de x)
         * @param tol Tolerancia - del Error Relativo Porcentual
         * @param n Número máximo de repeticiones
         * @return Solucion
         * 
        */

        solucion encontrar(double p0, double tol, int n){
            using raices::es_cero;
            using raices::error_relativo;

            solucion sol(f.str(), {p0});

            // Paso 0
            sol.agregar(p0);

            if (es_cero(f(p0))){
                sol.raiz = p0;
                return sol;
                
            }
            

            // Paso 1
            int i = 1;

            //Paso 2 hacemos un while para ir iterando
            while(i<=n){
                
                // Paso 3  calcular la nueva raiz

                // Validar si la deriva es cero
                if (es_cero(df(p0))){
                    return sol;
                }

                double p = p0 - (f(p0) / df(p0));


                sol.agregar(p);

                // Paso 3.5 calcular el error relativo porcentual

                double er = error_relativo(p, p0);
                double erp = er * 100.0f;
                
                // Paso 4  comprobar si el error relativo es menor a la tolerancia
                if (es_cero(f(p)) || erp < tol){
                    sol.raiz = p;
                    return sol;
                }

                // Paso 5
                i++;
                // Paso 6
                p0 = p;
            }
            
            // Paso 8
            return sol;
        }

    private:
        expression f /* Evaluador de expresiones para la función*/;
        expression df /* Evaluador de expresiones para la derivada */;
    };
    
}
#endif