//Nombre: <José Luis Ruiz Benito>
//Subgrupo: <A2>

#include <iostream>

using namespace std;

int main()
{
	int dorsal;
	int hora, minuto;
	char p; //separador entre horas y minutos.
	
	int participantes=0; //contador del númro de filas de datos introducidas
	int hora_min, minuto_min;
	
	int ganador;
	
	bool tiempo_incorrecto;
	
	cout << "Introduzca los dorsales y tiempo correspondientes. Termine con el dorsal 0" << endl;
	
	//ENTRADA:
	
		//Primera lectura:
		
		cin >> dorsal;
		
		if(dorsal!=0){		//si el primer dorsal es distinto de 0 el programa continúa.
			do{
				cin >> hora >> p >> minuto;
				
				tiempo_incorrecto = ( hora<0 || minuto<0 || minuto>59 );
				if(tiempo_incorrecto){
					cout << "Valor " << hora << ":" << minuto << " erróneo. Vuelva a introducir el tiempo del dorsal " << dorsal << endl;
				}
				else{
				hora_min=hora;
				minuto_min=minuto;
				participantes++;
				ganador=dorsal;
				}
			
			}while(tiempo_incorrecto);
		
		
			//Segunda lectura y sucesivas:
			
			while(dorsal!=0){	
				cin >> dorsal;
				
				if(dorsal!=0){
					do{
						cin >> hora >> p >> minuto;
						
						tiempo_incorrecto = ( hora<0 || minuto<0 || minuto>59 );
						if(tiempo_incorrecto){
							cout << "Valor " << hora << ":" << minuto << " erróneo. Vuelva a introducir el tiempo del dorsal " << dorsal << endl;
						}
						else{
							participantes++;
							
							if(hora<hora_min){
								hora_min=hora;
								minuto_min=minuto;
								ganador=dorsal;
							}
							if(hora==hora_min){
								if(minuto<minuto_min){
									minuto_min=minuto;
									ganador=dorsal;
								}
							}
						}
					}while(tiempo_incorrecto);
				}
			}
						
			//SALIDA: (si el primer dorsal introducido no fue 0)
			
			cout << "Número de participantes: " << participantes << "\nLa primera posición corresponde al dorsal " << ganador << " con un tiempo de " << hora_min << ":" << minuto_min << endl;
		}
		else{		//si el primer dorsal es 0.
		
			cout << "Número de participantes: " << participantes  << "\nNo hay ganador" << endl;
		}
}


