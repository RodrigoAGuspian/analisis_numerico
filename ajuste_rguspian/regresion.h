/**
* @file 
* @brief Regresion
* @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
* @copyright MIT License
 */

#ifndef REGRESION_H
#define REGRESION_H

#include <vector>
#include <cmath>

using std::vector;

namespace regresion{
    struct modelo_lineal{
        vector<double> x;
        vector<double> y;
        double b0;
        double b1;
        bool valido = false;
        modelo_lineal (vector<double> x, vector<double> y): x(x), y(y){
            construir();
        }

        void construir(){
            double sx = 0.0f;
            double sy = 0.0f;
            double sxy = 0.0f;
            double sx2 = 0.0f;
            double x_prom;
            double y_prom;
            

            size_t n = x.size();
            if (n != y.size()){
                return;
            }
            
            // Para calcular Sr se requiere al menos tres x
            if (n <3){{
                return;
            }}

            // TODO

            for (size_t i=0; i<n; i++){
                sx += x[i];
                sy += y[i];
                sxy += x[i]*y[i];
                sx2 += x[i]*x[i];
            }

            // Calcular los promedios
            x_prom = sx/ (double) n;
            y_prom = sy/ (double) n;

            b1 = (sxy - (y_prom * sx))/(sx2 - (x_prom * sx));

            b0 = y_prom - (b1 * x_prom);

            valido = true;


        }

        double estimar(double x_est){
            return (b1 * x_est) + b0;
        }
    };

    class lineal_simple{
        public:
            lineal_simple(vector<double> x, vector<double> y):modelo(x, y){
            }

            double estimar(double x_est){
                if (!modelo.valido){
                    return NAN;
                }
                return modelo.estimar(x_est);
            }
        private:
            modelo_lineal modelo;
    };
}

#endif
