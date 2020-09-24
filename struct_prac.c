// Struct Declaration
struct _Frac{
	int numerator;
	int denominator;
};
// The Tag "_Frac" Declaration

struct _Frac frac1 = {7,13};
// Members:
// frac1.numerator
// frac1.denominator

// Type Define:
// define keyword datatype length would be translate as an integer
// an alias of the original datatypes
typedef struct {
	int numerator;
	int denominator;
} Frac;
// alias Frac = struct
// alias declaration (alias utilization)
Frac frac1 = {7,13};

// Dual definition of struct
typedef struct _Frac {
	int numerator;
	int denominator;
} Frac;

// both datatypes are workable
struct _Frac frac1 = {7,12};
Frac frac2 = {1,2};

