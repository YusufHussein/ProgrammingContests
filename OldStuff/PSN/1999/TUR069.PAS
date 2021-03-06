{koder: A^2P}
{PSN 1999 #69 "Peaje de Autopista"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
  MaxM = 2000;
var
  fin,fout        : text;
  N,M,i,j,k,p,sol : word;
  b               : boolean;
  mark            : array[1..MaxN] of boolean;
  c               : array[1..MaxN,0..MaxN] of word;
  d               : array[boolean,0..MaxM] of word;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do
  begin
    readln(fin,j,k);
    inc(c[j,0]); inc(c[k,0]);
    c[j,c[j,0]] := k; c[k,c[k,0]] := j;
  end;{for}

  {solve}{bfs}
  for i:=1 to N do
  begin
    p := 0; d[b,0] := 1; d[b,1] := i;
    repeat
      inc(p); b := not b; d[b,0] := 0;
      for j:=1 to d[not b,0] do
        for k:=1 to c[d[not b,j],0] do
          if not mark[c[d[not b,j],k]] then
          begin
            inc(d[b,0]);
            mark[c[d[not b,j],k]] := true;
            d[b,d[b,0]] := c[d[not b,j],k];
          end;{then}
    until d[b,0] = 0;
    if p > sol then sol := p;
    for j:=1 to N do mark[j] := false;
  end;{for}

  {dprint}
  write(fout,(sol-1) * 100);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
 69� Peaje de Autopista                                   Turqu�a 1999
����������������������������������������������������������������������

 En   Palmia  existen  N  ciudades  conectadas  por  autopistas  (cada
 autopista  conecta  exactamente  2 ciudades en ambas direcciones). Es
 posible alcanzar cada ciudad desde cualquier  otra ciudad  usando una
 o varias autopistas. Hasta este  a�o el  peaje de las  autopistas fue
 cobrado en las autopistas. En la  mitad de  cada autopista exist�a un
 cobrador  de  peaje  que  cobraba una moneda  Palmia (1MP)  por  cada
 veh�culo que pasaba.

 Las autoridades oficiales del gobierno  decidieron reducir  el n�mero
 de cobradores  de  peaje e  introducir  sellos de  autopistas. Si  un
 carro desea entrar  en  la  autopista  debe tener  este sello  en  la
 ventanilla.

 Las autoridades  decidieron  que  el  sello  de  autopista por un a�o
 costara lo mismo que 100 viajes entre las  2 ciudades m�s lejanas. La
 distancia entre dos ciudades  es el  n�mero m�nimo de autopistas  que
 usted necesita usar para llegar de la primera ciudad a la otra.

 Su tarea consiste en escribir un programa el  cual calcule  el  costo
 del sello de autopista.

 Entrada

 El fichero de entrada contiene en la primera l�nea los enteros N y  M
 seperados por un espacio en blanco, donde N es el n�mero de  ciudades
 y M el n�mero de autopistas en Palmia (1 � N � 1000), (1 � M � 2000).
 Las ciudades est�n enumeradas por enteros desde 1 hasta  N. Cada  una
 de las pr�ximas M l�neas contienen un par de enteros A y B ( 1 � A, B
 � N) separdos por espacio, esto representa que  exite  una  autopista
 entre las ciudades A y B.

 Salida

 El  fichero  de  salida  contiene una l�nea con el costo del sello de
 autopista.

 ������������������Ŀ�����������������Ŀ
 �Ejemplo de Entrada��Ejemplo de Salida�
 ������������������Ĵ�����������������Ĵ
 �4 4               ��200              �
 �1 2               ��������������������
 �2 3               �
 �4 2               �
 �3 4               �
 ��������������������
}
