import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_17144 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] str = br.readLine().split(" ");
		
		int R = Integer.parseInt(str[0]);
		int C = Integer.parseInt(str[1]);
		int T = Integer.parseInt(str[2]);
		
		int[][] map = new int[R][C];
		
		int airR = 0;
		int airC = 0;
		
		for (int i = 0; i < R; i++) {
			str = br.readLine().split(" ");
			for (int j = 0; j < C; j++) {
				map[i][j] = Integer.parseInt(str[j]); 
				if (map[i][j] == -1) {
					airR = i;
					airC = j;
				}
			}
		}
		
		int[] dr = {0, 0, 1, -1};
		int[] dc = {1, -1, 0, 0};
		
		int turn = 0;
		while (turn < T) {
			int[][] nextMap = new int[R][C];
			
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (map[i][j] != 0) {
						int dir = 0;
						for (int k = 0; k < 4; k++) {
							int nextR = i + dr[k];
							int nextC = j + dc[k];
							
							if(nextR >= 0 && nextR < R && nextC >= 0 && nextC < C && map[nextR][nextC] != -1) {
								nextMap[nextR][nextC] += map[i][j]/5;
								dir++;
							}
						}
						nextMap[i][j] += map[i][j] - (map[i][j]/5)*dir;
					}
				}
			}
			
			
						
			for (int i = airR-2; i > 0; i--) {
				nextMap[i][airC] = nextMap[i-1][airC]; 
			}
			
			for (int i = airC; i < C-1; i++) {
				nextMap[0][i] = nextMap[0][i+1];
			}
			
			for (int i = 0; i < airR-1; i++) {
				nextMap[i][C-1] = nextMap[i+1][C-1];
			}
			
			for (int i = C-1; i > airC+1; i--) {
				nextMap[airR-1][i] = nextMap[airR-1][i-1];
			}
			
			nextMap[airR-1][airC+1] = 0;
			
			
			for (int i = airR+1; i < R-1; i++) {
				nextMap[i][airC] = nextMap[i+1][airC];
			}
			
			for (int i = airC; i < C-1; i++) {
				nextMap[R-1][i] = nextMap[R-1][i+1];
			}
			
			for (int i = R-1; i > airR; i--) {
				nextMap[i][C-1] = nextMap[i-1][C-1];
			}
			
			for (int i = C-1; i > airC+1 ; i--) {
				nextMap[airR][i] = nextMap[airR][i-1];
			}
			
			nextMap[airR][airC+1] = 0;
			
			turn++;
			
			nextMap[airR-1][airC] = -1;
			nextMap[airR][airC] = -1;
			
//			System.out.println();
//			System.out.printf("turn:%d =============\n", turn);
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					map[i][j] = nextMap[i][j];
//					System.out.printf("%d ", map[i][j]);
				}
//				System.out.println();
			}
//			System.out.println("=============\n\n");
			
			
		}
		
		int sum = 2;
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				sum += map[i][j];
			}
		}
		
		System.out.println(sum);

	}
}
