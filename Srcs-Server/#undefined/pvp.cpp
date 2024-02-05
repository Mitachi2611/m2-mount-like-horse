// Search:

#include "locale_service.h"

// add under, this:

#include "../../common/VnumHelper.h"

// Search:

	if( true == pkChr->IsHorseRiding() )
	{
		if( pkChr->GetHorseLevel() > 0 && 1 == pkChr->GetHorseGrade() ) 
			return false;
	}
	else
	{
	
		if(!g_bAllMountAttack)
		{
			switch( pkChr->GetMountVnum() )
			{
				case 0:
				case 20030:
				....
			}
		}
	}

// and replace with:

	if (pkChr->IsHorseRiding())
	{
		if (pkChr->GetHorseLevel() > 0 && 1 == pkChr->GetHorseGrade()) 
			return false;
	}
	else {
		const auto mountVnum = pkChr->GetMountVnum();
		if (mountVnum != 0 && !CMobVnumHelper::IsMount(mountVnum))
			return false;
	}

/*
NOTE: Make sure that all the cases you had in the switch,
are present in the new IsMount method added in VnumHelper.h

Also: g_bAllMountAttack comes from novaline, however if you have mainline replace the if/else statement anyway.
*/