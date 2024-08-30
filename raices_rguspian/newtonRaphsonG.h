/**
 * @file
 * @brief Newton Raphson Generalizaco
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef NEWTOW_RAPHSON_G
#define NEWTOW_RAPHSON_G


#include <cmath>
#include <string>

#include "expression.h"
#include "raices.h"

 
using std::string;
using raices::solucion;

namespace raices{
    class newton_raphson_g{
        
    public:
        /**
         * @brief Crea una nueva instancia del método de Newton Raphson Generalizado
         * @param f_str Función como texto
         * @param df_str Derivada como texto
         * @param df2_str Segunda derivada como texto
         */
        newton_raphson_g(string f_str, string df_str, string df2_str):f(f_str),df(df_str), df2(df2_str){

        }

        /**
         * @brief Encuentra una solucón a la función usando Newton Rapshon
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

                double numerador =f(p0)*df(p0); 
                double denominador = (pow(df(p0), 2) -(f(p0) *df2(p0)));

                double p = p0 -  numerador/ denominador;


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
        expression df2 /* Evaluador de expresiones para la 2da derivada */;
    };
    
}



#endif