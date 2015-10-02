import java.util.Scanner;
import java.math.*;
class Code
{
	public static void main (String[] args)
	{
		Scanner sc=new Scanner(System.in);
        BigInteger n=sc.nextBigInteger();
        int d=sc.nextInt();
        while(true)
        {
        	if(d==0&&n.compareTo(BigInteger.ZERO)==0)break;
        	BigInteger b=n.pow(d);
        	System.out.println(b);
            n=sc.nextBigInteger();
            d=sc.nextInt();
        }
	}
}