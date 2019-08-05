import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.List;

public class Main_5397 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int testCase = Integer.parseInt(br.readLine());
		for (int tc = 0; tc <testCase; tc++) {
			String str = br.readLine();
			
			List<Character> ll = new LinkedList<Character>();
//			HashMap<Character, V>
			int idx = 0;
			int len = 0;
			for (int i = 0; i < str.length(); i++) {
				char c = str.charAt(i);
//			for (char c : str.toCharArray()) {
				switch (c) {
				case '<':
					if(idx > 0) {
						idx--;
					}
					
					break;
				case '>':
					if (idx < len) {
						idx++;
					}
					break;
				case '-':
					if (idx > 0) {
						ll.remove(--idx);
						len--;
					}
					break;
				default:
					ll.add(idx, c);
					len++;
					idx++;
					break;
				}
			}
			
			
			
			for (Character c : ll) {
				bw.append(c);
			}
			bw.append('\n');
			bw.flush();
		}
		
	}
}
