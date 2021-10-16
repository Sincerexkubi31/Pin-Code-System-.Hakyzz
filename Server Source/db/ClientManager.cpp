// 1. Search for:

strlcpy(r.social_id, p->szSocialID, sizeof(r.social_id));

// 1. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
		strlcpy(r.pin, p->szPin, sizeof(r.pin));
#endif

// 2. Search for:

		sys_log(0, "AUTH_LOGIN id(%u) login(%s)"
				"social_id(%s) login_key(%u), client_key(%u %u %u %u)",
				p->dwID,
				p->szLogin, 
				p->szSocialID,
				p->dwLoginKey,
				p->adwClientKey[0],
				p->adwClientKey[1],
				p->adwClientKey[2],
				p->adwClientKey[3]);

// 2. Change like this:

#ifdef __PIN_CODE_HAKYZZ__
		sys_log(0, "AUTH_LOGIN id(%u) login(%s) pin(%s)"
#else
		sys_log(0, "AUTH_LOGIN id(%u) login(%s)"
#endif
				"social_id(%s) login_key(%u), client_key(%u %u %u %u)",
				p->dwID,
				p->szLogin, 
#ifdef __PIN_CODE_HAKYZZ__
				p->szPin,
#endif
				p->szSocialID,
				p->dwLoginKey,
				p->adwClientKey[0],
				p->adwClientKey[1],
				p->adwClientKey[2],
				p->adwClientKey[3]);