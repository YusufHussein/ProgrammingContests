/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 NOV Gold "Caminar la Conversaci�n"
*/
#include <fstream>
#include <cstring>
using namespace std;

#define problem "d"
#define MAXF 31
#define MAXLEN 100
#define dp( i, j, k ) \
  ( dp[i][j - 1][k] + dp[i][j][k - 1] - dp[i][j - 1][k - 1] )

int F, C, i, j, k, len, sol;
char mat[MAXF][MAXF];
int dp[MAXLEN][MAXF][MAXF];
char st[MAXLEN];

ifstream fin ( problem ".in" );
ifstream dict ( /*"twalk."*/ "dict.txt" );
ofstream fout ( problem ".out" );

int main() {

  fin >> F >> C;
  for ( i = F; i; i-- )
    for ( j = 1; j <= C; j++ )
      fin >> mat[i][j];

  for ( i = 0; i <= F; i++ )
    for ( j = 0; j <= C; j++ )
      dp[0][i][j] = 1;

  while ( dict >> st + 1 ) {

    len = strlen( st + 1 );

    for( i = 1; i <= len; i++ )
      for ( j = 1; j <= F; j++ )
        for ( k = 1; k <= C; k++ ) {

          dp[i][j][k] = dp( i, j, k );

          if ( st[i] == mat[j][k] )
            dp[i][j][k] += dp( i - 1, j, k );
        }

    sol += dp[len][F][C];
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 3: Caminar la Conversaci�n [Hal Burch, 2005]

El Granjero Juan ha puesto un juego de letras que sus vacas deben
resolver. En la entrada del establo, �l ha puesto un tablero H x W de
letras (1 <= H <= 30, 1 <= W <= 30). Antes que una vaca pueda entrar
al establo, ella debe deletrear una palabra v�lida en ingl�s saltando
de cuadrado en cuadrado, creando una secuencia de letras. Ella puede
comenzar en cualquier cuadrado pero puede solo saltar a un cuadrado
subsecuente que est� ubicado a la derecha y/o arriba de la ubicaci�n
del cuadrado actual (esto es, nunca a la izquierda, ni abajo). El
siguiente cuadrado puede estar a cualquier distancia del actual, pues
las vacas son saltadoras de clase mundial.

Ning�n par de vacas puede recorrer exactamente el mismo camino, sin
embargo se permite que dos vacas deletreen la misma palabra a trav�s
de caminos diferentes.

Como un ejemplo, considere este tablero (asumiendo que 'TO' y 'OX'
sean palabras):

  T X X O
  T X Q T
  X T X Q

Son v�lidos cuatro caminos, todos deletreando 'TO' (un deletreo
requiere una 'T' de la fila inferior y una 'O' de la fila superior).
'OX' es una palabra v�lida, pero requerir�a saltar a un cuadrado 'X' a
la izquierda de la 'O', lo cual no es permitido.

Dados el tablero y una lista de palabras v�lidas, calcule el n�mero de
vacas que pueden entrar al establo sin ninguna vaca repitiendo un
camino. El archivo `dict.txt' estar� disponible y contendr� la lista
de palabras v�lidas, una por l�nea. Vea una copia de �l en
http://ace.delos.com/usaco/dict-twalk.txt .

NOMBRE DEL PROBLEMA: twalk

FORMATO DE ENTRADA:

* L�nea 1: Dos enteros: H y W.

* L�neas 2..H+1: Cada l�nea contiene W caracteres, sin espacios,
        representando una fila del tablero. La primera fila es la de
m�s
        arriba. El primer caracter en cada fila es el caracter m�s a
la
        izquierda.


ENTRADA EJEMPLO (archivo twalk.in)

3 4
TXXO
TXQT
XTXQ

FORMATO DE SALIDA:

* L�nea 1: El n�mero de vacas que pueden entrar al establo sin repetir
un
        camino.

EJEMPLO DE SALIDA (archivo twalk.out):

4

DETALLES DE LA SALIDA:

Pueden entrar 4 vacas al establo, cada una deletreando una de las
'TO's
*/
