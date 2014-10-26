import java.util.ArrayList;
import java.util.Random;

/*
 * Frans 307
 */


public class Initialize{
	private int rounds;
	private ArrayList<Integer> array = new ArrayList<Integer>();
	
	public void setRounds(String numberOfRounds){
		if(numberOfRounds.equals("randomize") == true){
			Random rand = new Random();
			int number = rand.nextInt(100);
			rounds = number;
		}
		else{
			rounds = Integer.parseInt(numberOfRounds);
		}
	}
	
	public int getRounds(){
		return rounds;
	}
	
	public ArrayList<Integer> getArray(){
		return array;
	}
	
	public void setArray(int numPlayers){
		for(int i = 0; i < numPlayers; i++){
			array.add(i);
		}

	}
	
}
