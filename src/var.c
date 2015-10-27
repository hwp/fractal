// var.c
// variations
//
// Author : Weipeng He <heweipeng@gmail.com>
// Copyright (c) 2015, All rights reserved.

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include <gsl/gsl_rng.h>

int main(int argc, char** argv) {
  int size = 10000;
  int type = 0;
  double a = 1.0;
  double b = 1.0;

  int opt;
  while ((opt = getopt(argc, argv, "t:s:a:b:")) != -1) {
    switch (opt) {
      case 't':
        type = atoi(optarg);
        break;
      case 's':
        size = atoi(optarg);
        break;
      case 'a':
        a = atof(optarg);
        break;
      case 'b':
        b = atof(optarg);
        break;
    }
  }

  gsl_rng_env_setup();
  gsl_rng* rng = gsl_rng_alloc(gsl_rng_default);
 
  double px[4] = {0.0, 0.0, 1.0, 1.0};
  double py[4] = {0.0, 1.0, 0.0, 1.0};

  double x = gsl_rng_uniform(rng);
  double y = gsl_rng_uniform(rng);

  printf("%g %g\n", x, y);

  int i, d;
  double z, w, dx, dy;
  for (i = 0; i < size; i++) {
    d = gsl_rng_uniform_int(rng, 4);

    switch (type) {
      case 0:
        w = pow(y, b) * a;
        z = (x * w + px[d]) / (1.0 + w);
        w = pow(x, b) * a;
        y = (y * w + py[d]) / (1.0 + w);
        x = z;
        break;
      case 1:
        w = pow(y, b) * a;
        x = (x * w + px[d]) / (1.0 + w);
        w = pow(x, b) * a;
        y = (y * w + py[d]) / (1.0 + w);
        break;
      case 2:
        dx = fabs(px[d] - x);
        dy = fabs(py[d] - y);
        w = a / pow(pow(dx, b) + pow(dy, b), 1.0 / b);
        x = (x * w + px[d]) / (1.0 + w);
        y = (y * w + py[d]) / (1.0 + w);
        break;
      case 3:
        dx = fabs(px[d] - x);
        dy = fabs(py[d] - y);
        w = a * pow(pow(dx, b) + pow(dy, b), 1.0 / b);
        x = (x * w + px[d]) / (1.0 + w);
        y = (y * w + py[d]) / (1.0 + w);
        break;
      default:
        x = (x * a + px[d]) / (1.0 + a);
        y = (y * a + py[d]) / (1.0 + a);
        break;
    }

    printf("%g %g\n", x, y);
  }

  gsl_rng_free(rng);
}

