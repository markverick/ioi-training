#include <stdio.h>
#include <stdlib.h>
#define MAX 50005

struct rect { long long w, h; };

struct line {
  long long m, b;
  line(long long x=0, long long y=0) { m=x; b=y; }
};

int N, lstart, lend;
rect plots[MAX];
long long best[MAX];
line lines[MAX];

int cmp(const void *a, const void *b) {
  rect p = *(rect *)a, q = *(rect *)b;
  if (p.w < q.w) return -1;
  if (p.w > q.w) return 1;
  if (p.h < q.h) return -1;
  return 1;
}

bool bad(line x, line y, line z) {
  // lines x and y intersect at x-coordinate p1
  // lines y and z intersect at x-coordinate p2
  // bad <--> p1 >= p2
  return ((y.m-z.m) * (y.b-x.b) >= (x.m-y.m) * (z.b-y.b));
}

int main() {
  FILE *in = fopen("acquire.in", "r");
  fscanf(in, "%d", &N);
  for (int i = 0; i < N; i++) {
    fscanf(in, "%lld%lld", &plots[i].w, &plots[i].h);
  }
  fclose(in);

  qsort(plots, N, sizeof(plots[0]), cmp);
  int tN = 0;
  for (int i = 0; i < N; i++) {
    plots[tN] = plots[i];
    while (tN > 0 &&
	   plots[tN].w >= plots[tN-1].w &&
	   plots[tN].h >= plots[tN-1].h) {
      plots[tN-1] = plots[tN];
      tN--;
    }
    tN++;
  }
  N = tN;

  best[0] = 0;
  lines[0] = line(plots[0].h, best[0]);
  lstart = 0;
  lend = 1;
  for (int i = 0; i < N; i++) {
    // compute best[i+1]
    for (int j = lstart; j < lend; j++) {
      long long tmp = lines[j].m * plots[i].w + lines[j].b;
      if (j == lstart) {
	best[i+1] = tmp;
      }
      else if (tmp < best[i+1]) {
	best[i+1] = tmp;
	lstart = j;
      }
      else {
	break;
      }
    }

    if (i < N-1) {
      // compute new line
      lines[lend] = line(plots[i+1].h, best[i+1]);
      lend++;

      // erase irrelevant lines
      while (lend-lstart >= 3 &&
	     bad(lines[lend-3], lines[lend-2], lines[lend-1])) {
	lines[lend-2] = lines[lend-1];
	lend--;
      }
    }
  }

  FILE *out = fopen("acquire.out", "w");
  fprintf(out, "%lld\n", best[N]);
  fclose(out);

  return 0;
}
