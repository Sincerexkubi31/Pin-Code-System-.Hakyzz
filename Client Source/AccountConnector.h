// 1. Search for:

void SetLoginInfo(const char * c_szName, const char * c_szPwd)

// 1. Change like this:

		void SetLoginInfo(const char * c_szName, const char * c_szPwd
#ifdef __PIN_CODE_HAKYZZ__
		, const char* c_szPin
#endif
		);

// 2. Search for:

std::string m_strPassword;

// 2. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
		std::string m_strPin;
#endif