#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "/home/joel/Documentos/automata/widgets.h"

char *file_path = NULL;
FILE *file = NULL;
int State = 0;
int current_char = 32;
const char* Reservadas[] = {"if", "else", "switch", "case", "default", "for", "while","break", "int", "String", "double", "char", "print" };
const char* relacionales[] = {"<","<=",">",">=","==","!="};
const char* logicos[]={"&&","||","!"};
char currentWord[50] = "";
int currentWordIndex = 0;
int t_table [13][170];  //ñ=165
int counters[13]; //falta setearlos a 0
int reservadas =0;
int errors=0;


void inicializarTransiciones(){
t_table[0][10]=0;	t_table[0][9]=0;	t_table[0][32]=0;	t_table[0][97]=1;	t_table[0][98]=1;	t_table[0][99]=1;	t_table[0][100]=1;	t_table[0][101]=1;	t_table[0][102]=1;	t_table[0][103]=1;	t_table[0][104]=1;	t_table[0][105]=1;	t_table[0][106]=1;	t_table[0][107]=1;	t_table[0][108]=1;	t_table[0][109]=1;	t_table[0][110]=1;	t_table[0][164]=1;	t_table[0][111]=1;	t_table[0][112]=1;	t_table[0][113]=1;	t_table[0][114]=1;	t_table[0][115]=1;	t_table[0][116]=1;	t_table[0][117]=1;	t_table[0][118]=1;	t_table[0][119]=1;	t_table[0][120]=1;	t_table[0][121]=1;	t_table[0][122]=1;	t_table[0][65]=1;	t_table[0][66]=1;	t_table[0][67]=1;	t_table[0][68]=1;	t_table[0][69]=1;	t_table[0][70]=1;	t_table[0][71]=1;	t_table[0][72]=1;	t_table[0][73]=1;	t_table[0][74]=1;	t_table[0][75]=1;	t_table[0][76]=1;	t_table[0][77]=1;	t_table[0][78]=1;	t_table[0][165]=1;	t_table[0][79]=1;	t_table[0][80]=1;	t_table[0][81]=1;	t_table[0][82]=1;	t_table[0][83]=1;	t_table[0][84]=1;	t_table[0][85]=1;	t_table[0][86]=1;	t_table[0][87]=1;	t_table[0][88]=1;	t_table[0][89]=1;	t_table[0][90]=1;	t_table[0][95]=1;	t_table[0][60]=9;	t_table[0][62]=9;	t_table[0][61]=3;	t_table[0][33]=10;	t_table[0][38]=10;	t_table[0][124]=10;	t_table[0][43]=2;	t_table[0][45]=2;	t_table[0][42]=2;	t_table[0][47]=2;	t_table[0][37]=2;	t_table[0][46]=5;	t_table[0][49]=4;	t_table[0][50]=4;	t_table[0][51]=4;	t_table[0][52]=4;	t_table[0][53]=4;	t_table[0][54]=4;	t_table[0][55]=4;	t_table[0][56]=4;	t_table[0][57]=4;	t_table[0][48]=4;	t_table[0][34]=6;	t_table[0][40]=7;	t_table[0][41]=7;	t_table[0][123]=8;	t_table[0][125]=8;
t_table[1][10]=0;	t_table[1][9]=0;	t_table[1][32]=0;	t_table[1][97]=1;	t_table[1][98]=1;	t_table[1][99]=1;	t_table[1][100]=1;	t_table[1][101]=1;	t_table[1][102]=1;	t_table[1][103]=1;	t_table[1][104]=1;	t_table[1][105]=1;	t_table[1][106]=1;	t_table[1][107]=1;	t_table[1][108]=1;	t_table[1][109]=1;	t_table[1][110]=1;	t_table[1][164]=1;	t_table[1][111]=1;	t_table[1][112]=1;	t_table[1][113]=1;	t_table[1][114]=1;	t_table[1][115]=1;	t_table[1][116]=1;	t_table[1][117]=1;	t_table[1][118]=1;	t_table[1][119]=1;	t_table[1][120]=1;	t_table[1][121]=1;	t_table[1][122]=1;	t_table[1][65]=1;	t_table[1][66]=1;	t_table[1][67]=1;	t_table[1][68]=1;	t_table[1][69]=1;	t_table[1][70]=1;	t_table[1][71]=1;	t_table[1][72]=1;	t_table[1][73]=1;	t_table[1][74]=1;	t_table[1][75]=1;	t_table[1][76]=1;	t_table[1][77]=1;	t_table[1][78]=1;	t_table[1][165]=1;	t_table[1][79]=1;	t_table[1][80]=1;	t_table[1][81]=1;	t_table[1][82]=1;	t_table[1][83]=1;	t_table[1][84]=1;	t_table[1][85]=1;	t_table[1][86]=1;	t_table[1][87]=1;	t_table[1][88]=1;	t_table[1][89]=1;	t_table[1][90]=1;	t_table[1][95]=1;	t_table[1][60]=100;	t_table[1][62]=100;	t_table[1][61]=100;	t_table[1][33]=100;	t_table[1][38]=100;	t_table[1][124]=100;	t_table[1][43]=100;	t_table[1][45]=100;	t_table[1][42]=100;	t_table[1][47]=100;	t_table[1][37]=100;	t_table[1][46]=100;	t_table[1][49]=100;	t_table[1][50]=100;	t_table[1][51]=100;	t_table[1][52]=100;	t_table[1][53]=100;	t_table[1][54]=100;	t_table[1][55]=100;	t_table[1][56]=100;	t_table[1][57]=100;	t_table[1][48]=100;	t_table[1][34]=100;	t_table[1][40]=100;	t_table[1][41]=100;	t_table[1][123]=100;	t_table[1][125]=100;
t_table[2][10]=0;	t_table[2][9]=0;	t_table[2][32]=0;	t_table[2][97]=100;	t_table[2][98]=100;	t_table[2][99]=100;	t_table[2][100]=100;	t_table[2][101]=100;	t_table[2][102]=100;	t_table[2][103]=100;	t_table[2][104]=100;	t_table[2][105]=100;	t_table[2][106]=100;	t_table[2][107]=100;	t_table[2][108]=100;	t_table[2][109]=100;	t_table[2][110]=100;	t_table[2][164]=100;	t_table[2][111]=100;	t_table[2][112]=100;	t_table[2][113]=100;	t_table[2][114]=100;	t_table[2][115]=100;	t_table[2][116]=100;	t_table[2][117]=100;	t_table[2][118]=100;	t_table[2][119]=100;	t_table[2][120]=100;	t_table[2][121]=100;	t_table[2][122]=100;	t_table[2][65]=100;	t_table[2][66]=100;	t_table[2][67]=100;	t_table[2][68]=100;	t_table[2][69]=100;	t_table[2][70]=100;	t_table[2][71]=100;	t_table[2][72]=100;	t_table[2][73]=100;	t_table[2][74]=100;	t_table[2][75]=100;	t_table[2][76]=100;	t_table[2][77]=100;	t_table[2][78]=100;	t_table[2][165]=100;	t_table[2][79]=100;	t_table[2][80]=100;	t_table[2][81]=100;	t_table[2][82]=100;	t_table[2][83]=100;	t_table[2][84]=100;	t_table[2][85]=100;	t_table[2][86]=100;	t_table[2][87]=100;	t_table[2][88]=100;	t_table[2][89]=100;	t_table[2][90]=100;	t_table[2][95]=100;	t_table[2][60]=100;	t_table[2][62]=100;	t_table[2][61]=100;	t_table[2][33]=100;	t_table[2][38]=100;	t_table[2][124]=100;	t_table[2][43]=100;	t_table[2][45]=100;	t_table[2][42]=100;	t_table[2][47]=100;	t_table[2][37]=100;	t_table[2][46]=100;	t_table[2][49]=100;	t_table[2][50]=100;	t_table[2][51]=100;	t_table[2][52]=100;	t_table[2][53]=100;	t_table[2][54]=100;	t_table[2][55]=100;	t_table[2][56]=100;	t_table[2][57]=100;	t_table[2][48]=100;	t_table[2][34]=100;	t_table[2][40]=100;	t_table[2][41]=100;	t_table[2][123]=100;	t_table[2][125]=100;
t_table[3][10]=0;	t_table[3][9]=0;	t_table[3][32]=0;	t_table[3][97]=100;	t_table[3][98]=100;	t_table[3][99]=100;	t_table[3][100]=100;	t_table[3][101]=100;	t_table[3][102]=100;	t_table[3][103]=100;	t_table[3][104]=100;	t_table[3][105]=100;	t_table[3][106]=100;	t_table[3][107]=100;	t_table[3][108]=100;	t_table[3][109]=100;	t_table[3][110]=100;	t_table[3][164]=100;	t_table[3][111]=100;	t_table[3][112]=100;	t_table[3][113]=100;	t_table[3][114]=100;	t_table[3][115]=100;	t_table[3][116]=100;	t_table[3][117]=100;	t_table[3][118]=100;	t_table[3][119]=100;	t_table[3][120]=100;	t_table[3][121]=100;	t_table[3][122]=100;	t_table[3][65]=100;	t_table[3][66]=100;	t_table[3][67]=100;	t_table[3][68]=100;	t_table[3][69]=100;	t_table[3][70]=100;	t_table[3][71]=100;	t_table[3][72]=100;	t_table[3][73]=100;	t_table[3][74]=100;	t_table[3][75]=100;	t_table[3][76]=100;	t_table[3][77]=100;	t_table[3][78]=100;	t_table[3][165]=100;	t_table[3][79]=100;	t_table[3][80]=100;	t_table[3][81]=100;	t_table[3][82]=100;	t_table[3][83]=100;	t_table[3][84]=100;	t_table[3][85]=100;	t_table[3][86]=100;	t_table[3][87]=100;	t_table[3][88]=100;	t_table[3][89]=100;	t_table[3][90]=100;	t_table[3][95]=100;	t_table[3][60]=100;	t_table[3][62]=100;	t_table[3][61]=9;	t_table[3][33]=100;	t_table[3][38]=100;	t_table[3][124]=100;	t_table[3][43]=100;	t_table[3][45]=100;	t_table[3][42]=100;	t_table[3][47]=100;	t_table[3][37]=100;	t_table[3][46]=100;	t_table[3][49]=100;	t_table[3][50]=100;	t_table[3][51]=100;	t_table[3][52]=100;	t_table[3][53]=100;	t_table[3][54]=100;	t_table[3][55]=100;	t_table[3][56]=100;	t_table[3][57]=100;	t_table[3][48]=100;	t_table[3][34]=100;	t_table[3][40]=100;	t_table[3][41]=100;	t_table[3][123]=100;	t_table[3][125]=100;
t_table[4][10]=0;	t_table[4][9]=0;	t_table[4][32]=0;	t_table[4][97]=100;	t_table[4][98]=100;	t_table[4][99]=100;	t_table[4][100]=100;	t_table[4][101]=100;	t_table[4][102]=100;	t_table[4][103]=100;	t_table[4][104]=100;	t_table[4][105]=100;	t_table[4][106]=100;	t_table[4][107]=100;	t_table[4][108]=100;	t_table[4][109]=100;	t_table[4][110]=100;	t_table[4][164]=100;	t_table[4][111]=100;	t_table[4][112]=100;	t_table[4][113]=100;	t_table[4][114]=100;	t_table[4][115]=100;	t_table[4][116]=100;	t_table[4][117]=100;	t_table[4][118]=100;	t_table[4][119]=100;	t_table[4][120]=100;	t_table[4][121]=100;	t_table[4][122]=100;	t_table[4][65]=100;	t_table[4][66]=100;	t_table[4][67]=100;	t_table[4][68]=100;	t_table[4][69]=100;	t_table[4][70]=100;	t_table[4][71]=100;	t_table[4][72]=100;	t_table[4][73]=100;	t_table[4][74]=100;	t_table[4][75]=100;	t_table[4][76]=100;	t_table[4][77]=100;	t_table[4][78]=100;	t_table[4][165]=100;	t_table[4][79]=100;	t_table[4][80]=100;	t_table[4][81]=100;	t_table[4][82]=100;	t_table[4][83]=100;	t_table[4][84]=100;	t_table[4][85]=100;	t_table[4][86]=100;	t_table[4][87]=100;	t_table[4][88]=100;	t_table[4][89]=100;	t_table[4][90]=100;	t_table[4][95]=100;	t_table[4][60]=100;	t_table[4][62]=100;	t_table[4][61]=100;	t_table[4][33]=100;	t_table[4][38]=100;	t_table[4][124]=100;	t_table[4][43]=100;	t_table[4][45]=100;	t_table[4][42]=100;	t_table[4][47]=100;	t_table[4][37]=100;	t_table[4][46]=5;	t_table[4][49]=4;	t_table[4][50]=4;	t_table[4][51]=4;	t_table[4][52]=4;	t_table[4][53]=4;	t_table[4][54]=4;	t_table[4][55]=4;	t_table[4][56]=4;	t_table[4][57]=4;	t_table[4][48]=4;	t_table[4][34]=100;	t_table[4][40]=100;	t_table[4][41]=100;	t_table[4][123]=100;	t_table[4][125]=100;
t_table[5][10]=0;	t_table[5][9]=0;	t_table[5][32]=0;	t_table[5][97]=100;	t_table[5][98]=100;	t_table[5][99]=100;	t_table[5][100]=100;	t_table[5][101]=100;	t_table[5][102]=100;	t_table[5][103]=100;	t_table[5][104]=100;	t_table[5][105]=100;	t_table[5][106]=100;	t_table[5][107]=100;	t_table[5][108]=100;	t_table[5][109]=100;	t_table[5][110]=100;	t_table[5][164]=100;	t_table[5][111]=100;	t_table[5][112]=100;	t_table[5][113]=100;	t_table[5][114]=100;	t_table[5][115]=100;	t_table[5][116]=100;	t_table[5][117]=100;	t_table[5][118]=100;	t_table[5][119]=100;	t_table[5][120]=100;	t_table[5][121]=100;	t_table[5][122]=100;	t_table[5][65]=100;	t_table[5][66]=100;	t_table[5][67]=100;	t_table[5][68]=100;	t_table[5][69]=100;	t_table[5][70]=100;	t_table[5][71]=100;	t_table[5][72]=100;	t_table[5][73]=100;	t_table[5][74]=100;	t_table[5][75]=100;	t_table[5][76]=100;	t_table[5][77]=100;	t_table[5][78]=100;	t_table[5][165]=100;	t_table[5][79]=100;	t_table[5][80]=100;	t_table[5][81]=100;	t_table[5][82]=100;	t_table[5][83]=100;	t_table[5][84]=100;	t_table[5][85]=100;	t_table[5][86]=100;	t_table[5][87]=100;	t_table[5][88]=100;	t_table[5][89]=100;	t_table[5][90]=100;	t_table[5][95]=100;	t_table[5][60]=100;	t_table[5][62]=100;	t_table[5][61]=100;	t_table[5][33]=100;	t_table[5][38]=100;	t_table[5][124]=100;	t_table[5][43]=100;	t_table[5][45]=100;	t_table[5][42]=100;	t_table[5][47]=100;	t_table[5][37]=100;	t_table[5][46]=100;	t_table[5][49]=5;	t_table[5][50]=5;	t_table[5][51]=5;	t_table[5][52]=5;	t_table[5][53]=5;	t_table[5][54]=5;	t_table[5][55]=5;	t_table[5][56]=5;	t_table[5][57]=5;	t_table[5][48]=5;	t_table[5][34]=100;	t_table[5][40]=100;	t_table[5][41]=100;	t_table[5][123]=100;	t_table[5][125]=100;
t_table[6][10]=100;	t_table[6][9]=6;	t_table[6][32]=6;	t_table[6][97]=6;	t_table[6][98]=6;	t_table[6][99]=6;	t_table[6][100]=6;	t_table[6][101]=6;	t_table[6][102]=6;	t_table[6][103]=6;	t_table[6][104]=6;	t_table[6][105]=6;	t_table[6][106]=6;	t_table[6][107]=6;	t_table[6][108]=6;	t_table[6][109]=6;	t_table[6][110]=6;	t_table[6][164]=6;	t_table[6][111]=6;	t_table[6][112]=6;	t_table[6][113]=6;	t_table[6][114]=6;	t_table[6][115]=6;	t_table[6][116]=6;	t_table[6][117]=6;	t_table[6][118]=6;	t_table[6][119]=6;	t_table[6][120]=6;	t_table[6][121]=6;	t_table[6][122]=6;	t_table[6][65]=6;	t_table[6][66]=6;	t_table[6][67]=6;	t_table[6][68]=6;	t_table[6][69]=6;	t_table[6][70]=6;	t_table[6][71]=6;	t_table[6][72]=6;	t_table[6][73]=6;	t_table[6][74]=6;	t_table[6][75]=6;	t_table[6][76]=6;	t_table[6][77]=6;	t_table[6][78]=6;	t_table[6][165]=6;	t_table[6][79]=6;	t_table[6][80]=6;	t_table[6][81]=6;	t_table[6][82]=6;	t_table[6][83]=6;	t_table[6][84]=6;	t_table[6][85]=6;	t_table[6][86]=6;	t_table[6][87]=6;	t_table[6][88]=6;	t_table[6][89]=6;	t_table[6][90]=6;	t_table[6][95]=6;	t_table[6][60]=6;	t_table[6][62]=6;	t_table[6][61]=6;	t_table[6][33]=6;	t_table[6][38]=6;	t_table[6][124]=6;	t_table[6][43]=6;	t_table[6][45]=6;	t_table[6][42]=6;	t_table[6][47]=6;	t_table[6][37]=6;	t_table[6][46]=6;	t_table[6][49]=6;	t_table[6][50]=6;	t_table[6][51]=6;	t_table[6][52]=6;	t_table[6][53]=6;	t_table[6][54]=6;	t_table[6][55]=6;	t_table[6][56]=6;	t_table[6][57]=6;	t_table[6][48]=6;	t_table[6][34]=0;	t_table[6][40]=6;	t_table[6][41]=6;	t_table[6][123]=6;	t_table[6][125]=6;
t_table[7][10]=0;	t_table[7][9]=0;	t_table[7][32]=0;	t_table[7][97]=100;	t_table[7][98]=100;	t_table[7][99]=100;	t_table[7][100]=100;	t_table[7][101]=100;	t_table[7][102]=100;	t_table[7][103]=100;	t_table[7][104]=100;	t_table[7][105]=100;	t_table[7][106]=100;	t_table[7][107]=100;	t_table[7][108]=100;	t_table[7][109]=100;	t_table[7][110]=100;	t_table[7][164]=100;	t_table[7][111]=100;	t_table[7][112]=100;	t_table[7][113]=100;	t_table[7][114]=100;	t_table[7][115]=100;	t_table[7][116]=100;	t_table[7][117]=100;	t_table[7][118]=100;	t_table[7][119]=100;	t_table[7][120]=100;	t_table[7][121]=100;	t_table[7][122]=100;	t_table[7][65]=100;	t_table[7][66]=100;	t_table[7][67]=100;	t_table[7][68]=100;	t_table[7][69]=100;	t_table[7][70]=100;	t_table[7][71]=100;	t_table[7][72]=100;	t_table[7][73]=100;	t_table[7][74]=100;	t_table[7][75]=100;	t_table[7][76]=100;	t_table[7][77]=100;	t_table[7][78]=100;	t_table[7][165]=100;	t_table[7][79]=100;	t_table[7][80]=100;	t_table[7][81]=100;	t_table[7][82]=100;	t_table[7][83]=100;	t_table[7][84]=100;	t_table[7][85]=100;	t_table[7][86]=100;	t_table[7][87]=100;	t_table[7][88]=100;	t_table[7][89]=100;	t_table[7][90]=100;	t_table[7][95]=100;	t_table[7][60]=100;	t_table[7][62]=100;	t_table[7][61]=100;	t_table[7][33]=100;	t_table[7][38]=100;	t_table[7][124]=100;	t_table[7][43]=100;	t_table[7][45]=100;	t_table[7][42]=100;	t_table[7][47]=100;	t_table[7][37]=100;	t_table[7][46]=100;	t_table[7][49]=100;	t_table[7][50]=100;	t_table[7][51]=100;	t_table[7][52]=100;	t_table[7][53]=100;	t_table[7][54]=100;	t_table[7][55]=100;	t_table[7][56]=100;	t_table[7][57]=100;	t_table[7][48]=100;	t_table[7][34]=100;	t_table[7][40]=100;	t_table[7][41]=100;	t_table[7][123]=100;	t_table[7][125]=100;
t_table[8][10]=0;	t_table[8][9]=0;	t_table[8][32]=0;	t_table[8][97]=100;	t_table[8][98]=100;	t_table[8][99]=100;	t_table[8][100]=100;	t_table[8][101]=100;	t_table[8][102]=100;	t_table[8][103]=100;	t_table[8][104]=100;	t_table[8][105]=100;	t_table[8][106]=100;	t_table[8][107]=100;	t_table[8][108]=100;	t_table[8][109]=100;	t_table[8][110]=100;	t_table[8][164]=100;	t_table[8][111]=100;	t_table[8][112]=100;	t_table[8][113]=100;	t_table[8][114]=100;	t_table[8][115]=100;	t_table[8][116]=100;	t_table[8][117]=100;	t_table[8][118]=100;	t_table[8][119]=100;	t_table[8][120]=100;	t_table[8][121]=100;	t_table[8][122]=100;	t_table[8][65]=100;	t_table[8][66]=100;	t_table[8][67]=100;	t_table[8][68]=100;	t_table[8][69]=100;	t_table[8][70]=100;	t_table[8][71]=100;	t_table[8][72]=100;	t_table[8][73]=100;	t_table[8][74]=100;	t_table[8][75]=100;	t_table[8][76]=100;	t_table[8][77]=100;	t_table[8][78]=100;	t_table[8][165]=100;	t_table[8][79]=100;	t_table[8][80]=100;	t_table[8][81]=100;	t_table[8][82]=100;	t_table[8][83]=100;	t_table[8][84]=100;	t_table[8][85]=100;	t_table[8][86]=100;	t_table[8][87]=100;	t_table[8][88]=100;	t_table[8][89]=100;	t_table[8][90]=100;	t_table[8][95]=100;	t_table[8][60]=100;	t_table[8][62]=100;	t_table[8][61]=100;	t_table[8][33]=100;	t_table[8][38]=100;	t_table[8][124]=100;	t_table[8][43]=100;	t_table[8][45]=100;	t_table[8][42]=100;	t_table[8][47]=100;	t_table[8][37]=100;	t_table[8][46]=100;	t_table[8][49]=100;	t_table[8][50]=100;	t_table[8][51]=100;	t_table[8][52]=100;	t_table[8][53]=100;	t_table[8][54]=100;	t_table[8][55]=100;	t_table[8][56]=100;	t_table[8][57]=100;	t_table[8][48]=100;	t_table[8][34]=100;	t_table[8][40]=100;	t_table[8][41]=100;	t_table[8][123]=100;	t_table[8][125]=100;
t_table[9][10]=0;	t_table[9][9]=0;	t_table[9][32]=0;	t_table[9][97]=100;	t_table[9][98]=100;	t_table[9][99]=100;	t_table[9][100]=100;	t_table[9][101]=100;	t_table[9][102]=100;	t_table[9][103]=100;	t_table[9][104]=100;	t_table[9][105]=100;	t_table[9][106]=100;	t_table[9][107]=100;	t_table[9][108]=100;	t_table[9][109]=100;	t_table[9][110]=100;	t_table[9][164]=100;	t_table[9][111]=100;	t_table[9][112]=100;	t_table[9][113]=100;	t_table[9][114]=100;	t_table[9][115]=100;	t_table[9][116]=100;	t_table[9][117]=100;	t_table[9][118]=100;	t_table[9][119]=100;	t_table[9][120]=100;	t_table[9][121]=100;	t_table[9][122]=100;	t_table[9][65]=100;	t_table[9][66]=100;	t_table[9][67]=100;	t_table[9][68]=100;	t_table[9][69]=100;	t_table[9][70]=100;	t_table[9][71]=100;	t_table[9][72]=100;	t_table[9][73]=100;	t_table[9][74]=100;	t_table[9][75]=100;	t_table[9][76]=100;	t_table[9][77]=100;	t_table[9][78]=100;	t_table[9][165]=100;	t_table[9][79]=100;	t_table[9][80]=100;	t_table[9][81]=100;	t_table[9][82]=100;	t_table[9][83]=100;	t_table[9][84]=100;	t_table[9][85]=100;	t_table[9][86]=100;	t_table[9][87]=100;	t_table[9][88]=100;	t_table[9][89]=100;	t_table[9][90]=100;	t_table[9][95]=100;	t_table[9][60]=100;	t_table[9][62]=100;	t_table[9][61]=9;	t_table[9][33]=100;	t_table[9][38]=100;	t_table[9][124]=100;	t_table[9][43]=100;	t_table[9][45]=100;	t_table[9][42]=100;	t_table[9][47]=100;	t_table[9][37]=100;	t_table[9][46]=100;	t_table[9][49]=100;	t_table[9][50]=100;	t_table[9][51]=100;	t_table[9][52]=100;	t_table[9][53]=100;	t_table[9][54]=100;	t_table[9][55]=100;	t_table[9][56]=100;	t_table[9][57]=100;	t_table[9][48]=100;	t_table[9][34]=100;	t_table[9][40]=100;	t_table[9][41]=100;	t_table[9][123]=100;	t_table[9][125]=100;
t_table[10][10]=0;	t_table[10][9]=0;	t_table[10][32]=0;	t_table[10][97]=100;	t_table[10][98]=100;	t_table[10][99]=100;	t_table[10][100]=100;	t_table[10][101]=100;	t_table[10][102]=100;	t_table[10][103]=100;	t_table[10][104]=100;	t_table[10][105]=100;	t_table[10][106]=100;	t_table[10][107]=100;	t_table[10][108]=100;	t_table[10][109]=100;	t_table[10][110]=100;	t_table[10][164]=100;	t_table[10][111]=100;	t_table[10][112]=100;	t_table[10][113]=100;	t_table[10][114]=100;	t_table[10][115]=100;	t_table[10][116]=100;	t_table[10][117]=100;	t_table[10][118]=100;	t_table[10][119]=100;	t_table[10][120]=100;	t_table[10][121]=100;	t_table[10][122]=100;	t_table[10][65]=100;	t_table[10][66]=100;	t_table[10][67]=100;	t_table[10][68]=100;	t_table[10][69]=100;	t_table[10][70]=100;	t_table[10][71]=100;	t_table[10][72]=100;	t_table[10][73]=100;	t_table[10][74]=100;	t_table[10][75]=100;	t_table[10][76]=100;	t_table[10][77]=100;	t_table[10][78]=100;	t_table[10][165]=100;	t_table[10][79]=100;	t_table[10][80]=100;	t_table[10][81]=100;	t_table[10][82]=100;	t_table[10][83]=100;	t_table[10][84]=100;	t_table[10][85]=100;	t_table[10][86]=100;	t_table[10][87]=100;	t_table[10][88]=100;	t_table[10][89]=100;	t_table[10][90]=100;	t_table[10][95]=100;	t_table[10][60]=100;	t_table[10][62]=100;	t_table[10][61]=9;	t_table[10][33]=100;	t_table[10][38]=10;	t_table[10][124]=10;	t_table[10][43]=100;	t_table[10][45]=100;	t_table[10][42]=100;	t_table[10][47]=100;	t_table[10][37]=100;	t_table[10][46]=100;	t_table[10][49]=100;	t_table[10][50]=100;	t_table[10][51]=100;	t_table[10][52]=100;	t_table[10][53]=100;	t_table[10][54]=100;	t_table[10][55]=100;	t_table[10][56]=100;	t_table[10][57]=100;	t_table[10][48]=100;	t_table[10][34]=100;	t_table[10][40]=100;	t_table[10][41]=100;	t_table[10][123]=100;	t_table[10][125]=100;
t_table[11][10]=11;	t_table[11][9]=11;	t_table[11][32]=11;	t_table[11][97]=11;	t_table[11][98]=11;	t_table[11][99]=11;	t_table[11][100]=11;	t_table[11][101]=11;	t_table[11][102]=11;	t_table[11][103]=11;	t_table[11][104]=11;	t_table[11][105]=11;	t_table[11][106]=11;	t_table[11][107]=11;	t_table[11][108]=11;	t_table[11][109]=11;	t_table[11][110]=11;	t_table[11][164]=11;	t_table[11][111]=11;	t_table[11][112]=11;	t_table[11][113]=11;	t_table[11][114]=11;	t_table[11][115]=11;	t_table[11][116]=11;	t_table[11][117]=11;	t_table[11][118]=11;	t_table[11][119]=11;	t_table[11][120]=11;	t_table[11][121]=11;	t_table[11][122]=11;	t_table[11][65]=11;	t_table[11][66]=11;	t_table[11][67]=11;	t_table[11][68]=11;	t_table[11][69]=11;	t_table[11][70]=11;	t_table[11][71]=11;	t_table[11][72]=11;	t_table[11][73]=11;	t_table[11][74]=11;	t_table[11][75]=11;	t_table[11][76]=11;	t_table[11][77]=11;	t_table[11][78]=11;	t_table[11][165]=11;	t_table[11][79]=11;	t_table[11][80]=11;	t_table[11][81]=11;	t_table[11][82]=11;	t_table[11][83]=11;	t_table[11][84]=11;	t_table[11][85]=11;	t_table[11][86]=11;	t_table[11][87]=11;	t_table[11][88]=11;	t_table[11][89]=11;	t_table[11][90]=11;	t_table[11][95]=11;	t_table[11][60]=11;	t_table[11][62]=11;	t_table[11][61]=11;	t_table[11][33]=11;	t_table[11][38]=11;	t_table[11][124]=11;	t_table[11][43]=11;	t_table[11][45]=11;	t_table[11][42]=11;	t_table[11][47]=11;	t_table[11][37]=11;	t_table[11][46]=11;	t_table[11][49]=11;	t_table[11][50]=11;	t_table[11][51]=11;	t_table[11][52]=11;	t_table[11][53]=11;	t_table[11][54]=11;	t_table[11][55]=11;	t_table[11][56]=11;	t_table[11][57]=11;	t_table[11][48]=11;	t_table[11][34]=11;	t_table[11][40]=11;	t_table[11][41]=11;	t_table[11][123]=11;	t_table[11][125]=11;
t_table[12][10]=0;	t_table[12][9]=12;	t_table[12][32]=12;	t_table[12][97]=12;	t_table[12][98]=12;	t_table[12][99]=12;	t_table[12][100]=12;	t_table[12][101]=12;	t_table[12][102]=12;	t_table[12][103]=12;	t_table[12][104]=12;	t_table[12][105]=12;	t_table[12][106]=12;	t_table[12][107]=12;	t_table[12][108]=12;	t_table[12][109]=12;	t_table[12][110]=12;	t_table[12][164]=12;	t_table[12][111]=12;	t_table[12][112]=12;	t_table[12][113]=12;	t_table[12][114]=12;	t_table[12][115]=12;	t_table[12][116]=12;	t_table[12][117]=12;	t_table[12][118]=12;	t_table[12][119]=12;	t_table[12][120]=12;	t_table[12][121]=12;	t_table[12][122]=12;	t_table[12][65]=12;	t_table[12][66]=12;	t_table[12][67]=12;	t_table[12][68]=12;	t_table[12][69]=12;	t_table[12][70]=12;	t_table[12][71]=12;	t_table[12][72]=12;	t_table[12][73]=12;	t_table[12][74]=12;	t_table[12][75]=12;	t_table[12][76]=12;	t_table[12][77]=12;	t_table[12][78]=12;	t_table[12][165]=12;	t_table[12][79]=12;	t_table[12][80]=12;	t_table[12][81]=12;	t_table[12][82]=12;	t_table[12][83]=12;	t_table[12][84]=12;	t_table[12][85]=12;	t_table[12][86]=12;	t_table[12][87]=12;	t_table[12][88]=12;	t_table[12][89]=12;	t_table[12][90]=12;	t_table[12][95]=12;	t_table[12][60]=12;	t_table[12][62]=12;	t_table[12][61]=12;	t_table[12][33]=12;	t_table[12][38]=12;	t_table[12][124]=12;	t_table[12][43]=12;	t_table[12][45]=12;	t_table[12][42]=12;	t_table[12][47]=12;	t_table[12][37]=12;	t_table[12][46]=12;	t_table[12][49]=12;	t_table[12][50]=12;	t_table[12][51]=12;	t_table[12][52]=12;	t_table[12][53]=12;	t_table[12][54]=12;	t_table[12][55]=12;	t_table[12][56]=12;	t_table[12][57]=12;	t_table[12][48]=12;	t_table[12][34]=12;	t_table[12][40]=12;	t_table[12][41]=12;	t_table[12][123]=12;	t_table[12][125]=12;
}

void clear_current_word(){
	memset(currentWord,0,50); //limpiar la palabra
	currentWordIndex=0;
}
int wordIsReserv(){
	g_print("\nCadena: |%s|\n", currentWord);
		g_print("\nFinalIndex: |%d|\n", currentWordIndex);

	for(int i=0; i<13; i++){
		if(strncmp(currentWord, Reservadas[i],strlen(currentWord)-1)==0){
			return 1;
		}
	}
	return 0;
}
int wordIsRelacio(){
	g_print("\n(%s)\n",currentWord);
	
	for(int i=0; i<6; i++){
		if(strncmp(currentWord, relacionales[i], strlen(currentWord)-1)==0){
			return 1;
		}
	}
	return 0;
}
int wordIsLogic(){
	for(int i=0; i<3; i++){
		if(strncmp(currentWord, logicos[i],strlen(currentWord)-1)==0 && strlen(currentWord)-1==strlen(logicos[i])){
			return 1;
		}
	}
	return 0;
}
void terminaPalabra(){
	
	while(current_char!= -1 && current_char!=10 && current_char!=9 && current_char!=32){
		current_char = fgetc(file);
	}
}




void file_selected(GtkFileChooserButton *chooser, gpointer user_data){
	file_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_v1));
	file = fopen(file_path, "r");
	if(file_path != NULL){
		g_print("\nArchivo abierto %s\n",file_path);
		gtk_widget_set_sensitive(button_v1,TRUE);
	}else{
		gtk_widget_set_sensitive(button_v1,FALSE);
	}
	
	
	
}

void set_labels(){
	char matriz[14][10];
	for(int i=0;i<14; i++){
		if(i==0){
			sprintf(matriz[i],"%d",reservadas);
			gtk_label_set_text(GTK_LABEL(lb_v0),matriz[i]);

		}else if(i == 13){
			sprintf(matriz[i],"%d", errors);
			gtk_label_set_text(GTK_LABEL(lb_v13),matriz[i]);
		}else{
			sprintf(matriz[i],"%d",counters[i]);
		}
	}
	
	gtk_label_set_text(GTK_LABEL(lb_v1),matriz[1]);
	gtk_label_set_text(GTK_LABEL(lb_v2),matriz[9]);
	gtk_label_set_text(GTK_LABEL(lb_v3),matriz[10]);
	gtk_label_set_text(GTK_LABEL(lb_v4),matriz[2]);
	gtk_label_set_text(GTK_LABEL(lb_v5),matriz[3]);
	gtk_label_set_text(GTK_LABEL(lb_v6),matriz[4]);
	gtk_label_set_text(GTK_LABEL(lb_v7),matriz[5]);
	gtk_label_set_text(GTK_LABEL(lb_v8),matriz[6]);
	gtk_label_set_text(GTK_LABEL(lb_v9),matriz[11]);
	gtk_label_set_text(GTK_LABEL(lb_v10),matriz[12]);
	gtk_label_set_text(GTK_LABEL(lb_v11),matriz[7]);
	gtk_label_set_text(GTK_LABEL(lb_v12),matriz[8]);
	
	for(int i=0; i<13; i++){
		counters[i]=0;
	}
	reservadas=0;
	errors=0;


}

int transicion(int caracter){
	if(State==6 && caracter == -1){
		return 100;
	}else if(feof(file)){
		return 0;
	}else{
		return t_table[State][caracter];

	}

}

void automata(int car){
		// Puedes seguir guardando la palabra
		//putchar(current_char);
		currentWord[currentWordIndex] = car;
		//g_print("%c",currentWord[currentWordIndex]);
		
		switch (State){
			case 0:
				if(transicion(car)==0){
					//limpia la palabra
					clear_current_word();
				}else{
					State = transicion(car);
					currentWordIndex++;
				}
				
				

				break;
				
			case 1:
				//Termino la palabra
				if(transicion(car) == 0){
					//Verifica si es reservada
					if(wordIsReserv()==1){
						//Incrementa el numero de reservadas
						reservadas++;
						State = transicion(car);
						
					}else{
						//Incrementa el counter del state
						counters[State]++;
						State = transicion(car);
					}
					clear_current_word();
					
							
					
				}else if(transicion(car)==100){
					//Terminó palabra, Incrementa el error counter y mueve al estado 0
					errors++;
					terminaPalabra();
					State=0;
					clear_current_word();		
				}else{
					//mantente escribiendo la palabra
					currentWordIndex++;
				}
				
				
				break;
			
			case 2:
				g_print("\n caracter=%c\n",currentWord[currentWordIndex]);
				//g_print("%c",currentWord[currentWordIndex]);
				if(currentWord[currentWordIndex]=='*'){
					printf("\nExcelente\n");
				}
				if(transicion(car) == 0){
					//Termina la palabra, Incrementa el counter del state, cambia de estado, limpia la palabra y reset al Index
					counters[State]++;
					State = transicion(car);	
					clear_current_word();			
					
				}else if(transicion(car)==100){
					
					if(currentWord[currentWordIndex]=='/'){
						State = 12;
						currentWordIndex++;
					}else if(currentWord[currentWordIndex]=='*'){
						State = 11;
						currentWordIndex++;
					}else{
						//Termina la palabra y ve a estado 0
						errors++;
						terminaPalabra();
						clear_current_word();
						State=0;
						
					}
						
				}
				
			
				break;
			
			case 3:
				if(transicion(car) == 0){
					//Termino la palabra, Incrementa el counter del state, cambia de estado, limpia la palabra y reset al Index
					counters[State]++;
					State = transicion(car);	
					clear_current_word();			
					
				}else if(transicion(car)==100){
					//Termina la palabra
					errors++;
					terminaPalabra();
					State=0;
					clear_current_word();
						
				}else{
					State = transicion(car);
					currentWordIndex++;
				}
				
			
				break;
			
			case 4:
			
				if(transicion(car) == 0){
					//Termino la palabra, Incrementa el counter del state, cambia de estado, limpia la palabra y reset al Index
					counters[State]++;
					State = transicion(car);	
					clear_current_word();			
					
				}else if(transicion(car)==100){
					
					errors++;
					terminaPalabra();
					State=0;
					clear_current_word();
					
						
				}else{
					State = transicion(car);
					currentWordIndex++;
						
				
				}
				
				break;
			
			case 5:
				
				if(transicion(car) == 0){
					//Termina la palabra, Incrementa el counter del state, cambia de estado, limpia la palabra y reset al Index
					counters[State]++;
					State = transicion(car);	
					clear_current_word();			
					
				}else if(transicion(car)==100){
					
					errors++;
					terminaPalabra();
					State=0;
					clear_current_word();
				}else{
					State=transicion(car);
					currentWordIndex++;
				}
				break;
			
			case 6:
				if(transicion(car) == 0){
					//Termina la palabra, Incrementa el counter del state, cambia de estado, limpia la palabra y reset al Index
					counters[State]++;
					State = transicion(car);	
					clear_current_word();			
					
				}else if(transicion(car)==100){
					
					errors++;
					terminaPalabra();
					State=0;
					clear_current_word();
				}else{
					State=transicion(car);
					currentWordIndex++;
				}
				break;
			
			case 7:
				if(transicion(car) == 0){
					//Incrementa el counter del state, cambia de estado, limpia la palabra y reset al Index
					counters[State]++;
					State = transicion(car);	
					clear_current_word();			
					
				}else if(transicion(car)==100){
					
					errors++;
					terminaPalabra();
					State=0;
					clear_current_word();
						
				}
				break;
			
			case 8:
				if(transicion(car) == 0){
					//Incrementa el counter del state, cambia de estado, limpia la palabra y reset al Index
					counters[State]++;
					State = transicion(car);	
					clear_current_word();			
					
				}else if(transicion(car)==100){
					
					errors++;
					terminaPalabra();
					State=0;
					
						
				}
				break;
			
			case 9:
				if(transicion(car) == 0){
					//verifica que existe en las relacionales
					if(wordIsRelacio()==1){
						counters[State]++;
						State = transicion(car);
						clear_current_word();
					}else{
						//g_print("\n a ver: |%s| !=? |%s|\n", currentWord, relacionales[1]);
						errors++;
						terminaPalabra();
						clear_current_word();
						State=0;
					}
					
					
				}else if(transicion(car)==100){
					
					errors++;
					terminaPalabra();
					clear_current_word();
					State=0;
					
						
				}else{
					State = transicion(car);
					currentWordIndex++;
				}
			
				break;
			
			case 10:
				if(transicion(car) == 0){
					//verifica que existe en las relacionales
					if(wordIsLogic()==1){
						counters[State]++;
						State = transicion(car);
						clear_current_word();
					}else{
						errors++;
						terminaPalabra();
						State=0;
						clear_current_word();
					}
					
					
				}else if(transicion(car)==100){
					
					errors++;
					terminaPalabra();
					State=0;
					clear_current_word();
					
						
				}else if(car==61){
					State=9;
					currentWordIndex++;
				}else{
					State = transicion(car);
					currentWordIndex++;
				}
			
				break;
				
			case 11:
				g_print("\nCharsito=|%d| -> State = %d\n",car, transicion(car));
				if(transicion(car) == 0){
					//Termina palabra, verifica que existe en las relacionales
					counters[State]++;
					State = transicion(car);
					clear_current_word();
					
				}else if(car==47 && currentWord[currentWordIndex-1]=='*'){ 
					//'*'
					// Termina palabra, aumenta counter, limpia palabra y ve a estado 0
					counters[State]++;
					State = 0;
					clear_current_word();
					
				}else{
					
					State=transicion(car);
					currentWordIndex++;
				}
				
				break;
			
			case 12:
				//g_print("\nChar=|%d|\n",car);
				if(transicion(car) == 0){
					//g_print("\nnunca debimos llegar aqui con %d\n",car);
					//verifica que existe en las relacionales
					counters[State]++;
					State = transicion(car);
					clear_current_word();
					
				}
				/*else if(currentWord[currentWordIndex-1]=='/' && car == 42){
					State=11;
					currentWordIndex++;
				}*/else{
					State=transicion(car);
					currentWordIndex++;
				}
			
				break;
		}
		
		
	
}

void generate_report(GtkButton *button, gpointer user_data){
	current_char = fgetc(file);
	do{
		
		automata (current_char);
	}while((current_char = fgetc(file)) != -1);
		//finaliza lo que quede pendiente
		automata (current_char);
		
		
	fclose(file);
	file=NULL;
	g_print("\nInforme Generado ---------------\n");
	
	g_print("\n[0] = %d\n", reservadas);
	for(int i=1; i<13; i++){
		g_print("\n[%d] = %d\n",i, counters[i]);
	}
	g_print("\n[13] = %d\n", errors);
	
	set_labels();

}






void on_window_closed(GtkWidget* widget, gpointer data){
	gtk_main_quit();
}

void initializeWidgets(){
	
	
	builder = gtk_builder_new();
	
	buildError = NULL;
	if(!gtk_builder_add_from_file(builder, "/home/joel/Documentos/automata/vista.glade", &buildError)){
		g_printerr("Error loading glade file %s\n", buildError->message);
		g_error_free(buildError);
		return;
		
	}
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "vistaPrincipal"));
		g_signal_connect(window,"delete-event", G_CALLBACK(on_window_closed),NULL);
		
		box_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "box_v1"));
				label_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "label_v1"));
				
				file_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "filechooser_v1"));
					g_signal_connect(file_v1, "file_set", G_CALLBACK(file_selected),NULL);
				
				button_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_v1"));
					gtk_widget_set_sensitive(button_v1,FALSE);
					g_signal_connect(button_v1, "clicked", G_CALLBACK(generate_report),NULL);
					
				lb_v0 = GTK_WIDGET(gtk_builder_get_object(builder, "v0"));
				lb_v1 = GTK_WIDGET(gtk_builder_get_object(builder, "v1"));
				lb_v2 = GTK_WIDGET(gtk_builder_get_object(builder, "v2"));
				lb_v3 = GTK_WIDGET(gtk_builder_get_object(builder, "v3"));
				lb_v4 = GTK_WIDGET(gtk_builder_get_object(builder, "v4"));
				lb_v5 = GTK_WIDGET(gtk_builder_get_object(builder, "v5"));
				lb_v6 = GTK_WIDGET(gtk_builder_get_object(builder, "v6"));
				lb_v7 = GTK_WIDGET(gtk_builder_get_object(builder, "v7"));
				lb_v8 = GTK_WIDGET(gtk_builder_get_object(builder, "v8"));
				lb_v9 = GTK_WIDGET(gtk_builder_get_object(builder, "v9"));
				lb_v10 = GTK_WIDGET(gtk_builder_get_object(builder, "v10"));
				lb_v11 = GTK_WIDGET(gtk_builder_get_object(builder, "v11"));
				lb_v12 = GTK_WIDGET(gtk_builder_get_object(builder, "v12"));
				lb_v13 = GTK_WIDGET(gtk_builder_get_object(builder, "v13"));



				

	
}

int main(int argc, char* argv[]){
	
    printf("Hi from codelite\n");
	printf("hola");
	
	
	inicializarTransiciones();
	
	gtk_init(&argc, &argv);

	initializeWidgets();
	
	gtk_widget_show_all(window);
	
	gtk_main();
	
    return 0;
}
