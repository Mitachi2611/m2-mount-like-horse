/// If you want CTRL + B and CTRL G unsummon and summon the mount:

// Srcs-Server/game/src/cmd_general.cpp, add at beginning of ACMD(do_user_horse_back), this:

ACMD(do_ride)
{
#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (const auto pItem = ch->GetWear(WEAR_COSTUME_MOUNT)) {
		if (!ch->GetHorse() && !ch->IsRiding()) {
			ch->HorseSummon(true, false, pItem->GetValue(0));
			return;
		}
	}
#endif



/// If you want CTRL + B to remove the seal, that's enough:

// Srcs-Server/game/src/cmd_general.cpp, edit ACMD(do_user_horse_back) like this:

ACMD(do_user_horse_back)
{
	if (ch->GetHorse())
	{
		ch->HorseSummon(false);
#ifdef ENABLE_MOUNT_LIKE_HORSE
		if (const LPITEM pMount = ch->GetWear(WEAR_COSTUME_MOUNT))
			ch->UnequipItem(pMount);
#endif
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("¸»À» µ¹·Áº¸³Â½À´Ï´Ù."));
	}
	else if (ch->IsHorseRiding())
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("¸»¿¡¼­ ¸ÕÀú ³»·Á¾ß ÇÕ´Ï´Ù."));
	else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("¸»À» ¸ÕÀú ¼ÒÈ¯ÇØÁÖ¼¼¿ä."));
}



/// If you want CTRL + B don't remove your mount:

// Srcs-Server/game/src/cmd_general.cpp, edit ACMD(do_user_horse_back) like this:

ACMD(do_user_horse_back)
{
#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (const LPITEM pMount = ch->GetWear(WEAR_COSTUME_MOUNT))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't do that with mounts, only with horse."));
		return;
  	}
#endif

	if (ch->GetHorse())
	{
		ch->HorseSummon(false);
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("¸»À» µ¹·Áº¸³Â½À´Ï´Ù."));
	}
	else if (ch->IsHorseRiding())
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("¸»¿¡¼­ ¸ÕÀú ³»·Á¾ß ÇÕ´Ï´Ù."));
	else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("¸»À» ¸ÕÀú ¼ÒÈ¯ÇØÁÖ¼¼¿ä."));
}



/// For those who want bonuses to be awarded even if you are not riding, but simply have the mount summoned:

// Remove from Srcs-Server/game/src/item.cpp, void CItem::ModifyPoints

#ifdef ENABLE_MOUNT_LIKE_HORSE
		if (IsMount())
			continue;
#endif

// Remove from Srcs-Server/game/src/char.cpp, void CHARACTER::MountVnum

#ifdef ENABLE_MOUNT_LIKE_HORSE
	RemoveAffect(AFFECT_MOUNT_BONUS);
	if (const auto pMountItem = GetWear(WEAR_COSTUME_MOUNT))
	{
		for (int i = 0; i < ITEM_APPLY_MAX_NUM; ++i) {
			if (pMountItem->GetProto()->aApplies[i].bType == APPLY_NONE || vnum == 0)
				continue;
			AddAffect(AFFECT_MOUNT_BONUS, aApplyInfo[pMountItem->GetProto()->aApplies[i].bType].bPointType, pMountItem->GetProto()->aApplies[i].lValue, AFF_NONE, INFINITE_AFFECT_DURATION, 0, false);
		}
	}
#endif

// Remove from Srcs-Server/game/src/char.cpp, bool CHARACTER::StopRiding

#ifdef ENABLE_MOUNT_LIKE_HORSE
		RemoveAffect(AFFECT_MOUNT_BONUS);
#endif