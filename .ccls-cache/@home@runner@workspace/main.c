#include <stdio.h>
#include <string.h>

struct Pessoa {
  char nome[50];
  int idade;
};

void trocar(struct Pessoa *p1, struct Pessoa *p2) {
  struct Pessoa temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void bubbleSort(struct Pessoa pessoas[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (pessoas[j].idade > pessoas[j + 1].idade) {
        trocar(&pessoas[j], &pessoas[j + 1]);
      }
    }
  }
}

int main(void) {
  struct Pessoa pessoas[100];

  for (int i = 0; i < 100; i++) {
    sprintf(pessoas[i].nome, "Pessoa %d", i + 1);
    pessoas[i].idade = rand() % 100 + 1;
  }

  printf("Antes da ordenação:\n");
  for (int i = 0; i < 10; i++) {
    printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
  }

  bubbleSort(pessoas, 100);

  printf("\nDepois da ordenação:\n");

  for (int i = 0; i < 10; i++) {
    printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
  }

  return 0;
}
