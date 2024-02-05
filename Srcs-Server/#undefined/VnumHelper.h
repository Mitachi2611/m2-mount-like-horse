// Search:

	static	bool	IsPhoenix(DWORD vnum)				{ return 34001 == vnum; }

// add under, this:

	static	bool	IsMount(DWORD vnum) {
		switch (vnum) {
		case 20030: case 20110: case 20111: case 20112: case 20113: case 20114: case 20115:
		case 20116: case 20117: case 20118: case 20205: case 20206: case 20207: case 20208:
		case 20209: case 20210: case 20211: case 20212: case 20119: case 20219: case 20220:
		case 20221: case 20222: case 20120: case 20121: case 20122: case 20123: case 20124:
		case 20125: case 20214: case 20215: case 20217: case 20218: case 20224: case 20225:
		case 20226: case 20227:
			return true;
		default:
			return false;
		}
	}

// If you are sick:
	static constexpr bool IsMount(const DWORD& vnum) noexcept {