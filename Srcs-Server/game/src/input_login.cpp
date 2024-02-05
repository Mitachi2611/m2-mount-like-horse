/// 1.) Search in void CInputLogin::Entergame(LPDESC d, const char * data):

	if (ch->GetHorseLevel() > 0)
		ch->EnterHorse();

// and add under, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	ch->CheckEnterMount();
#endif