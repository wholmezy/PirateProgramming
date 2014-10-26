import java.util.ArrayList;


/*
 * Frans 307
 */


public class eliminatePlayers {
	public int eliminate(int rounds, ArrayList<Integer> numPlayers){
		
		while(numPlayers.size() > 1){
			int z = 0;
			for(int i = 0; i < rounds; i++){
				z++;
				int x = numPlayers.size();
				if(z >= x){
					z = 0;
				}
			}
			numPlayers.remove(z);
		}
		int result = numPlayers.get(0);
		return result;
	}
}
