import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//import java.util.Arrays;

public class Main_17406 {
	
	static int[][] map;
	static int[][] mapT;
	
	static int Min = Integer.MAX_VALUE;
	static int N;
	static int M;
	
	static Node[] nodes;
	
	static class Node{
		int r;
		int c;
		int s;
		public Node(int r, int c, int s) {
			super();
			this.r = r;
			this.c = c;
			this.s = s;
		}
	}
	
	
	static void r(int r, int c, int len) {
		int temp = map[r-len][c-len];
		
		for (int i = r-len; i < r+len; i++) {
			map[i][c-len] = map[i+1][c-len];
		}
		
		for (int i = c-len; i < c+len; i++) {
			map[r+len][i] = map[r+len][i+1];
		}
		
		for (int i = r+len; i > r-len; i--) {
			map[i][c+len] = map[i-1][c+len];
		}
		
		for (int i = c+len; i > c-len+1; i--) {
			map[r-len][i] = map[r-len][i-1];
		}
		
		map[r-len][c-len+1] = temp;
	}
	
	static void rotation(int r, int c, int s) {
		for (int i = 1; i <= s; i++) {
			r(r, c, i);
		}
	}
	
	static void checkMin() {
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++) {
				sum += map[i][j];
			}
			if (sum < Min) {
				Min = sum;
			}
		}
	}
	
	static void combination(int idx, int end, int[] arr, boolean[] check) {
		if (idx == end) {
			for (int i = 0; i < end; i++) {
				int now = arr[i];
//				System.out.print(now+" ");
				rotation(nodes[now].r, nodes[now].c, nodes[now].s);
			}
			checkMin();
			for (int i = 0; i <= N; i++) {
				for (int j = 0; j <= M; j++) {
					map[i][j] = mapT[i][j];
				}
			}
//			System.out.println();
			return;
		}
		
		for (int i = 0; i < end; i++) {
			if (!check[i]) {
//				System.out.println("idx: "+idx);
//				System.out.println("end: "+end);
				arr[idx] = i;
				check[i] = true;
				combination(idx+1, end, arr, check);
				check[i] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		
		N = Integer.parseInt(str.split(" ")[0]);
		M = Integer.parseInt(str.split(" ")[1]);
		int K = Integer.parseInt(str.split(" ")[2]);
		
		map = new int[N+1][M+1];
		mapT = new int[N+1][M+1];
		for (int i = 1; i <= N; i++) {
			str = br.readLine();
			for (int j = 1; j <= M; j++) {
				map[i][j]  = Integer.parseInt(str.split(" ")[j-1]);
				mapT[i][j] = map[i][j];
			}
		}
		
		nodes = new Node[K];
		
		for (int k = 0; k < K; k++) {
			str = br.readLine();
			int r = Integer.parseInt(str.split(" ")[0]);
			int c = Integer.parseInt(str.split(" ")[1]);
			int s = Integer.parseInt(str.split(" ")[2]);
			
			nodes[k] = new Node(r, c, s);
		}

		boolean[] check = new boolean[K+1];
		int[] arr = new int[K+1];
		combination(0, K, arr, check);
		
		System.out.println(Min);
		
		
//		rotation(r, c, s);
//
//		
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= M; j++) {
//				map[i][j] = mapT[i][j];
//			}
//		}
	}
}
