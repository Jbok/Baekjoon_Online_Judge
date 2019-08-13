import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_2629 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		int N = Integer.parseInt(br.readLine());
		int[] weights = new int[N+1];
		
		String str = br.readLine();
		for (int i = 1; i <= N; i++) {
			weights[i] = Integer.parseInt(str.split(" ")[i-1]);
		}
		
		
		int M = Integer.parseInt(br.readLine());
		int[] targets = new int[M];
		str = br.readLine();
		for (int j = 0; j < M; j++) {
			targets[j] = Integer.parseInt(str.split(" ")[j]);
		}
		
		int[][] dp = new int[31][40001];
		dp[0][15000] = 1;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= 15000; j++) {
				for (int k = -1; k <= 1; k++) {
					int weight = weights[i]*k;
					if (j+weight >= 0) {
						dp[i][j] += dp[i-1][j+weight];
					}
				}
			}
		}
		
		for (int i = 0; i < M; i++) {
//			System.out.println("targets[i]: " + targets[i]);
//			System.out.println(dp[0][15000]);
			
			if (dp[N][15000+targets[i]] == 0) {
				System.out.print("N ");
			}else {
				System.out.print("Y ");
			}
		}
		
	}
}
