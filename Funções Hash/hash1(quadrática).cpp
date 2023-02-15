//Método da divisão
int hash_aux(int k, int m)
{
	int h; //resultado

	h = k % m; //resto da divisão de k por m

	if (h < 0) //em caso do resltado h ser menor que 0

		h = h + m; //soma-se m no resultado

	return h; //retorno do resultado h
}

//sondagem quadrática
int hash1(int k, int i, int m, int c1, int c2)
{
	return (hash_aux(k, m) + c1 * i + c2 * (i * i)) % m;
}