import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//import java.util.Arrays;

public class Main_2468 {
	
	static int N;
	static int[][] map;
	static boolean[][] check;
	
	static int[] dr = {0, 0, 1, -1};
	static int[] dc = {1, -1, 0, 0};
	
	static void f(int r, int c, int height) {

		for (int i = 0; i < 4; i++) {
			int nextR = r + dr[i];
			int nextC = c + dc[i];
			
			if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < N && !check[nextR][nextC] && map[nextR][nextC] > height) {
				check[nextR][nextC] = true;
				f(nextR, nextC, height);
			}
		}
		
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(str.split(" ")[j]);
			}
		}
		
		int sum = 0;
		for (int h = 0; h <= 100; h++) {
			int cnt = 0;
			check = new boolean[N][N];
			
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (!check[i][j] && map[i][j] > h) {
						cnt++;
						check[i][j] = true;
						f(i, j, h);
					}
				}
			}
			
//			System.out.println("height: "+h);
//			System.out.println(sum);
//			for (int i = 0; i < N; i++) {
//				System.out.println(Arrays.toString(check[i]));
//			}
//			
			if (cnt > sum) {
				sum = cnt;
			}
		}
		
		System.out.println(sum);
		
		
	}
}
