import java.math.BigInteger;
import java.util.*;
public class Main {
	static BigInteger num[]=new BigInteger[110];
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		int n=sc.nextInt();
		num[0]=BigInteger.valueOf(1);
		num[1]=BigInteger.valueOf(0);
		num[2]=BigInteger.valueOf(1);
		for(int i=3;i<=100;i++){
			num[i]=BigInteger.valueOf(i-1).multiply(num[i-1].add(num[i-2]));
		}
		BigInteger fenzi=num[n-k];
		BigInteger fenmu=BigInteger.valueOf(1);
		for(int i=k;i>=1;i--){
			fenmu=fenmu.multiply(BigInteger.valueOf(i));
		}
		for(int i=n-k;i>=1;i--){
			fenmu=fenmu.multiply(BigInteger.valueOf(i));
		}
		if(fenzi.compareTo(BigInteger.valueOf(0))==0) System.out.println(0);
		else{
		BigInteger gc=gcd(fenzi,fenmu);
		fenmu=fenmu.divide(gc);
		fenzi=fenzi.divide(gc);
		System.out.println(fenzi+"/"+fenmu);
		}
	}
	
	static BigInteger gcd(BigInteger a,BigInteger b){
		return a.mod(b).compareTo(BigInteger.valueOf(0))==0?b:gcd(b,a.mod(b));
	}
}