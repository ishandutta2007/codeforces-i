import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.math.MathContext;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long n = in.nextLong();
        long m = in.nextLong();
        int k = in.nextInt();
        long[] a = new long[k];
        long N = 1;
        for (int i = 0; i < k; ++i) {
            a[i] = in.nextLong();
            long x = a[i];
            long d = IntegerUtlis.gcd(x, N);
            x /= d;
            if (N > ((long)(1E15)) / x + 10) {
                out.printLine("NO");
                return;
            }
            N *= x;
            if (N > n) {
                out.printLine("NO");
                return;
            }
        }
        long _N = N;
        long[] p = new long[1000];
        int[] ppow = new int[1000];
        int pcnt = 0;
        for (long i = 2; i * i <= N; ++i) {
            if (N % i == 0) {
                int pw = 0;
                while (N % i == 0) {
                    ++pw;
                    N /= i;
                }
                p[pcnt] = i;
                ppow[pcnt] = pw;
                ++pcnt;
            }
        }
        if (N > 1) {
            p[pcnt] = N;
            ppow[pcnt] = 1;
            ++pcnt;
        }

        long[] shifts = new long[pcnt];
        for (int i = 0; i < pcnt; ++i) {
            for (int j = 0; j < k; ++j) {
                int cur = 0;
                long x = a[j];
                while (x % p[i] == 0) {
                    x /= p[i];
                    ++cur;
                }
                if (cur == ppow[i]) {
                    shifts[i] = -j;
                }
            }
        }

        // Chinese theorem
        long res = 0;
        long mod = 1;
        for (int i = 0; i < pcnt; ++i) {
            long cm = 1;
            for (int j = 0; j < ppow[i]; ++j)
                cm *= p[i];
            long co = cm + shifts[i];
            co %= cm;
            co += cm;
            co %= cm;

            BigInteger rcm = BigInteger.valueOf(cm).modInverse(BigInteger.valueOf(mod));
            rcm = rcm.multiply(BigInteger.valueOf(res - co));
            rcm = rcm.mod(BigInteger.valueOf(mod)).add(BigInteger.valueOf(mod)).mod(BigInteger.valueOf(mod));
            rcm = rcm.multiply(BigInteger.valueOf(cm)).add(BigInteger.valueOf(co));
            Assert.assertTrue(rcm.mod(BigInteger.valueOf(cm)).longValue() == co);
            Assert.assertTrue(rcm.mod(BigInteger.valueOf(mod)).longValue() == res);

            if (rcm.compareTo(BigInteger.valueOf(m)) > 0) {
                out.printLine("NO");
                return;
            }

            res = rcm.longValue();
            mod *= cm;
            if (res > m) {
                out.printLine("NO");
                return;
            }
        }
        if (res == 0) res = mod;
        for (int i = 0; i < k; ++i) {
            if (res + i > m) {
                out.printLine("NO");
                return;
            }
            long cur = IntegerUtlis.gcd(_N, res + i);
            if (cur != a[i]) {
                out.printLine("NO");
                return;
            }
        }
        out.printLine("YES");
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buffer = new byte[10000];
    private int cur;
    private int count;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public static boolean isSpace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public int read() {
        if (count == -1) {
            throw new InputMismatchException();
        }
        try {
            if (cur >= count) {
                cur = 0;
                count = stream.read(buffer);
                if (count <= 0)
                    return -1;
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return buffer[cur++];
    }

    public int readSkipSpace() {
        int c;
        do {
            c = read();
        } while (isSpace(c));
        return c;
    }

    public int nextInt() {
        int sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10 + c - '0';
            c = read();
        } while (!isSpace(c));
        res *= sgn;
        return res;
    }

    public long nextLong() {
        long sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10L + (long)(c - '0');
            c = read();
        } while (!isSpace(c));
        res *= sgn;
        return res;
    }

    }

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

    }

class IntegerUtlis {

    public static long gcd(long x, long y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

    }

class Assert {

    public static void assertTrue(boolean flag) {
        if (!flag)
            throw new AssertionError();
    }

    }