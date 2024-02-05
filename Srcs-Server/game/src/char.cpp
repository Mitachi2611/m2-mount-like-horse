/// 1.) Search in void CHARACTER::SetProto(const CMob * pkMob):

	if (m_bCharType == CHAR_TYPE_HORSE || 
			GetRaceNum() == 20101 ||
			GetRaceNum() == 20102 ||
			GetRaceNum() == 20103 ||
			GetRaceNum() == 20104 ||
			GetRaceNum() == 20105 ||
			GetRaceNum() == 20106 ||
			GetRaceNum() == 20107 ||
			GetRaceNum() == 20108 ||
			GetRaceNum() == 20109
	  )

// and replace with:

	if (m_bCharType == CHAR_TYPE_HORSE || 
			GetRaceNum() == 20101 ||
			GetRaceNum() == 20102 ||
			GetRaceNum() == 20103 ||
			GetRaceNum() == 20104 ||
			GetRaceNum() == 20105 ||
			GetRaceNum() == 20106 ||
			GetRaceNum() == 20107 ||
			GetRaceNum() == 20108 ||
			GetRaceNum() == 20109
#ifdef ENABLE_MOUNT_LIKE_HORSE
		|| CMobVnumHelper::IsMount(GetRaceNum())
#endif
	  )

/// 2.) Search in void CHARACTER::MountVnum(DWORD vnum):

	}

	SetValidComboInterval(0);
	SetComboSequence(0);

// and add under, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	RemoveAffect(AFFECT_MOUNT_BONUS);
	if (const auto pMountItem = GetWear(WEAR_COSTUME_MOUNT))
	{
		for (int i = 0; i < ITEM_APPLY_MAX_NUM; ++i) {
			if (pMountItem->GetProto()->aApplies[i].bType == APPLY_NONE || vnum == 0)
				continue;
			AddAffect(AFFECT_MOUNT_BONUS, aApplyInfo[pMountItem->GetProto()->aApplies[i].bType].bPointType, pMountItem->GetProto()->aApplies[i].lValue, AFF_NONE, INFINITE_AFFECT_DURATION, 0, true);
		}
	}
#endif

/// 3.) Add at the end of the file:

#ifdef ENABLE_MOUNT_LIKE_HORSE
void CHARACTER::CheckEnterMount()
{
	if (GetHorse()) // If is already summoned, do nothing
		return;

	if (const auto pMountItem = GetWear(WEAR_COSTUME_MOUNT))
		HorseSummon(true, false, pMountItem->GetValue(1));
}
#endif