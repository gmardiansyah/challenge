#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

int main(int argc, char **argv) {

  FILE *fp;
  unsigned int number, digit, divider, part, count, i;
  char *line;
  char *end;
  unsigned int *numbers = NULL;
  size_t len = 0;
  ssize_t read;

  if (argc < 2) {
    fprintf(stderr, "input.txt diperlukan.");
    return 1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "%s tidak dapat dibuka.", argv[1]);
    return 1;
  }

  while ((read =  getline(&line, &len, fp)) != -1) {
    digit = atoi(line);
    if (digit > 0 && digit % 2 == 0) {
      break;
    }
   fprintf(stderr, "input.txt hanya dapat berisi satu angka genap.");
    return 1;
 }

  fclose(fp);
  fp = fopen("output.txt", "w");
  if (fp == NULL) {
    fprintf(stderr, "output.txt tidak dapat dibuka.");
    return 1;
  }

  number = 0;
  count = 0;
  while (number < pow(10, digit)) {
    divider = number > 0 ? pow(10, ((int) floor (log10(number) + 1))/2) : 10;
    part = number / divider + number % divider;
    if (number == part * part) {
      numbers = realloc(numbers, (count + 1) * sizeof(unsigned int));
      numbers[count++] = number;
    }
    number++;
  }

  for (i = 0; i < count; i++) {
    fprintf(fp, "%0*d", digit, numbers[i]);
    if (count > 1) {
      if (i < count - 1) {
        fprintf(fp, count == 2 ? " " : ", ");
      }
      if (i == count - 2) {
        fprintf(fp, "dan ");
      }
    }
  }

  free(numbers);
  fclose(fp);
  return 0;
}
