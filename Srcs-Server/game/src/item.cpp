/// 1.) Search in void CItem::ModifyPoints(bool bAdd):

	for (int i = 0; i < ITEM_APPLY_MAX_NUM; ++i)
	{
		if (m_pProto->aApplies[i].bType == APPLY_NONE)
			continue;

// and add under, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
		if (IsMount())
			continue;
#endif

/*Example:
	for (int i = 0; i < ITEM_APPLY_MAX_NUM; ++i)
	{
		if (m_pProto->aApplies[i].bType == APPLY_NONE)
			continue;
#ifdef ENABLE_MOUNT_LIKE_HORSE
		if (IsMount())
			continue;
#endif

		long value = m_pProto->aApplies[i].lValue;
	...
*/