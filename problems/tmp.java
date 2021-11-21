import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Elephant {
	int w;
	int s;
	int id;

	public Elephant(int w, int s, int id) {
		this.w = w;
		this.s = s;
		this.id = id;
	}
}

class EleComparator implements Comparator<Elephant> {

	@Override
	public int compare(Elephant o1, Elephant o2) {
		if (o1.w < o2.w)
			return -1;
		else if (o1.w > o2.w)
			return 1;
		else {
			if (o1.s > o2.s)
				return -1;
			else if (o1.s < o2.s)
				return 1;
			else
				return 0;
		}
	}
}

class BiggerSmarter {
	static final int MAXN = 1005;
	Elephant[] e = new Elephant[MAXN];
	int[] d = new int[MAXN];
	int[] fa = new int[MAXN];
	int index = 0;
	int count = 0;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		BiggerSmarter m = new BiggerSmarter();
		int n = 0;
		while (scanner.hasNext()) {
			m.e[++n] = new Elephant(scanner.nextInt(), scanner.nextInt(), n);
		}
		Arrays.fill(m.fa, -1);
		Arrays.sort(m.e, 1, n + 1, new EleComparator());
		m.dp(n);
		System.out.println(m.count);
		m.print(m.index);
	}

	private void dp(int n) {
		for (int i = 1; i <= n; i++) {
			d[i] = 1;
			for (int j = 1; j < i; j++) {
				if (e[j].w < e[i].w && e[j].s > e[i].s) {
					if (d[i] < d[j] + 1) {
						d[i] = d[j] + 1;
						fa[i] = j;
					}
				}
				if (count < d[i]) {
					count = d[i];
					index = i;
				}
			}
		}
	}

	private void print(int x) {
		int y = fa[x];
		if (y == -1) {
			System.out.println(e[x].id);
			return;
		}
		print(y);
		System.out.println(e[x].id);
	}
}