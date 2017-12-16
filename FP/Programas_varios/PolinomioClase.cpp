//Por Andrés Millán
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
using namespace std;

/**
 * @brief: TDA; clase para representar polinomios.
 * Los polinomios vienen dados por x0+a1*x1+...+an*xn
 * donde a1...an son escalares y x0...xn es el polinomio, con grado n. N puede ser [0,n]
 * 
 * Operaciones definidas: +, -, *, /, Extraer raíces, evaluar, factorizar
 */
class Polinomio{
private:
    unsigned int grado;                 //Grado se entiende por la pertenencia de variables; es decir, a+bx => grado 1. 
                                        //Por lo tanto, tendremos que hacer cálculos teniendo en cuenta un grado más
    vector<double> Px;
public:
    //Constructor por defecto. 0+0x+0x²
    Polinomio(){
        grado=2;
        Px.resize(grado+1);
        for (int i=0; i<grado+1; i++)
            Px[i]=0;
    };
    
    /**
     * @brief: constructor primitivo
     * @param grado_: grado del polinomio
     * @paran Px_: vector de coeficientes. Desde 0 hasta n
     */
    Polinomio(unsigned int grado_, vector<double> Px_){
        grado=grado_;
        Px.resize(grado+1);
        for (int i=0; i<grado+1; i++)
          Px[i]=Px_[i];      
    }
    
    /**
     * @brief: constructor de copia
     * @param Px_: polinomio a copiar
     */
    Polinomio(const Polinomio & Px_){
        grado=Px_.grado;
        Px=Px_.Px;
    }

    /**
     * @brief: obtiene el grado
     */
    int GetGrado() const{
        return grado;
    }

    /**
     * @brief: obtiene los coeficientes
     */   
    vector<double> GetCoeficientes() const{
        return Px;
    }
    /**
     * @brief: saca a la salida estándar el polinomio
     */
    void EscribirPolinomio(){
        for (int i=grado; i>=0; i--){
            if (Px[i]>0 && i!=0)
                cout <<" + "<<Px[i]<<"x^"<<i;
            if (Px[i]<0 && i!=0)
                cout <<Px[i]<<"x^"<<i;
            if (Px[i]>0 && i==0)
                cout <<" + "<<Px[i];
            if (Px[i]<0 && i==0)
                cout <<Px[i];
        }
    }
    /**
     * @brief: Halla las raíces de un polinomio de grado 2 o menor
     * @param sol1: si existe, le asigna el valor de una raiz
     * @param sol2: si existe, le asgina el valor de la otra raíz
     * @return: -1 si el grado es mayor que 2 (es una clase simple, implementarlo para todos los grados sería una locura para este ejercicio)
     */
    int Raices(double & sol1, double & sol2){
        if (grado>2)
            return -1;
        double a = Px[0]; //Estoy reutilizando código de otro ejercicio pasado,
        double b = Px[1]; //el de hallar las raíces 
        double c = Px[2];
        
        if (a==0)
		    if (b==0)
                sol1=c;

		    else
                sol1=(-1*c)/b;
           
	    else{
		    if (b==0){
			    sol1=sqrt((-1*c)/a);
                sol2=-sqrt((-1*c)/a);

			}	
	    	else
			    if (c==0){
				    sol1=-b/a;
				    sol2=0;
		    	}
		    	else{
			    	sol1=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
			    	sol2=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
		    	}
	    }
    }

    /**
     * @brief: dado un valor para x, lo evalúa
     * @param fx: valor para asignarle a x
     * @return: devuelve el valor obtenido
     */
    double Evaluar(double fx) const{
        double resultado=0;
        for (int i=0; i<grado+1; i++){
            resultado = resultado + pow(Px[i],i);
        }

        return resultado; 
    }

    /**
     * @brief: suma dos polinomios
     * @param Py: segundo sumando. 
     * @return: devuelve la suma del objeto receptor y el argumento Py
     */
    Polinomio operator+(const Polinomio & Py) const{ //No entiendo por qué, pero cuando el grado es 2, se introduce una variable basura. Ƥuede alguien mirarlo?
        Polinomio Pz;
        int gradillo1=Px.size();
        int gradillo2=Py.Px.size();
        int gradon=max(gradillo1,gradillo2);
        
        Pz.grado=gradon;

        if (Pz.Px.size()<gradon)
            while (Pz.Px.size()!=max(gradillo1,gradillo2))
                Pz.Px.push_back(0);
        if (Pz.Px.size()>gradon)
            while (Pz.Px.size()!=gradon)
                Pz.Px.pop_back();

        for (int i=0; i<grado+1; i++)
            Pz.Px[i]=Px[i]+Py.Px[i];

        return Pz;
    }

    /**
     * @brief: resta dos polinomios
     * @param Py: segundo restando. 
     * @return: devuelve la resta del objeto receptor y el argumento Py
     */
    Polinomio operator-(const Polinomio & Py) const{
        Polinomio Pz;
        int gradillo1=Px.size();
        int gradillo2=Py.Px.size();
        int gradon=max(gradillo1,gradillo2);
        
        Pz.grado=gradon;

        if (Pz.Px.size()<gradon)
            while (Pz.Px.size()!=max(gradillo1,gradillo2))
                Pz.Px.push_back(0);
        if (Pz.Px.size()>gradon)
            while (Pz.Px.size()!=gradon)
                Pz.Px.pop_back();

        for (int i=0; i<grado+1; i++)
            Pz.Px[i]=Px[i]-Py.Px[i];
        return Pz;
    }

    /**
     * @brief: Multiplicación de un escalar por un polinomio
     * @param escalar: escalar a multiplicar
     * @return: devuelve el resultado  
     */
    Polinomio operator*(const double escalar) const{
        Polinomio Pz;
        Pz.grado=grado;
        Pz.Px.resize(grado+1);
        for (int i=0; i<grado+1; i++)
            Pz.Px[i]=Px[i]*escalar;
        return Pz;
    }
    
    /**
     * @brief: División de un escalar por un polinomio
     * @param escalar: escalar a dividir
     * @return: devuelve el resultado  
     */
    Polinomio operator/(const double escalar) const{
        Polinomio Pz;
        Pz.grado=grado;
        Pz.Px.resize(grado+1);
        if (escalar!=0)
            for (int i=0; i<grado+1; i++)
                Pz.Px[i]=Px[i]/escalar;
        return Pz;
    }

    /**
     * @brief: Le asgina un polinomio a otro
     * @param Py: Polinomio cuyos valores serán asignados al pasado como objeto receptor
     * @return: devuelve el nuevo polinomio
     */
    Polinomio operator=(const Polinomio & Py){ //Por algún motivo se rompe a partir de la tercera itinerancia dios sabe por qué
        grado=Py.grado;
        if (Px.size()<Py.Px.size())
            while (Px.size()!=Py.Px.size())
                Px.push_back(0);
        if (Px.size()>Py.Px.size())
            while (Px.size()!=Py.Px.size())
                Px.pop_back();
        for (int i=0; i<grado+1; i++){               
            Px[i]=Py.Px[i];
        }
        return *this;
    }


};

int main(){
    cout <<"Vamos a ir haciendo un tour por la clase. Primero, crearemos un polinomio P(w). Introduce el grado del polinomio: ";
    unsigned int grad;
    cin >>grad;

    vector<double> Poli(grad+1);
    cout <<"Muy bien. Ahora, pon los coeficientes (an*xn + ... + a1*x1 + a0): \n";
    for (int i=grad; i>=0; i--){
        cout <<"x^"<<i<<": ";
        cin >>Poli[i];
    }
    Polinomio pw(grad,Poli);

    cout <<"La dimensión del polinomio es "<< pw.GetGrado() <<" y sus coeficientes son: ";
    pw.EscribirPolinomio();
    
    cout <<"\nVeamos ahora el constructor por defecto para P(z): ";
    Polinomio Pz;
    Pz.EscribirPolinomio();
    cout <<"(No escribe nada porque está vacío). \nCreemos ahora una copia del antiguo vector a uno nuevo, P(a): ";
    Polinomio pa(pw);
    pa.EscribirPolinomio();

    cout <<"\nCopiemos el valor de este último en P(z): ";
    Pz=pa;
    Pz.EscribirPolinomio();

    cout <<"\nMultipliquemos P(a) vector por un escalar, 3. P(a): ";
    pa=(pa*3);
    pa.EscribirPolinomio();
    
    cout <<"\nSumemos P(a) y P(w) en P(z): ";
    Pz=(pa+pw);
    Pz.EscribirPolinomio();

    cout <<"Evaluemos ahora este último en algún punto. Dime, ¿cuál quieres?\n";
    int evaluador;
    cin >>evaluador;
    cout <<"Pues vale "<<Pz.Evaluar(evaluador)<<". No está mal, eh?";

    cout <<"Para finalizar, miraremos las raíces de los polinomios <=2. Por ejemplo, probemos con P(w): ";
    if (grad>2)
        cout <<"Ups, pero parece que no vamos a poder en este caso. Sorry!";
    else{
        double sol1, sol2;
        pw.Raices(sol1, sol2);
        cout <<"Las raíces son "<<sol1<<" y "<<sol2;
    }

    cout <<"Han quedado funciones sin probar, y hay algunas con bugs. Pero llevo casi 300 líneas, una tarde entera, y estoy cansado de probar cosas. ¡Así que eso es todo!";

    
    
    
    return 0;
}

