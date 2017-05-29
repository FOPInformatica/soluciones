import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n = (new Scanner(System.in)).nextInt();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
            ++ans;
        ans += n;
        System.out.println(ans);
    }
}
