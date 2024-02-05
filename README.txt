Copr. Mitachi

Pros:
- Fewer lines of code (50 or so, versus 1200+ in the public system)
- By not using apply_type and value to assign the monster to ride, we will not lose a usable bonus
- Being horse-based, trivially it is code that has been tested for years.
- If you are on the mount and warp, you will still be on the mount at login (being that we use EnterHorse)
- You can take advantage of the horse name system with a few modifications
- You only get mount bonuses if you are riding it and not while it is summoned

Cons:
- I couldn't find any

USAGE:
	Put the mount vnum in the seal item's value1.
	You can remove ride.quest or whatever quest you're using for mounts.