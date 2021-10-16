// 1. Search for:

strlcpy(pkTab->passwd, r.passwd, sizeof(pkTab->passwd));

// 2. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
	strlcpy(pkTab->pin, r.pin, sizeof(pkTab->pin));
#endif