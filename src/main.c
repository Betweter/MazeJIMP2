#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
  int dev, verb = 0;
  FILE *in = NULL;
  FILE *out = stdout;

  int opt;
  int option_index = 0;
  struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"verb", no_argument, NULL, 'v'},
    {"dev", no_argument, NULL, 'd'},
    {"file", required_argument, NULL, 'f'},
    {"out", required_argument, NULL, 'o'},
    {NULL, 0, NULL, 0}
  };

  while ((opt = getopt_long(argc, argv, "hvdfo:", long_options, &option_index)) != -1) {
    switch (opt) {
      case 'h':
        fprintf(stderr, "Ten program służy do znajdowania ścieżek labiryntu. Podstawowe wywołanie:\n");
        fprintf(stderr, "./%s -f <nazwa_pliku>\n", argv[0]);
        fprintf(stderr, "Po więcej informacji otwórz plik Readme lub instrukcję.\n");
        return 1;
      case 'v':
        verb++;
        break;
      case 'd':
        dev++;
        break;
      case 'f':
        in = fopen( optarg, "r");
        break;
      case 'o':
        out = fopen( optarg, "w");
        break;
      default:
        fprintf(stderr, "Nierozpoznana flaga, wywołaj program z flagą \"-h\" aby wyświetlić pomoc.\n");
        return 1;
    }
  }

  if(in == NULL){
    fprintf(stderr, "Błąd otwarcia pliku z labiryntem lub jego brak.\n");
    return 1;
  }
  if(out == NULL){
    fprintf(stderr, "Błąd otwarcia pliku do pisania.\n");
    return 1;
  }

return 0;
}

