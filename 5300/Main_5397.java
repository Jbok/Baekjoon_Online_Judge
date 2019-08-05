import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Deque;
import java.util.LinkedList;

public class Main_5397 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int testCase = Integer.parseInt(br.readLine());
		for (int tc = 0; tc <testCase; tc++) {
			String str = br.readLine();
			
//			List<Character> ll = new LinkedList<Character>();
//			HashMap<Character, V>
			
			Deque<Character> dqLeft = new LinkedList<>();
			Deque<Character> dqRight = new LinkedList<>();
		
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
//			for (char c : str.toCharArray()) {
				switch (c) {
				case '<':
					if (!dqLeft.isEmpty()) {
						dqRight.addFirst(dqLeft.pollLast());
					}
					break;
				case '>':
					if (!dqRight.isEmpty()) {
						dqLeft.addLast(dqRight.pollFirst());
					}
					break;
				case '-':
					if (!dqLeft.isEmpty()) {
						dqLeft.pollLast();
					}
					break;
				default:
					dqLeft.addLast(c);
					break;
				}
			}
			
			
			
			for (Character c : dqLeft) {
				bw.append(c);
			}
			for (Character c : dqRight) {
				bw.append(c);
			}
			bw.append('\n');
			bw.flush();
		}
		
	}
}
