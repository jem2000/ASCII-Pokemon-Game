# ASCII-Pokemon-Game
A Pokemon game created with a simple ASCII grid that involves functionalities of moving, training, battling, recovering health, and Pokemon trading. Created in EC327


To move, type m followed by the ID of the pokemon and the coordinates you want to move to. For example, m 1 20 20 will move pokemon 1 to location 20,20.
Moving around generates Pokedollars, but costs stamina. If your stamina reaches 0, that pokemon can no longer be used.
You can recover stamina at the cost of Pokedollars at the Pokemon Center ('c') or you can win money and experience points by training at the Pokemon Gym ('g')
Once your pokemon are sufficiently trained, you can go defeat rivals in the Battle Arena. 
To enter the various buildings, use 'c', 'g', or 'a' followed by the ID of the pokemon, followed by the ID of the building. For example, c 1 1 will move pokemon 1 to center 1.
While in the appropriate building, you can use 'r' to recover, 't' to train, or 'b' to battle. Use the letter following by the pokemon ID,followed by the amount of currency wanted.
For example, r 1 10 will cause pokemon 1 to recover 10 health points if you are in the Pokemon Center and have enough Pokedollars. 
While in battle, advancing the time will cause you to be prompted to choose a move. Select a number to use different moves!
All commands take time once entered, to advance the time by one step, use v, to advance it by five steps, use x. Use s to cancel commands.
As a bonus, there is also a trading hub! Use 'h' to move to the hub, then 'j' followed by the pokemon ID to trade your pokemon for a new one. Remember your new pokemon might have a different ID!
Use 'q' to quit the game. 
AI mode activates RivalAI, who will play the game much like you will. Try to level up before he does!
To win, beat all the gyms! Defeating rivals isn't necessary, but battles are fun! You'll lose if all your pokemon run out of stamina.
