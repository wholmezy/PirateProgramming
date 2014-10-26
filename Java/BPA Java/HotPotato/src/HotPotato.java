import java.util.ArrayList;

/*
 * Frans 307
 */

public class HotPotato {
	public static void main(String[] args){
		
		if(args.length > 2){
			System.out.println(">> Proper usage: java program players rounds");
			System.exit(0);
		}
		else if(args.length < 2){
			System.out.println(">> Proper usage: java program players rounds");
			System.exit(0);
		}
		
		ArrayList<Integer> numPlayers = new ArrayList<Integer>();

		Initialize init = new Initialize();
		
		init.setRounds(args[1]);
		
		int rounds = init.getRounds();
		
		init.setArray(Integer.parseInt(args[0]));
		
		numPlayers = init.getArray();
		
		System.out.println(">> Starting game with " + numPlayers.size() + " Players");
		System.out.println(">> Eliminating a player every " + rounds + " passes");
		
		eliminatePlayers game = new eliminatePlayers();
		
		int result = game.eliminate(rounds, numPlayers);
		
		System.out.println(">> WINNER: Player " + result);
	}
}
