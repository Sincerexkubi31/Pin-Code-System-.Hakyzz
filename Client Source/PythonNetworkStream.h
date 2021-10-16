// 1. Search for:

void SetLoginInfo(const char* c_szID, const char* c_szPassword)

// 1. Change like this:

		void SetLoginInfo(const char* c_szID, const char* c_szPassword
#ifdef __PIN_CODE_HAKYZZ__
		, const char* c_szPin
#endif
		);
		
// 2. Search for:

std::string	m_stPassword;

// 2. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
		std::string m_stPin;
#endif