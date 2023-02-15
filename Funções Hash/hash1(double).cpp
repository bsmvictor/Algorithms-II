//Método da divisão
int h1(int k, int m)
{
	int h; //resultado

	h = k % m; //resto da divisão de k por m

	if (h < 0) //em caso do resultado h ser menor que 0

		h = h + m; //soma-se m no resultado

	return h; //retorno do resultado h
}

//Sondagem linear
int h2(int k, int m)
{
    int r = 0; //resultado

	r = 1 + k % (m-1); //resto da divisão de k por (m - 1) + 1

    if(r < 0) //caso o resultado de r seja menor que 0

		  r = r + m; //soma-se m ao resultado
    
    return r; //retorno do resultado r
}

//double Hashing
int hash1(int k, int m, int i)
{
    return (h1(k, m) + i * h2(k, m)) % (m);
}