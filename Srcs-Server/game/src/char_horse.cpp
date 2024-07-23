/// 1.) Search in bool CHARACTER::StartRiding():

		return false;
	}

	DWORD dwMountVnum = m_chHorse ? m_chHorse->GetRaceNum() : GetMyHorseVnum();

// and add under, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (const LPITEM pMountItem = GetWear(WEAR_COSTUME_MOUNT))
		if (CMobVnumHelper::IsMount(pMountItem->GetValue(1)))
			dwMountVnum = pMountItem->GetValue(1);
#endif

// then search:

		if (m_chHorse)
		{
			...
		}

// and replace with this:

		if (m_chHorse)
		{
#ifdef ENABLE_MOUNT_LIKE_HORSE
			if (GetMountVnum() != dwVnum)
				m_chHorse->SetPolymorph(dwVnum);
#endif
			return;
		}

/*Example
void CHARACTER::HorseSummon(bool bSummon, bool bFromFar, DWORD dwVnum, const char* pPetName)
{
#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (const LPITEM pMountItem = GetWear(WEAR_COSTUME_MOUNT))
		dwVnum = pMountItem->GetValue(1);
#endif
	if (bSummon)
	{
		// NOTE: If you summon and there is already a horse, it will do nothing.
		if (m_chHorse)
		{
#ifdef ENABLE_MOUNT_LIKE_HORSE
			if (GetMountVnum() != dwVnum)
				m_chHorse->SetPolymorph(dwVnum);
#endif
			return;
		}
*/

// then search:

			UpdatePacket();
		}

		PointChange(POINT_ST, 0);
		PointChange(POINT_DX, 0);
		PointChange(POINT_HT, 0);
		PointChange(POINT_IQ, 0);

// and add under, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
		RemoveAffect(AFFECT_MOUNT_BONUS);
#endif

/// 2.) Search in LPCHARACTER CHARACTER::GetRider() const:

void CHARACTER::HorseSummon(bool bSummon, bool bFromFar, DWORD dwVnum, const char* pPetName)
{

// and add at the init, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (const LPITEM pMountItem = GetWear(WEAR_COSTUME_MOUNT))
		if (CMobVnumHelper::IsMount(pMountItem->GetValue(1)))
			dwVnum = pMountItem->GetValue(1);
#endif

/*Example:
void CHARACTER::HorseSummon(bool bSummon, bool bFromFar, DWORD dwVnum, const char* pPetName)
{
#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (const LPITEM pMountItem = GetWear(WEAR_COSTUME_MOUNT))
		dwVnum = pMountItem->GetValue(1);
#endif

	if (bSummon)
	{...
*/

/// 3.) Search in void CHARACTER::HorseSummon(bool bSummon, bool bFromFar, DWORD dwVnum, const char* pPetName):

			m_chHorse->m_stName += LC_TEXT("´ÔÀÇ ¸»");

// and replace with:

#ifdef ENABLE_MOUNT_LIKE_HORSE
			m_chHorse->m_stName += LC_TEXT(CMobVnumHelper::IsMount(dwVnum) ? "'s Mount" : "´ÔÀÇ ¸»");
#else
			m_chHorse->m_stName += LC_TEXT("´ÔÀÇ ¸»");
#endif

/*Example:
		if (pHorseName && strlen(pHorseName) != 0)
			m_chHorse->m_stName = pHorseName;
		else
		{
			m_chHorse->m_stName = GetName();
#ifdef ENABLE_MOUNT_LIKE_HORSE
			m_chHorse->m_stName += LC_TEXT(CMobVnumHelper::IsMount(dwVnum) ? "'s Mount" : "´ÔÀÇ ¸»");
#else
			m_chHorse->m_stName += LC_TEXT("´ÔÀÇ ¸»");
#endif
		}
*/

/// 4.) Add at the end of the file:

#ifdef ENABLE_MOUNT_LIKE_HORSE
void CHARACTER::CheckEnterMount()
{
	if (GetHorse()) // If is already summoned, do nothing
		return;

	if (const auto pMountItem = GetWear(WEAR_COSTUME_MOUNT))
		HorseSummon(true, false, pMountItem->GetValue(1));
}

void CHARACTER::CalcMountBonusBySeal(const LPITEM pMountItem)
{
	if (!GetMountVnum() || !pMountItem || !pMountItem->IsMount())
		return;

	RemoveAffect(AFFECT_MOUNT_BONUS);
	for (int i = 0; i < ITEM_APPLY_MAX_NUM; ++i) {
		if (pMountItem->GetProto()->aApplies[i].bType == APPLY_NONE || pMountItem->GetValue(1) == 0)
			continue;
		AddAffect(AFFECT_MOUNT_BONUS, aApplyInfo[pMountItem->GetProto()->aApplies[i].bType].bPointType, pMountItem->GetProto()->aApplies[i].lValue, AFF_NONE, INFINITE_AFFECT_DURATION, 0, false);
	}
}
#endif