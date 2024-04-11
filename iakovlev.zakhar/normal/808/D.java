import java.util.*;
import java.io.*;
import java.math.BigInteger;
import java.nio.file.WatchEvent.Kind;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    
    
    public void solve() {
    	int n = in.nextInt();
    	long[] a = new long[n];
    	TreeMap<Long, Integer> first = new TreeMap<>();
    	TreeMap<Long, Integer> last = new TreeMap<>();
    	long s = 0L;
    	for (int i = 0; i < a.length; i++) {
			a[i] = in.nextLong();
			s += a[i];
			last.put(a[i], i);
			if (!first.containsKey(a[i])) {
				first.put(a[i], i);
			}
		}
    	if (s % 2 != 0) {
			System.out.println("NO");
			return;
		}
    	long s1 = 0L;
    	for (int i = 0; i < a.length; i++) {
			s1 += a[i];
			long s2 = s - s1;
			if (s1 == s2) {
				System.out.println("YES");
				return;
			}
			if (first.containsKey((s1 - s2) / 2) && first.get((s1 - s2) / 2) <= i) {
				System.out.println("YES");
				return;
			}
			if (last.containsKey((s2 - s1) / 2) && last.get((s2 - s1) / 2) > i) {
				System.out.println("YES");
				return;
			}
		}
    	System.out.println("NO");
    			
    }

    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("segments.in"));
                out = new PrintWriter(new File("segments.out"));
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
    public static void main(String[] arg) {
        new D().run();
    }
}