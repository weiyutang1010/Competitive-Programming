import java.io.*;
import java.util.*;
public class WormholeInputValidator {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		assertInRange(t, 1, 10, "Number of test cases not in bounds");
		for(int a = 0; a < t; a++) {
			int n = Integer.parseInt(br.readLine());
			assertInRange(n, 1, 60, "N out of bounds");
			String[] list = new String[n];
			int[] y = new int[n];
			int[] x = new int[n];
			int[] z = new int[n];
			Set<String> set = new HashSet<String>();
			Set<State> locs = new HashSet<State>();
			for(int i = 0; i < n; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				list[i] = st.nextToken();
				x[i] = Integer.parseInt(st.nextToken());
				y[i] = Integer.parseInt(st.nextToken());
				z[i] = Integer.parseInt(st.nextToken());
				if(st.hasMoreTokens()) throw new RuntimeException("Extra data on line");
				assertInRange(x[i], 0, 2000000, "x not in bounds");
				assertInRange(y[i], 0, 2000000, "x not in bounds");
				assertInRange(z[i], 0, 2000000, "x not in bounds");
				assertValidPlanet(list[i]);
				if(!set.add(list[i])) throw new RuntimeException("Duplicate planet name");
				if(!locs.add(new State(x[i], y[i], z[i]))) throw new RuntimeException("Duplicate planet location");
			}
			int w = Integer.parseInt(br.readLine());
			assertInRange(w, 0, 40, "wormhole bad");
			for(int i = 0; i < w; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				String aa = st.nextToken();
				String bb = st.nextToken();
				if(st.hasMoreTokens()) throw new RuntimeException("Extra data on line");
				if(!set.contains(aa) || !set.contains(bb)) throw new RuntimeException("Illegal wormhole");
			}
			int tt = Integer.parseInt(br.readLine());
			assertInRange(tt, 1, 20, "queries bad");
			for(int i = 0; i < tt; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				String aa = st.nextToken();
				String bb = st.nextToken();
				if(st.hasMoreTokens()) throw new RuntimeException("Extra data on line");
				if(!set.contains(aa) || !set.contains(bb)) throw new RuntimeException("Illegal query");
			}
		}
		assertNoExtraData(br);
	}
	
	static class State {
		public int x,y,z;

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			result = prime * result + z;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			if (z != other.z)
				return false;
			return true;
		}

		public State(int x, int y, int z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}
		
	}
	
	public static void assertValidPlanet(String s) {
		assertInRange(s.length(), 1, 50, "Bad length");
		if(!Character.isLetter(s.charAt(0))) throw new RuntimeException("Not start with letter");
		for(int i = 0; i < s.length(); i++) {
			if(!Character.isLetterOrDigit(s.charAt(i))) throw new RuntimeException("Illegal char");
		}
	}
	
	public static void assertNoExtraData(BufferedReader br) throws IOException {
		if(br.ready()) {
			throw new RuntimeException("Extra data found at end of file");
		}
	}
	public static void assertInRange(int variable, int min, int max, String error) {
		if(variable < min || variable > max) {
			throw new RuntimeException(error + ": " + variable);
		}
	}
}

