// Search:

		DWORD	GetSIGVnum() const
		{
			return m_dwSIGVnum;
		}

// add under, this:

// #ifdef ENABLE_MOUNT_COSTUME
		const bool	IsMount() { return GetType() == ITEM_COSTUME && GetSubType() == COSTUME_MOUNT; }
// #endif