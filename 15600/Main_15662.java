import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;

class Main_15662{
	
	static void rotate (int dir, Deque<Integer> dq) {
		if (dir == 1) {
			// 시계방향
			dq.addFirst(dq.pollLast());
		} else {
			// 반시계 방향
			dq.addLast(dq.pollFirst());
		}
	}

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		Deque<Integer>[] dq = new Deque[T+1];
		
		for (int i = 1; i <= T; i++) {
			String str = br.readLine();
			dq[i] = new LinkedList<>();
			for (int j = 0; j < 8; j++) {
				dq[i].addLast(str.charAt(j)-'0');
			}
		}
		
		int K = Integer.parseInt(br.readLine());
		
		int[] num = new int[K];
		int[] dirs = new int[K];
		
		for (int i = 0; i < K; i++) {
			String[] str = br.readLine().split(" ");
			num[i] = Integer.parseInt(str[0]);
			dirs[i] = Integer.parseInt(str[1]);
		}
		
		for (int i = 0; i < K; i++) {
			int target = num[i];
			int dir = dirs[i];

			int targetRight = target+1;
			int dirR = dir*-1;
			// 오른쪽
			while (targetRight < T+1) {
				int[] arr = new int[8];
				for (int j = 0; j < 8; j++) {
					arr[j] = dq[target].pollFirst();
				}
				
				for (int j = 0; j < 8; j++) {
					dq[target].addLast(arr[j]);
				}
				
				// 바퀴 구하기
				int[] arrR = new int[8];
				for (int j = 0; j < 8; j++) {
					arrR[j] = dq[targetRight].pollFirst();
				}
				
				for (int j = 0; j < 8; j++) {
					dq[targetRight].addLast(arrR[j]);
				}

				if (arr[2] != arrR[6]) {
					target = targetRight;
					targetRight += 1;
				} else {
					break;
				}
			}
			
			for (int r = num[i]+1; r < targetRight; r++) {
				rotate(dirR, dq[r]);
				dirR = dirR*-1;
			}
			
			target = num[i];
			dir = dirs[i];
			
			int targetLeft = target-1;
			int dirL = dir*-1;
			// 왼쪽
			while (targetLeft > 0) {
				int[] arr = new int[8];
				for (int j = 0; j < 8; j++) {
					arr[j] = dq[target].pollFirst();
				}
				
				for (int j = 0; j < 8; j++) {
					dq[target].addLast(arr[j]);
				}
				
				// 바퀴 구하기
				int[] arrL = new int[8];
				for (int j = 0; j < 8; j++) {
					arrL[j] = dq[targetLeft].pollFirst();
				}
				
				for (int j = 0; j < 8; j++) {
					dq[targetLeft].addLast(arrL[j]);
				}

				if (arr[6] != arrL[2]) {
					target = targetLeft;
					targetLeft -= 1;
				} else {
					break;
				}
			}
			
			for (int l = num[i]-1; l > targetLeft; l--) {
				rotate(dirL, dq[l]);
				dirL = dirL*-1;
			}
			
			rotate(dirs[i], dq[num[i]]);
			
			
		}
		
		int sum = 0;
		for (int i = 1; i <= T; i++) {
			if (dq[i].peek() == 1) {
				sum++;
			}
		}
		System.out.println(sum);
	}
}

































