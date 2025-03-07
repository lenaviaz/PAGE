#include "../include/core.h"

void write_ppm_data(char *ppm_file, char *textfile) {

  dimensions dims;

  dims.width = 0;
  dims.height = 0;

  FILE *sample_data_1 = fopen(ppm_file, "r");
  FILE *image_data = fopen(textfile, "w");

  int max_size = 200;

  char line[max_size]; // max size
  int line_count = 0;

  while (fgets(line, max_size, sample_data_1)) {

    if (line[0] == 'P') {
      line_count += 1;
      continue;
    }

    if (line[0] == '#') {
      // don't copy comments
      continue;
    }

    if (line_count == 1) {

      printf("printing line");
      printf(line);

      if (sscanf(line, "%d %d", &dims.width, &dims.height) == 2) {

        line_count += 1;
        continue;
      }

      else {
        // Parsing failed; the buffer does not contain two valid integers
        // Handle the error here
        printf("Error: Unable to parse width and height from the buffer.\n");
        line_count += 1;
      }
    }

    /* if(line[4] == '\0' && line[1] == ' ') */
    /*   { */
    /*     //set matrix width and height */
    /*     width = line[0] - '0'; */
    /*     height = line[2] - '0'; */
    /*     continue; */
    /*   } */

    if (line[4] == '\0' && line[1] != ' ') {
      // skip final line before image data
      continue;
    }

    fputs(line, image_data);
  }

  // fputc('a', image_data);
  fclose(image_data);
  fclose(sample_data_1);
}
