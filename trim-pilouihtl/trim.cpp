/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			trim.cpp
 * Author:			P. Bauer
 * Due Date:		March 14, 2015
 * ----------------------------------------------------------
 * Description:
 * Test functions for trim.h
 * ----------------------------------------------------------
 */
#include "trim.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void 	trim (const char *source, char *trimmed_string){
  int countBlanksFor = 0;
  int i = 0;
  bool split = false;
  while(!split){
    if(source[i] == ' '){
      countBlanksFor++;
    }
    else{
      split = true;
    }
    if(i == strlen(source) - 1 || source == ""){
      split = true;
    }
    i++;
  }

  int countBlanksAfter = 0;
  split = false;
  i = strlen(source) - 1;
  while(!split){
    if(i < 0){
      split = true;
    }
    if(source[i] == ' '){
      countBlanksAfter++;
    }
    else{
      split = true;
    }
    i--;
  }
  trimmed_string = copyInArray(countBlanksFor, countBlanksAfter, source, trimmed_string);
}
char* copyInArray(int countBlanksFor, int countBlanksAfter, const char* source, char* trimmed_string){
  if(countBlanksFor == 0 && countBlanksAfter == 0){
    strcpy(trimmed_string, source);
  }
  else{
    for(int a = countBlanksFor; a < strlen(source) - countBlanksAfter; a++){
      trimmed_string[a - countBlanksFor] = source[a];
    }
  }
    return trimmed_string;
}
