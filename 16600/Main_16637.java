import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_16637 {

	static int N;
	static char[] crr = new char[20];
	static int MAX = Integer.MIN_VALUE;
	static public void makeCombination(int n, int r, int len, int[] check) {
		
		if (r > n) {
			char[] cTemp = new char[20];
			for (int i = 0; i < 20; i++) {
				cTemp[i] = crr[i];
			}
			
			for (int i = 0; i < len; i++) {
//				System.out.printf("%d ", check[i]);
				int oper = check[i]*2 + 1;
				int left = oper - 1;
				int right = oper + 1;
				
				int val = 0;
				
				switch (cTemp[oper]) {
				case '+':
					val = (cTemp[left]-'0') + (cTemp[right]-'0');
					break;
				case '*':
					val = (cTemp[left]-'0') * (cTemp[right]-'0');
					break;
				case '-':
					val = (cTemp[left]-'0') - (cTemp[right]-'0');
					break;
				}
				
				cTemp[left] = (char) (val + (int)'0');
				cTemp[oper] = '+';
				cTemp[right] = '0';
			}
			

			int sum = cTemp[0]-'0';
			
			for (int i = 1; i < N; i = i+2) {
				switch (cTemp[i]) {
				case '+':
					sum += cTemp[i+1] - '0';
					break;
				case '*':
					sum *= cTemp[i+1] - '0';
					break;
				case '-':
					sum -= cTemp[i+1] - '0';
					break;
				}
			}
			
			if (sum > MAX) {
				MAX = sum;
			}
			return;
		}
		
		makeCombination(n, r+1, len, check);
		check[len] = r;
		makeCombination(n, r+2, len+1, check);
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		String str = br.readLine();
		for (int i = 0; i < str.length(); i++) {
			crr[i] = str.charAt(i);
		}
		
		int[] check = new int[20];
		makeCombination(N/2-1, 0, 0, check);
		System.out.println(MAX);
	}
}
