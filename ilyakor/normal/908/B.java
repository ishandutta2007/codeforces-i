import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        static final int[] dx = new int[]{-1, 1, 0, 0};
        static final int[] dy = new int[]{0, 0, -1, 1};
        char[][] A;
        int n;
        int m;
        int x;
        int y;
        int fx = -1;
        int fy = -1;
        boolean broken;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            A = new char[n][];
            int sx = -1, sy = -1;
            for (int i = 0; i < n; ++i) {
                A[i] = in.nextToken().toCharArray();
                for (int j = 0; j < m; ++j) {
                    if (A[i][j] == 'S') {
                        sx = i;
                        sy = j;
                    }
                    if (A[i][j] == 'E') {
                        fx = i;
                        fy = j;
                    }
                }
            }
            char[] seq = in.nextToken().toCharArray();
            int[] p = new int[]{0, 1, 2, 3};
            int res = 0;
            do {
                int[] a = new int[seq.length];
                for (int i = 0; i < a.length; ++i)
                    a[i] = p[seq[i] - '0'];
                x = sx;
                y = sy;
                broken = false;
                apply(a);
                if (!broken && x == fx && y == fy) ++res;
            } while (Permutations.nextPermutation(p));
            out.printLine(res);
        }

        private void apply(int[] a) {
            for (int dir : a) {
                x += dx[dir];
                y += dy[dir];
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    broken = true;
                    break;
                }
                if (A[x][y] == '#') {
                    broken = true;
                    break;
                }
                if (x == fx && y == fy) break;
            }
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

        public String nextToken() {
            int c = readSkipSpace();
            StringBuilder sb = new StringBuilder();
            while (!isSpace(c)) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
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

    static class Permutations {
        public static boolean nextPermutation(int[] p) {
            for (int a = p.length - 2; a >= 0; --a)
                if (p[a] < p[a + 1])
                    for (int b = p.length - 1; ; --b)
                        if (p[b] > p[a]) {
                            int t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                            for (++a, b = p.length - 1; a < b; ++a, --b) {
                                t = p[a];
                                p[a] = p[b];
                                p[b] = t;
                            }
                            return true;
                        }
            return false;
        }

    }
}