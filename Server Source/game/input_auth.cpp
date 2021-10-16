// 1. Search for:

	char szLogin[LOGIN_MAX_LEN * 2 + 1];
	DBManager::instance().EscapeString(szLogin, sizeof(szLogin), login, strlen(login));
	
// 1. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
	char szPin[PIN_MAX_LEN * 2 + 1];
	DBManager::instance().EscapeString(szPin, sizeof(szPin), p->pin, strlen(p->pin));
#endif

// 2. Search for:

	if (Login_IsInChannelService(szLogin))
	{
	
// 2. Change like this:

	if (Login_IsInChannelService(szLogin))
	{
		sys_log(0, "ChannelServiceLogin [%s]", szLogin);

		DBManager::instance().ReturnQuery(QID_AUTH_LOGIN, dwKey, p,
#ifdef __PIN_CODE_HAKYZZ__
				"SELECT '%s',password,'%s',pin,,"
#else
				"SELECT '%s',password,"
#endif
#endif
				"social_id,id,status,"
#ifndef _IMPROVED_PACKET_ENCRYPTION_
				"COALESCE(GM.mAuthority-1, 0),"
#endif
				"availDt - NOW() > 0,"
				"UNIX_TIMESTAMP(silver_expire),"
				"UNIX_TIMESTAMP(gold_expire),"
				"UNIX_TIMESTAMP(safebox_expire),"
				"UNIX_TIMESTAMP(autoloot_expire),"
				"UNIX_TIMESTAMP(fish_mind_expire),"
				"UNIX_TIMESTAMP(marriage_fast_expire),"
				"UNIX_TIMESTAMP(money_drop_rate_expire),"
				"UNIX_TIMESTAMP(create_time)"
				" FROM account WHERE login='%s'",
				szPasswd,
#ifdef __PIN_CODE_HAKYZZ__
				szPin,
#endif
				szLogin);
	}
	else
	{
		DBManager::instance().ReturnQuery(QID_AUTH_LOGIN, dwKey, p, 
#ifdef __PIN_CODE_HAKYZZ__
				"SELECT PASSWORD('%s'),password,'%s',pin,"
#else
				"SELECT PASSWORD('%s'),password,"
#endif
				"social_id,id,status,"
#ifndef _IMPROVED_PACKET_ENCRYPTION_
				"COALESCE(GM.mAuthority-1, 0),"
#endif
				"availDt - NOW() > 0,"
				"UNIX_TIMESTAMP(silver_expire),"
				"UNIX_TIMESTAMP(gold_expire),"
				"UNIX_TIMESTAMP(safebox_expire),"
				"UNIX_TIMESTAMP(autoloot_expire),"
				"UNIX_TIMESTAMP(fish_mind_expire),"
				"UNIX_TIMESTAMP(marriage_fast_expire),"
				"UNIX_TIMESTAMP(money_drop_rate_expire),"
				"UNIX_TIMESTAMP(create_time)"
				" FROM account WHERE login='%s'",
				szPasswd,
#ifdef __PIN_CODE_HAKYZZ__
				szPin,
#endif
				szLogin);
	}