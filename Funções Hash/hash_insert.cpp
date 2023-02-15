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