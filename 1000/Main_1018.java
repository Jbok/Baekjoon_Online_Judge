import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_1018 {
	static int min = 64;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] str = br.readLine().split(" ");
		
		int N = Integer.parseInt(str[0]);
		int M = Integer.parseInt(str[1]);
		
		boolean[][] board = new boolean[N][M];
		boolean[][] boardR = new boolean[N][M];
		
		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < M; j++) {
				// White True
				// Black False
				if (s.charAt(j) == 'W'){
					board[i][j] = true;
				} else {
					board[i][j] = false;
				}
			}
		}
		
		for (int row = 0; row <= N-8; row++) {
			for (int col = 0; col <= M-8; col++) {
				int sum = 0;
				int sumR = 0;
				boolean s = true;
				boolean sR = false;
				
				for (int i = row; i < row+8; i++) {
					for (int j = col; j < col+8; j++) {
						if (board[i][j] == s) {
							sum++;
						}
						
						if (board[i][j] == sR) {
							sumR++;
						}
						
						s = !s;
						sR = !sR;
					}
					s = !s;
					sR = !sR;
				}
				
				if (64-sum < min) {
					min = 64-sum;
				}
				
				if (64-sumR < min) {
					min = 64-sumR;
				}
			}
		}
		
		System.out.println(min);
	}
}
