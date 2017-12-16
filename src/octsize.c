
#include <R.h>
#include <Rinternals.h>

SEXP octsize(SEXP size)
{
    double s = asReal(size);
    SEXP ans = allocVector(RAWSXP, 11);
    Rbyte *ra = RAW(ans);
    if (!R_FINITE(s) && s >= 0) error("size must be finite and >= 0");
    /* We have to be able to do this on a 32-bit system */
    for (int i = 0; i < 11; i++) {
	double s2 = floor(s/8.);
	double t = s - 8.*s2;
	s = s2;
	ra[10-i] = (Rbyte) (48 + t); // as ASCII
    }
    return ans;
}

static const R_CallMethodDef callMethods[]  = {
  { "octsize", (DL_FUNC) &octsize, 1 },
  { NULL, NULL, 0 }
};

void R_init_tar(DllInfo *dll) {
  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
