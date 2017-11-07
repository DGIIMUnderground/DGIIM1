#include<iostream>
using namespace std;

int main()
{
	int planta;
	char letra;
	int mes;
	double consumo;
	//int fijo = 6;
	double consumo_max=0;
	char letra_max;
	int planta_max;
	int mes_max;
	double consumo_total;
	double consumo_medio;
	double facturacion;
	double facturacion_total;
	double facturacion_total_fija;
	
	double facturacion_media;
	
	
	cin >> planta;
	while ( planta != -1)
	{
		while ( planta < 1 && planta > 3){
			cout <<"Planta aceptada está entre 1 y 3"<<endl;
			cout << "Introduzca planta  ";
			cin >> planta;
		}
		
		cin >> letra;
		while (letra != 'A' && letra != 'B'){
			cout <<"Letra aceptada está es A o B"<<endl;
			cout << "Introduzca letra  ";
			cin >> letra;
		}
		
		cin >> mes;
		while (mes < 1 && mes > 12){
			cout <<"Mes aceptado está entre 1 y 12"<<endl;
			cout << "Introduzca mes  ";
			cin >> mes;
		}
		
		cin >> consumo;
		while (consumo < 0){
			cout << "El volumen de agua consumido no puede ser negativo"<<endl;
			cout << "Introduzca consumo mensual(en m^3)  ";
			cin >> consumo;
		}
		
			
		consumo_total = consumo_total+consumo;
		consumo_medio = consumo_total/12;
		
		if (consumo <= 2)
			facturacion=consumo*0.4053;
		else if (consumo > 2 && consumo < 10)
			facturacion=consumo*0.6763;
		else if (consumo > 10)
			facturacion=consumo*1.3996;
			
		facturacion_total=facturacion_total+facturacion;
		facturacion_total_fija = 2*3*12*6;
		facturacion_media=(facturacion_total+facturacion_total_fija)/12;
		
		if (consumo > consumo_max){
			consumo_max = consumo;
			planta_max = planta;
			letra_max = letra;
			mes_max = mes;
		}
		cin >> planta; 
	}
	
	cout << "Consumo total: "<< consumo_total <<"m3"<<endl;
	cout << "Consumo medio: "<< consumo_medio << "m3/mes"<<endl;
	cout << "Facturación total: "<< facturacion_total + facturacion_total_fija << "€"<<endl;
	cout << "Facturacion media: " << facturacion_media << "€"<<endl;
	cout << "El piso que más ha consumido ha sido el " << planta_max << "º"<< letra_max << " en el mes " << mes_max << " con " << consumo_max << "m3"<<endl;
}

