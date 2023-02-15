 //Método da divisão
int hash_aux(int k, int m)
{
	int h; //resultado

	h = k % m; //resto da divisão de k por m

	if (h < 0) //em caso do resltado h ser menor que 0

		h = h + m; //soma-se m no resultado

	return h; //retorno do resultado h
}

//Sondagem linear
int hash1(int k, int i, int m) 
{
	return (hash_aux(k, m) + i) % m;																	
}
	//i conta as tentativas, 0, 1, 2,...
 //a posição da chave resulta do resto de h + i por m
//sempre que (h + i) < m, será 1