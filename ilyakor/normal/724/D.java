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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int m = in.nextInt();
            String s_ = in.nextToken();
            char[] s = s_.toCharArray();
            for (char last = 'a'; last <= 'z'; ++last) {
                boolean okish = true;
                int pt = -1;
                for (int i = 0; i < s.length; ++i) {
                    if (s[i] <= last)
                        pt = i;
                    if (i - pt >= m) {
                        okish = false;
                        break;
                    }
                }
                if (!okish) continue;
                pt = -1;
                int prev = -100000000;
                StringBuilder res = new StringBuilder();
                for (int i = 0; i < s.length; ++i) {
                    if (s[i] + 1 <= last) {
                        res.append(s[i]);
                        prev = i;
                        pt = i;
                        continue;
                    }
                    if (s[i] == last) {
                        prev = i;
                    }
                    if (i - pt >= m) {
                        res.append(s[prev]);
                        pt = prev;
                    }
                }
                char[] r = res.toString().toCharArray();
                Arrays.sort(r);
                out.printLine(new String(r));
                return;
            }
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
}