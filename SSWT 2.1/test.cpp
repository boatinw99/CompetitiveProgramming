wall-templates/                                                                                     000700  000765  000024  00000000000 12361050375 014405  5                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         wall-templates/compile_c.sh                                                                         000644  000765  000024  00000000137 12350040374 016702  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         #!/bin/bash

NAME=wall

/usr/bin/gcc -DEVAL -static -O2 -std=c11 -o $NAME grader.c $NAME.c -lm
                                                                                                                                                                                                                                                                                                                                                                                                                                 wall-templates/compile_cpp.sh                                                                       000644  000765  000024  00000000141 12350040366 017236  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         #!/bin/bash

NAME=wall

/usr/bin/g++ -DEVAL -static -O2 -std=c++11 -o $NAME grader.cpp $NAME.cpp
                                                                                                                                                                                                                                                                                                                                                                                                                               wall-templates/compile_pas.sh                                                                       000644  000765  000024  00000000107 12350040404 017232  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         #!/bin/bash

NAME=wall

/usr/bin/fpc -dEVAL -XS -O2 -o$NAME grader.pas
                                                                                                                                                                                                                                                                                                                                                                                                                                                         wall-templates/grader.c                                                                             000644  000765  000024  00000001272 12357203274 016034  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         #include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "wall.h"

int main()
{
  int n;
  int k;

  int i, j;
  int status = 0;

  status = scanf("%d%d", &n, &k);
  assert(status == 2);

  int* op = (int*)calloc(sizeof(int), k);
  int* left = (int*)calloc(sizeof(int), k);
  int* right = (int*)calloc(sizeof(int), k);
  int* height = (int*)calloc(sizeof(int), k);
  int* finalHeight = (int*)calloc(sizeof(int), n);

  for (i = 0; i < k; i++){
    status = scanf("%d%d%d%d", &op[i], &left[i], &right[i], &height[i]);
    assert(status == 4);
  }

  buildWall(n, k, op, left, right, height, finalHeight);

  for (j = 0; j < n; j++)
    printf("%d\n", finalHeight[j]);

  return 0;
}
                                                                                                                                                                                                                                                                                                                                      wall-templates/grader.cpp                                                                           000644  000765  000024  00000001272 12357203266 016375  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         #include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "wall.h"

int main()
{
  int n;
  int k;

  int i, j;
  int status = 0;

  status = scanf("%d%d", &n, &k);
  assert(status == 2);

  int* op = (int*)calloc(sizeof(int), k);
  int* left = (int*)calloc(sizeof(int), k);
  int* right = (int*)calloc(sizeof(int), k);
  int* height = (int*)calloc(sizeof(int), k);
  int* finalHeight = (int*)calloc(sizeof(int), n);

  for (i = 0; i < k; i++){
    status = scanf("%d%d%d%d", &op[i], &left[i], &right[i], &height[i]);
    assert(status == 4);
  }

  buildWall(n, k, op, left, right, height, finalHeight);

  for (j = 0; j < n; j++)
    printf("%d\n", finalHeight[j]);

  return 0;
}
                                                                                                                                                                                                                                                                                                                                      wall-templates/grader.pas                                                                           000644  000765  000024  00000001330 12357203256 016370  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         program main;

uses wall;

var
   n    : longint;
   k    : longint;
   op	       : array of longint;
   left        : array of longint;
   right       : array of longint;
   height      : array of longint;
   finalHeight : array of longint;
   i, j	       : longint;
begin
   read(n);
   read(k);

   setLength(op, k);
   setLength(left, k);
   setLength(right, k);
   setLength(height, k);
   setLength(finalHeight, n);

   for i := 0 to k - 1 do
   begin
      read(op[i]);
      read(left[i]);
      read(right[i]);
      read(height[i]);
   end;

   for j := 0 to n - 1 do
      finalHeight[j] := 0;

   buildWall(n, k, op, left, right, height, finalHeight);

   for j := 0 to n - 1 do
      writeln(finalHeight[j]);
end.
                                                                                                                                                                                                                                                                                                        wall-templates/sample-1.in                                                                          000644  000765  000024  00000000051 12352215546 016365  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         10 3
1 3 4 91220
1 5 9 48623
2 3 5 39412
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       wall-templates/sample-1.out                                                                         000644  000765  000024  00000000060 12352215546 016566  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         0
0
0
39412
39412
39412
48623
48623
48623
48623
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                wall-templates/sample-2.in                                                                          000644  000765  000024  00000000065 12352215546 016373  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         10 6
1 1 8 4
2 4 9 1
2 3 6 5
1 0 5 3
1 2 2 5
2 6 7 0
                                                                                                                                                                                                                                                                                                                                                                                                                                                                           wall-templates/sample-2.out                                                                         000644  000765  000024  00000000024 12352215546 016567  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         3
4
5
4
3
3
0
0
1
0
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            wall-templates/wall.c                                                                               000644  000765  000024  00000000210 12357203222 015507  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         #include "wall.h"

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  return;
}

                                                                                                                                                                                                                                                                                                                                                                                        wall-templates/wall.cpp                                                                             000644  000765  000024  00000000210 12357203214 016050  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         #include "wall.h"

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  return;
}

                                                                                                                                                                                                                                                                                                                                                                                        wall-templates/wall.h                                                                               000644  000765  000024  00000000213 12357203206 015521  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         #ifndef _WALL_H
#define _WALL_H

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]);

#endif
                                                                                                                                                                                                                                                                                                                                                                                     wall-templates/wall.pas                                                                             000644  000765  000024  00000000451 12357203200 016053  0                                                                                                    ustar 00cclljj                          staff                           000000  000000                                                                                                                                                                         unit wall;

interface

procedure buildWall(n, k : longint; op, left, right, height: array of longint; var finalHeight : array of longint);

implementation
   procedure buildWall(n, k : longint; op, left, right, height: array of longint; var finalHeight : array of longint);
   begin

   end;
end.
