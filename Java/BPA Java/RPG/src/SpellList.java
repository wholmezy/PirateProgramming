import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;

//Frans #307

public class SpellList {
	public static void main(String[] args){
		
		
		try{
			//Counter for number of lines to make things easier..
			int lines = 0;
			//Open textfile located in ------------------------------------------------------------------------------------------------V
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Wholm_000\\Dropbox\\Eclipse Java Workspace\\RPG\\bin\\spells.txt"));
			//Count number of lines
			while (br.readLine() != null) {
			    lines++;
			}
			//Print number of lines
			System.out.println("There is " + lines + " spells");	
			
			
			
			//if args exists take it and display that number of lines
			if(args.length == 1){
				if(isInteger(args[0]) != true){
					System.err.println("\nARGUMENT IS NOT INTEGER!!!!");
					System.exit(0);
				}
				//Print the number args times.
				for(int i = 0; i < Integer.parseInt(args[0]); i++){
					BufferedReader br2 = new BufferedReader(new FileReader("C:\\spells.txt"));
					Random rand = new Random();
					int Randomizer = rand.nextInt(lines) + 1;
					String buffer = "error";
					for(int j = 0; j < Randomizer; j++){
						buffer = br2.readLine();
						if(buffer == null){
							buffer = "666 erase from existance.";
							break;
						}
					}
					System.out.println(buffer);
					br2.close();
				}
			}
			else{
				Random rand = new Random();
				int Randomizer = rand.nextInt(lines) + 1;
				BufferedReader br3 = new BufferedReader(new FileReader("C:\\spells.txt"));
				String buffer = "error";
				for(int i = 0; i < Randomizer; i++){
					buffer = br3.readLine();
					if(buffer == null){
						buffer = "666 erase from existance.";
						break;
					}
				}
				System.out.println(buffer);
				br3.close();
			}
			br.close();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	public static boolean isInteger(String s) {
	    try { 
	        Integer.parseInt(s); 
	    } catch(NumberFormatException e) { 
	        return false; 
	    }
	    // only got here if we didn't return false
	    return true;
	}
}
