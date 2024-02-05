/// 1.) Search in bool CHARACTER::MoveItem(TItemPos Cell, TItemPos DestCell, BYTE count):

	if (!CanHandleItem())
	{
		if (NULL != DragonSoul_RefineWindow_GetOpener())
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("°­È­Ã¢À» ¿¬ »óÅÂ¿¡¼­´Â ¾ÆÀÌÅÛÀ» ¿Å±æ ¼ö ¾ø½À´Ï´Ù."));
		return false;
	}

// and add under, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (item->IsMount() && item->IsEquipped() && DestCell.IsDefaultInventoryPosition()) {
		StopRiding();
		HorseSummon(false);
	}
#endif

/// 2.) Search in bool CHARACTER::SwapItem(BYTE bCell, BYTE bDestCell):

		item1->AddToCharacter(this, TItemPos(INVENTORY, bCell2));
		item2->AddToCharacter(this, TItemPos(INVENTORY, bCell1));
	}

// and add under, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (item1->IsMount() && item2->IsMount() && destCell.IsEquipPosition()) {
		HorseSummon(false);
		HorseSummon(true);
	}
#endif

/// 3.) Search in bool CHARACTER::UnequipItem(LPITEM item):

	if (!CanUnequipNow(item))
		return false;

// and add before, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (item->IsMount()) {
		StopRiding();
		HorseSummon(false);
	}
#endif

/// 4.) in bool CHARACTER::EquipItem(LPITEM item):

// before the final "return true;", add this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	if (item->IsMount())
		HorseSummon(true);
#endif