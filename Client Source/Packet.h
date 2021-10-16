// 1. Search for:

PASS_MAX_NUM = 16,

// 1. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
	PIN_MAX_NUM = 4,
#endif

// 2. Search for:

typedef struct command_login3

// 2. Inside you can find this:

    char	pwd[PASS_MAX_NUM + 1];

// 2. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
	char	pin[PIN_MAX_NUM + 1];
#endif