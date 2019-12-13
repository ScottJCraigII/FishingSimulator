# FishingSimulator 

Man -		'#',
		1	moves up to 4 spaces randomly  between every cast
		2	casts up to 5 times a day
		3	casts that are out of bounds take one of the cast actions
		4	can cast up to 2 spaces away
		
Fish - 	1	changes display char to 's','M','L' depending on weight
		2	moves at the end of each day up one space in row and one in column
		3	gains weight based on size (smaller fish grow faster) every off season
		4	fish breed in the offseason
		5	fish breeding eligiblity based on sex 
		6	fish breeding based limited by size
		
Pond - 	1	inherits size from World
		2	it expands the limits of the 2d World, by allowing multiple fish to occupy 
				the same grid square, effectively turning it into a 3d array
		3	controls the limits of fish/man movement
		4	controls the interaction betweer man and fish
		
	This Simulation starts with a freshly stocked pond and a man that likes to fish.
Everyday during fishing season, he goes out in his boat and tries to catch fish. He casts 
five times a day and keeps fish that are large enough.
	At the end of the day the fish swim to a new spot in the pond waiting to be caught.
When the season ends, the fish grow and search for a mate and make baby fish. Over time,
the fisherman becomes more and more successful as the fish become more plentiful and grow.
		
	The best part of this simulation, is that it easily converts into a game! 
the UI could ask the user for boat movements and overload the random functions 
ie : sail() into sail(int row, int col), and cast() into cast (int row, int col)
and all work with all the available methods.  This simulation works with a larger 
grid without modification.
	
