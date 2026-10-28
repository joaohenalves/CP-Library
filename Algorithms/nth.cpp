// função que separa um vetor por um pivo
// do jeito que esta ai, o indice pivo 'k' eh o primeiro de fora do grupo [0, k -1]
// separa nos indices [0, k - 1] todos os elementos maiores que no indice k, se aux estivesse ordenado
// separa nos indices [k + 1, n] todos os elementos menores que no indice k, se aux estivesse ordenado
// nessa versao, k precisa ser menor que o tamanho de aux. em outras palavras, é necessario que k < n;
// pode ser que faça sentido usar k - 1 na funcao ao invés de só k, aí o indice k faz parte do grupo da esquerda.
// ai nesse caso, nao tem problema utilizar k == n.
// pode ser que a complexidade dessa funcaop seja quadrática. se der TLE usando isso, é melhor
// utilizar outros metodos como sort, set, etc

nth_element(aux.begin(), aux.begin() + k, aux.end(), greater<int>());