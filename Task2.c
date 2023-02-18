#include "utils.h"

void SolveTask2() {
  char metoda[10] = "";
  char linie[10] = "";
  scanf("\n");
  scanf("%[^\n]s", metoda);
  if (strcmp(metoda, "caesar") == 0) {
    int cheie = 0;
    char * cheie1 = malloc(100);
    char cuvant[100] = "", descifrare[100] = "";
    scanf("%d\n", & cheie);
    scanf("%[^\n]s", cuvant);
    strncpy(descifrare, cuvant, strlen(cuvant) + 1);

    for (int i = 0; i < strlen(cuvant); i++) {
      if (isdigit(cuvant[i])) {
        int n = cuvant[i] - '0';  // cate caractere se poate duce inapoi
        // fara a o lua de la coada (de la '9')
        if (cheie % 10 <= n) {
          descifrare[i] = cuvant[i] - cheie % 10;
        } else {
          int coada = 0;
          coada = cheie % 10 - n;  // cate caractere mai trebuie
          // sa dea inapoi dupa ce a luat-o de la coada
          descifrare[i] = '9' - coada + 1;
        }
      }
      if (isalpha(cuvant[i]) && isupper(cuvant[i])) {
        int n = cuvant[i] - 'A';
        if (cheie % 26 <= n) {
          descifrare[i] = cuvant[i] - cheie % 26;
        } else {
          int coada = 0;
          coada = cheie % 26 - n;
          descifrare[i] = 'Z' - coada + 1;
        }
      }
      if (isalpha(cuvant[i]) && islower(cuvant[i])) {
        int n = cuvant[i] - 'a';
        if (cheie % 26 <= n) {
          descifrare[i] = cuvant[i] - cheie % 26;
        } else {
          int coada = 0;
          coada = cheie % 26 - n;
          descifrare[i] = 'z' - coada + 1;
        }
      }
    }

    printf("%s\n", descifrare);
  }

  if (strcmp(metoda, "vigenere") == 0) {
    char cheie[10] = "";
    char cuvant[1000] = "", descifrare[1000] = "";
    scanf("\n");
    scanf("%[^\n]s", cheie);
    scanf("\n");
    scanf("%[^\n]s", cuvant);
    strncpy(descifrare, cuvant, strlen(cuvant));
    cheie[strcspn(cheie, "\n")] = 0;

    char cheie_extinsa[1000] = "";
    strncpy(cheie_extinsa, cheie, strlen(cheie));
    for (int i = 0; i < strlen(cuvant) / strlen(cheie); i++)
      strncat(cheie_extinsa, cheie, strlen(cheie));
    if (strlen(cuvant) < strlen(cheie_extinsa))
      cheie_extinsa[strlen(cuvant)] = '\0';

    for (int i = 0; i < strlen(cuvant); i++) {
      if (isdigit(cuvant[i])) {
        int n = cuvant[i] - '0';  // cate caractere poate da inapoi
        // fara sa o ia de la coada
        int x = cheie_extinsa[i] - 'A';
        // cu cate caractere trebuie sa dea inapoi in functie de cheie
        if (x % 10 <= n) {
          descifrare[i] = cuvant[i] - x % 10;
        } else {
          int coada = 0;
          coada = x % 10 - n;
          descifrare[i] = '9' - coada + 1;
        }
      }
      if (isalpha(cuvant[i]) && isupper(cuvant[i])) {
        int n = cuvant[i] - 'A';
        int x = cheie_extinsa[i] - 'A';
        if (x % 26 <= n) {
          descifrare[i] = cuvant[i] - x % 26;
        } else {
          int coada = 0;
          coada = x % 26 - n;
          descifrare[i] = 'Z' - coada + 1;
        }
      }
      if (isalpha(cuvant[i]) && islower(cuvant[i])) {
        int n = cuvant[i] - 'a';
        int x = cheie_extinsa[i] - 'A';
        if (x % 26 <= n) {
          descifrare[i] = cuvant[i] - x % 26;
        } else {
          int coada = 0;
          coada = x % 26 - n;
          descifrare[i] = 'z' - coada + 1;
        }
      }
    }

    printf("%s", descifrare);
  }

  if (strcmp(metoda, "addition") == 0) {
    int cheie = 0;
    char cuvant1[1000] = "", cuvant2[1000] = "";
    char descifrare1[1000] = "", descifrare2[1000] = "";
    scanf("%d\n", & cheie);
    scanf("%[^\n]s", cuvant1);
    strncpy(descifrare1, cuvant1, strlen(cuvant1) + 1);
    scanf("\n");
    scanf("%[^\n]s", cuvant2);
    strncpy(descifrare2, cuvant2, strlen(cuvant2) + 1);

    for (int i = 0; i < strlen(cuvant1); i++) {
      if (isdigit(cuvant1[i])) {
        int n = cuvant1[i] - '0';
        if (cheie % 10 <= n) {
          descifrare1[i] = cuvant1[i] - cheie % 10;
        } else {
          int cheita = 0;
          cheita = cheie % 10 - n;
          descifrare1[i] = '9' - cheita + 1;
        }
      }
    }
    for (int i = 0; i < strlen(cuvant2); i++) {
      if (isdigit(cuvant2[i])) {
        int n = cuvant2[i] - '0';
        if (cheie % 10 <= n) {
          descifrare2[i] = cuvant2[i] - cheie % 10;
        } else {
          int cheita = 0;
          cheita = cheie % 10 - n;
          descifrare2[i] = '9' - cheita + 1;
        }
      }
    }
    descifrare1[strcspn(descifrare1, "\n")] = 0;
    descifrare2[strcspn(descifrare2, "\n")] = 0;

    char suma[1000] = "";
    for (int i = 0; i < 1000; i++)
      suma[i] = '0';  // initializarea sumei cu 0
    char des1[1000] = "", des2[1000] = "";
    for (int i = 0; i < abs(strlen(descifrare2) - strlen(descifrare1)); i++) {
      des1[i] = '0';
      des2[i] = '0';
    }  // adaug cate 0-uri sunt necesare
    // pentru ca cele 2 nr sa aiba lungime egala
    int modul = abs(strlen(descifrare2) - strlen(descifrare1));
    for (int i = modul; i < 1000; i++) {
      des1[i] = 0;
      des2[i] = 0;
    }
    if (strlen(descifrare1) < strlen(descifrare2)) {
      strncat(des1, descifrare1, strlen(descifrare1));
      // adaug 0-urile in fata
      for (int i = strlen(des1) - 1; i >= 0; i--) {
        int o = suma[i] - '0';
        int p = des1[i] - '0';
        int r = descifrare2[i] - '0';
        if (o + p + r < 10) {
          suma[i] = o + p + r + '0';
        } else {
          suma[i] = ((o + p + r) % 10) + '0';
          suma[i - 1] = (suma[i - 1] - '0' + 1) + '0';
        }
      }
      for (int i = strlen(des1); i < 1000; i++)
        suma[i] = 0;  // sterg 0-urile de la final
      for (int i = 0; i < strlen(des1); i++) {
        if (suma[i] != '0') {
          break;
        } else {
          strncpy(suma, suma + 1, strlen(suma + 1) + 1);
          // sterg 0-urile din fata
          i--;
        }
      }
    } else {
      if (strlen(descifrare1) > strlen(descifrare2)) {
        strncat(des2, descifrare2, strlen(descifrare2));
        for (int i = strlen(des2) - 1; i >= 0; i--) {
          int o = suma[i] - '0';
          int p = des2[i] - '0';
          int r = descifrare1[i] - '0';
          if ((o + r + p) < 10) {
            suma[i] = (o + r + p) + '0';
          } else {
            suma[i] = ((o + r + p) % 10) + '0';
            suma[i - 1] = (suma[i - 1] - '0' + 1) + '0';
          }
        }
        for (int i = strlen(des2); i < 1000; i++)
          suma[i] = 0;
        for (int i = 0; i < strlen(des2); i++) {
          if (suma[i] != '0') {
            break;
          } else {
            strncpy(suma, suma + 1, strlen(suma + 1) + 1);
            i--;
          }
        }
      } else {
        for (int i = strlen(descifrare1); i >= 0; i--) {
          int o = suma[i + 1] - '0';
          int p = descifrare2[i] - '0';
          int r = descifrare1[i] - '0';
          if (o + r + p < 10) {
            suma[i + 1] = (o + r + p) + '0';
          } else {
            suma[i + 1] = ((o + r + p) % 10) + '0';
            suma[i] = (suma[i] - '0' + 1) + '0';
          }
        }
        for (int i = strlen(descifrare1) + 1; i < 1000; i++)
          suma[i] = 0;
        for (int i = 0; i < strlen(descifrare1); i++) {
          if (suma[i] != '0') {
            break;
          } else {
            for (int i = 0; i < strlen(descifrare1); i++)
              suma[i] = suma[i + 1];
            suma[strlen(suma) - 1] = 0;
          }
        }
      }
    }
    printf("%s", suma);
  }
}
