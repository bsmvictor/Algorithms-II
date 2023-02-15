struct dado
{
    int k;       // chave
    int status; // 0:vazio, 1:ocupado
};

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

//Pesquisa em tabela
int hash_search(dado t[], int m, int k)
{
	int i = 0;  //tentativas
  int j = 0; //posição na tabela

    do
    {
	    j = hash1(k, i, m); //posição da chave, Sondagem linear

      if (t[j].k == k) //valor de k é igual ao da posição j
	      return j;     //retorna a posição j

      else    //valor de k é difernte do que está na posição j
	      i++; //soma 1 em i
			
		//testar status em j e ver se i é menor que m
    } while (t[j].status != 0 && i < m);
	return -1; //tabela cheia
}