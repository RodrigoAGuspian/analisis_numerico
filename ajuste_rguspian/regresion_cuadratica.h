/**
* @file 
* @brief Regresion Cuadratica
* @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
* @copyright MIT License
 */

#ifndef REGRESION_CUADRATICA_H
#define REGRESION_CUADRATICA_H

#include <vector>
#include "gauss.h"
#include <cmath>
#include <ostream>

using std::ostream;
using std::vector;
using std::endl;


namespace regresion
{
    struct modelo_cuadratico{
        vector<double> x; /* !<Variable independeinete */
        vector<double> y; /* !<Variable dependeinete */
        vector<double> a; /*!< Arreglo de coeficientes*/
        double st; /* !< Sumatoria de la  diferencai cuadratica de y con y_prom */
        double sr; /* !<  Sumatoria de la  diferencai cuadratica de y con y_estimado */
        double sy; /* !< Desviación estandar */
        double syx; /* !< Error estandar de aproximación */
        double r2; /* !< Coeficiente determinación*/
        bool valido = false; 

        /**
         * @brief Crea una ninstancia de un modelo de regresion cuadratica
         * @param x Variable independiente
         * @param y Variable dependiente
         * 
        */
        modelo_cuadratico (vector<double> x, vector<double> y): x(x), y(y){
            construir();
        }

        void construir(){
            size_t n = x.size();

            if (n != y.size()){
                // X e Y de difrentes tamaños
                return;
            }

            if (n <= 3){
                // Datos insuficientes
                return;
            }
            
            double sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, 
                sum_xy = 0, sum_x2y = 0, 
                sum_y = 0;
            
            // Calcular las sumatorias
            for (size_t i = 0; i < n; i++)
            {
                sum_x += x[i];
                sum_x2 += pow(x[i], 2);
                sum_x3 += pow(x[i], 3);
                sum_x4 += pow(x[i], 4);

                sum_xy += x[i]*y[i];
                sum_x2y += pow(x[i], 2) * y[i];
                
                sum_y += y[i];
            }
            
            // Resolver el sistema de ecuaciones
            vector<vector<double>> m_gauss = {
                {(double)n, sum_x, sum_x2, sum_y},
                {sum_x, sum_x2, sum_x3, sum_xy},
                {sum_x2, sum_x3, sum_x4, sum_x2y}
                
            };
            
            // Invocar Gauss para obtner los coeficientes;
            a = gauss(m_gauss);

            // Verificar si el modelo es valido
            valido = (!std::isnan(a[0]) ) && (!std::isnan(a[1])) && (!std::isnan(a[2]));

            // Si el modelo no es valido, terminar su construcción
            if (!valido){
                return;
            }

            // Calcular los estadisticos


            double y_prom = sum_y / (double) n;
            st = 0.0f;
            sr = 0.0f;
            for (size_t i = 0; i < n; i++){
                st += pow(y[i] - y_prom, 2),
                sr += pow(y[i]- estimar(x[i]), 2);
            }

            sy= sqrt(st/(double) (n-1));
            syx= sqrt(sr/(double) (n-3));

            r2 = (st-sr) /st;
            
        }

        /**
         * @brief Calcula el valor estimado de x_est usando regresion cuadratica
         * @param x_est Valor de x a estimar
         * @return Valor del polinomio cuadratico para x_est
         */
        double estimar(double x_est){
            if (!valido)
                return NAN;
            return a[0] + a[1]*x_est + a[2]*x_est*x_est;
        }

        /**
         * @brief Sobrecarga del operador sobre un flujo de salida
         * @param os Flujo de salida a envaar el modelo
         * @param m Modelo a enviar
         * @return Flujo luego e enviar el modelo
         */
        friend ostream& operator<<(ostream & os, const modelo_cuadratico & m){
            if (!m.valido){
                os<<"el modelo no es válido :("<<endl;
                return os;
            }

            os<< "Ecuación cuadratica: "<<"y= "<<m.a[2] << " * x ^ 2"
            <<((m.a[1]<0.0f)?"* x - ":" + ") 
            <<fabs(m.a[0])<<endl;
            os<<"Desv. Estandar: "
            <<m.sy<<endl;
            os<<"Error estandar de aproximacion: "
            <<m.syx<<endl;
            os<<"Coeficiente determinación: "
            <<m.r2<<endl;
            return os;
        }
   
    };

    /**
     * @brief Regresión Cuadratica
     */

    class cuadratica{
        
        public:
            /**
             * @brief Crea una instancia de regresion cuadratica
             * @param x_est Valor
            */
            cuadratica(vector<double> x, vector<double> y):modelo(x, y){
            }

            /**
             * @brief Calcula el valor estimado de x_est usando regresion cuadratica
             * @param x_est Valor de x a estimar
             * @return Valor del polinomio cuadratico para x_est
             */

            double estimar(double x_est){
                if (!modelo.valido){
                    return NAN;
                }
                return modelo.estimar(x_est);
            }
            /**
             * @brief Retorna el modelo de regresion cuadratica
             *  @return Modelo de regresion cuadratica otendido
             */
            modelo_cuadratico  obtener_modelo(){
                return modelo;
            }
            
        private:
            modelo_cuadratico modelo; /*<! Modelo regresión cuadratico*/
    };
        
} // namespace regresion

#endif