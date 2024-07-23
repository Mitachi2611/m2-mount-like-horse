/// 1.) Search in void ITEM_MANAGER::RemoveItem(LPITEM item, const char * c_pszReason)

		}
		// END_OF_SAFEBOX_TIME_LIMIT_ITEM_BUG_FIX
		else
		{

// and add under, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
			if (o->GetWear(WEAR_COSTUME_MOUNT) && item == o->GetWear(WEAR_COSTUME_MOUNT)) {
				o->StopRiding();
				o->HorseSummon(false);
			}
#endif

/*Example:
void ITEM_MANAGER::RemoveItem(LPITEM item, const char * c_pszReason)
{
	LPCHARACTER o;

	if ((o = item->GetOwner()))
	{
		char szHint[64]{};
		snprintf(szHint, sizeof(szHint), "%s %u ", item->GetName(), item->GetCount());
		LogManager::instance().ItemLog(o, item, c_pszReason ? c_pszReason : "REMOVE", szHint);

		// SAFEBOX_TIME_LIMIT_ITEM_BUG_FIX
		if (item->GetWindow() == MALL || item->GetWindow() == SAFEBOX)
		{
			// If you have a timed item in your store, the server will go down when the time expires.
			if (const auto pSafebox = item->GetWindow() == MALL ? o->GetMall() : o->GetSafebox())
				pSafebox->Remove(item->GetCell());
		}
		// END_OF_SAFEBOX_TIME_LIMIT_ITEM_BUG_FIX
		else
		{
#ifdef ENABLE_MOUNT_LIKE_HORSE
			if (o->GetWear(WEAR_COSTUME_MOUNT) && item == o->GetWear(WEAR_COSTUME_MOUNT)) {
				o->StopRiding();
				o->HorseSummon(false);
			}
#endif
			o->SyncQuickslot(QUICKSLOT_TYPE_ITEM, item->GetCell(), 255);
			item->RemoveFromCharacter();
		}
	}

	M2_DESTROY_ITEM(item);
}
*/