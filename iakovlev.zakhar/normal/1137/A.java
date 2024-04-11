import java.util.*;

import java.io.*;
import java.math.BigInteger;

public class E {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public class Edge implements Comparable<Edge> {
		int from;
		int to;
		long len;
		
		public Edge(int from, int to, long len) {
			this.from = from;
			this.to = to;
			this.len = len;
		}

		@Override
		public int compareTo(Edge o) {
			if (len > o.len) {
				return 1;
			}
			if (len < o.len) {
				return -1;
			}
			return 0;
		}
		
	}
	
	public class DSU {
		int[] sz;
		int[] p;
		
		public DSU(int n) {
			sz = new int[n];
			p = new int[n];
			for (int i = 0; i < p.length; i++) {
				p[i] = i;
				sz[i] = 1;
			}
		}
		
		public int get(int x) {
			if (x == p[x]) {
				return x;
			}
			int par = get(p[x]);
			p[x] = par;
			return par;
		}
		
		public boolean unite(int a, int b) {
			int pa = get(a);
			int pb = get(b);
			if (sz[pa] == 1) {
				p[pa] = pb;
				sz[pb] += sz[pa];
				return true;
			}
			if (sz[pb] == 1) {
				p[pb] = pa;
				sz[pa] += sz[pb];
				return true;
			}
			return false;
		}
	}
	
	public class SegmentTree {
		int pow;
		int[][] sum;
		int[][] delta;
		boolean[] flag;
		
		public SegmentTree(int[][] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			sum = new int[2 * pow][24];
			delta = new int[2 * pow][24];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
			}
			for (int i = pow - 1; i > 0; i--) {
				sum[i] = f(sum[2 * i], sum[2 * i + 1]);
			}
		}
		
		public int[] get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (l > r) {
				return new int[24];
			}
			if (l == tl && r == tr) {
				return sum[v];
			}
			int tm = (tl + tr) / 2;
			return f(get(2 * v, tl, tm, l, Math.min(r, tm)), get(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r));
		}
		
		public void set(int v, int tl, int tr, int l, int r, int[] x) {
			push(v, tl, tr);
			if (l > tr || r < tl) {
				return;
			}
			if (l <= tl && r >= tr) {
				delta[v] = x.clone();
				flag[v] = true;
				push(v, tl, tr);
				return;
			}
			int tm = (tl + tr) / 2;
			set(2 * v, tl, tm, l, r, x);
			set(2 * v + 1, tm + 1, tr, l, r, x);
			sum[v] = f(sum[2 * v], sum[2 * v + 1]);
		}
		
		public void push(int v, int tl, int tr) {
			if (flag[v]) {
				if (v < pow) {
					flag[2 * v] = true;
					flag[2 * v + 1] = true;
					delta[2 * v] = delta[v].clone();
					delta[2 * v + 1] = delta[v].clone();
				}
				flag[v] = false;
				for (int i = 0; i < 24; i++) {
					sum[v][i] = delta[v][i] * (tr - tl + 1);
				}
			}
		}
		
		public int[] f(int[] a, int[] b) {
			int[] ans = new int[24];
			for (int i = 0; i < ans.length; i++) {
				ans[i] = a[i] + b[i];
			}
			return ans;
		}
	}
	
	public class Pair implements Comparable<Pair>{
		long x;
		long y;
		int n;

		public Pair(long x, long y, int n) {
			this.x = x;
			this.y = y;
			this.n = n;
		}

		@Override
		public int compareTo(Pair o) {
			if (x - y > o.x - o.y) {
				return 1;
			}
			if (x - y < o.x - o.y) {
				return -1;
			}
			return 0;
		}
	}
	
	long mod;
	Random random = new Random();
	
	public void shuffle(int[][] a) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				int x = random.nextInt(j + 1);
				int t = a[i][x];
				a[i][x] = a[i][j];
				a[i][j] = t;
			}
		}
	}
	
	public void sort(int[][] a) {
		for (int i = 0; i < a.length; i++) {
			Arrays.sort(a[i]);
		}
	}
	
	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				a[i][j] = in.nextInt();
			}
		}
		int[][] row = new int[n][m];
		for (int i = 0; i < row.length; i++) {
			row[i] = a[i].clone();
		}
		int[][] c = new int[m][n];
		for (int i = 0; i < c.length; i++) {
			for (int j = 0; j < c[0].length; j++) {
				c[i][j] = a[j][i];
			}
		}
		shuffle(row);
		shuffle(c);
		sort(row);
		sort(c);
		HashMap<Integer, Integer>[] rm = new HashMap[n];
		HashMap<Integer, Integer>[] cm = new HashMap[m];
		int[] freer = new int[n];
		int[] freec = new int[m];
		for (int i = 0; i < row.length; i++) {
			rm[i] = new HashMap<>();
			rm[i].put(row[i][0], 1);
			freer[i] = 2;
			for (int j = 1; j < row[i].length; j++) {
				if (row[i][j] != row[i][j - 1]) {
					rm[i].put(row[i][j], freer[i]);
					freer[i]++;
				}
			}
		}
		for (int i = 0; i < c.length; i++) {
			cm[i] = new HashMap<>();
			cm[i].put(c[i][0], 1);
			freec[i] = 2;
			for (int j = 1; j < c[i].length; j++) {
				if (c[i][j] != c[i][j - 1]) {
					cm[i].put(c[i][j], freec[i]);
					freec[i]++;
				}
			}
		}
		int[][] ans = new int[n][m];
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
//				System.out.println(a[i][j] + " " + rm[i].get(a[i][j]) + " " + cm[j].get(a[i][j]) + " " + freer[i] + " " + freec[j] + " " + Math.max(rm[i].get(a[i][j]), cm[j].get(a[i][j])) + " " + Math.max(freer[i] - rm[i].get(a[i][j]), freec[j] - cm[j].get(a[i][j])));
				ans[i][j] = Math.max(rm[i].get(a[i][j]), cm[j].get(a[i][j])) + Math.max(freer[i] - rm[i].get(a[i][j]), freec[j] - cm[j].get(a[i][j])) - 1;
//				System.out.println(ans[i][j]);
			}
		}
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				out.print(ans[i][j] + " ");
			}
			out.println();
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
		new E().run();
	}
}