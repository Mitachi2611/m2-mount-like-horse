/// 1.) Search:

};

ESex GET_SEX(LPCHARACTER ch);

// and add before, this:

#ifdef ENABLE_MOUNT_LIKE_HORSE
	public:
		void CheckEnterMount();
#endif

// like:
/*

#ifdef ENABLE_MOUNT_LIKE_HORSE
	public:
		void CheckEnterMount();
#endif
};

ESex GET_SEX(LPCHARACTER ch);
#endif
*/