/// 1.) Search:

};

ESex GET_SEX(LPCHARACTER ch);

// and add before, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	public:
		void CheckEnterMount();
		void CalcMountBonusBySeal(const LPITEM pMountItem);
#endif

// like:
/*

#ifdef ENABLE_MOUNT_LIKE_HORSE
	public:
		void CheckEnterMount();
		void CalcMountBonusBySeal(const LPITEM pMountItem);
#endif
};

ESex GET_SEX(LPCHARACTER ch);
#endif
*/