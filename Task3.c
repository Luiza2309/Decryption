#include "utils.h"

void SolveTask3() {
  char text[4000] = "", temp[4000] = "";
  int task = 0;
  char curent[4000] = "";
  int nr = 0;
  while (scanf("%s", curent) != -1) {
    strncat(text, curent, strlen(curent));
    strncat(text, " ", 1);
    nr++;  // numar cuvinte
  }
  strncpy(temp, text, strlen(text));

  // Elimina punctuatia
  int i = 0, j = 0;
  char punctuatie[] = ".?!;,";
  while (text[i] != '\0') {
    while (punctuatie[j] != '\0') {
      if (text[i] == punctuatie[j]) {
        for (int k = i; k < strlen(text) - 1; k++)
          text[k] = text[k + 1];
        text[strlen(text) - 1] = '\0';
        i--;
      }
      j++;
    }
    j = 0;
    i++;
  }
  strncpy(temp, text, strlen(text));

  char sep[10] = {
    ' ',
    '\n'
  };
  char temp1[4000] = "";
  strncpy(temp1, temp, strlen(temp));

  char * cuv1;
  cuv1 = strtok(temp1, sep);

  char dictionar[1000][100] = {};
  for (int i = 0; i < nr - 1; i++) {
    char * aux = cuv1;
    cuv1 = strtok(NULL, sep);
    strncat(dictionar[i], aux, strlen(aux));
    strncat(dictionar[i], " ", 1);
    strncat(dictionar[i], cuv1, strlen(cuv1));
  }

  int repetari[1000] = {
    0
  }, perechi = 0;
  for (int j = 0; j < nr - 1; j++)
    for (int i = 0; i <= j; i++) {
      if (strcmp(dictionar[i], dictionar[j]) == 0) {
        repetari[i]++;
        break;
      }
      if (i == j - 1)
        perechi++;
    }

  printf("%d\n", perechi + 1);  // prima pereche nu este numarata
  // pentru ca iese cu break
  for (int i = 0; i < nr - 1; i++) {
    if (repetari[i] != 0)
      printf("%s %d\n", dictionar[i], repetari[i]);
  }
}
