// 1. Search for:

void CAccountConnector::SetLoginInfo(const char * c_szName, const char * c_szPwd)

// 1. Change like this:

void CAccountConnector::SetLoginInfo(const char * c_szName, const char * c_szPwd
#ifdef __PIN_CODE_HAKYZZ__
	, const char * c_szPin
#endif
)
{
	m_strID = c_szName;
	m_strPassword = c_szPwd;
#ifdef __PIN_CODE_HAKYZZ__
	m_strPin = c_szPin;
#endif
}

// 2. Search for:

strncpy(LoginPacket.pwd, m_strPassword.c_str(), PASS_MAX_NUM);

// 2. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
		strncpy(LoginPacket.pin, m_strPin.c_str(), PIN_MAX_NUM);
#endif

// 3. Search for:

LoginPacket.pwd[PASS_MAX_NUM] = '\0';

// 3. Paste below:

#ifdef __PIN_CODE_HAKYZZ__		
		LoginPacket.pin[PIN_MAX_NUM] = '\0';
#endif

// 4. Search for:

m_strPassword = "";

// 4. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
		m_strPin = "";
#endif

// 5. Search for:

SetLoginInfo("", "")

// 5. Change like this:

	SetLoginInfo("", ""
#ifdef __PIN_CODE_HAKYZZ__
		, ""
#endif
	);