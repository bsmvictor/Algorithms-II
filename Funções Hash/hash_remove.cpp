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

//Função de inserção de elementos
int hash_insert(dado t[], int m, int k)
{
	int i = 0;  //tentativas
  int j = 0; //posição na tabela

   do
   {
	   j = hash1(k, i, m); //posição da chave, Sondagem linear

     if (t[j].status != 1) //se status for diferente de 1
     {
	     t[j].k = k; //recebe a chave na posição j

       t[j].status = 1; //altera status para 1, (ocupado)
       return j;       //posição em que k foi inserida em t
     }
	   else    //em caso de colisão
		   i++; //soma 1 em i e tenta uma nova posição

   }while (i != m); //enquanto i for menor que m
	return -1;       //tabela cheia
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

//Remoção da tabela para
int hash_remove(dado t[], int m, int k)
{
	int j; //posição na tabela

	j = hash_search(t, m, k); //posição da chave, função de busca

	if(j != -1) //posição sendo diferente de -1
	{
		t[j].status = 2; //muda o status para removido
		t[j].k = -1;    //altera o valor da chave para -1
		return 0;      //conseguiu remover
	}
	else //valor da posição seja = -1
	{
		return -1; //k não está na tabela
	}
}