// triagle.c
// Sierpinksi Triangle
//
// Author : Weipeng He <heweipeng@gmail.com>
// Copyright (c) 2015, All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <gsl/gsl_rng.h>

int main(int argc, char** argv) {
  int size = 10000;
  double sx = 1.0;
  double sy = 1.0;

  int opt;
  while ((opt = getopt(argc, argv, "s:x:y:")) != -1) {
    switch (opt) {
      case 's':
        size = atoi(optarg);
        break;
      case 'x':
        sx = atof(optarg);
        break;
      case 'y':
        sy = atof(optarg);
        break;
    }
  }

  gsl_rng_env_setup();
  gsl_rng* rng = gsl_rng_alloc(gsl_rng_default);
 
  double px[3] = {0.0, 0.5, 1.0};
  double py[3] = {0.0, 1.0, 0.0};

  double x = gsl_rng_uniform(rng);
  double y = gsl_rng_uniform(rng);

  printf("%g %g\n", x, y);

  int i, d;
  for (i = 0; i < size; i++) {
    d = gsl_rng_uniform_int(rng, 3);
    x = (x * sx + px[d]) / (1.0 + sx);
    y = (y * sy + py[d]) / (1.0 + sy);
    printf("%g %g\n", x, y);
  }

  gsl_rng_free(rng);
}

