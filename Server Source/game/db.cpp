// 1. Search for:

trim_and_lower(r.login, ptod.szLogin, sizeof(ptod.szLogin));

// 1. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
	strlcpy(ptod.szPin, r.pin, sizeof(ptod.szPin));
#endif

// 2. Search for:

					char szEncrytPassword[45 + 1];
					char szPassword[45 + 1];

// 2. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
					char szPin[PIN_MAX_LEN + 1];
					char szActualPin[PIN_MAX_LEN + 1]; 
#endif

// 3. Search for:

strlcpy(szPassword, row[col++], sizeof(szPassword));

// 3. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
					if (!row[col])
					{
						sys_err("error column %d", col);
						M2_DELETE(pinfo);
						break;
					}

					std::strncpy(szPin, row[col++], sizeof(szPin));
					szPin[PIN_MAX_LEN] = '\0';

					if (!row[col])
					{
						sys_err("error column %d", col);
						M2_DELETE(pinfo);
						break;
					}

					std::strncpy(szActualPin, row[col++], sizeof(szActualPin));
					szActualPin[PIN_MAX_LEN] = '\0';
#endif

// 4. Search for:

int nPasswordDiff = strcmp(szEncrytPassword, szPassword);

// 4. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
					bool hasPin = strlen(szActualPin) == PIN_MAX_LEN; 
#endif

// 5. Search for:

					if (nPasswordDiff)
					{
						LoginFailure(d, "WRONGPWD");
						sys_log(0, "   WRONGPWD");
						M2_DELETE(pinfo);
					}
					
// 5. Paste below:

#ifdef __PIN_CODE_HAKYZZ__
					else if (!hasPin)
					{
						if (strlen(szPin) != PIN_MAX_LEN)
						{
							LoginFailure(d, "WLPIN");
							sys_log(0, "Wrong Pin length");
							M2_DELETE(pinfo);
							break;
						}
						else
						{
							std::string stPin = szPin; 

							if (!std::all_of(stPin.begin(), stPin.end(), isdigit))
							{
								LoginFailure(d, "WRPIN");
								sys_log(0, "Wrong Pin");
								M2_DELETE(pinfo);
								break;
							}

							char	szLoginEscaped[LOGIN_MAX_LEN  * 2+ 1];
							DBManager::instance().EscapeString(szLoginEscaped, sizeof(szLoginEscaped), pinfo->login, strlen(pinfo->login));

							char szPinEscaped[PIN_MAX_LEN * 2 + 1];
							DBManager::instance().EscapeString(szPinEscaped, sizeof(szPinEscaped), szPin, strlen(szPin));
							std::unique_ptr<SQLMsg> pMsg(DBManager::instance().DirectQuery("UPDATE `account`.`account` SET `pin`= '%s' WHERE login='%s'", szPin, szLoginEscaped));

							LoginFailure(d, "CRPIN");
							sys_log(0, "Pin was created");
							M2_DELETE(pinfo);
							break;
						}
					}
					else if (strncmp(szActualPin, szPin, PIN_MAX_LEN) != 0)
					{
						LoginFailure(d, "WRONGPIN");
						sys_log(0, "WRONGPIN");
						M2_DELETE(pinfo);
						break;
					}
#endif