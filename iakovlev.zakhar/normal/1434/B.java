import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair implements Comparable<Pair> {
		long x;
		long y;

		public Pair(long x, long y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			if (x > o.x) {
				return 1;
			}
			if (x < o.x) {
				return -1;
			}
			if (y > o.y) {
				return 1;
			}
			if (y < o.y) {
				return -1;
			}
			return 0;
		}

	}

	public class Fenvik {
		int[] sum;

		public Fenvik(int n) {
			sum = new int[n];
		}

		public void add(int x, int d) {
			for (int i = x; i < sum.length; i = (i | (i + 1))) {
				sum[i] += d;
			}
		}

		public int sum(int r) {
			int ans = 0;
			for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
				ans += sum[i];
			}
			return ans;
		}

		public int sum(int l, int r) {
			if (l > r) {
				return 0;
			}
			return sum(r) - sum(l - 1);
		}
	}

	public long gcd(long x, long y) {
		if (y == 0) {
			return x;
		}
		if (x == 0) {
			return y;
		}
		return gcd(y, x % y);
	}

	public long[][] pow(long[][] x, long p) {
		if (p == 0) {
			long[][] ans = new long[x.length][x.length];
			for (int i = 0; i < ans.length; i++) {
				ans[i][i] = 1;
			}
			return ans;
		}
		long[][] t = pow(x, p / 2);
		t = multiply(t, t);
		if (p % 2 == 1) {
			t = multiply(t, x);
		}
		return t;
	}

	public long[][] multiply(long[][] a, long[][] b) {
		long[][] ans = new long[a.length][b[0].length];
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				for (int k = 0; k < b.length; k++) {
					ans[i][j] += a[i][k] * b[k][j];
					ans[i][j] %= mod;
				}
			}
		}
		return ans;
	}

	public long pow(long x, long p) {
		if (p == 0) {
			return 1;
		}
		long t = pow(x, p / 2);
		t *= t;
		t %= mod;
		if (p % 2 == 1) {
			t *= x;
			t %= mod;
		}
		return t;
	}

	public long modInv(long x) {
		return pow(x, mod - 2);
	}
	
	long mod = 1000000007;
	
	public class VectorInt {
		long x;
		long y;
		
		public VectorInt(long x, long y) {
			this.x = x;
			this.y = y;
		}
		
		public VectorInt subtract(VectorInt v) {
			return new VectorInt(x - v.x, y - v.y);
		}
		
		public double norm() {
			return Math.sqrt(x * x + y * y);
		}
	}
	
	public class VectorDouble {
		double x;
		double y;
		
		public VectorDouble(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		public VectorDouble(VectorInt v) {
			x = v.x;
			y = v.y;
		}
		
		public String toString() {
			return x + " " + y;
		}
		
		public VectorDouble add(VectorDouble v) {
			return new VectorDouble(x + v.x, y + v.y);
		}

		public VectorDouble subtract(VectorDouble v) {
			return new VectorDouble(x - v.x, y - v.y);
		}
		
		public VectorDouble mult(double c) {
			return new VectorDouble(x * c, y * c);
		}
		
		public double norm() {
			return Math.sqrt(x * x + y * y);
		}
		
		public double norm2() {
			return x * x + y * y;
		}
		
		public void normalize() {
			double n = norm();
			x /= n;
			y /= n;
		}
	}
	
	public long dp(VectorInt a, VectorInt b) {
		return a.x * b.x + a.y * b.y;
	}
	
	public long cp(VectorInt a, VectorInt b) {
		return a.x * b.y - a.y * b.x;
	}
	
	public double dp(VectorDouble a, VectorDouble b) {
		return a.x * b.x + a.y * b.y;
	}
	
	public double cp(VectorDouble a, VectorDouble b) {
		return a.x * b.y - a.y * b.x;
	}
	
	Random random = new Random(566);
	
	double eps = 1e-9;
	
	public class Fret implements Comparable<Fret> {
		int value;
		int index;
		
		public Fret(int value, int index) {
			this.value = value;
			this.index = index;
		}

		@Override
		public int compareTo(Fret o) {
			if (value != o.value) {
				return value - o.value;
			}
			return index - o.index;
		}
		
	}
	
	public void solve() {
		int n = in.nextInt();
		boolean[] type = new boolean[2 * n];
		int[] a = new int[2 * n];
		Stack<Integer> index = new Stack<>();
		for (int i = 0; i < a.length; i++) {
			if (in.next().equals("+")) {
				type[i] = true;
				index.add(i);
			} else {
				int x = in.nextInt();
				if (index.isEmpty()) {
					out.print("NO");
					return;
				}
				a[index.pop()] = x;
				a[i] = x;
			}
		}
		PriorityQueue<Integer> q = new PriorityQueue<>();
		for (int i = 0; i < type.length; i++) {
			if (type[i]) {
				q.add(a[i]);
			} else {
				if (!q.poll().equals(a[i])) {
					out.print("NO");
					return;
				}
			}
		}
		out.println("YES");
		for (int i = 0; i < a.length; i++) {
			if (type[i]) {
				out.print(a[i] + " ");
			}
		}
	}
	
	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("input.txt"));
				out = new PrintWriter(new File("output.txt"));
			}
			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				return null;
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

	}

	// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	public static void main(String[] arg) {
		long time = System.currentTimeMillis();
		new D().run();
		System.err.println(System.currentTimeMillis() - time);
	}
}