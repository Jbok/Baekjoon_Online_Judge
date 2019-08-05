import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;

public class Main_1966 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testCase = Integer.parseInt(br.readLine());
		
		for (int tc = 0; tc < testCase; tc++) {
			String[] str = br.readLine().split(" ");
			int N = Integer.parseInt(str[0]);
			int M = Integer.parseInt(str[1]);
			
			int[] arr = new int[N];
			str = br.readLine().split(" ");
			
			Deque<Integer> dq = new LinkedList<>();
			
			for (int i = 0; i < N; i++) {
				arr[i] = Integer.parseInt(str[i]);
				dq.add(i);
			}
			
			
			int turn = 0;
			
			while (true) {
//				System.out.println("dq: "+dq);
//				System.out.println("ar: "+Arrays.toString(arr));
				int front = dq.peek();
				
				boolean flag = false;
				
				for (int j = 0; j < N; j++) {
					if (j == front) {
						
					} else {
						if (arr[front] < arr[j]) {
							dq.addLast(dq.pop());
							flag = true;
							break;
						}
					}
				}				
				
				
				
				if (flag == false) {
					int val = dq.pop();
					
					arr[val] = 0;
					turn++;
					if (val == M) {
						break;
					}
					
				}
				
			}
			
			System.out.println(turn);
		}
		
		
	}
}
