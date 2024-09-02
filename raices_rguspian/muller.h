/**
 * @file
 * @brief Método de Müller
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef MULLER_H
#define MULLER_H

#include "expression.h"
#include "raices.h"

using std::string;
using raices::solucion;

namespace raices{
    class muller{
        
    public:
        /**
         * @brief Crea una nueva instancia del método de Müller
         * @param f_str Función como texto
         */
        muller(string f_str):f(f_str){

        }

        /**
         * @brief Encuentra una solución a la función usando el método de de Müller
         * @param x0 Punto inicial
         * @param x1 Punto intermedio
         * @param x2 Punto final
         * @param tol Tolerancia - del Error Relativo Porcentual
         * @param n Número máximo de repeticiones
         * @return Solucion
         * 
        */

        solucion encontrar(double x0, double x1, double x2, double tol, int n){
            using raices::es_cero;
            using raices::error_relativo;

            solucion sol(f.str(), {x0, x1, x2});

            // Paso 0  agregar y evaluar las aproximaciones
            
            sol.agregar(x0);
            sol.agregar(x1);
            sol.agregar(x2);

            double f0 = f(x0);
            double f1 = f(x1);
            double f2 = f(x2);
            
            if (es_cero(f0)){
                sol.raiz = x0;
                return sol;
                
            }

            if (es_cero(f1)){
                sol.raiz = x1;
                return sol;
                
            }

            if (es_cero(f2)){
                sol.raiz = x2;
                return sol;
                
            }

            // Paso 1
            double h1 = x1-x0;
            double h2 = x2-x1;

            //1e-5
    
            double delta1 = (f1 - f0) / h1;
            double delta2 = (f2 - f1) / h2;
            double a = (delta2-delta1) / (h2+h1);

            int i = 2;

            //Paso 2 hacemos un while para ir iterando
            while(i<=n){
                // Paso 3 
                double b = delta2 + (h2*a);
                double d = sqrt(pow(b,2) - (4 * f2 * a));
                // Paso 4
                double e = b-d;
                if (fabs(b-d) < fabs(b+d)){
                    e = b+d;
                }

                // Paso 5
                double h = (-2 * f2) / e;
                double p = x2+h;
            
                sol.agregar(p);
                // Paso 6
                double er = error_relativo(p, x2);
                // Calcular el error relativo porcentual
                double erp = er * 100;

                
                if (es_cero(f(p)) || erp < tol){
                    sol.raiz = p;
                    return sol;
                }


                // Paso 7
                x0 = x1;
                x1 = x2;
                x2 = p;
                h1 = x1-x0;
                h2 = x2-x1;


                f0 = f(x0);
                f1 = f(x1);
                f2 = f(x2);

                double delta1 = (f1 - f0) / h1;
                double delta2 = (f2 - f1) / h2;
                double a = (delta2-delta1) / (h2+h1);
                i = i +1;
            }
            
               // Paso 8
            return sol;
        }

    private:
        expression f /* Evaluador de expresiones */;
    };
    
}
#endif