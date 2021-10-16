// 1. Search for:

char			passwd[PASSWD_MAX_LEN + 1];

// 1. Inside of:

typedef struct SAccountTable

// 1. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
	char			pin[PIN_MAX_LEN + 1];
#endif

// 2. Search for:

char	szLogin[LOGIN_MAX_LEN + 1];

// 2. Inside of:

typedef struct SPacketGDAuthLogin

// 2. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
	char	szPin[PIN_MAX_LEN + 1];
#endif