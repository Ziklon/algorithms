#ifndef H_CORR_H
#define H_CORR_H

#ifdef __cplusplus // __CPLUSPLUS
/* extern "C" { */
/*  #include <sys/varargs.h> */
/* } */
#include <cstdarg>
#include <cstdio>
#include <stdlib.h>
#else
#include <sys/varargs.h>
#include <stdio.h>
#endif


const int EXIT_AC = 0;
const int EXIT_WA = 1;
const int EXIT_CANTJUDGE = 2;
const int EXIT_JUDGEERR = 3;
const int EXIT_INPUTERR = 4;
const int EXIT_AC_SCORE = 5;

#define USAGE "%s: judge_in judge_out feedback_file\n"

FILE *judgein, *judgeout, *teamout;
FILE *feedback;

void report_error(char *err, ...) {
   va_list pvar;
   va_start(pvar, err);
   vfprintf(stderr, err, pvar);
   fprintf(stderr, "\n");
   exit(EXIT_WA);
}

void report_cantjudge(char *err, ...) {
   va_list pvar;
   va_start(pvar, err);
   vfprintf(stderr, err, pvar);
   fprintf(stderr, "\n");
   exit(EXIT_CANTJUDGE);
}

void accept_with_score(double score) {
	fprintf(feedback, "%.9le\n", score);
	exit(EXIT_AC_SCORE);
}

void init_io(int argc, char **argv) {

   if(argc < 4) {
     fprintf(stderr, USAGE, argv[0]);
     exit(EXIT_JUDGEERR);
   }


   if ((judgein = fopen(argv[1], "r")) == 0) {
     fprintf(stderr, "%s: failed to open %s\n", argv[0], argv[1]);
     exit(EXIT_JUDGEERR);
   }
   
   if ((judgeout = fopen(argv[2], "r")) == 0) {
     fprintf(stderr, "%s: failed to open %s\n", argv[0], argv[2]);
     exit(EXIT_JUDGEERR);
   }
   
   if((feedback = fopen(argv[3], "w")) == 0) {
     fprintf(stderr, "%s: failed to open %s\n", argv[0], argv[3]);
     exit(EXIT_JUDGEERR);
   }

   teamout = stdin;
}

#endif /* H_CORR_H */
