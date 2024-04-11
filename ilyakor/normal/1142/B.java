import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int q = in.nextInt();
            int[] p = new int[n];
            for (int i = 0; i < n; ++i)
                p[in.nextInt() - 1] = i;
            int[] a = new int[m];
            for (int i = 0; i < m; ++i)
                a[i] = p[in.nextInt() - 1];
            int[][] next = new int[20][m];
            {
                int[] nx = new int[n];
                Arrays.fill(nx, m);
                for (int i = m - 1; i >= 0; --i) {
                    int x = a[i];
                    nx[x] = i;
                    next[0][i] = nx[(x + 1) % n];
                }
            }
            for (int i = 1; i < next.length; ++i) {
                for (int j = 0; j < m; ++j) {
                    int t = next[i - 1][j];
                    if (t < m) t = next[i - 1][t];
                    next[i][j] = t;
                }
            }
            int[] d = new int[m];
            for (int i = 0; i < m; ++i) {
                int t = i;
                for (int j = next.length - 1; j >= 0; --j) {
                    if (t >= m) break;
                    if (((n - 1) >> j) % 2 == 1)
                        t = next[j][t];
                }
                d[i] = t;
            }

            SegmentTreeFastAddMax tree = new SegmentTreeFastAddMax(m + 2);
            for (int i = 0; i < m; ++i)
                tree.set(i + 1, -d[i]);
            for (int i = 0; i < q; ++i) {
                int l = in.nextInt();
                int r = in.nextInt();
                long val = -tree.max(l, r);
                if (val + 1 <= r)
                    out.print('1');
                else
                    out.print('0');
            }
            out.printLine();
        }

    }

    static class SegmentTreeFastAddMax {
        final int n;
        final long[] t;

        public SegmentTreeFastAddMax(int n) {
            int h = 1;
            while (h <= n) h *= 2;
            n = h;
            this.n = n;
            t = new long[n + n];
        }

        public void set(int i, long value) {
            add(i, value - t[i + n]);
        }

        public void add(int i, long value) {
            i += n;
            t[i] += value;
            for (; i > 1; i >>= 1)
                t[i >> 1] = Math.max(t[i], t[i ^ 1]);
        }

        public long max(int a, int b) {
            long res = Long.MIN_VALUE;
            for (a += n, b += n; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
                res = Math.max(res, t[a]);
                res = Math.max(res, t[b]);
            }
            return res;
        }

    }

    static class OutputWriter {
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

    static class InputReader {
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

    }
}