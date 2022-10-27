# FindFiles
Program in C to find filex in an Unix system

Implementa uma versão simplificada do comando Unix find. Este comando permite procurar a localização de um arquivo ou diretório, a partir do seu nome. Por exemplo:
find . -name foto.jpeg
O comando acima irá procurar recursivamente, a partir do diretório atual (.), todas as ocorrências
de arquivos ou diretórios com o nome foto.jpeg. Ao encontrar uma ocorrência, ele exibe o
caminho relativo até sua localização, por exemplo:
./semana/trabalho/foto.jpeg
./viagem/foto.jpeg
O comando find possui uma série de parâmetros adicionais que podem ser consultados em seu manual com o comando man find. Iremos implementar uma versão simplificada que permita localizar um arquivo recursivamente (procurar em subdiretórios) a partir de um caminho qualquer. A implementação aceita dois parâmetros: caminho e nome. Exemplos:
my_find . foto.jpeg #procura a partir do diretório local
my_find / planilha.xls # procura a partir do diretório raiz.
Como resultado, o programa mostra todas as ocorrências dos arquivos ou diretóriosencontrados.
