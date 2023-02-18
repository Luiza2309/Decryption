#include "utils.h"

int este_prim(int n) {
  if (n < 2)
    return 0;
  for (int i = 2; i < n / 2 + 1; i++)
    if (n % i == 0)
      return 0;
  return 1;
}

int este_palindrom(int n) {
  int m = 0, x, n1;
  n1 = n;
  while (n != 0) {
    x = n % 10;
    m = m * 10 + x;
    n = n / 10;
  }
  if (n1 == m)
    return 1;
  else
    return 0;
}

void SolveTask1() {
  int Templu[50][50] = {
    0
  };
  int n, m;
  int misc_curenta = 1, lin = 0, col = 0;
  Templu[0][0] = 1;
  char v[200];
  char linie[10];
  char * cuvant = malloc(100);
  scanf("%d", & n);
  scanf("%d\n", & m);
  scanf("%[^\n]s", v);
  cuvant = strtok(v, " ");

  while (cuvant) {
    if (cuvant[0] == 'a') {
      int max = 0, poz = 0;
      for (int i = 1; i < 5; i++) {
        if ((cuvant[i] - '0') > max) {
          max = cuvant[i] - '0';
          poz = i;
        }
      }
      switch (poz) {
      case 1:
        col += 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
        break;
      case 2:
        lin -= 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
        break;
      case 3:
        col -= 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
        break;
      case 4:
        lin += 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
        break;
      }
    }
    if (cuvant[0] == 'b') {
      int nr = strlen(cuvant);
      int k = 0;
      for (int i = 1; i < nr; i++) {
        k *= 10;
        k += cuvant[i] - '0';
      }
      int e_palindrom = este_palindrom(k);
      int x = 0;
      x += cuvant[nr - 2] - '0';
      x *= 10;
      x += cuvant[nr - 1] - '0';
      int e_prim = este_prim(x);
      if (e_palindrom == 1 && e_prim == 1) {
        col -= 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
      }
      if (e_palindrom == 1 && e_prim == 0) {
        col += 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
      }
      if (e_palindrom == 0 && e_prim == 1) {
        lin -= 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
      }
      if (e_palindrom == 0 && e_prim == 0) {
        lin += 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
      }
    }
    if (cuvant[0] == 'c') {
      int suma = 0;
      int n, k;
      n = cuvant[1] - '0';
      k = cuvant[2] - '0';
      strncpy(cuvant, cuvant + 3, strlen(cuvant + 3));
      // sterg litera 'c', n si k
      int j = 0;
      for (int i = 0; i < k; i++) {
        if (j >= n)
          suma = suma + cuvant[j % n] - '0';
        else
          suma = suma + cuvant[j] - '0';
        j += k;
      }
      switch (suma % 4) {
      case 0:
        col -= 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
        break;
      case 1:
        lin -= 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
        break;
      case 2:
        col += 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
        break;
      case 3:
        lin += 1;
        misc_curenta++;
        Templu[lin][col] = misc_curenta;
        break;
      }
    }
    cuvant = strtok(NULL, " ");
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", Templu[i][j]);
    printf("\n");
  }
}
