/**
   DISEÑO E IMPLEMENTACIÓN DE TDA POLINOMIO
   Blanca Cano Camarero
   Última modificación: 17/12/17

Errores:
Polinomio(): cuando intento relacionarlo con otros objetos, declarados cone el otro conductor me indca que no son de la misma clase
bolzano(); violaciones del segmento por todos lados xD 
Polinomio operator=()... //violación de segmento
 */

#include <iostream>
#include <vector>

using namespace std;

/**
   @brief lee número hasta su defecto y los almacena en el vector que devuelve
   @return vector de los número leídos
 */
vector<double> lee_numeros()
{
  vector <double> v;
  double num;

  while (cin >> num )
    v.push_back(num);

  cin.clear();
  cin.ignore( 300 , '\n');
  
  return v;
}
/**
   @brief devuelve el número mayor de dos
   @param a: entero a comparar
   @param b: entero a comparar
   @return el mayor, si son igules uno
   
 */
inline int max( int a , int b )
{
  return ( a > b)? a : b;
}

/**
   @brief menor de dos número
   @param a:entero a comparar
   @param b: entero a comparar
   @return el menor, si son iguales uno 
 */
inline int min( int a , int b)
{
  return ( a < b)? a : b;
}
  

//######################################## clase  polinimio ####################################################
/**
   @brief clase polinomio
   private: 
   coef vector con coeficientes
   
 */
class Polinomio
{
  vector<double> coef;

public:

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ constructores ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
  /**
     @brief constructor del polinomio sin introducid ningun valor
   */
  // ERROR which is of non-class type ‘Polinomio()’
  //cUANDO INTENTO COMPARAR REALIZAR OPERACIONESCON CON POLINOMIOS QUE NO SE NA DECLARADO CON ESTE CONSTRUCCTOR, NO ENTIENDO TAL ERROR
  Polinomio()
  {
    coef = lee_numeros();
  }
  

  
  /**
     @brief constructor de copia
     @param v, vector de números que representa simbólicamente a los coeficientes del polinomio, comenzando por el de menor grado
   */
  Polinomio( const vector<double>& v )
  {
    coef = v;
  }

  /**
     @brief construrtos de copia
     @param pol: polinomio mediante al que queramos que sea igual
   */
  Polinomio( const Polinomio& pol)
  {
    int pol_grado = pol.grado();
    coef.resize( pol_grado+1 );

    for( int i = 0; i <= pol_grado ; i++ )
      coef[i] = pol.coef[i];
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ métodos informativos ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /**
     @brief representa en consola el polinomio de menor a mayor
   */
  void representacion()const 
  {
    int tam = coef.size()-1;

    for( int i = 0; i< tam ; i++ )
      cout << coef[i] <<"X^"<<i << " + ";
    cout << coef[tam] <<"X^"<<tam<< endl;
  }
  
  /**
     @brief devuelve el grado de cuestro polinomio
     @return grado
   */
  int grado() const
  {
    int grado = coef.size()-1;

    while(grado > 0 && coef[grado] == 0 ) //primera condición por si el plinomio es el (0,0,...,0)
      grado--;
    
    return grado;
  }

  /**
     @brief evalua polinomio, el polinomio debe ser mayor que 2
     @param x: valor en el que se desea evalual
     @return resultado evaluación
  */
  double evalua( double x ) const 
  {
    double sumatoria = coef[0]; //genera error si el polinomio no toma ningun valor
    double x0 = x;  
    for( int i = 1 ; i <= grado() ; i++)
      {
	sumatoria += coef[i]*x;
	x *= x0;
      }

    return sumatoria;
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   raíces  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /**ERROR VIOLACIÓN DEL SEGMENTO
     @brief haciendo uso del teorema de Bolzano, si el inervalo introducido es por un lado negativo o positivo, calcula una de sus raíces del polinomio, con un rango de error
     @param a,b: intervalo en el que buscar, a < b
     @param error valor voluntario, si se introduce es la precisión con la que busa el resultado
     @return dónde se anula, si no se anula, devuelve a-1 
   */
  double bolzano( double a , double b , double error = 0.000000001 )const
  {
    double sol = a -1 ;
    double fa = evalua(a);
    double fb = evalua(b);
    
    if( a < b && fa * fb < 0)
      {
	sol = (b+a)/2;
	double valor = evalua(sol);
	while( !(valor > -error && valor < error) )
	  {
	    if( valor * fb < 0 )
	      {
		a = sol;
		fa = valor;
	      }
	    else
	      {
		b = sol;
		fb = valor;
	      }
	    sol = (a+b)/2;
	    valor = evalua( sol);
	  }
      }
    return sol;
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ operaciones ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  /**
     @brief operación suma
     @param otro polinomio
     @return objeto de la clase polinomio resultado de la suma de dos vectores
   */
  Polinomio operator+( Polinomio& pol) const 
  {
    int mi_grado = grado();
    int otro_grado = pol.grado();
    int max_g = max( mi_grado , otro_grado );

    vector<double> v ( max_g+1 , 0 );
    
    for( int i = 0; i <= mi_grado ; i++ )
      v[i]=coef[i];
    
    for( int i = 0 ; i <= otro_grado ; i++ )
      v[i] += pol.coef[ i ];
    
    return Polinomio (v);
  }

  /**
     @brief operación resta
     @param otro polinomio
     @return objeto de la clase polinomio resultado de la resta de dos polinomios
   */
  Polinomio operator-( Polinomio& pol) const 
  {
    int mi_grado = grado();
    int otro_grado = pol.grado();
    int max_g = max( mi_grado , otro_grado );

    vector<double> v ( max_g+1 , 0 );
    
    for( int i = 0; i <= mi_grado ; i++ )
      v[i]=coef[i];
    
    for( int i = 0 ; i <= otro_grado ; i++ )
      v[i] -= pol.coef[ i ];
    
    return Polinomio (v);
  }

  /**
     @brief producto por escalar
     @param k: escalar por el que se multiplica
     @return: policnomio con coeficientes multiplicados
   */
  Polinomio operator*( double k ) const 
  {
    vector<double> v (coef);
    for( int i= 0 ; i <= grado() ; i++)
      v[i] *= k;
    return Polinomio(v); 
  }

  /**ERROR
     @brief asignación de igualdad a nuestro polinomio MODIFICÁNDOLO
     @param pol: polinomio con el que queremos la igualdad
   */
  Polinomio operator=( const Polinomio& pol)
  {
    int pol_grado = pol.grado();
     coef.resize( pol_grado+1 );

    for( int i = 0; i <= pol_grado ; i++ )
      coef[i] = pol.coef[i];               // ERROR VIOLACIÓN DE SEGMENTO, dos días detrás de él y nada...
    representacion();
  }

};

//########################################### MAIN #########################################################

int main()
{
  //prueba declaraciones
  cout << "Introduzca coeficiente polinomio desde X⁰ hasta su máximo grado, un caracter no numérico para finalizar: "<< endl;
  Polinomio pol( lee_numeros());

  //prueba métodos de información
  cout << "El polinomio introducido es: ";
  pol.representacion();
  cout << "Grado: " << pol.grado() << endl;

  //prueba operaciones
  cout << "Introduzca coeficiente polinomio desde X⁰ hasta su máximo grado, un caracter no numérico para finalizar: "<< endl;
  Polinomio p( lee_numeros());

  cout << "El resulatdo de sumar ambos polinomios es:" ;
  Polinomio q ( pol + p);
  q.representacion();

  cout << "El resulatdo de restar ambos polinomios es:" ;
  Polinomio r ( pol - p);
  r.representacion();
  
  cout << "Dónde quiere evaluar el polinomio anterior : ";
  double x;
  cin >> x;
  cout << "Resultado: " << r.evalua( x ) << endl;

  cout << "El resultado de multipricar el polinomio evaluado por " << x << " es: ";
  (r*2).representacion();

  cout << "Bolzano: " << Polinomio({0,1}).bolzano ( -1 , 7); //violación del segmento 
  cout << endl;
  return 0;
}
