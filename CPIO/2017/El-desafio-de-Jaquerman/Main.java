/*
 * https://omegaup.com/arena/problem/El-desafio-de-Jaquerman/
 * 
 * Se observa que para i<n el mcd(i, i+1, ..., n) es siempre 1 y
 * para i=n es n.
 * Por tanto, la sumatoria queda 1+1+...+1+n, donde
 * la cantidad de 1s es n-1.
 */

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n = (new Scanner(System.in)).nextInt();
        long rpta = (n - 1) + n;  // Equivalentemente: 2 * n - 1
        System.out.println(rpta);
    }
}
