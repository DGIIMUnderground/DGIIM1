#include <iostream>
using namespace std;


int Comparar ( char v1[], char v2[], int util1, int util2){
	
	int comparacion;
	int elementos1=0, elementos2=0;
	
	for ( int i = 0 ; i < util1 && *(v1+i) != '\0'; i++)
		elementos1++;
	
	for ( int j = 0 ; j < util2 && *(v2+j) != '\0' ; j ++ )
		elementos2++;
		
	if ( elementos1 == elementos2 ) 
		comparacion = 0;
	if ( elementos1<elementos2 )
		comparacion = -1;
	else
		comparacion = 1;
		
	return comparacion;	
}

void insertar ( char cad[], int util1, char subcad[], int util2 ){
	
	int contador2 = 0;
	for ( int i = util1 + 1 ;i < ( util1+util2) ; i++) 
	{
		*(cad+i) = *(subcad+contador2);
		contador2++;
	}
	util1= util1 + util2;
	*(cad+util1) = ' ';
 
	for ( int j = 0 ; j < util1 ; j ++ ) 
		cout << *(cad+j) << " ";
}


int main() {
	
	char cadena1[20] = {'J', 'a', 'v', 'i', 'e', 'r', '\0'};
	char cadena2[30] = {'J', 'o', 's', 'e', '\0'};
	int util1 = 7;
	int util2 = 5;
	int comparacion = Comparar(cadena1, cadena2, util1, util2);
	
	cout << "Comparacion: " << comparacion << endl;
	cout << "Insertar: ";
	insertar(cadena1, util1, cadena2, util2);
	
	
	}
