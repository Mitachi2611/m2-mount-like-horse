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
	if (const auto pMountItem = GetWear(WEAR_COSTUME_MOUNT))
		CalcBonusMount(pMountItem);
#endif
