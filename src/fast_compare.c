// brings in types, functions and macros to use when working with NIFS
#include "/usr/local/Cellar/erlang/22.1.8/lib/erlang/erts-10.5.6/include/erl_nif.h"

// THis a type that represents all erlang types
// think atoms, strings, list, tuple
// we use erl_nif.h to convert functions provided by erlang to c values
static ERL_NIF_TERM

//ErlNifEnv: this is the erlang environment that cpp is running in
fast_comparison(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
	int a, b;

	// Fill a and b with values of the first two args
	enif_get_int(env, argv[0], &a);
	enif_get_int(env, argv[1], &b);


	// here we are using a nested ternary statement to return a range of values
	// depending on whether the args are equal or not
	int result = a == b ? 0 : (a > b ? 1 : -1);

	return enif_make_int(env, result);
}


// Define an array of NIFs
static ErlNifFunc nif_funcs[] = {
	//{erl_function_name, erl_function_arity, c_function}
	{"fast_comparison", 2, fast_comparison}
};


// Export the function to erlang land
//{erl_module, functions, load, upgrade, unload, reload}
//The above are pointers to use when the function is loaded, unloaded, upgraded and reloaded

ERL_NIF_INIT(Elixir.Comparator, nif_funcs, NULL, NULL, NULL, NULL);

