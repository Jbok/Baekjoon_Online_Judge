import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main_17136 {
	static boolean[][] map = new boolean[10][10];
	static boolean[][] visit = new boolean[10][10];
	
	static int[] arr = new int[6];
	static boolean isPossible(int r, int c, int n) {
		if (r+n <= 10 && c+n <= 10) {
			for (int i = r; i < r+n; i++) {
				for (int j = c; j < c+n; j++) {
					if (map[i][j] == false) {
						return false;
					}
				}
			}			
			return true;
		}
		return false;
	}
	static int min = Integer.MAX_VALUE;
	
	static void f(int n) {
//		System.out.println(Arrays.toString(arr));
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += arr[i];
			if (arr[i] > 5 || sum >= min) {
				return;
			}
		}
	
		if (n == 100) {
			int ssum = 0;
			for (int i = 0; i < 6; i++) {
				ssum += arr[i];
				
			}
			min = ssum;
			return;
		}

		int r = n/10;
		int c = n%10;
//		System.out.println(r+","+c);
		if (map[r][c] == false) { 
//			System.out.println("false");
			f(n+1);
		} else {
			for (int N = 5; N >= 1; N--) {
				if (isPossible(r, c, N)) {
					
//					for (int i = 0; i < 10; i++) {
//						for (int j = 0; j< 10 ;j++) {
//							if (map[i][j]) {
//								if (r==2 && c==6)System.out.printf("%d ", 1);
//							}else {
//								if (r==2 && c==6)System.out.printf("%d ", 0);
//							}
//						}
//						if (r==2 && c==6)System.out.println();
//					}
					
					for (int i = r; i < r+N; i++) {
						for (int j = c; j < c+N; j++){
							map[i][j] = false;
						}
					}
//					if (r==2 && c==6)System.out.println("=================");
//					for (int i = 0; i < 10; i++) {
//						for (int j = 0; j< 10 ;j++) {
//							if (map[i][j]) {
//								if (r==2 && c==6)System.out.printf("%d ", 1);
//							}else {
//								if (r==2 && c==6)System.out.printf("%d ", 0);
//							}
//						}
//						if (r==2 && c==6)System.out.println();
//					}
					
//					System.out.println("N: "+N);
					arr[N]++;
					f(n+1);
					arr[N]--;
								
					for (int i = r; i < r+N; i++) {
						for (int j = c; j < c+N; j++){
							map[i][j] = true;
						}
					}
				}
			}
		
		}	
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for (int i = 0; i < 10; i++) {
			String[] s = br.readLine().split(" ");
			for (int j = 0; j < 10; j++) {
				if (s[j].equals("0")) {
					map[i][j] = false;
				} else {
					map[i][j] = true;
				}
			}
		}
		
		visit[0][0] = true;
		f(0);
		System.out.println(min == Integer.MAX_VALUE ? -1 : min);
		
		
	}
}
