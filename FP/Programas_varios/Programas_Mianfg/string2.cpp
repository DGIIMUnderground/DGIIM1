class string2 {
	string cadena_;
	string2 () {
		cadena_ = "";
	}
	string2 ( const string & cadena ) {
		cadena_ = cadena;
	}
	string2 ( const string2 & cadena ) {
		cadena_ = cadena.cadena_;
	}
	string2 replace ( int inicio, int longitud, string insertar ) {
		string string_a = "";
		string string_b = "";
		string2 resultado;
		for ( int i = 0; i < cadena_.size(); i++ ) {
			if ( i < inicio )
				string_a += cadena_[i];
			if ( i >= inicio+longitud )
				string_b += cadena_[i];
		}
		resultado.cadena_ = string_a + cadena_ + string_b;
		return resultado;
	}
};
