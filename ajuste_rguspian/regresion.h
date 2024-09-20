/**
* @file 
* @brief Regresion
* @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
* @copyright MIT License
 */

#ifndef REGRESION_H
#define REGRESION_H

#include <istream>
#include <cmath>
#include <vector>


using std::ostream;
using std::endl;
using std::vector;
namespace regresion{
    struct modelo_lineal{
        vector<double> x; /* !<Variable independeinete */
        vector<double> y; /* !<Variable dependeinete */
        double b0;  /* !<Término independiente de la ecuaciión de la recta de regresión */
        double b1;  /* !< Coeficiente de x de la recta de regresión */
        double st; /* !< Sumatoria de la  diferencai cuadratica de y con y_prom */
        double sr; /* !<  Sumatoria de la  diferencai cuadratica de y con y_estimado */
        double sy; /* !< Desviación estandar */
        double syx; /* !< Error estandar de aproximación */
        double r2; /* !< Coeficiente determinación*/
        bool valido = false; 
        modelo_lineal (vector<double> x, vector<double> y): x(x), y(y){
            construir();
        }

        void construir(){
            double s_x = 0.0f;
            double s_y = 0.0f;
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

            for (size_t i=0; i<n; i++){
                s_x += x[i];
                s_y += y[i];
                sxy += x[i]*y[i];
                sx2 += x[i]*x[i];
            }

            // Calcular los promedios
            x_prom = s_x/ (double) n;
            y_prom = s_y/ (double) n;

            b1 = (sxy - (y_prom * s_x))/(sx2 - (x_prom * s_x));

            b0 = y_prom - (b1 * x_prom);

            // Calcular st y sr
            st = 0;
            sr = 0;
            for (size_t i=0; i<n; i++){
                st += pow(y[i] - y_prom ,2);
                sr += pow(y[i] - b0 - (b1*x[i]), 2);
            }

            sy = sqrt(st / ((double) (n - 1)));
            syx = sqrt(sr / ((double) (n - 2)));

            // Calcular r2
            r2 = (st- sr) / st;
            
            valido = true;


        }

        double estimar(double x_est){
            return (b1 * x_est) + b0;
        }

        friend ostream& operator<<(ostream & os, const modelo_lineal & m){
            if (!m.valido){
                os<<"el modelo no es válido :("<<endl;
                return os;
            }

            os<< "Recta de regresión: "<<"y= "<<m.b1 << " * x"
            <<((m.b0<0.0f)?" - ":" + ") 
            <<fabs(m.b0)<<endl;
            os<<"Desv. Estandar: "
            <<m.sy<<endl;
            os<<"Error estandar de aproximacion: "
            <<m.syx<<endl;
            os<<"Coeficiente determinación: "
            <<m.r2<<endl;
            return os;
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
            modelo_lineal  obtener_modelo(){
                return modelo;
            }
            
        private:
            modelo_lineal modelo;
    };

    /**
     * @breif Calcula el logartimo neperiano de un vector de datos
     * @param v Vector de datos
     * @return Copiao con el logaritmo neperiando de los datos;
     */
    

    vector<double> ln(vector<double> v){
        for (auto & x: v){
            x = log(x);
            
        }


        return v;
    }



    /**
     * @breif Calcula el logartimo base 10 de un vector de datos
     * @param v Vector de datos
     * @return Copia con el logaritmo base 10 de los datos;
     */

    vector<double> log(vector<double> v){
        for(auto & x: v){
            x = log10(x);
        }

        return v;
    }

    /**
     * @brief Función potencia y = c * x ^ a
     * 
    */
     struct modelo_potencia{
        double c;
        double a;
        struct modelo_lineal lineal;
        bool valido;
        modelo_potencia(vector<double> x, vector<double> y): lineal(log(x), log(y)){
            c = pow(10.0f, lineal.b0);
            valido = lineal.valido;
            a = lineal.b1;
        }

        double estimar(double x_est){
            return c * pow(x_est, a);
        }

        friend ostream& operator<<(ostream & os, const modelo_potencia & m){
            if (!m.lineal.valido){
                os<<"El modelo no es válido :("<<endl;
                return os;
            }

            os<<"Función potencia"
                <<" y = "<<m.c
                <<" * x^"<<m.a
                <<endl;
            os<<"Desv. Estandar: "
            <<m.lineal.sy<<endl;
            os<<"Error estandar de aproximacion: "
            <<m.lineal.syx<<endl;
            os<<"Coeficiente determinación: "
            <<m.lineal.r2<<endl;
            return os;
            return os;
        }
     };
     


    class lineal_potencia{
        public:
            lineal_potencia(vector<double> x, vector<double> y):modelo(x, y){
            }

            double estimar(double x_est){
                if (!modelo.valido){
                    return NAN;
                }
                return modelo.estimar(x_est);
            }
            modelo_potencia  obtener_modelo(){
                return modelo;
            }
            
        private:
            modelo_potencia modelo;
    };

}

#endif
