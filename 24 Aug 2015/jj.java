
import java.util.Scanner;

public class SherlockAndAnagrams {

	public static void main(String[] args) {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */

		Scanner sc = new Scanner(System.in);
		int num = Integer.parseInt( sc.nextLine());

		String inputStr = null;
		for(int i =0;  i< num; i++ ){
			inputStr = sc.nextLine(); //check null
			debug(inputStr);
			System.out.println( findNumberOfAnagramicPairs(inputStr));
		}

	}


	public static int findNumberOfAnagramicPairs(String inputStr){
		int numOfPairs = 0;
		String subString = "";
		int startPos = 0;
		int len = 1;

		while( startPos < inputStr.length() ){

			while( startPos + len < inputStr.length()){
				{
					subString = getNextSubString(inputStr, startPos, len);//null for breaking the loop
					if( findAnagramicPair( subString, inputStr) ){
						numOfPairs++;
					}

				}
				len++;
			}
			len = 1;
			startPos++;
		}

		return numOfPairs;
	}

	private static String getNextSubString(String inputStr, int startPos, int len){

		if( inputStr == null || inputStr.isEmpty() || inputStr.length() < len || startPos > len || startPos < 0){
			return null;
		}
		else{
			return inputStr.substring(startPos, startPos+len);
		}


	}

	private static boolean findAnagramicPair(String subString, String inputStr) {

		if(subString==null){
			return false;
		}

		StringBuilder sb =  new StringBuilder(subString);

		String revStr = sb.reverse().toString();

		    //avoid checking against itself:
			int pos1 = inputStr.indexOf(subString);
			String inputStr2 = inputStr.substring(pos1 +1);

			boolean isFound = inputStr2.contains(revStr) ;

			debug(">>> " + subString + "/" + inputStr2 + "  VS " + revStr + "  found: " + isFound);

			return (isFound );
	}




	private static void debug(final String str){
		//  System.out.println(str);
	}

}



