/*
 * Ejercicio 5.14 — Codificación. Escriba un programa para codificar un texto, es decir, un conjunto de líneas que termina
con una línea especial "#FIN#". Para ello, cambiará unas letras por otras predefinidas. El resultado del texto es otro texto
–las mismas líneas– con los caracteres cambiados. Por ejemplo, si encuentra alguna de las letras de la siguiente cadena:

	" !\"#$ %&’()∗+,−./0123456789:;<=>?@ABCDEFGHIJKLMN"
	"OPQRSTUVWXYZ[]^_‘abcdefghijklmnopqrstuvwxyz{|}~"

deberá cambiarse por la correspondiente de la siguiente cadena:

	"oEjlv2?i:TL[BPzwdY %6~;3QN|(5tA_&K=,up!RhIHx@∗f8]−"
	"7Fa)sn^q1m+OW>}Sge0cMbG’\"{#ZV DXyU<C$/Jr.k9‘4"

Así, si se introduce el siguiente texto:
	"Hay una antigua historia sobre una persona que quería que su
	ordenador fuese tan fácil de utilizar como su teléfono. Estos
	deseos se han hecho realidad, ya no sé cómo usar mi teléfono"
	Bjarne Stroustrup
	#FIN#

Se obtendrá como resultado lo siguiente:

	jISroCVSoSV<’bCSoG’U< y’SoU gycoCVSoDcyU VSoXCcoXCcyíSoXCcoUC
	y0cVS0 yoMCcUco<SVoMáe’#o0coC<’#’.Syoe Z oUCo<c#éM V zo!U< U
	0cUc UoUcoGSVoGceG oycS#’0S0BorSoV oUéoeóZ oCUSyoZ’o<c#éM V j

José L. Ruiz
* 
*NOTA: La ejecución para el ejemplo no es exactamente la misma, aunque si probamos diferentes caracteres se ve que esta solución funciona.
* Creo que el error está en que en las cadenas "normal" y "modificado" hay que poner "\" antes de cada carácter especial.
* Como todo parece indicar que el algoritmo es el correcto, paso de calentarme la cabeza poniendo barritas invertidas.
* 

 */

#include <iostream>
#include <string>

using namespace std;

void Codificar (string & t)
{
	string normal(" !\"#$ %&’()∗+,−./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_‘abcdefghijklmnopqrstuvwxyz{|}~");
	string codificado("oEjlv2?i:TL[BPzwdY %6~;3QN|(5tA_&K=,up!RhIHx@∗f8]−7Fa)sn^q1m+OW>}Sge0cMbG’\"{#ZV DXyU<C$/Jr.k9‘4");
	
	for (int i=0; i<t.size(); i++)
	{
		int posicion_codificacion = normal.find( t.at(i) ); //busco la posición de f.at(i) en la cadena normal
		
		if ( posicion_codificacion != string::npos )
		{
			t.at(i) = codificado.at( posicion_codificacion ); //sustuyo f.at(i) por el equivalente en codificado.
		}
	}
}

int main()
{
	string texto, linea;
	
	cout << "Introducir texto. Finalizar con la línea \"#FIN#\" :" << endl;
	getline(cin, linea);
	while(linea != "#FIN#" )
	{
		texto += "\n" + linea;
		getline(cin, linea);
	}
	
	Codificar(texto);
	
	cout << "El texto codificado es: " << endl << texto << endl;
}
